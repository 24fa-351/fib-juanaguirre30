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
   int inputNumber = atoi(argv[1]);
   char option = argv[2][0]; 

   FILE *file;
   file = fopen(argv[3], "r");

   int fileNumber; 
   fscanf(file, "%d", &fileNumber); 
   fclose(file);

   int totalInput = inputNumber + fileNumber;
   int decrement = 1;
   totalInput -= decrement;  

   int result;
   if (option == 'r') {
      result = fibRecursive(totalInput);
   } else {
      result = fibIterative(totalInput);
   }

   printf("%d\n", result);

   return 0; 
}