#include <stdio.h>
#include "Ass-01.h"
#include <inttypes.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <err.h>


int16_t *samples = NULL;                            //Gotta comment these
char* data;
pcm_wavefile_header_t *header;



/*
 *  Comment this
 *
 */
int read_pcm_wavefile(pcm_wavefile_header_t *header_p, char **data_p, char *filename)
{

  FILE *file;

  if (file = fopen(filename, "rb") == NULL){                                        //Check if file exists
    printf("ERROR: File does not exist\n");
    return -1;
  }

  if (fread(header_p, sizeof(pcm_wavefile_header_t), 1 ,filename) != 1)){           //If the number of elements read in does not match 1 then something went wrong.
      fprint("ERROR: The file header was not read correctly");
      return -1;
  }


  if (strncmp(header_p->ChunkID, "RIFF", 4)){                                         //If strncmp returns 1, no match.
    printf("ERROR: The ChunkID is not RIFF");
    return -1;
  }
  if(strncmp(header_p->Format, "WAVE", 4)){                                           //If strncmp returns 1, no match.
    printf("ERROR: The file format is not WAVE");
    return -1;
  }

  if (header_p->AudioFormat != 1){                                                    //AudioFormat should be 1.
    printf("ERROR: Only PCM encoding supported");
    return -1;
  }


  samples = (int16_t*)malloc(header->Subchunk2Size);//seg fault
  if (!samples)
    errx(1, "Error allocating memory");
  fread(samples, sizeof(char), header->Subchunk2Size, file);
  /* if (read(fd, samples, header->Subchunk2Size) < header->Subchunk2Size) */
  /* errx(1, "File broken: samples"); */
  fclose(fd);
}










/*
 * Comment this...
 */
int write_pcm_wavefile(pcm_wavefile_header_t *header_p, char *data, char *filename)
{
  printf("hello\n");
  int fd;
  FILE *file;
  file = fopen(filename, "wb");

  if (!filename)
    errx(1, "Filename not specified");
  if (!samples)
    errx(1, "Samples buffer not specified");
  if ((fd = creat(filename, 0666)) < 1)
    errx(1, "Error creating file");
  fwrite(header, sizeof(pcm_wavefile_header_t), 1, file);
  /* if (write(file, header, sizeof(pcm_wavefile_header_t)) < sizeof(pcm_wavefile_header_t)) */
  /* errx(1, "Error writing header"); */
  fwrite(samples, sizeof(char), header->Subchunk2Size, file);
  /* if (write(fd, samples, header->Subchunk2Size) < header->Subchunk2Size) */
  /*     errx(1, "Error writing samples"); */
  printf("ChunkID   = %c%c%c%c\n", header_p->ChunkID[0], header_p->ChunkID[1], header_p->ChunkID[2], header_p->ChunkID[3]);
  printf("ChunkSize = %u\n", header_p->ChunkSize);
  printf("Format    = %c%c%c%c\n", header_p->Format[0], header_p->Format[1], header_p->Format[2], header_p->Format[3]);
  printf("Subchunk1SiE  = %u\n", header_p->Subchunk1Size);
  printf("AudioForma  = %u\n", header_p->AudioFormat);
  printf("NumChannels = %u\n", header_p->NumChannels);
  printf("SampleRate  = %u\n", header_p->SampleRate);
  printf("ByteRate  = %u\n", header_p->ByteRate);
  printf("BlockAlign  = %u\n", header_p->BlockAlign);
  printf("BitsPerSample = %u\n", header_p->BitsPerSample);
  printf("Subchunk2ID = %c%c%c%c\n", header_p->Subchunk2ID[0], header_p->Subchunk2ID[1], header_p->Subchunk2ID[2], header_p->Subchunk2ID[3]);
  printf("Subchunk2Size = %u\n", header_p->Subchunk2Size);
  close(fd);
}
