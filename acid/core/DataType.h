// Copyright 2025 huyoufu. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ACID_CORE_DATATYPE_H_
#define ACID_CORE_DATATYPE_H_

namespace acid {

enum class DataType {
  Int8,
  Int16,
  Int32,
  Int64,
  UInt8,
  UInt16,
  UInt32,
  UInt64,
  Float16,
  Float32,
  Float64,
  Bfloat16,
  Bool,
  Char,
  NumTypes,
  Unknown
};

#ifndef FOR_EACH_DATA_TYPE
#define FOR_EACH_DATA_TYPE(_) \
  _(Int8) \
  _(Int16) \
  _(Int32) \
  _(Int64) \
  _(UInt8) \
  _(UInt16) \
  _(UInt32) \
  _(UInt64) \
  _(Float16) \
  _(Float32) \
  _(Float64) \
  _(Bfloat16) \
  _(Bool) \
  _(Char)
#endif

#define CONSTEXPR_DATA_TYPE_CASE(data_type) \
  constexpr DataType k##data_type = DataType::data_type;

  FOR_EACH_DATA_TYPE(CONSTEXPR_DATA_TYPE_CASE)

#undef CONSTEXPR_DATA_TYPE_CASE


} // namespace acid

#endif //ACID_CORE_DATATYPE_H_
