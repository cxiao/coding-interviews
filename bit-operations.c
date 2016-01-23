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

// Function to determine number of bits needed to convert integer A to B
int bitsRequiredForConversion(int a, int b) {
  int diff = a ^ b;
  int result = 0;
  // Keep getting last bit
  while (diff != 0) { // shift off all bits until we're at 0
    if (diff & 1 == 1) {
      result++;
    }
    diff = diff >> 1;
  }
  return result;
}

int main(int argc, char* argv[]) {
  int i;
  if (argc != 3) {
    printf("ERROR: Program expects 2 arguments.\n");
    exit(0);
  }
  int a; int b;
  a = atoi(argv[1]); b = atoi(argv[2]);
  int result;
  result = integerCompare(atoi(argv[1]), atoi(argv[2]));
  printf("Result: %d\n", result);

  result = bitsRequiredForConversion(a, b);
  printf("Result: %d\n", result);
}
