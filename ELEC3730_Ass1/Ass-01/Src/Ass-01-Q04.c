//     $Date: 2019-01-05 04:50:09 +1100 (Sat, 05 Jan 2019) $
// $Revision: 1529 $
//   $Author: Peter $

// Question 4

// Ask about "zero length strings".

#include "Ass-01.h"

int string_parser(char *inp, char **array_of_words_p[]) {

  // Need to parse a terminal input into individual words.
  // The input is NULL terminated.
  // Needs to return the number of individual words in the input.

  int *num_of_words = 0;                      // The number of words in the input.
  char delim[] = " ";                         // The delimiter for breaking up the input into words.
  int init_size = strlen(inp);                // The length of the input.
  char copiedInput[init_size];
  strncpy(copiedInput,inp,init_size);


  char *ptr = strtok(copiedInput, delim);// strtok returns a pointer to the word

  while(ptr != NULL)                          // Keep breaking the input up until NULL is reached at the end.
  {
    printf("'%s'\n", ptr);
    ptr = strtok(NULL, delim);                // NULL is specified as the input to broken up due to the way strtok works.
    num_of_words++;
}

  // This loop will show that there are zeroes in the str after tokenizing
  for (int i = 0; i < init_size; i++)
  {
    printf("%d ", inp[i]); // Convert the character to integer, in this case the character's ASCII equivalent
  }
  printf("\n");

  return *num_of_words;
}
