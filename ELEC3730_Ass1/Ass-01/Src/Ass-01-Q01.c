#include "Ass-01.h"
#include <stdlib.h>


/*
 * Reads the filter coefficients from a binary file and store them in cooef_values_p.
 *
 * @Params
 *
 *    int *coeff_num_p -        Points to an int that is the number of coefficients stored in the file. This value is
 *                              is stored in the first 4 bytes of the file.
 *
 *    double **coeff_values_p - Points to pointer that points to the coefficient values that are stored in the bin file.
 *
 *    char *filename -          Points to the file name of the binary file containing filter data.
 *
 *
 * @Returns
 *
 *   -1: If an error occured and the file could not be read correctly.
 *    0: The file was successfully read.
 *
 */
int read_coefficients(int *coeff_num_p, double **coeff_values_p,
                      char *filename) {
	FILE *file;


	if ((file = fopen(filename, "rb")) == NULL)                         // Open file for reading.
	{
		printf("ERROR: File does not exist\n");
		return -1;                                                        //If file could not be read return -1.
	}


	fseek(file, 0, SEEK_END);                                          //Seek to end of file.
	long int fileLength = ftell(file);                                //This is cursor position at the end of file.
	fseek(file,0,SEEK_SET);                                           //Put the cursor back to the beginning of the file.


	fread(coeff_num_p,4,1,file);                                       // Read number of filter coefficient (n). Stored in 1st 4 bytes of data.

	if(fileLength != (*coeff_num_p*sizeof(double) + 4)){                //If file's length (size) does not match the number of numbers specified then it is not formatted correctly.
    printf("ERROR: The file is empty\n");
    return -1;
  }

	*coeff_values_p = (double*)malloc(*coeff_num_p * sizeof(double));   // Allocate (number coefficients x sizeof(double)) of memory to store the coefficient values.
	fread(*coeff_values_p, 8, *coeff_num_p, file);


	fclose(file);                                                       //Close the file and prevent corruption.
	return 0;
}

