// Practicing some bit operations.
// Bitwise ops in C:
// & - bitwise and
// | - bitwise inclusive or
// ^ - bitwise XOR
// << - left shift, used for multiplication by 2
// >> - right shift, used for division by 2
// ~ - bitwise NOT, used for 1's complement

#include <stdio.h>
#include <stdlib.h>

// Check if 2 integers are equal without using comparison operators.
int integerCompare(int a, int b) {
  // a: 00010101
  // b: 00011000
  // r: 00001100 // desired result
  // Need XOR for this!
  int result;
  result = a ^ b;
  if (result != 0) { return 0; } // integers not equal
  else { return 1; } // integers equal
}

int main(int argc, char* argv[]) {
  int i;
  if (argc != 3) {
    printf("ERROR: Program expects 2 arguments.\n");
    exit(0);
  }
  int result;
  result = integerCompare(atoi(argv[1]), atoi(argv[2]));
  printf("Result: %d\n", result);
}
