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

#ifndef SELF_DESCRIBING_JSON_H
#define SELF_DESCRIBING_JSON_H

#include <string>
#include <list>
#include "constants.hpp"
#include "utils.hpp"
#include "payload.hpp"
#include "../include/json.hpp"

using namespace std;
using json = nlohmann::json;

class SelfDescribingJson {
private:
  string m_schema;
  json m_data;

public:
  SelfDescribingJson(const string & schema, json data);
  json get();
  string to_string();
};

#endif
