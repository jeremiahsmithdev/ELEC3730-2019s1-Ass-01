//     $Date: 2019-01-05 03:04:20 +1100 (Sat, 05 Jan 2019) $
// $Revision: 1524 $
//   $Author: Peter $

// Assignment include file

#ifndef ASS_01_H_
#define ASS_01_H_

// Standard includes
#ifdef STM32F407xx
#include "stm32f4xx_hal.h"
#else
#include <io.h>
#include <windows.h>
#endif
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// Data types
typedef struct {
  uint8_t ChunkID[4]; // 'RIFF'
  uint32_t ChunkSize;
  uint8_t Format[4];

  uint8_t Subchunk1ID[4]; // 'fmt '
  uint32_t Subchunk1Size; // Assume a size of 16 for PCM encoded data
  uint16_t AudioFormat;   // 1=PCM encoded data
  uint16_t NumChannels;
  uint32_t SampleRate;
  uint32_t ByteRate;
  uint16_t BlockAlign;
  uint16_t BitsPerSample;

  uint8_t Subchunk2ID[4]; // 'data'
  uint32_t Subchunk2Size;
} pcm_wavefile_header_t;

// Assignment main
extern int Ass_01_Main(void);

// Question 1
extern int read_coefficients(int *coeff_num_p, double **coeff_values_p,
                             char *filename);

// Question 2
extern int read_pcm_wavefile(pcm_wavefile_header_t *header_p, char **data_p,
                             char *filename);
extern int write_pcm_wavefile(pcm_wavefile_header_t *header_p, char *data_p,
                              char *filename);

// Question 3
extern int filter(char *filter_filename, char *input_wavefilename,
                  char *output_wavefilename);

// Question 4
extern int string_parser(char *inp, char **array_of_words_p[]);

// Question 5
extern void serial_string_parser(void);

#endif /* ASS_01_H_ */
