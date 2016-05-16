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
#include "../client_session.hpp"

TEST_CASE("client_session") {
  ClientSession cs("test.db");
  //REQUIRE("" == cs.get_session_context("fuck-off").to_string());

  cs.start(2000, 2000, 500);

  this_thread::sleep_for(chrono::milliseconds(5000));

  cs.stop();
}
