/*
Copyright (c) 2016 Snowplow Analytics Ltd. All rights reserved.

This program is licensed to you under the Apache License Version 2.0,
and you may not use this file except in compliance with the Apache License Version 2.0.
You may obtain a copy of the Apache License Version 2.0 at http://www.apache.org/licenses/LICENSE-2.0.

Unless required by applicable law or agreed to in writing,
software distributed under the Apache License Version 2.0 is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the Apache License Version 2.0 for the specific language governing permissions and limitations there under.
*/

#include "../vendored/catch.hpp"
#include "../emitter.hpp"

TEST_CASE("emitter") {

  Emitter emitter("ea2673c7.ngrok.io", Emitter::Strategy::ASYNC, Emitter::Method::POST, Emitter::Protocol::HTTP, 500, 52000, 52000, "test.db");
  emitter.start();

  Payload payload;
  payload.add("e", "pv");
  payload.add("tv", "cpp-0.1.0");
  payload.add("p", "srv");
  payload.add("dtm", std::to_string(Utils::get_unix_epoch_ms()));

  const int send_events_per_thread = 1000;
  const int thread_count = 10;
  vector<thread> threads;

  for (int j = 0; j < thread_count; j++) {
    threads.push_back(thread([=](Emitter & e) {
      Payload payload2;
      payload2.add("e", "pv");
      payload2.add("tv", "cpp-0.1.0");
      payload2.add("p", "srv");
      payload2.add("dtm", std::to_string(Utils::get_unix_epoch_ms()));

      for (int i = 0; i < send_events_per_thread; i++)
      {
        e.add(payload2);
      }
    }, std::ref(emitter)));
  }


  for (unsigned int j = 0; j < threads.size(); j++)
  {
    threads[j].join();
  }

  emitter.stop();

  auto res = test_get_http_request_results();
  int size = res.size();

  int expected = send_events_per_thread*(thread_count + 1);
  REQUIRE(size > expected);
  
  // but does it start again
  emitter.start();
  for (int i = 0; i < 100; i++) {
    emitter.add(payload);
  }
  emitter.stop();

  res = test_get_http_request_results();
  size = res.size();

  REQUIRE(size > expected + 100);

}
