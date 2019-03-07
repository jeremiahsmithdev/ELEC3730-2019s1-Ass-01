//     $Date: 2019-01-05 03:04:20 +1100 (Sat, 05 Jan 2019) $
// $Revision: 1524 $
//   $Author: Peter $

#include "Ass-01.h"

// Maximum characters in the input string
#define MAX_STR_LEN 100
// Carriage return character
#define CR 13

void serial_string_parser(void) {
  char c;
  int i, j;
  char command_line[MAX_STR_LEN + 1];
  char **array_of_words;
  int count;

  // Get one line of input
  printf("--> Enter text:\n");
  i = 0;
  c = getchar();
  while (c != CR && i < MAX_STR_LEN) {
    printf("%c", c);
    if (c < ' ')
      printf("[0x%02x]", c);
    command_line[i] = c;
    i++;
    c = getchar();
  }
  command_line[i] = 0;

  // Parse the input and print result
  count = string_parser(command_line, &array_of_words);
  printf("\n--> count = %d\n", count);
  for (j = 0; j < count; j++) {
    printf("---> %2d: '%s'\n", j + 1, (array_of_words)[j]);
  }
  if (count != 0) {
    free(array_of_words[0]);
    free(array_of_words);
  }
}
