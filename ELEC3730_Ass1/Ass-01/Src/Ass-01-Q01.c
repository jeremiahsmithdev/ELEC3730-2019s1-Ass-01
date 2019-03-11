//     $Date: 2019-01-05 04:50:09 +1100 (Sat, 05 Jan 2019) $
// $Revision: 1529 $
//   $Author: Peter $

// Question 1

#include "Ass-01.h"
#include <stdlib.h>

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
	int coeffNum;
	fread(&coeffNum,4,1,file);
	printf("%d\n",coeffNum);

	// The number of filter coefficients is passed back in the variable pointed to by coeff_num_p.
	coeff_num_p = &coeffNum;

	// The function allocates enough memory using malloc() to store the filter coefficients
	double *coeff = (double *)malloc(1 * coeffNum * sizeof(double));
	fread(coeff, 8, coeffNum, file);

	// passes back a pointer to the filter coefficients pointed to by coeff_values_p.
	coeff_values_p = &coeff;
	/* *coeff_values_p = coeff; */

	// print values (test)
	for (int i = 0; i < coeffNum; i++) { printf("%f\n", coeff[i]); }

	/* for (int i = 0; i < coeffNum; i++) { printf("%f\n", &coeff_values_p[i]); } */

	  return 0;
}

int main()
{
	read_coefficients(0, 0, "filterBP.bin");
	// test code here
}
// count file size...

// reverse into little endian format?
/* coeffNum = (coeffNum >> 24) | (coeffNum >> 8 & 0x0000FF00) | (coeffNum << 8 & 0x00FF0000) | (coeffNum << 24); */


/* printf("%f\n", *coeff_values_p[0]); */
/* printf("last... %f\n", *coeff_values_p[2]); */

//– Little Endian: Increasing numerical significance with increasing memory address.
/* (Examples are: x86, 8051, NIOS). */

/* while ( fread( coeff_num_p, 4, 1, file) != 0) */
/* { */
/* coeff_values_p += 1; */
/* } */
/*  */
/* if (fread(&coeff_num_p, sizeof(coeff_num_p), 1, file) != 1) */
/* { */
/* 	printf("ERROR: Reading double from file\n"); */
/* 	fclose(file); */
/* 	return -1; */
/* } */
