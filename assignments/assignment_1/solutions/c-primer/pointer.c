// Copyright (c) 2012 MIT License by 6.172 Staff

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char * argv[]) {  // What is the type of argv?
  int i = 5;
  // The & operator here gets the address of i and stores it into pi
  int * pi = &i;
  // The * operator here dereferences pi and stores the value -- 5 --
  // into j.
  int j = *pi;

  char c[] = "6.172";
  char * pc = c;  // Valid assignment: c acts like a pointer to c[0] here.
  char d = *pc;
  printf("char d = %c\n", d);  // What does this print?

  // compound types are read right to left in C.
  // pcp is a pointer to a pointer to a char, meaning that
  // pcp stores the address of a char pointer.
  char ** pcp;
  pcp = argv;  // Why is this assignment valid? 
  // (answer: argv is a array of pointers or can be used as a pointer to argv[0]
  // and since argv[0] is a pointer itself this is valid)

  const char * pcc = c;  // pcc is a pointer to char constant
  char const * pcc2 = c;  // What is the type of pcc2? (answer: a constant pointer to a char)

  // For each of the following, why is the assignment:
  // *pcc = '7';  // invalid? (answer: pcc points to a constant)
  pcc = *pcp;  // valid? (answer: the pointer pcc isn't a constant itself so can be changed)
  pcc = argv[0];  // valid? (answer: argv is an array of pointers so argv[0] is a pointer to char)

  char * const cp = c;  // cp is a const pointer to char
  // For each of the following, why is the assignment:
  // cp = *pcp;  // invalid? (answer: a const pointer can't change where it's pointing)
  // cp = *argv;  // invalid? (answer: a const pointer can't change where it's pointing)
  *cp = '!';  // valid? (answer: a const pointer can change the value it's pointing at)

  const char * const cpc = c;  // cpc is a const pointer to char const
  // For each of the following, why is the assignment:
  // cpc = *pcp;  // invalid? (answer: a const pointer can't change where it's pointing)
  // cpc = argv[0];  // invalid? (answer: a const pointer can't change where it's pointing)
  // *cpc = '@';  // invalid? (answer: a pointer to a char const can't change the value it's pointing at)

  return 0;
}
