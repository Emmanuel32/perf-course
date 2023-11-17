// Copyright (c) 2012 MIT License by 6.172 Staff

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define PRINT_SIZE(a) printf("size of %s : %zu bytes \n", #a, sizeof(a))
#define PRINT_SIZE_STRING(a, b) printf("size of %s : %zu bytes \n", a, sizeof(b))
#define PRINT_SIZE_POINTER(a, b) { b number; printf("size of %s : %zu bytes \n", a, sizeof(&number)); }

int main() {
  // Please print the sizes of the following types:
  // int, short, long, char, float, double, unsigned int, long long
  // uint8_t, uint16_t, uint32_t, and uint64_t, uint_fast8_t,
  // uint_fast16_t, uintmax_t, intmax_t, __int128, and student

  PRINT_SIZE(int);
  PRINT_SIZE(short);
  PRINT_SIZE(long);
  PRINT_SIZE(char);
  PRINT_SIZE(float);
  PRINT_SIZE(double);
  PRINT_SIZE(unsigned int);
  PRINT_SIZE(long long);
  PRINT_SIZE(uint8_t);
  PRINT_SIZE(uint16_t);
  PRINT_SIZE(uint32_t);
  PRINT_SIZE(uint64_t);
  PRINT_SIZE(uint_fast8_t);
  PRINT_SIZE(uint_fast16_t);
  PRINT_SIZE(uintmax_t);
  PRINT_SIZE(intmax_t);
  PRINT_SIZE(__int128);

  // Composite types have sizes too.
  typedef struct {
    int id;
    int year;
  } student;

  student you;
  you.id = 12345;
  you.year = 4;


  // Array declaration. Use your macro to print the size of this.
  int x[5];

  PRINT_SIZE_STRING("student", you);
  PRINT_SIZE(x);

  PRINT_SIZE_POINTER("int*", int);
  PRINT_SIZE_POINTER("short*", short);
  PRINT_SIZE_POINTER("long*", long);
  PRINT_SIZE_POINTER("char*", char);
  PRINT_SIZE_POINTER("float*", float);
  PRINT_SIZE_POINTER("double*", double);
  PRINT_SIZE_POINTER("unsigned int*", unsigned int);
  PRINT_SIZE_POINTER("long long*", long long);
  PRINT_SIZE_POINTER("uint8_t*", uint8_t);
  PRINT_SIZE_POINTER("uint16_t*", uint16_t);
  PRINT_SIZE_POINTER("uint32_t*", uint32_t);
  PRINT_SIZE_POINTER("uint64_t*", uint64_t);
  PRINT_SIZE_POINTER("uint_fast8_t*", uint_fast8_t);
  PRINT_SIZE_POINTER("uint_fast16_t*", uint_fast16_t);
  PRINT_SIZE_POINTER("uintmax_t*", uintmax_t);
  PRINT_SIZE_POINTER("intmax_t*", intmax_t);
  PRINT_SIZE_POINTER("__int128*", __int128);
  PRINT_SIZE_POINTER("student*", student);
  PRINT_SIZE(&x);

  return 0;
}
