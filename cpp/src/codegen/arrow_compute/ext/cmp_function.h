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

#include <boost/variant.hpp>

namespace sparkcolumnarplugin {
namespace codegen {
namespace arrowcompute {
namespace extra {

struct CompareFunction {
  CompareFunction(const std::vector<arrow::ArrayVector>& array_vectors, 
                  std::vector<std::shared_ptr<arrow::Field>> key_field_list,
                  std::vector<int> key_index_list) {
    for (int key_idx = 0; key_idx < key_field_list.size(); key_idx++) {
      auto field = key_field_list[key_idx];
      int key_col_id = key_index_list[key_idx];
      arrow::ArrayVector col = array_vectors[key_col_id];
      if (field->type()->id() == arrow::Type::UINT8) {
        std::vector<std::shared_ptr<arrow::UInt8Array>> arrays;
        for (int array_id = 0; array_id < col.size(); array_id++) {
          auto typed_array = 
              std::static_pointer_cast<arrow::UInt8Array>(col[array_id]);
          arrays.push_back(typed_array);
        }
        uint8_array_vectors_.push_back(arrays);
        uint8_key_idx.push_back(key_idx);
      } else if (field->type()->id() == arrow::Type::INT8) {
        std::vector<std::shared_ptr<arrow::Int8Array>> arrays;
        for (int array_id = 0; array_id < col.size(); array_id++) {
          auto typed_array = 
              std::static_pointer_cast<arrow::Int8Array>(col[array_id]);
          arrays.push_back(typed_array);
        }
        int8_array_vectors_.push_back(arrays);
        int8_key_idx.push_back(key_idx);
       } else if (field->type()->id() == arrow::Type::UINT16) {
        std::vector<std::shared_ptr<arrow::UInt16Array>> arrays;
        for (int array_id = 0; array_id < col.size(); array_id++) {
          auto typed_array = 
              std::static_pointer_cast<arrow::UInt16Array>(col[array_id]);
          arrays.push_back(typed_array);
        }
        uint16_array_vectors_.push_back(arrays);
        uint16_key_idx.push_back(key_idx);
        } else if (field->type()->id() == arrow::Type::INT16) {
        std::vector<std::shared_ptr<arrow::Int16Array>> arrays;
        for (int array_id = 0; array_id < col.size(); array_id++) {
          auto typed_array = 
              std::static_pointer_cast<arrow::Int16Array>(col[array_id]);
          arrays.push_back(typed_array);
        }
        int16_array_vectors_.push_back(arrays);
        int16_key_idx.push_back(key_idx);  
      } else if (field->type()->id() == arrow::Type::UINT32) {
        std::vector<std::shared_ptr<arrow::UInt32Array>> arrays;
        for (int array_id = 0; array_id < col.size(); array_id++) {
          auto typed_array = 
              std::static_pointer_cast<arrow::UInt32Array>(col[array_id]);
          arrays.push_back(typed_array);
        }
        uint32_array_vectors_.push_back(arrays);
        uint32_key_idx.push_back(key_idx);
      } else if (field->type()->id() == arrow::Type::INT32) {
        std::vector<std::shared_ptr<arrow::Int32Array>> arrays;
        for (int array_id = 0; array_id < col.size(); array_id++) {
          auto typed_array = 
              std::static_pointer_cast<arrow::Int32Array>(col[array_id]);
          arrays.push_back(typed_array);
        }
        int32_array_vectors_.push_back(arrays);
        int32_key_idx.push_back(key_idx);
      } else if (field->type()->id() == arrow::Type::UINT64) {
        std::vector<std::shared_ptr<arrow::UInt64Array>> arrays;
        for (int array_id = 0; array_id < col.size(); array_id++) {
          auto typed_array = 
              std::static_pointer_cast<arrow::UInt64Array>(col[array_id]);
          arrays.push_back(typed_array);
        }
        uint64_array_vectors_.push_back(arrays);
        uint64_key_idx.push_back(key_idx);
      } else if (field->type()->id() == arrow::Type::INT64) {
        std::vector<std::shared_ptr<arrow::Int64Array>> arrays;
        for (int array_id = 0; array_id < col.size(); array_id++) {
          auto typed_array = 
              std::static_pointer_cast<arrow::Int64Array>(col[array_id]);
          arrays.push_back(typed_array);
        }
        int64_array_vectors_.push_back(arrays);
        int64_key_idx.push_back(key_idx);
      } else if (field->type()->id() == arrow::Type::DATE32) {
        std::vector<std::shared_ptr<arrow::Date32Array>> arrays;
        for (int array_id = 0; array_id < col.size(); array_id++) {
          auto typed_array = 
              std::static_pointer_cast<arrow::Date32Array>(col[array_id]);
          arrays.push_back(typed_array);
        }
        date32_array_vectors_.push_back(arrays);
        date32_key_idx.push_back(key_idx);
      } else if (field->type()->id() == arrow::Type::DATE64) {
        std::vector<std::shared_ptr<arrow::Date64Array>> arrays;
        for (int array_id = 0; array_id < col.size(); array_id++) {
          auto typed_array = 
              std::static_pointer_cast<arrow::Date64Array>(col[array_id]);
          arrays.push_back(typed_array);
        }
        date64_array_vectors_.push_back(arrays);
        date64_key_idx.push_back(key_idx);
      } else if (field->type()->id() == arrow::Type::FLOAT) {
        std::vector<std::shared_ptr<arrow::FloatArray>> arrays;
        for (int array_id = 0; array_id < col.size(); array_id++) {
          auto typed_array = 
              std::static_pointer_cast<arrow::FloatArray>(col[array_id]);
          arrays.push_back(typed_array);
        }
        float_array_vectors_.push_back(arrays);
        float_key_idx.push_back(key_idx);
      } else if (field->type()->id() == arrow::Type::DOUBLE) {
        std::vector<std::shared_ptr<arrow::DoubleArray>> arrays;
        for (int array_id = 0; array_id < col.size(); array_id++) {
          auto typed_array = 
              std::static_pointer_cast<arrow::DoubleArray>(col[array_id]);
          arrays.push_back(typed_array);
        }
        double_array_vectors_.push_back(arrays);
        double_key_idx.push_back(key_idx);
      } else if (field->type()->id() == arrow::Type::BOOL) {
        std::vector<std::shared_ptr<arrow::BooleanArray>> arrays;
        for (int array_id = 0; array_id < col.size(); array_id++) {
          auto typed_array = 
              std::static_pointer_cast<arrow::BooleanArray>(col[array_id]);
          arrays.push_back(typed_array);
        }
        bool_array_vectors_.push_back(arrays);
        bool_key_idx.push_back(key_idx);
      } else if (field->type()->id() == arrow::Type::STRING) {
        std::vector<std::shared_ptr<arrow::StringArray>> arrays;
        for (int array_id = 0; array_id < col.size(); array_id++) {
          auto typed_array = 
              std::static_pointer_cast<arrow::StringArray>(col[array_id]);
          arrays.push_back(typed_array);
        }
        str_array_vectors_.push_back(arrays);
        str_key_idx.push_back(key_idx);
      }
    }
  }

  void cmp_uint8(bool asc,
                 bool nulls_first,
                 int key_idx,
                 int left_array_id,
                 int right_array_id,
                 int64_t left_id,
                 int64_t right_id,
                 int& cmp_res) const {
    auto it = find(uint8_key_idx.begin(), uint8_key_idx.end(), key_idx);
    int idx = it - uint8_key_idx.begin();
    bool is_left_null = uint8_array_vectors_[idx][left_array_id]->IsNull(left_id);
    bool is_right_null = uint8_array_vectors_[idx][right_array_id]->IsNull(right_id);
    if (!is_left_null || !is_right_null) {
      if (is_left_null) {
        cmp_res = nulls_first ? 1 : 0;
      } else if (is_right_null) {
        cmp_res = nulls_first ? 0 : 1;
      } else {
        uint32_t left = uint8_array_vectors_[idx][left_array_id]->GetView(left_id);
        uint32_t right = uint8_array_vectors_[idx][right_array_id]->GetView(right_id);
        if (left != right) {
          cmp_res = asc ? (left < right) : (left > right);
        }
      }
    }
  }
  void cmp_int8(bool asc,
                bool nulls_first,
                int key_idx,
                int left_array_id,
                int right_array_id,
                int64_t left_id,
                int64_t right_id,
                int& cmp_res) const {
    auto it = find(int8_key_idx.begin(), int8_key_idx.end(), key_idx);
    int idx = it - int8_key_idx.begin();
    bool is_left_null = int8_array_vectors_[idx][left_array_id]->IsNull(left_id);
    bool is_right_null = int8_array_vectors_[idx][right_array_id]->IsNull(right_id);
    if (!is_left_null || !is_right_null) {
      if (is_left_null) {
        cmp_res = nulls_first ? 1 : 0;
      } else if (is_right_null) {
        cmp_res = nulls_first ? 0 : 1;
      } else {
        uint32_t left = int8_array_vectors_[idx][left_array_id]->GetView(left_id);
        uint32_t right = int8_array_vectors_[idx][right_array_id]->GetView(right_id);
        if (left != right) {
          cmp_res = asc ? (left < right) : (left > right);
        }
      }
    }
  }
  void cmp_uint16(bool asc,
                  bool nulls_first,
                  int key_idx,
                  int left_array_id,
                  int right_array_id,
                  int64_t left_id,
                  int64_t right_id,
                  int& cmp_res) const {
    auto it = find(uint16_key_idx.begin(), uint16_key_idx.end(), key_idx);
    int idx = it - uint16_key_idx.begin();
    bool is_left_null = uint16_array_vectors_[idx][left_array_id]->IsNull(left_id);
    bool is_right_null = uint16_array_vectors_[idx][right_array_id]->IsNull(right_id);
    if (!is_left_null || !is_right_null) {
      if (is_left_null) {
        cmp_res = nulls_first ? 1 : 0;
      } else if (is_right_null) {
        cmp_res = nulls_first ? 0 : 1;
      } else {
        uint32_t left = uint16_array_vectors_[idx][left_array_id]->GetView(left_id);
        uint32_t right = uint16_array_vectors_[idx][right_array_id]->GetView(right_id);
        if (left != right) {
          cmp_res = asc ? (left < right) : (left > right);
        }
      }
    }
  }
  void cmp_int16(bool asc,
                 bool nulls_first,
                 int key_idx,
                 int left_array_id,
                 int right_array_id,
                 int64_t left_id,
                 int64_t right_id,
                 int& cmp_res) const {
    auto it = find(int16_key_idx.begin(), int16_key_idx.end(), key_idx);
    int idx = it - int16_key_idx.begin();
    bool is_left_null = int16_array_vectors_[idx][left_array_id]->IsNull(left_id);
    bool is_right_null = int16_array_vectors_[idx][right_array_id]->IsNull(right_id);
    if (!is_left_null || !is_right_null) {
      if (is_left_null) {
        cmp_res = nulls_first ? 1 : 0;
      } else if (is_right_null) {
        cmp_res = nulls_first ? 0 : 1;
      } else {
        uint32_t left = int16_array_vectors_[idx][left_array_id]->GetView(left_id);
        uint32_t right = int16_array_vectors_[idx][right_array_id]->GetView(right_id);
        if (left != right) {
          cmp_res = asc ? (left < right) : (left > right);
        }
      }
    }
  }  
  void cmp_uint32(bool asc,
                  bool nulls_first,
                  int key_idx,
                  int left_array_id,
                  int right_array_id,
                  int64_t left_id,
                  int64_t right_id,
                  int& cmp_res) const {
    auto it = find(uint32_key_idx.begin(), uint32_key_idx.end(), key_idx);
    int idx = it - uint32_key_idx.begin();
    bool is_left_null = uint32_array_vectors_[idx][left_array_id]->IsNull(left_id);
    bool is_right_null = uint32_array_vectors_[idx][right_array_id]->IsNull(right_id);
    if (!is_left_null || !is_right_null) {
      if (is_left_null) {
        cmp_res = nulls_first ? 1 : 0;
      } else if (is_right_null) {
        cmp_res = nulls_first ? 0 : 1;
      } else {
        uint32_t left = uint32_array_vectors_[idx][left_array_id]->GetView(left_id);
        uint32_t right = uint32_array_vectors_[idx][right_array_id]->GetView(right_id);
        if (left != right) {
          cmp_res = asc ? (left < right) : (left > right);
        }
      }
    }
  }
  void cmp_int32(bool asc,
                  bool nulls_first,
                  int key_idx,
                  int left_array_id,
                  int right_array_id,
                  int64_t left_id,
                  int64_t right_id,
                  int& cmp_res) const {
    auto it = find(int32_key_idx.begin(), int32_key_idx.end(), key_idx);
    int idx = it - int32_key_idx.begin();
    bool is_left_null = int32_array_vectors_[idx][left_array_id]->IsNull(left_id);
    bool is_right_null = int32_array_vectors_[idx][right_array_id]->IsNull(right_id);
    if (!is_left_null || !is_right_null) {
      if (is_left_null) {
        cmp_res = nulls_first ? 1 : 0;
      } else if (is_right_null) {
        cmp_res = nulls_first ? 0 : 1;
      } else {
        uint32_t left = int32_array_vectors_[idx][left_array_id]->GetView(left_id);
        uint32_t right = int32_array_vectors_[idx][right_array_id]->GetView(right_id);
        if (left != right) {
          cmp_res = asc ? (left < right) : (left > right);
        }
      }
    }
  }
  void cmp_uint64(bool asc,
                  bool nulls_first,
                  int key_idx,
                  int left_array_id,
                  int right_array_id,
                  int64_t left_id,
                  int64_t right_id,
                  int& cmp_res) const {
    auto it = find(uint64_key_idx.begin(), uint64_key_idx.end(), key_idx);
    int idx = it - uint64_key_idx.begin();
    bool is_left_null = uint64_array_vectors_[idx][left_array_id]->IsNull(left_id);
    bool is_right_null = uint64_array_vectors_[idx][right_array_id]->IsNull(right_id);
    if (!is_left_null || !is_right_null) {
      if (is_left_null) {
        cmp_res = nulls_first ? 1 : 0;
      } else if (is_right_null) {
        cmp_res = nulls_first ? 0 : 1;
      } else {
        uint32_t left = uint64_array_vectors_[idx][left_array_id]->GetView(left_id);
        uint32_t right = uint64_array_vectors_[idx][right_array_id]->GetView(right_id);
        if (left != right) {
          cmp_res = asc ? (left < right) : (left > right);
        }
      }
    }
  }
  void cmp_int64(bool asc,
                 bool nulls_first,
                 int key_idx,
                 int left_array_id,
                 int right_array_id,
                 int64_t left_id,
                 int64_t right_id,
                 int& cmp_res) const {
    auto it = find(int64_key_idx.begin(), int64_key_idx.end(), key_idx);
    int idx = it - int64_key_idx.begin();
    bool is_left_null = int64_array_vectors_[idx][left_array_id]->IsNull(left_id);
    bool is_right_null = int64_array_vectors_[idx][right_array_id]->IsNull(right_id);
    if (!is_left_null || !is_right_null) {
      if (is_left_null) {
        cmp_res = nulls_first ? 1 : 0;
      } else if (is_right_null) {
        cmp_res = nulls_first ? 0 : 1;
      } else {
        uint32_t left = int64_array_vectors_[idx][left_array_id]->GetView(left_id);
        uint32_t right = int64_array_vectors_[idx][right_array_id]->GetView(right_id);
        if (left != right) {
          cmp_res = asc ? (left < right) : (left > right);
        }
      }
    }
  }
  void cmp_date32(bool asc,
                  bool nulls_first,
                  int key_idx,
                  int left_array_id,
                  int right_array_id,
                  int64_t left_id,
                  int64_t right_id,
                  int& cmp_res) const {
    auto it = find(date32_key_idx.begin(), date32_key_idx.end(), key_idx);
    int idx = it - date32_key_idx.begin();
    bool is_left_null = date32_array_vectors_[idx][left_array_id]->IsNull(left_id);
    bool is_right_null = date32_array_vectors_[idx][right_array_id]->IsNull(right_id);
    if (!is_left_null || !is_right_null) {
      if (is_left_null) {
        cmp_res = nulls_first ? 1 : 0;
      } else if (is_right_null) {
        cmp_res = nulls_first ? 0 : 1;
      } else {
        auto left = date32_array_vectors_[idx][left_array_id]->GetView(left_id);
        auto right = date32_array_vectors_[idx][right_array_id]->GetView(right_id);
        if (left != right) {
          cmp_res = asc ? (left < right) : (left > right);
        }
      }
    }
  }
  void cmp_date64(bool asc,
                  bool nulls_first,
                  int key_idx,
                  int left_array_id,
                  int right_array_id,
                  int64_t left_id,
                  int64_t right_id,
                  int& cmp_res) const {
    auto it = find(date64_key_idx.begin(), date64_key_idx.end(), key_idx);
    int idx = it - date64_key_idx.begin();
    bool is_left_null = date64_array_vectors_[idx][left_array_id]->IsNull(left_id);
    bool is_right_null = date64_array_vectors_[idx][right_array_id]->IsNull(right_id);
    if (!is_left_null || !is_right_null) {
      if (is_left_null) {
        cmp_res = nulls_first ? 1 : 0;
      } else if (is_right_null) {
        cmp_res = nulls_first ? 0 : 1;
      } else {
        auto left = date64_array_vectors_[idx][left_array_id]->GetView(left_id);
        auto right = date64_array_vectors_[idx][right_array_id]->GetView(right_id);
        if (left != right) {
          cmp_res = asc ? (left < right) : (left > right);
        }
      }
    }
  }
  void cmp_float(bool asc,
                 bool nulls_first,
                 int key_idx,
                 int left_array_id,
                 int right_array_id,
                 int64_t left_id,
                 int64_t right_id,
                 int& cmp_res) const {
    auto it = find(float_key_idx.begin(), float_key_idx.end(), key_idx);
    int idx = it - float_key_idx.begin();
    bool is_left_null = float_array_vectors_[idx][left_array_id]->IsNull(left_id);
    bool is_right_null = float_array_vectors_[idx][right_array_id]->IsNull(right_id);
    if (!is_left_null || !is_right_null) {
      if (is_left_null) {
        cmp_res = nulls_first ? 1 : 0;
      } else if (is_right_null) {
        cmp_res = nulls_first ? 0 : 1;
      } else {
        auto left = float_array_vectors_[idx][left_array_id]->GetView(left_id);
        auto right = float_array_vectors_[idx][right_array_id]->GetView(right_id);
        if (left != right) {
          cmp_res = asc ? (left < right) : (left > right);
        }
      }
    }
  }
  void cmp_double(bool asc,
                  bool nulls_first,
                  int key_idx,
                  int left_array_id,
                  int right_array_id,
                  int64_t left_id,
                  int64_t right_id,
                  int& cmp_res) const {
    auto it = find(double_key_idx.begin(), double_key_idx.end(), key_idx);
    int idx = it - double_key_idx.begin();
    bool is_left_null = double_array_vectors_[idx][left_array_id]->IsNull(left_id);
    bool is_right_null = double_array_vectors_[idx][right_array_id]->IsNull(right_id);
    if (!is_left_null || !is_right_null) {
      if (is_left_null) {
        cmp_res = nulls_first ? 1 : 0;
      } else if (is_right_null) {
        cmp_res = nulls_first ? 0 : 1;
      } else {
        auto left = double_array_vectors_[idx][left_array_id]->GetView(left_id);
        auto right = double_array_vectors_[idx][right_array_id]->GetView(right_id);
        if (left != right) {
          cmp_res = asc ? (left < right) : (left > right);
        }
      }
    }
  }
  void cmp_bool(bool asc,
                bool nulls_first,
                int key_idx,
                int left_array_id,
                int right_array_id,
                int64_t left_id,
                int64_t right_id,
                int& cmp_res) const {
    auto it = find(bool_key_idx.begin(), bool_key_idx.end(), key_idx);
    int idx = it - bool_key_idx.begin();
    bool is_left_null = bool_array_vectors_[idx][left_array_id]->IsNull(left_id);
    bool is_right_null = bool_array_vectors_[idx][right_array_id]->IsNull(right_id);
    if (!is_left_null || !is_right_null) {
      if (is_left_null) {
        cmp_res = nulls_first ? 1 : 0;
      } else if (is_right_null) {
        cmp_res = nulls_first ? 0 : 1;
      } else {
        auto left = bool_array_vectors_[idx][left_array_id]->GetView(left_id);
        auto right = bool_array_vectors_[idx][right_array_id]->GetView(right_id);
        if (left != right) {
          cmp_res = asc ? (left < right) : (left > right);
        }
      }
    }
  }
  void cmp_str(bool asc,
               bool nulls_first,
               int key_idx,
               int left_array_id,
               int right_array_id,
               int64_t left_id,
               int64_t right_id,
               int& cmp_res) const {
    auto it = find(str_key_idx.begin(), str_key_idx.end(), key_idx);
    int idx = it - str_key_idx.begin();
    bool is_left_null = str_array_vectors_[idx][left_array_id]->IsNull(left_id);
    bool is_right_null = str_array_vectors_[idx][right_array_id]->IsNull(right_id);
    if (!is_left_null || !is_right_null) {
      if (is_left_null) {
        cmp_res = nulls_first ? 1 : 0;
      } else if (is_right_null) {
        cmp_res = nulls_first ? 0 : 1;
      } else {
        auto left = str_array_vectors_[idx][left_array_id]->GetString(left_id);
        auto right = str_array_vectors_[idx][right_array_id]->GetString(right_id);
        if (left != right) {
          cmp_res = asc ? (left < right) : (left > right);
        }
      }
    }
  }

  private:
  std::vector<std::vector<std::shared_ptr<arrow::UInt8Array>>> uint8_array_vectors_;
  std::vector<int> uint8_key_idx;
  std::vector<std::vector<std::shared_ptr<arrow::Int8Array>>> int8_array_vectors_;
  std::vector<int> int8_key_idx;
  std::vector<std::vector<std::shared_ptr<arrow::UInt16Array>>> uint16_array_vectors_;
  std::vector<int> uint16_key_idx;
  std::vector<std::vector<std::shared_ptr<arrow::Int16Array>>> int16_array_vectors_;
  std::vector<int> int16_key_idx;
  std::vector<std::vector<std::shared_ptr<arrow::UInt32Array>>> uint32_array_vectors_;
  std::vector<int> uint32_key_idx;
  std::vector<std::vector<std::shared_ptr<arrow::Int32Array>>> int32_array_vectors_;
  std::vector<int> int32_key_idx;
  std::vector<std::vector<std::shared_ptr<arrow::UInt64Array>>> uint64_array_vectors_;
  std::vector<int> uint64_key_idx;
  std::vector<std::vector<std::shared_ptr<arrow::Int64Array>>> int64_array_vectors_;
  std::vector<int> int64_key_idx;
  std::vector<std::vector<std::shared_ptr<arrow::Date32Array>>> date32_array_vectors_;
  std::vector<int> date32_key_idx;
  std::vector<std::vector<std::shared_ptr<arrow::Date64Array>>> date64_array_vectors_;
  std::vector<int> date64_key_idx;
  std::vector<std::vector<std::shared_ptr<arrow::FloatArray>>> float_array_vectors_;
  std::vector<int> float_key_idx;
  std::vector<std::vector<std::shared_ptr<arrow::DoubleArray>>> double_array_vectors_;
  std::vector<int> double_key_idx;
  std::vector<std::vector<std::shared_ptr<arrow::BooleanArray>>> bool_array_vectors_;
  std::vector<int> bool_key_idx;
  std::vector<std::vector<std::shared_ptr<arrow::StringArray>>> str_array_vectors_;
  std::vector<int> str_key_idx;
};

void GenCmpFunction(std::vector<std::shared_ptr<arrow::Field>> key_field_list, 
    std::vector<std::function<void(const CompareFunction&, bool, bool, 
    int, int, int, int64_t, int64_t, int&)>>& cmp_functions) {
  std::function<void(const CompareFunction&, bool, bool, int, int, 
                      int, int64_t, int64_t, int&)> cmp_func;
  for (auto field : key_field_list) {
    if (field->type()->id() == arrow::Type::UINT8) {
      cmp_func = &CompareFunction::cmp_uint8;
    } else if (field->type()->id() == arrow::Type::INT8) {
      cmp_func = &CompareFunction::cmp_int8;
    } else if (field->type()->id() == arrow::Type::UINT16) {
      cmp_func = &CompareFunction::cmp_uint16;
    } else if (field->type()->id() == arrow::Type::INT16) {
      cmp_func = &CompareFunction::cmp_int16;
    } else if (field->type()->id() == arrow::Type::UINT32) {
      cmp_func = &CompareFunction::cmp_uint32;
    } else if (field->type()->id() == arrow::Type::INT32) {
      cmp_func = &CompareFunction::cmp_int32;
    } else if (field->type()->id() == arrow::Type::UINT64) {
      cmp_func = &CompareFunction::cmp_uint64;
    } else if (field->type()->id() == arrow::Type::INT64) {
      cmp_func = &CompareFunction::cmp_int64;
    } else if (field->type()->id() == arrow::Type::DATE32) {
      cmp_func = &CompareFunction::cmp_date32;
    } else if (field->type()->id() == arrow::Type::DATE64) {
      cmp_func = &CompareFunction::cmp_date64;
    } else if (field->type()->id() == arrow::Type::FLOAT) {
      cmp_func = &CompareFunction::cmp_float;
    } else if (field->type()->id() == arrow::Type::DOUBLE) {
      cmp_func = &CompareFunction::cmp_double;
    } else if (field->type()->id() == arrow::Type::BOOL) {
      cmp_func = &CompareFunction::cmp_bool;
    } else if (field->type()->id() == arrow::Type::STRING) {
      cmp_func = &CompareFunction::cmp_str;
    }
    cmp_functions.push_back(cmp_func);
  }
}

template <typename DataType>
class PrefixCalculator {
 public:

  template <typename TYPE>
  auto calPrefix(const std::shared_ptr<arrow::Array>& array, 
                 std::vector<uint64_t>& prefix_list,
                 bool nullAsLeast) -> 
      typename std::enable_if_t<std::is_floating_point<TYPE>::value> {
    uint64_t num = array->length();
    auto typed_array = std::dynamic_pointer_cast<ArrayType>(array);
    for (uint64_t i = 0; i < num; i++) {
      if (typed_array->IsNull(i)) {
        if (nullAsLeast) {
          prefix_list.push_back(0);
        } else {
          prefix_list.push_back(UINT64_MAX);
        }
      } else {
        double val = (double)typed_array->GetView(i);
        uint64_t bits = doubleToRawBits(val);
        uint64_t mask = -(bits >> 63) | 0x8000000000000000L;
        prefix_list.push_back(bits ^ mask);
      }
    }
  }

  template <typename TYPE>
  auto calPrefix(const std::shared_ptr<arrow::Array>& array, 
                 std::vector<uint64_t>& prefix_list,
                 bool nullAsLeast) -> 
      typename std::enable_if_t<std::is_same<TYPE, std::string>::value> {
    uint64_t num = array->length();
    // auto typed_array = std::dynamic_pointer_cast<ArrayType>(array);
    for (uint64_t i = 0; i < num; i++) {
      // uint64_t val = (uint64_t)typed_array->GetString(i);
      prefix_list.push_back(0);
    }
  }

  template <typename TYPE>
  auto calPrefix(const std::shared_ptr<arrow::Array>& array, 
                 std::vector<uint64_t>& prefix_list,
                 bool nullAsLeast) -> 
      typename std::enable_if_t<!std::is_same<TYPE, std::string>::value && 
                                !std::is_floating_point<TYPE>::value> {
    uint64_t num = array->length();
    auto typed_array = std::dynamic_pointer_cast<ArrayType>(array);
    for (uint64_t i = 0; i < num; i++) {
      if (typed_array->IsNull(i)) {
        if (nullAsLeast) {
          prefix_list.push_back(0);
        } else {
          prefix_list.push_back(UINT64_MAX);
        }
      } else {
        uint64_t val = (uint64_t)typed_array->GetView(i);
        prefix_list.push_back(val);
      }
    }
  }

 private:
  static inline uint64_t doubleToRawBits(double x) {
    uint64_t bits;
    memcpy(&bits, &x, sizeof bits);
    return bits;
  }

  using ArrayType = typename arrow::TypeTraits<DataType>::ArrayType;
};

#define PROCESS_SUPPORTED_TYPES(PROCESS) \
  PROCESS(arrow::BooleanType)            \
  PROCESS(arrow::UInt8Type)              \
  PROCESS(arrow::Int8Type)               \
  PROCESS(arrow::UInt16Type)             \
  PROCESS(arrow::Int16Type)              \
  PROCESS(arrow::UInt32Type)             \
  PROCESS(arrow::Int32Type)              \
  PROCESS(arrow::UInt64Type)             \
  PROCESS(arrow::Int64Type)              \
  PROCESS(arrow::FloatType)              \
  PROCESS(arrow::DoubleType)             \
  PROCESS(arrow::Date32Type)             \
  PROCESS(arrow::Date64Type)
static arrow::Status GetPrefix(std::shared_ptr<arrow::DataType> type, 
                               const std::shared_ptr<arrow::Array>& array, 
                               std::vector<uint64_t>& prefix_list,
                               bool asc,
                               bool nulls_first) {
  bool nullAsLeast = ((asc && nulls_first) || (!asc && !nulls_first)) ? true : false;
  if (type->id() == arrow::Type::STRING) {
    auto calculator = std::make_shared<PrefixCalculator<arrow::StringType>>();
    calculator->calPrefix<std::string>(array, prefix_list, nullAsLeast);
  } else {
    switch (type->id()) {
#define PROCESS(InType)                                                             \
      case InType::type_id: {                                                       \
        auto calculator = std::make_shared<PrefixCalculator<InType>>();             \
        using CType = typename arrow::TypeTraits<InType>::CType;                    \
        calculator->calPrefix<CType>(array, prefix_list, nullAsLeast);              \
      } break;
        PROCESS_SUPPORTED_TYPES(PROCESS)
#undef PROCESS
      default: {
        std::cout << "GenPrefixCalculator type not supported, type is " 
                  << type << std::endl;
      } break;
    }
  }
  return arrow::Status::OK();
#undef PROCESS_SUPPORTED_TYPES
}

class TypedArraysBase {
 public:
  virtual ~TypedArraysBase() {}

  virtual bool GetView(int array_id, int id, bool res) {
    // return arrow::Status::NotImplemented("TypedArraysBase GetView is abstract. ");
    return res;
  }

  virtual uint8_t GetView(int array_id, int id, uint8_t res) {
    // return arrow::Status::NotImplemented("TypedArraysBase GetView is abstract. ");
    return res;
  }

  virtual int8_t GetView(int array_id, int id, int8_t res) {
    // return arrow::Status::NotImplemented("TypedArraysBase GetView is abstract. ");
    return res;
  }

  virtual uint16_t GetView(int array_id, int id, uint16_t res) {
    // return arrow::Status::NotImplemented("TypedArraysBase GetView is abstract. ");
    return res;
  }

  virtual int16_t GetView(int array_id, int id, int16_t res) {
    // return arrow::Status::NotImplemented("TypedArraysBase GetView is abstract. ");
    return res;
  }

  virtual uint32_t GetView(int array_id, int id, uint32_t res) {
    // return arrow::Status::NotImplemented("TypedArraysBase GetView is abstract. ");
    return res;
  }

  virtual int32_t GetView(int array_id, int id, int32_t res) {
    // return arrow::Status::NotImplemented("TypedArraysBase GetView is abstract. ");
    return res;
  }

  virtual uint64_t GetView(int array_id, int id, uint64_t res) {
    // return arrow::Status::NotImplemented("TypedArraysBase GetView is abstract. ");
    return res;
  }

  virtual int64_t GetView(int array_id, int id, int64_t res) {
    // return arrow::Status::NotImplemented("TypedArraysBase GetView is abstract. ");
    return res;
  }

  virtual float GetView(int array_id, int id, float res) {
    // return arrow::Status::NotImplemented("TypedArraysBase GetView is abstract. ");
    return res;
  }

  virtual double GetView(int array_id, int id, double res) {
    // return arrow::Status::NotImplemented("TypedArraysBase GetView is abstract. ");
    return res;
  }

  virtual std::string GetString(int array_id, int id) {
    // return arrow::Status::NotImplemented("TypedArraysBase GetView is abstract. ");
    std::string res;
    return res;
  }

  virtual bool IsNull(int array_id, int id) {
    std::cout << "TypedArraysBase IsNull is abstract. " << std::endl;
    return false;
  }
};

template <typename DataType, typename CType>
class TypedArrays : public TypedArraysBase {
 public:
  TypedArrays(const arrow::ArrayVector& arrays) {
    for (int array_id = 0; array_id < arrays.size(); array_id++) {
      auto typed_array = std::dynamic_pointer_cast<ArrayType>(arrays[array_id]);
      typed_arrays_.push_back(typed_array);
    }
  }
  ~TypedArrays() {}

  CType GetView(int array_id, int id, CType res) {
    return typed_arrays_[array_id]->GetView(id);
    // std::cout << "res is: " << res << std::endl;
    // return arrow::Status::OK();
    // return res;
  }

  bool IsNull(int array_id, int id) {
    return typed_arrays_[array_id]->IsNull(id);
  }

 private:
  using ArrayType = typename arrow::TypeTraits<DataType>::ArrayType;
  std::vector<std::shared_ptr<ArrayType>> typed_arrays_;
};

template <typename DataType, typename CType>
class StringArrays : public TypedArraysBase {
 public:
  StringArrays(const arrow::ArrayVector& arrays) {
    for (int array_id = 0; array_id < arrays.size(); array_id++) {
      auto typed_array = std::dynamic_pointer_cast<ArrayType>(arrays[array_id]);
      typed_arrays_.push_back(typed_array);
    }
  }
  ~StringArrays() {}

  std::string GetString(int array_id, int id) {
    return typed_arrays_[array_id]->GetString(id);
  }

  bool IsNull(int array_id, int id) {
    return typed_arrays_[array_id]->IsNull(id);
  }

 private:
  using ArrayType = typename arrow::TypeTraits<DataType>::ArrayType;
  std::vector<std::shared_ptr<ArrayType>> typed_arrays_;
};

#define PROCESS_SUPPORTED_TYPES(PROCESS) \
  PROCESS(arrow::BooleanType)            \
  PROCESS(arrow::UInt8Type)              \
  PROCESS(arrow::Int8Type)               \
  PROCESS(arrow::UInt16Type)             \
  PROCESS(arrow::Int16Type)              \
  PROCESS(arrow::UInt32Type)             \
  PROCESS(arrow::Int32Type)              \
  PROCESS(arrow::UInt64Type)             \
  PROCESS(arrow::Int64Type)              \
  PROCESS(arrow::FloatType)              \
  PROCESS(arrow::DoubleType)             \
  PROCESS(arrow::Date32Type)             \
  PROCESS(arrow::Date64Type)
static arrow::Status MakeTypedArrays(const arrow::ArrayVector& arrays,
                                     std::shared_ptr<arrow::DataType> type,
                                     std::shared_ptr<TypedArraysBase>* out) {
  if (type->id() == arrow::Type::STRING) {
    auto arrays_ptr = 
        std::make_shared<StringArrays<arrow::StringType, std::string>>(arrays);
    *out = std::dynamic_pointer_cast<TypedArraysBase>(arrays_ptr);
  } else {
    switch (type->id()) {
#define PROCESS(InType)                                                           \
    case InType::type_id: {                                                       \
      using CType = typename arrow::TypeTraits<InType>::CType;                    \
      auto arrays_ptr = std::make_shared<TypedArrays<InType, CType>>(arrays);     \
      *out = std::dynamic_pointer_cast<TypedArraysBase>(arrays_ptr);              \
    } break;
      PROCESS_SUPPORTED_TYPES(PROCESS)
#undef PROCESS
      default: {
        std::cout << "MakeTypedArrays type not supported, type is " << type << std::endl;
      } break;
    }
  }
  return arrow::Status::OK();
}
#undef PROCESS_SUPPORTED_TYPES

void GenCmpFlags(std::vector<std::shared_ptr<arrow::Field>> key_field_list, 
    std::vector<boost::variant<uint8_t, int8_t, uint16_t, int16_t, uint32_t, int32_t, 
                               uint64_t, int64_t, float, double, bool>>& cmp_flags) {
  for (auto field : key_field_list) {
    if (field->type()->id() == arrow::Type::UINT8) {
      uint8_t flag;
      cmp_flags.push_back(flag);
    } else if (field->type()->id() == arrow::Type::INT8) {
      int8_t flag;
      cmp_flags.push_back(flag);
    } else if (field->type()->id() == arrow::Type::UINT16) {
      uint16_t flag;
      cmp_flags.push_back(flag);
    } else if (field->type()->id() == arrow::Type::INT16) {
      int16_t flag;
      cmp_flags.push_back(flag);
    } else if (field->type()->id() == arrow::Type::UINT32) {
      uint32_t flag;
      cmp_flags.push_back(flag);
    } else if (field->type()->id() == arrow::Type::INT32) {
      int32_t flag;
      cmp_flags.push_back(flag);
    } else if (field->type()->id() == arrow::Type::UINT64) {
      uint64_t flag;
      cmp_flags.push_back(flag);
    } else if (field->type()->id() == arrow::Type::INT64) {
      int64_t flag;
      cmp_flags.push_back(flag);
    } else if (field->type()->id() == arrow::Type::DATE32) {
      int32_t flag;
      cmp_flags.push_back(flag);
    } else if (field->type()->id() == arrow::Type::DATE64) {
      int64_t flag;
      cmp_flags.push_back(flag);
    } else if (field->type()->id() == arrow::Type::FLOAT) {
      float flag;
      cmp_flags.push_back(flag);
    } else if (field->type()->id() == arrow::Type::DOUBLE) {
      double flag;
      cmp_flags.push_back(flag);
    } else if (field->type()->id() == arrow::Type::BOOL) {
      bool flag;
      cmp_flags.push_back(flag);
    }
  }
}

}  // namespace extra
}  // namespace arrowcompute
}  // namespace codegen
}  // namespace sparkcolumnarplugin
