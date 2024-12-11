#include <stdio.h>
#include <stdlib.h>

int fibRecursive(int input) {
   if (input < 2) {
      return input; 
   } else {
      return fibRecursive(input - 1) + fibRecursive(input - 2); 
   } 
}

int fibIterative(int input) {
   int previous = 0; 
   int current = 1; 
   int next = 0;

   for (int i = 0; i < input; i++) {
      next = previous + current;
      previous = current;
      current = next;
   }

   return previous; 
}

int main(int argc, char* argv[]){
   // added check for argc
   if (argc < 4) {
      printf("Usage: %s <inputNumber> <option> <file>\n", argv[0]);
      return 1;
   }

   int inputNumber = atoi(argv[1]);
   char option = argv[2][0]; 

   FILE *file;
   file = fopen(argv[3], "r");
   if (file == NULL) {
      printf("Error: Could not open file %s\n", argv[3]); // added if cant open file
      return 1;
   }

   int fileNumber; 
   fscanf(file, "%d", &fileNumber); 
   fclose(file);

   int totalInput = inputNumber + fileNumber;
   int adjustment = 1;  // aligns input to a zero based index
   totalInput -= adjustment;  

   int result;
   if (option == 'r') {
      result = fibRecursive(totalInput);
   } else {
      result = fibIterative(totalInput);
   }

   printf("%d\n", result);

   return 0; 
}
