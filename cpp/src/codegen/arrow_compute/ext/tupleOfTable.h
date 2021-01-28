/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <arrow/status.h>

#include <arrow/type.h>
#include <arrow/array.h>

#include <vector>
#include <tuple>
#include <iostream>

namespace sparkcolumnarplugin {
namespace codegen {
namespace arrowcompute {
namespace extra {

#ifndef TUPLE_OF_VECTORS_H
#define TUPLE_OF_VECTORS_H

template<typename... Ts>
struct TupleOfVectors 
{
  std::tuple<std::vector<Ts>...> tuple;

  template<typename ...Args>
  TupleOfVectors(Args... args)
  : tuple(args...){}

  void do_something_to_each_vec() {
      do_something_to_vec(tuple);
  }

  template<size_t I = 0, class ...P>
  typename std::enable_if<I == sizeof...(P)>::type
  do_something_to_vec(std::tuple<P...> &) {}

  template<size_t I = 0, class ...P>
  typename std::enable_if<I < sizeof...(P)>::type
  do_something_to_vec(std::tuple<P...> & parts) {
      auto & part = std::get<I>(tuple);
      // Doing something...
      std::cout << "vector[" << I << "][0] = " << part[0] << std::endl;
      do_something_to_vec<I + 1>(parts);
  }
};

#endif // EOF

#ifndef TUPLE_OF_TABLE_H
#define TUPLE_OF_TABLE_H

template<typename... Ts>
struct TupleOfTable 
{
  std::tuple<std::vector<std::vector<Ts>...>> tuple;

  template<typename ...Args>
  TupleOfVectors(Args... args)
  : tuple(args...){}

  void do_something_to_each_vec() {
      do_something_to_vec(tuple);
  }

  template<size_t I = 0, class ...P>
  typename std::enable_if<I == sizeof...(P)>::type
  do_something_to_vec(std::tuple<P...> &) {}

  template<size_t I = 0, class ...P>
  typename std::enable_if<I < sizeof...(P)>::type
  do_something_to_vec(std::tuple<P...> & parts) {
      auto & part = std::get<I>(tuple);
      // Doing something...
      std::cout << "vector[" << I << "][0] = " << part[0][0] << std::endl;
      do_something_to_vec<I + 1>(parts);
  }
};

#endif // EOF


}  // namespace extra
}  // namespace arrowcompute
}  // namespace codegen
}  // namespace sparkcolumnarplugin
