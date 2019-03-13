//     $Date: 2019-01-05 04:50:09 +1100 (Sat, 05 Jan 2019) $
// $Revision: 1529 $
//   $Author: Peter $

// Question 3

#include "Ass-01.h"
#include <stdio.h>
#include <stdlib.h>

// TODO just call functions from Q2

pcm_wavefile_header_t *header;
int16_t *data = NULL;

int filter(char *filter_filename, char *input_wavefilename,
           char *output_wavefilename) {
	int coefficients = 0;
	FILE *ffile;
	FILE *wifile;
	FILE *wofile;

	header = (pcm_wavefile_header_t*)malloc(sizeof(pcm_wavefile_header_t));

	data = (int16_t*)malloc(header->Subchunk2Size);//seg fault

	printf("Opening filter file %s...\n", filter_filename);
	ffile = fopen(filter_filename, "rb");
	// TODO read filter
	printf("Number of coefficients	= %x\n\n", coefficients);

	printf("Opening input wavefile %s...", input_wavefilename);
	wifile = fopen(input_wavefilename, "rb");
	fread(header, sizeof(pcm_wavefile_header_t), 1, wifile);

	printf("ChunkID		= %c%c%c%c\n", header->ChunkID[0], header->ChunkID[1], header->ChunkID[2], header->ChunkID[3]);
	printf("ChunkSize	= %u\n", header->ChunkSize);
	printf("Format		= %c%c%c%c\n", header->Format[0], header->Format[1], header->Format[2], header->Format[3]);
	printf("Subchunk1SiE	= %u\n", header->Subchunk1Size);
	printf("AudioForma	= %u\n", header->AudioFormat);
	printf("NumChannels	= %u\n", header->NumChannels);
	printf("SampleRate	= %u\n", header->SampleRate);
	printf("ByteRate	= %u\n", header->ByteRate);
	printf("BlockAlign	= %u\n", header->BlockAlign);
	printf("BitsPerSample	= %u\n", header->BitsPerSample);
	printf("Subchunk2ID	= %c%c%c%c\n", header->Subchunk2ID[0], header->Subchunk2ID[1], header->Subchunk2ID[2], header->Subchunk2ID[3]);
	printf("Subchunk2Size	= %u\n\n", header->Subchunk2Size);

	fread(data, sizeof(char), header->Subchunk2Size, wifile);

	printf("Filter the input...\n\n");
	// TODO MAIN CODE WILL BE HERE
	
	printf("Write output wavefile %s...\n", output_wavefilename);
	wofile = fopen(output_wavefilename, "wb");
	fwrite(header, sizeof(pcm_wavefile_header_t), 1, wofile);
	fwrite(data, sizeof(char), header->Subchunk2Size, wofile);
	printf("Done.");
  return 1;
}

int main()
{
	filter("FilterBP.bin", "8k16bitpcm.wav", "filteredWave.wav");
	// test here
}
