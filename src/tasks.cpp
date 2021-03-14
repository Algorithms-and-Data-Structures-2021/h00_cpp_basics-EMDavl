#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

void swap_args(int *lhs, int *rhs) {
    if((lhs == nullptr)||(rhs == nullptr)){
        return;
    }
    int temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

int **allocate_2d_array(int num_rows, int num_cols, int init_value) {
    if((num_rows < 1) || (num_cols < 1)){
        return nullptr;
    }
    int **arr = new int* [num_rows];
    for (int i = 0; i < num_rows; ++i) {
        arr[i] = new int[num_cols];
    }
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            arr[i][j] = init_value;
        }
    }

    return arr;
}

bool copy_2d_array(int **arr_2d_source, int **arr_2d_target, int num_rows, int num_cols) {
    if(arr_2d_source == nullptr || arr_2d_target == nullptr){
        return false;
    }
    if(num_cols < 1 || num_rows < 1){
        return false;
    }
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            arr_2d_target[i][j] = arr_2d_source[i][j];
        }
    }
    return true;
}

void reverse_1d_array(vector<int> &arr) {
    if(arr.empty()){
        return;
    }
    int temp;
    for (int i = 0; i < arr.size() / 2; ++i) {
        temp = arr[i];
        arr[i] = arr[arr.size() - i - 1];
        arr[arr.size() - i - 1] = temp;
    }
}

void reverse_1d_array(int *arr_begin, int *arr_end) {
    if(arr_begin == nullptr || arr_end == nullptr){
        return;
    }
    int temp;
    int *end = arr_end;
    int *begin = arr_begin;
    for (int *pInt = arr_begin; pInt < (arr_end - (arr_end - arr_begin)/2); ++pInt) {
        temp = *begin;
        *begin = *end;
        *end = temp;
        ++begin;
        --end;
    }
}

int *find_max_element(int *arr, int size) {
    if(arr == nullptr || size < 1){
        return nullptr;
    }
    int *max = &arr[0];

    for (int i = 0; i < size; ++i) {
        if(arr[i] > *max){
            max = &arr[i];
        }
    }
    return max;
}

vector<int> find_odd_numbers(vector<int> &arr) {
    vector<int> vector = {};
    if(arr.empty()){
        return vector;
    }
    for (int & i : arr) {
        if(i%2 !=0){
            vector.push_back(i);
        }
    }
    return vector;
}

vector<int> find_common_elements(vector<int> &arr_a, vector<int> &arr_b) {
    vector<int> res;
    if(arr_a.empty() || arr_b.empty()){
        return {};
    }
    for (int i = 0; i < arr_a.size() - 1; ++i) {
        for (int j = 0; j < arr_b.size(); ++j) {
            if(arr_a[i] == arr_b[j]){
                res.push_back(arr_a[i]);
            }
        }
    }
    return res;
}
