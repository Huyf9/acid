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

#ifndef ACID_CORE_CPU_CPUALLOCATOR_H_
#define ACID_CORE_CPU_CPUALLOCATOR_H_

#include <acid/core/AllocatorBase.h>
#include <mimalloc.h>

namespace acid {

namespace cpu {

static void* cpu_malloc(size_t size) {
return mi_malloc(size);
}
        
static void* cpu_realloc(void* p, size_t new_size) {
    return mi_realloc(p, new_size);
}
        
static void cpu_free(void* p) {
    mi_free(p);
}

} // namespace cpu

class ACID_API CPUAllocator : public AllocatorBase {
public:
  CPUAllocator() = default;

  DataPtr allocate(size_t nbytes) override {
    void* data = cpu::cpu_malloc(nbytes);
    return DataPtr(data, CPUAllocator::free);
  }

  void reallocate(DataPtr& d, size_t nbytes) override {
    void* data = cpu::cpu_realloc(d.mutable_get(), nbytes);
    d.reset(data, CPUAllocator::free);
  }

  static void free(void* p) {
    cpu::cpu_free(p);
  }
};

} // namespace acid

#endif //ACID_CORE_CPU_CPUALLOCATOR_H_