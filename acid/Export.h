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

#ifndef EXPORT_H
#define EXPORT_H

#if defined(__GNUC__)
#define ACID_DEPRECATED __attribute__((deprecated))
#define ACID_FORCE_INLINE __attribute__((always_inline))
#elif defined(_MSC_VER)
#define ACID_DEPRECATED
#define ACID_FORCE_NOINLINE __forceinline
#else
#define ACID_DEPRECATED
#define ACID_FORCE_INLINE
#endif

#if defined(_MSC_VER)
#define ACID_IMPORT __declspec(dllimport)
#define ACID_EXPORT __declspec(dllexport)
#define ACID_LOCAL
#elif __GNUC__ >= 4
#define ACID_IMPORT __attribute__((visibility("default")))
#define ACID_EXPORT __attribute__((visibility("default")))
#define ACID_LOCAL __attribute__((visibility("hidden")))
#else
#define ACID_IMPORT
#define ACID_EXPORT
#define ACID_LOCAL
#endif

#ifdef ACID_EXPORT
#define ACID_API ACID_EXPORT
#else
#define ACID_API
#endif

#endif //EXPORT_H
