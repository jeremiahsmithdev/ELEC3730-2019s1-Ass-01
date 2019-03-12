// Question 4

#include "Ass-01.h"
#include <stdio.h>

int string_parser(char *inp, char **array_of_words_p[]) {


  const char delim[2] = " ";                            //The delimiter for breaking up the string.
  char *token;                                          //Intermediate storage of words.
  char* string = strdup(inp);                           //NULL terminated string copy of inp.
  array_of_words_p = malloc(sizeof(char)*100);          //Allocate some memory for the array of words. This amount matches the input string "inp".
  int count = 1;


  token = strtok(string,delim);       //Initial breaking of the string to get first word.
  strcpy(*array_of_words_p[0],token); //Store initial words in the array of words.


  while( token !=  NULL){

    printf("\n%s", token);

    token = strtok(NULL, delim);            //Store the next broken word from the string.
   // strcpy(*array_of_words_p[count],token); //Copy the word into the array of words.
    count++;
  }

/*
    printf("%s ", *array_of_words_p[0]);
    printf("%s ", *array_of_words_p[1]);
    printf("%s ", *array_of_words_p[2]);
    printf("\n");
    i++;
*/

  return 0;
}