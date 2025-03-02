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

#ifndef ALLOCATORBASE_H
#define ALLOCATORBASE_H

#include <memory>
#include <cstddef>
#include <functional>

#include <acid/Export.h>


namespace acid {

using deleteFunc = std::function<void(void*)>;

static void freeNothing(void*) {}

class ACID_API DataPtr {
public:
  DataPtr() : DataPtr(nullptr, freeNothing) {}
  DataPtr(void* data, deleteFunc deleter)
      : data_(data), deleter_(deleter) {}
  DataPtr(DataPtr&& other) noexcept
      : data_(other.data_), deleter_(std::move(other.deleter_)) {
    other.data_ = nullptr;
  }
  DataPtr& operator=(DataPtr&& other) noexcept {
    if (this != &other) {
      data_ = other.data_;
      deleter_ = std::move(other.deleter_);
      other.data_ = nullptr;
    }
    return *this;
  }
  ~DataPtr() {
    if (deleter_) {
      deleter_(data_);
    }
  }

public:
  void* mutable_get() const {
    return data_;
  }

  const void* get() const {
    return data_;
  }

  void reset(void* data, deleteFunc deleter) {
    if (deleter_) {
      deleter_(data_);
    }
    data_ = data;
    deleter_ = deleter;
  }

  deleteFunc get_deleter() const {
    return deleter_;
  }

private:
  void* data_;
  deleteFunc deleter_;
};

class ACID_API AllocatorBase {
public:
  virtual DataPtr allocate(size_t nbytes) = 0;
  virtual void reallocate(DataPtr& d, size_t nbytes) = 0;
  virtual ~AllocatorBase() {}
};

} // namespace acid

#endif //ALLOCATORBASE_H
