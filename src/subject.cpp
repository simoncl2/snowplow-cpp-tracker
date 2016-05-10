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

#include "subject.hpp"

void Subject::set_user_id(const string & user_id) {
  this->m_payload.add(UID, user_id);
}

void Subject::set_screen_resolution(int width, int height) {
  string res = std::to_string(width) + "x" + std::to_string(height);
  this->m_payload.add(RESOLUTION, res);
}

void Subject::set_viewport(int width, int height) {
  string vport = std::to_string(width) + "x" + std::to_string(height);
  this->m_payload.add(VIEWPORT, vport);
}

void Subject::set_color_depth(int depth) {
  this->m_payload.add(COLOR_DEPTH, std::to_string(depth));
}

void Subject::set_timezone(const string & timezone) {
  this->m_payload.add(TIMEZONE, timezone);
}

void Subject::set_language(const string & language) {
  this->m_payload.add(LANGUAGE, language);
}

Payload Subject::get() {
  return this->m_payload;
}

map<string, string> Subject::get_map() {
  return this->get().get();
}
