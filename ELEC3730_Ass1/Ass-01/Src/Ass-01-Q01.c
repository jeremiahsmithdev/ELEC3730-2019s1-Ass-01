//     $Date: 2019-01-05 04:50:09 +1100 (Sat, 05 Jan 2019) $
// $Revision: 1529 $
//   $Author: Peter $

// Question 1

#include "Ass-01.h"

int read_coefficients(int *coeff_num_p, double **coeff_values_p,
                      char *filename) {
	FILE *file;
	// Open file for reading
	if ((file = fopen(filename, "rb")) == NULL)
	{
		printf("ERROR: Opening file for reading\n");
		return -1;
	}

	// Read number of filter coefficients
	// The number of filter coefficients is passed back in the variable pointed to by coeff_num_p.
	unsigned char bytes[4];
	file = fopen(filename, "rb");
	while ( fread(bytes, 4, 1, file) != 0)
	{
		coeff_num_p += bytes[0] | (bytes[1]<<8 | bytes[2]<<16 | bytes[3]<<24);
	}
	// The function allocates enough memory using malloc() to store the filter coefficients and passes back a pointer to the filter coefficients pointed to by coeff_values_p.
	
	
	if (fread(&coeff_num_p, sizeof(coeff_num_p), 1, file) != 1)
	{
		printf("ERROR: Reading double from file\n");
		fclose(file);
		return -1;
	}



  //
  // WRITE CODE HERE
  //
  printf("CODE TO BE WRITTEN...\n");
  return 0;
}

int main()
{
	// test code here
}

//– Little Endian: Increasing numerical significance with increasing memory address.
/* (Examples are: x86, 8051, NIOS). */
