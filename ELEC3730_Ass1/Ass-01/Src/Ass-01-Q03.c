/*
 * Need to apply to filter to the data (*data).
 * That should be it.
 *
 */

#include "Ass-01.h"
#include <stdio.h>
#include <stdlib.h>


int16_t *data = NULL;

int coeff_num;
double **coeff_values; // Array of coefficient values

int filter(char *filter_filename, char *input_wavefilename,
           char *output_wavefilename) {


  //READ IN FILE SECTION
  pcm_wavefile_header_t* header_p = NULL;
  char** data_p = NULL;
  header_p= (pcm_wavefile_header_t*)malloc(sizeof(pcm_wavefile_header_t));
  read_pcm_wavefile(header_p, data_p,input_wavefilename);
  printf("\n ChunkID: %c%c%c%c \n", header_p->ChunkID[0],header_p->ChunkID[1],header_p->ChunkID[2],header_p->ChunkID[3]);



  //READ IN THE FILTER
  read_coefficients(&coeff_num, coeff_values, filter_filename);
  printf("\n Coeff Num: %d", coeff_num);


  //FILTER THE FILE



  //WRITE FILE
  /*
  write_pcm_wavefile(pcm_wavefile_header_t *header_p, char *data_p,
                                char *filename);
*/




  return 0;
}
// TODO
// data_p variable should be assigned with "sample" values

//char *samples = NULL;

/*
  FILE *ffile;
  FILE *wifile;
  FILE *wofile;

  header = (pcm_wavefile_header_t*)malloc(sizeof(pcm_wavefile_header_t));
  data = (int16_t*)malloc(header->Subchunk2Size);//seg fault
  printf("Opening filter file %s...\n\n", filter_filename);
  ffile = fopen(filter_filename, "rb");

//  / *************** READ FILTER FUNCTION **************
  int coeffNum;
  fread(&coeffNum,4,1,ffile);
  coeff_num = coeffNum;
  double *coeff = (double *)malloc(coeff_num * sizeof(double));
  fread(coeff, 8, coeffNum, ffile);
  coeff_values = coeff;
//  /* *************** END READ FILTER FUNCTION **************

  printf("Opening input wavefile %s...\n", input_wavefilename);
  wifile = fopen(input_wavefilename, "rb");
  fread(header, sizeof(pcm_wavefile_header_t), 1, wifile);

  printf("ChunkID   = %c%c%c%c\n", header->ChunkID[0], header->ChunkID[1], header->ChunkID[2], header->ChunkID[3]);
  printf("ChunkSize = %u\n", header->ChunkSize);
  printf("Format    = %c%c%c%c\n", header->Format[0], header->Format[1], header->Format[2], header->Format[3]);
  printf("Subchunk1ID = %u\n", header->Subchunk1Size);
  printf("AudioForma  = %u\n", header->AudioFormat);
  printf("NumChannels = %u\n", header->NumChannels);
  printf("SampleRate  = %u\n", header->SampleRate);
  printf("ByteRate  = %u\n", header->ByteRate);
  printf("BlockAlign  = %u\n", header->BlockAlign);
  printf("BitsPerSample = %u\n", header->BitsPerSample);
  printf("Subchunk2ID = %c%c%c%c\n", header->Subchunk2ID[0], header->Subchunk2ID[1], header->Subchunk2ID[2], header->Subchunk2ID[3]);
  printf("Subchunk2Size = %u\n\n", header->Subchunk2Size);

  fread(data, sizeof(char), header->Subchunk2Size, wifile);

  printf("Filter the input...\n\n");

  //data16 = (short*)data;
  //filtered_data = (short*)malloc((size_t)sizeof(short) * header->Subchunk2Size);//seg fault
  int k,n;

  printf("%d\n", coeff_num);

  // main code
  //printf("%f\n", coeff_values[0]);
  short* u = data;
  short* b = (short*)malloc((size_t)sizeof(short) * header->Subchunk2Size);
  for (k = 0; k < header->Subchunk2Size/2; k++)
  {
    // filter sample
    b[k] = 0; // clear sample
    for (n = 0; n < coeff_num; n++)
    {
      if (k-n >= 0) // apply filter
        b[k] += u[k-n] * coeff_values[n];
    }
  }
  data = b;

  printf("Write output wavefile %s...\n", output_wavefilename);
  wofile = fopen(output_wavefilename, "wb");
  fwrite(header, sizeof(pcm_wavefile_header_t), 1, wofile);
  fwrite(data, sizeof(char), header->Subchunk2Size, wofile);
  printf("Done.");
  */

