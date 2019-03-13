// Question 4
//Very close to being done just have to ask for help on lines 75 and 76. I think...

#include "Ass-01.h"
#include <stdio.h>


/*
 * Gets the size of the contents of a char pointer.
 * The function will only be used in this file and so is static.
 *
 * @Params:
 *
 *  char* s - input pointer whose contents are the subject of the function.
 *
 *
 * @Returns:
 *
 *  int - this is the size of the pointer's subject in bytes.
 *
 *
 */
static int getSize(char *s){

  char* t;                        //This pointer will move through the input input pointer's contents.
  for(t = s; *t !='\0'; t++){}    //Moves the t through contents of s until it NULL terminator
  return t - s;                   //The difference in address between two pointers is the size of s. s points to beggining and t points to the end.
}


/*
 * Break ups a string by a delimiter (currently a space " "). Will be modified later to include a delimiter parameter (dynamic for later assignments).
 *
 * @Params:
 *
 *  char* inp - the input data to be parsed.
 *  char** array_of_words_p[] - pointer to a pointer to an array of char. (Which is also an array of pointers?) Will be updated to hold the words in
 *                              in the char* input as determined by the delimiter.
 *
 * @Returns:
 *
 *  int - the number of words in the input char* as determined by the delimiter.
 */
int string_parser(char *inp, char **array_of_words_p[]) {


  int sizeInput = getSize(inp);     //This is the number of bytes of data in char* input's subject. //NB: I QUESTION THE NECCISITY OF THIS INFORMATION, SHOULD ASK ABOUT.
  int numWords = 0;                 //Number of words in the input char*.

  if(sizeInput == 0){               //If the input is empty return that there's 0 words in string.
    return 0;
  }

  char* scanner = inp;                //Scanner moves through the contents of input.
  char temp[sizeInput];             //This is an intermediary that holds words. It will always be big enough.
  int charNum = 0;                  //This is the number of characters in an individual word. Used for malloc.

  while((scanner-inp)<sizeInput){                     //Move through input char* until all char are read.

    if((*scanner)!= ' '){                             //No delim (' ') so keep building word.
      if(charNum == 0){
        strncpy(temp,scanner,1);                        //If first char need to use strcpy.
      }else{
        strncat(temp,scanner,1);            //Concatenate characters to make the word.
      }

      charNum++;
      printf("\nTemp string is %s", temp);

    }else if(*scanner == '\0'){                       //If scanner reaches end (NULL) return the number of words.
      return numWords++;

    }else{                                            //Delimiter (' ') is encountered, store the word.

      **array_of_words_p= malloc(charNum);  //Allocate memory to the array based on charNum
      strncpy(**array_of_words_p,temp,charNum);             //Store the contents in the array
      charNum = 0;                                    //Reset charNum
      numWords++;
    }

    scanner++;
  }

  return -1;        //Something went very wrong.
}




