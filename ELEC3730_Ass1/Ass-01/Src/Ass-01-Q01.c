/* QUESTION ONE */


#include "Ass-01.h"
#include <stdlib.h>
#include <stdio.h>

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

	return *coeff_num_p;
}
