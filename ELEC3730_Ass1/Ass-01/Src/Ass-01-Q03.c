/*
 * Need to apply to filter to the data (*data).
 * That should be it.
 *
 */

#include "Ass-01.h"
#include <stdio.h>
#include <stdlib.h>



int filter(char *filter_filename, char *input_wavefilename,
           char *output_wavefilename) {


  //READ IN FILE SECTION
  pcm_wavefile_header_t header_p;
  char* data_p = NULL;
  printf("\n\nREADING FILE\n");
  read_pcm_wavefile(&header_p, &data_p,input_wavefilename);


  //READ IN THE FILTER
  int coeff_num;
  double *coeff_values;
  printf("\n\nREADING COEFFICIENTS\n");
  read_coefficients(&coeff_num, &coeff_values, filter_filename);               //This will allocate memory for coeff_values.
  printf("\n Coeff Num: %d", coeff_num);
  printf("\nFirst Coefficient %f\n\n", coeff_values[0]);


  //FILTER THE FILE
  printf("\n\n FILTERING THE FILE\n");
  short* shortUnfiltered = (short*)data_p;
  short* shortFiltered = (short*)malloc((size_t)sizeof(short) * header_p.Subchunk2Size);

  for (int k = 0; k < header_p.Subchunk2Size/2; k++)
  {
    shortFiltered[k] = 0;                                                   // clear sample
    for (int n = 0; n < coeff_num; n++)
    {
      if (k-n >= 0){                                                        // apply filter
        shortFiltered[k] += (shortUnfiltered[k-n] * coeff_values[n]);
      }
      else{
        shortFiltered[k] += 0;
      }
    }
  }
  char* filteredData = (char*)shortFiltered;


  //WRITE FILE
  write_pcm_wavefile(&header_p, filteredData, output_wavefilename);


  free(coeff_values);
  free(filteredData);
  free(data_p);


  return 0;
}

