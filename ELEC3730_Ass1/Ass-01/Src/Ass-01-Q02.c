//     $Date: 2019-01-05 04:50:09 +1100 (Sat, 05 Jan 2019) $
// $Revision: 1529 $
//   $Author: Peter $

// Question 2

#include "Ass-01.h"
#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// data to read
// * Audio format code * Number of channels (mono or stereo)
// * Sample rate * Data rate
// * Number of bits per sample * Block alignment information

int read_pcm_wavefile(pcm_wavefile_header_t *header_p, char **data_p,
                      char *filename) {
	FILE *file;

	// A function is required that reads information in the WAV file named filename.
	if ((file = fopen(filename, "rb")) == NULL)
	{
		printf("ERROR: Opening file for reading\n");
		return -1;
	}

	// it could all be done in one step?!
	/* pcm_wavefile_header_t wave = pcm-wavefile_header_t(); */

	// The header section is read and the information loaded into the structure pointed to by header_p
	/* which is of type pcm_wavefile_header_t provided by the calling function. */
	header_p = malloc(44);		// allocate space to store the header data
	if (fread(header_p, sizeof(pcm_wavefile_header_t), 1, file) != 1)
	{
		printf("ERROR: File of unexpected size");
	}
	printf("ChunkID: %c%c%c%c\n", header_p->ChunkID[0], header_p->ChunkID[1], header_p->ChunkID[2], header_p->ChunkID[3]);
	printf("ChunkSize: %u\n", header_p->ChunkSize);
	printf("Format: %c%c%c%c\n", header_p->Format[0], header_p->Format[1], header_p->Format[2], header_p->Format[3]);
	printf("Subchunk1SiE: %u\n", header_p->Subchunk1Size);
	printf("AudioFormat: %u\n", header_p->AudioFormat);
	printf("NumChannels: %u\n", header_p->NumChannels);
	printf("SampleRate: %u\n", header_p->SampleRate);
	printf("ByteRate: %u\n", header_p->ByteRate);
	printf("BlockAlign: %u\n", header_p->BlockAlign);
	printf("BitsPerSample: %u\n", header_p->BitsPerSample);

	// Memory for the data section is allocated by the program and passed back using the pointer data_p.
	data_p = malloc(sizeof(char) * header_p->Subchunk2Size);

	fread(data_p, sizeof(sizeof(char) * header_p->Subchunk2Size), 1, file);

	// call function to write data
	write_pcm_wavefile(header_p, *data_p, "output");


	printf("hello");
	return 1;
	// The function returns 0 if it was successful in reading the file else it returns -1. 
	// The function should also print out the header information.
}

int write_pcm_wavefile(pcm_wavefile_header_t *header_p, char *data,
                       char *filename) {

	FILE *file;

	// Open binary file for writing
	if ((file = fopen(filename, "wt")) == NULL)
	{
		printf("ERROR: Opening file for writing\n");
		return -1;
	}

	// write header to file
	fwrite(&header_p, sizeof(pcm_wavefile_header_t), 1, file);

	printf("subsize:   %d\n", header_p->Subchunk2Size);
	// write data to file
	
	printf("size of data... %lx\n", sizeof(data));
	printf("size of read space: %lx\n", sizeof(sizeof(char) * header_p->Subchunk2Size));
	/* fwrite(data, sizeof(char), header_p->Subchunk2Size, file); */
  //
  // WRITE CODE HERE
  //
  printf("CODE TO BE WRITTEN...\n");
  return 1;
}

int main()
{
	read_pcm_wavefile(0, 0, "11k16bitpcm.wav");
	//test
}
/* uint8_t ChunkID; */
/* fread(&ChunkID, 4, 1, file); */
/* printf("%s", ChunkID); */
/*  */
/* uint32_t ChunkSize; */
/* fread(&ChunkSize, 4, 1, file); */
/* #<{(| printf("%u", &ChunkSize); |)}># */
/*  */
/* uint8_t Format; */
/* fread(&Format, 4, 1, file); */
/* printf("%s", &Format); */
/*  */
/* uint8_t Subchunk1ID; */
/* fread(&Subchunk1ID, 4, 1, file); */
/* printf("%s", &Subchunk1ID); */
/*  */
/* uint32_t Subchunk1Size; */
/* fread(&Subchunk1Size, 4, 1, file); */
/* #<{(| printf("%s", &Subchunk1Size); |)}># */
/*  */
/* uint16_t AudioFormat; */
/* fread(&AudioFormat, 2, 1, file); */
/* #<{(| printf("%s", &AudioFormat); |)}># */
/*  */
/* uint16_t NumChannels; */
/* fread(&NumChannels, 2, 1, file); */
/* #<{(| printf("%s", &NumChannels); |)}># */
/*  */
/* uint32_t SampleRate; */
/* fread(&SampleRate, 4, 1, file); */
/* #<{(| printf("%s", &SampleRate); |)}># */
/*  */
/* uint32_t ByteRate; */
/* fread(&ByteRate, 4, 1, file); */
/* #<{(| printf("%s", &ByteRate); |)}># */
/*  */
/* uint16_t BlockAlign; */
/* fread(&BlockAlign, 2, 1, file); */
/* #<{(| printf("%s", &BlockAlign); |)}># */
/*  */
/* uint16_t BitsPerSample; */
/* fread(&BitsPerSample, 2, 1, file); */
/* #<{(| printf("%s", &BitsPerSample); |)}># */
/*  */
/* uint8_t Subchunk2ID; */
/* fread(&Subchunk2ID, 4, 1, file); */
/* printf("\nID: \n"); */
/* printf("%s", &Subchunk2ID); */
/*  */
/* uint32_t Subchunk2Size; */
/* fread(&Subchunk2Size, 4, 1, file); */
/* #<{(| printf("%s", &Subchunk2Size); |)}># */
/*  */
/* unsigned char* data; */
/* fread(&data, 4, 1, file); */
/* printf("%s", data); */
/*  */

/* header_p[0] = *ChunkID; */
/* header_p = (pcm_wavefile_header_t){.ChunkID}; */


/* memcpy(header_p->ChunkID, ChunkID, sizeof(ChunkID)); */
/* header_p->ChunkSize = ChunkSize; */
/* strcpy(header_p->Format, Format); */
/* strcpy(header_p->Subchunk1ID, Subchunk1ID); */
/* header_p->Subchunk1Size = Subchunk1Size; */
/* header_p->AudioFormat = AudioFormat; */
/* header_p->NumChannels = NumChannels; */
/* header_p->ChunkSize = ChunkSize; */
/* header_p->SampleRate = SampleRate; */
/* header_p->ByteRate = ByteRate; */
/* header_p->BlockAlign = BlockAlign; */
/* header_p->BitsPerSample = BitsPerSample; */
/* strcpy(header_p->Subchunk2ID, Subchunk2ID); */
/* header_p->Subchunk2Size = Subchunk2Size; */

