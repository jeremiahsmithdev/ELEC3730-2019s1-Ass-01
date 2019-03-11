//     $Date: 2019-01-05 04:50:09 +1100 (Sat, 05 Jan 2019) $
// $Revision: 1529 $
//   $Author: Peter $

// Question 2

#include "Ass-01.h"

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
	
	// The header section is read and the information loaded into the structure pointed to by header_p
	unsigned char* ChunkID;
	fread(&ChunkID, 4, 1, file);
	printf("%s", &ChunkID);

	unsigned char* ChunkSize;
	fread(&ChunkSize, 4, 1, file);
	printf("%s", &ChunkSize);

	unsigned char* Format;
	fread(&Format, 4, 1, file);
	printf("%s", &Format);

	unsigned char* Subchunk1ID;
	fread(&Subchunk1ID, 4, 1, file);
	printf("%s", &Subchunk1ID);

	unsigned char* Subchunk1Size;
	fread(&Subchunk1Size, 4, 1, file);
	printf("%s", &Subchunk1Size);

	unsigned char* AudioFormat;
	fread(&AudioFormat, 2, 1, file);
	printf("%s", &AudioFormat);

	unsigned char* NumChannels;
	fread(&NumChannels, 2, 1, file);
	printf("%s", &NumChannels);

	unsigned char* SampleRate;
	fread(&SampleRate, 4, 1, file);
	printf("%s", &SampleRate);

	unsigned char* ByteRate;
	fread(&ByteRate, 4, 1, file);
	printf("%s", &ByteRate);

	unsigned char* BlockAlign;
	fread(&BlockAlign, 2, 1, file);
	printf("%s", &BlockAlign);

	unsigned char* BitsPerSample;
	fread(&BitsPerSample, 2, 1, file);
	printf("%s", &BitsPerSample);

	unsigned char* Subchunk2ID;
	fread(&Subchunk2ID, 4, 1, file);
	printf("\nID: \n");
	printf("%s", &Subchunk2ID);

	unsigned char* Subchunk2Size;
	fread(&Subchunk2Size, 4, 1, file);
	printf("%s", &Subchunk2Size);
	
	unsigned char* data;
	fread(&data, 4, 1, file);
	printf("%s", &data);
	// which is of type pcm_wavefile_header_t provided by the calling function.
	
	// Memory for the data section is allocated by the program and passed back using the pointer data_p.
	
	// The function returns 0 if it was successful in reading the file else it returns -1. 
	
	// The function should also print out the header information.
	
  // WRITE CODE HERE
  //
  /* printf("CODE TO BE WRITTEN...\n"); */
  return 1;
}

int write_pcm_wavefile(pcm_wavefile_header_t *header_p, char *data,
                       char *filename) {
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
