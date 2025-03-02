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

#ifndef ACID_IRANGE_H_
#define ACID_IRANGE_H_

#include <type_traits>

namespace acid {

template <typename T,
    typename = std::enable_if_t<std::is_integral_v<T>>>
struct IRange {
  struct Iterator {
    Iterator(T value) : value_(value) {}

    T operator*() const {
      return value_;
    }

    Iterator& operator++() {
      ++value_;
      return *this;
    }

    bool operator!=(const Iterator& other) const {
      return value_ != other.value_;
    }

    private:
        T value_;
  };

  IRange(T end) : IRange(0, end) {}
  IRange(T begin, T end) : begin_(begin), end_(end) {}

  Iterator begin() const {
    return Iterator(begin_);
  }

  Iterator end() const {
    return Iterator(end_);
  }
};

}  // namespace acid

#endif // ACID_IRANGE_H_
