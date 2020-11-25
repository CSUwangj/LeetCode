// Copyright 2020 <CSUwangj@protonmail.com>
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

int M[2], R[3];

void A() {
  R[0] = M[0];
}

void B() {
  R[1] = M[1];
}

void C() {
  M[0] = R[2];
}

void D() {
  M[1] = R[2];
}

void E() {
  R[2] = R[1] + R[0];
}

void F() {
  R[2] = R[0] - R[1];
}

int main() {
  int m1, m2;
  char command[300];
  // printf("%d\n", result);
  // char ans[2][10] = {"Happy!\0", "UnHappy!\0"}; 
  while(scanf("%d%d", &m1, &m2) != EOF) {
    M[0] = m1;
    M[1] = m2;
    scanf("%s", command);
    for(int i = 0; command[i] != '\0'; ++i) {
      switch(command[i]) {
        case 'A':
          A();
          break;
        case 'B':
          B();
          break;
        case 'C':
          C();
          break;
        case 'D':
          D();
          break;
        case 'E':
          E();
          break;
        case 'F':
          F();
          break;
      }
    }
    printf("%d,%d\n", M[0], M[1]);
  }
  return 0;
}