#include <stdio.h>
#include "Ass-01.h"
#include <inttypes.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <err.h>


// TODO
// data_p variable should be assigned with "sample" values

char *samples = NULL;
char* data;

/*
 * COMMENT THIS
 */
int read_pcm_wavefile(pcm_wavefile_header_t *header_p, char **data_p, char *filename)
{
	FILE *file;

	file = fopen(filename, "rb");
	fread(header_p, sizeof(pcm_wavefile_header_t), 1, file);
	samples = (char*)malloc(header_p->Subchunk2Size);
	fread(samples, sizeof(char), header_p->Subchunk2Size, file);
	*data_p = samples;

	printf("\nChunkID   = %c%c%c%c\n", header_p->ChunkID[0], header_p->ChunkID[1], header_p->ChunkID[2], header_p->ChunkID[3]);
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
  fclose(file);

  return 0;
}


/*
 * COMMENT THIS
 */
int write_pcm_wavefile(pcm_wavefile_header_t *header_p, char *data, char *filename)
{
	FILE *file;
	file = fopen(filename, "wb");


	printf("\nChunkID		= %c%c%c%c\n", header_p->ChunkID[0], header_p->ChunkID[1], header_p->ChunkID[2], header_p->ChunkID[3]);
	printf("ChunkSize	= %u\n", header_p->ChunkSize);
	printf("Format		= %c%c%c%c\n", header_p->Format[0], header_p->Format[1], header_p->Format[2], header_p->Format[3]);
	printf("Subchunk1SiE	= %u\n", header_p->Subchunk1Size);
	printf("AudioForma	= %u\n", header_p->AudioFormat);
	printf("NumChannels	= %u\n", header_p->NumChannels);
	printf("SampleRate	= %u\n", header_p->SampleRate);
	printf("ByteRate	= %u\n", header_p->ByteRate);
	printf("BlockAlign	= %u\n", header_p->BlockAlign);
	printf("BitsPerSample	= %u\n", header_p->BitsPerSample);
	printf("Subchunk2ID	= %c%c%c%c\n", header_p->Subchunk2ID[0], header_p->Subchunk2ID[1], header_p->Subchunk2ID[2], header_p->Subchunk2ID[3]);
	printf("Subchunk2Size	= %u\n", header_p->Subchunk2Size);

	fwrite(header_p, sizeof(pcm_wavefile_header_t), 1, file);
	fwrite(samples, sizeof(char), header_p->Subchunk2Size, file);
	close(file);
	return 0;
}
