// Question 4
//Very close to being done just have to ask for help on lines 75 and 76. I think...

#include "Ass-01.h"
#include <stdio.h>

/*
 * NB: true = 1; false = 0;
 */


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
 * Find the number of "words" in an series of characters based on a delimiter.
 *
 * @Params:
 *
 *  char* s - input pointer whose contents are the subject of the function.
 *  char delim - a delimiter that determines what is a word and what isn't.
 *               This parameter can be passed by value as it is not modified
 *               by the function.
 *
 * @Returns:
 *
 *  int - the number of words in the series of characters.
 *
 *
 */
static int getNumWords(char *s, char delim){

  char* t;                                  //This pointer will move through the input input pointer's contents.
  char tPrev;
  int wordCount = 0;
  int flag1,flag2 = 0;                      //Flags for determining if word is present.



for(t = s+1; *t !='\0'; t++){             //Loop begins at second character.

    tPrev = *(t-1);                         //Hold previous character.

    if((*t != delim && tPrev == delim) || (t == (s+1) && tPrev != delim)){     //Check if the beginning of word has been found.
      flag1 = 1;
    }
    if((tPrev != delim && *t == delim) || ((t-s) == (getSize(s)-1) && *t != delim)){//Check if the end of word has been found.
      flag2 = 1;
    }


    if(flag1 && flag2){                     //If both flags set a whole word has been found!
      wordCount++;
      flag1 = 0;                            //Reset the flags.
      flag2 = 0;
    }

  }
  return wordCount;


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


  int sizeInput = getSize(inp);                                   //Total no. of characters in input. //NB: I QUESTION THE NECCISITY OF THIS INFORMATION, SHOULD ASK ABOUT.
  int numWords = getNumWords(inp, ' ');                           //Number of words in the input char*.
  int wordCount = 0;


  if(numWords == 0){                                              //Return 0 if no words 0.
    return 0;
  }

  *array_of_words_p = malloc(numWords*sizeof(char));              //Allocate memory to array pointer. It corresponds to the number of words in input.

  char* scanner = inp;                                            //Scanner moves through the contents of input.
  char temp[sizeInput];                                           //This is an intermediary that holds words. It will always be big enough.
  int charNum = 0;                                                //This is the number of characters in an individual word. Used for malloc.

  while((scanner-inp)<sizeInput){                                 //Move through input char* until all char are read.

    if((*scanner)!= ' '){                                         //No delim (' ') so keep building word.
      if(charNum == 0){
        strncpy(temp,scanner,1);                                     //If first char need to use strcpy.
      }else{
        strncat(temp + charNum,scanner,1);                           //Concatenate characters to make the word.
      }

      charNum++;
      printf("\nTemp string is %s", temp);

    }else if(*scanner == '\0'){                                  //If scanner reaches end (NULL) return the number of words.
      return numWords;

    }else{                                                      //Delimiter (' ') is encountered, store the word.
      array_of_words_p[wordCount] = malloc(charNum*sizeof(char));//Allocate memory for the pointer to char to store words of size "charNum".
      strncpy(array_of_words_p[wordCount],temp,charNum);                   //Store "charNum" characters in the pointer to char.
      charNum = 0;                                              //Reset charNum
      wordCount++;
    }

    scanner++;
  }

  return -1;                                                    //Something went very wrong.
}



/*
 * Malloc Plan
 *
 * 1. Allocate the Pointer to the Array "inputSize" bytes
 * 2. Individually allocate the size of each of the elements of the arrays to charNum
 * 3. ... unsure
 *
 *
 *
 *
 *
 *
 */



