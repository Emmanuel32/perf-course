/**
 * Copyright (c) 2012 MIT License by 6.172 Staff
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 **/


#include "./util.h"

// Global temp allocation
data_t* g_left = 0;

// Function prototypes
static inline void merge_m(data_t* A, data_t* B, data_t* C);
static inline void copy_m(data_t* source, data_t* dest, int n);
void isort(data_t* begin, data_t* end);

// A basic merge sort routine that sorts the subarray A[p..r]
void sort_m(data_t* A, int p, int r) {
  assert(A);
  int alloc = 0;
  if (g_left == 0) {
    mem_alloc(&g_left, r - p);
    alloc = 1;
    if (g_left == NULL) {
      mem_free(&g_left);
      return;
    }
  }
  if (p + 30 < r) {
    int q = (p + r) / 2;
    sort_m(A, p, q);
    sort_m(A, q + 1, r);
    merge_m(A + p, A + q, A + r);
  } else {
    isort(A + p, A + r);
  }
  if (alloc) {
    mem_free(&g_left);
  }
}

// A merge routine. Merges the sub-arrays A [p..q] and A [q + 1..r].
// Uses two arrays 'left' and 'right' in the merge operation.
static inline void merge_m(data_t* A, data_t* B, data_t* C) {
  assert(A);
  assert(A <= B);
  assert(B <= C);
  int n1 = B - A + 1;
  data_t* left = g_left;
  copy_m(A, left, n1);
  B++;
  left[n1] = UINT_MAX;

  for (; B <= C; A++) {
    if (*left < *B) {
      *A = *left;
      left++;
    } else {
      *A = *B;
      B++;
    }
  }
  for (; A <= C; A++) {
    *A = *left;
    left++;
  }
}

static inline void copy_m(data_t* source, data_t* dest, int n) {
  assert(dest);
  assert(source);

  for (int i = 0 ; i < n ; i++) {
    dest[i] = source[i];
  }
}
