//     $Date: 2019-01-05 04:04:59 +1100 (Sat, 05 Jan 2019) $
// $Revision: 1526 $
//   $Author: Peter $

// Assignment 1 test for all questions

#include "Ass-01.h"

int Ass_01_Main(void) {

#ifndef STM32F407xx

  // Filter coefficient filenames
  char *filename_filter[] = {"filterBP.bin",     "filterHP.bin",
                             "filterLP.bin",     "filterSB.bin",
                             "filter-Bad-0.bin", "filter-Bad-1.bin",
                             "filter-Bad-2.bin", NULL};
  char *filename_audio[] = {
      "8k16bitpcm.wav",       "11k8bitpcm.wav",       "11k16bitpcm.wav",
      "8kmp38.wav",           "8k16bitpcm-Bad-0.wav", "8k16bitpcm-Bad-1.wav",
      "8k16bitpcm-Bad-2.wav", "8k16bitpcm-Bad-3.wav", NULL};
  char *parse_string[] = {"         one two three  ", " hello there", " butt ", NULL};

  // Loop variables
  int i, j;

#endif

  // Welcome
  printf("\nELEC3730-2019t1 Assignment 1 (Ver: 01 $Rev: 1526 $)\n");

#ifndef STM32F407xx

  // Change working directory to be the one with all the input files.
  // Output files will also be placed there.
  if (chdir("Ass-01-Files")) {
    printf("ERROR: Unable to change directory\n");
    printf("ERROR: Check that directory 'Ass-01-Files' exists\n");
  }
/*
  // Question 1
  {
    int coeff_num;
    double *coeff_values; // Array of coefficient values
    printf("\n-> Question 1...\n");
    i = 0;
    while (filename_filter[i] != NULL) {
      printf("--> %19s: ", filename_filter[i]);
      if (read_coefficients(&coeff_num, &coeff_values, filename_filter[i]) ==
          0) {
        printf("coeff_num = %d", coeff_num);
        if (coeff_num > 0)
          printf(", coeff_values[0] = %f", coeff_values[0]);
        printf("\n");
      }
      i++;
    }

    //free(coeff_values);
    //free(&coeff_num);
  }

  // Question 2

  {
    pcm_wavefile_header_t header;
    char filename_output[100];
    char *data;
    printf("\n-> Question 2...\n");
    i = 0;
   // while (filename_audio[i] != NULL) {
      printf("--> %20s: ", filename_audio[i]);
      if (read_pcm_wavefile(&header, &data, filename_audio[i]) == 0) {
        if (strcmp(filename_audio[i], "8k16bitpcm.wav") == 0) {
          snprintf(filename_output, 100, "%s-%s", filename_audio[i],
                   filename_audio[i]);
          printf("--> Write %s", filename_output);
          write_pcm_wavefile(&header, data, filename_output);
        }
        free(data);
   //   }
      i++;
   }
  }
*/
  // Question 3
  {
    char filename_output[100];
    printf("\n-> Question 3...\n");
    //for (i = 0; i < 4; i++) {
      printf("--> %17s: ", filename_filter[i]);
      snprintf(filename_output, 100, "%s-%s", filename_filter[i],
               filename_audio[0]);
      if (filter(filename_filter[i], filename_audio[0], filename_output) == 0) {
        printf("--> Written %s.\n", filename_output);
      }
//    }
  }

/*
  // Question 4
  {
    char **array_of_words;
    int count;
    printf("\n-> Question 4...\n");
    i = 0;
    while (parse_string[i] != NULL) {
      printf("--> '%17s': ", parse_string[i]);
      count = string_parser(parse_string[i], &array_of_words);
      if (count != 0) {
        printf("count = %d\n", count);
        for (j = 0; j < count; j++) {
          printf("---> %d: '%s'\n", j + 1, (array_of_words)[j]);
        }
        free(array_of_words[0]);
        free(array_of_words);
      }
      i++;
    }
  }
*/
#endif

#ifdef STM32F407xx
  // Question 5
  {
    printf("\n-> Question 5...\n");
    while (1)
      serial_string_parser();
  }
#endif

  printf("Done.\n");

  // Always return pass for now
  return 0;
}
