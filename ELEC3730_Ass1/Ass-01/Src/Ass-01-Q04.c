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
 * Given a delimiter terminated word determines the number of characters in the word.
 *
 * @Params
 *  char* word - target of the character count.
 *  char delim - the character indicating the end of the word.
 *
 * @Returns
 *  int - the number of characters in the word.
 */
static int getWordCharCount(char* word, char delim){
  int numChar = 0;
  int i = 0;

  while(*(word+i) != delim){
    numChar++;
    i++;
  }


  return numChar;
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

  int sizeOfInput = getSize(inp);
  int wordsInInput = getNumWords(inp, ' ');

  if(wordsInInput == 0 || sizeOfInput == 0) return 0;

  *array_of_words_p = (char**)malloc(sizeof(char*)*wordsInInput);
  wordsInInput = 0;
  char* carrier;
  int numChar = 0;

  for(int i = 0; i < sizeOfInput; i++){
    carrier = inp + i;
    if(*(carrier) != ' '){
       numChar = getWordCharCount((carrier), ' ');
       (*array_of_words_p)[wordsInInput] = (char*)malloc(sizeof(char)*(numChar+1));
       i+= numChar;
       wordsInInput++;
       numChar = 0;
    }
  }

    wordsInInput = 0;
    numChar = 0;


  for(int i = 0; i < sizeOfInput; i++){
    carrier = inp + i;
    if(*(carrier) != ' '){
       (*array_of_words_p)[wordsInInput][numChar] = *(carrier);
       numChar++;
    }
    if(*(carrier) == ' ' && i!=0){
      numChar = 0;
      if(*(carrier - 1) != ' '){
        wordsInInput++;
      }
    }
  }


  return getNumWords(inp,' ');

}




