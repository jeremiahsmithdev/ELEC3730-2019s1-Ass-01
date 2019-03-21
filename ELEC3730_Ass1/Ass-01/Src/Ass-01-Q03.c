/*
 * Need to apply to filter to the data (*data).
 * That should be it.
 *
 */

#include "Ass-01.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Given a WAV file and a file containing filter data, applies the filter to the original WAV file data and
 * outputs the new filtered WAV file.
 *
 * @Params
 *
 *  char *filter_filename - the filter file.
 *  char *input_wavefilename - the original WAV file.
 *  char *output_wavefilename - the filtered output WAV file.
 *
 * @Returns
 *
 *  int -
 *    -1: If the filtering was unsuccessful.
 *     0: If the filtering was a success.
 */
int filter(char *filter_filename, char *input_wavefilename,
           char *output_wavefilename) {


  char* data_p = NULL;              //Original WAV data.
  pcm_wavefile_header_t header_p;   //Original WAV file header struct pointer.
  int coeff_num;                    //Number of coefficients in filter.
  double *coeff_values;             //Value of coefficients in filter.
  short* shortUnfiltered = NULL;    //Short formatted original WAV data.
  short* shortFiltered = NULL;      //Filtered WAV data formatted as short.


  //READ ORIGINAL WAV
  if(read_pcm_wavefile(&header_p, &data_p,input_wavefilename)!=0){
    printf("ERROR: Wavefile could not be read. \n");
    return -1;
  }

  //READ FILTER
  if(read_coefficients(&coeff_num, &coeff_values, filter_filename)!=0){
    printf("ERROR: Filter file could not be read. \n");
  }

  //FILTER THE FILE
  shortUnfiltered = (short*)data_p;
  shortFiltered = (short*)malloc((size_t)sizeof(short) * header_p.Subchunk2Size);
  for (int k = 0; k < header_p.Subchunk2Size/2; k++)
  {
    shortFiltered[k] = 0;                                                       // clear sample
    for (int n = 0; n < coeff_num; n++)
    {
      if (k-n >= 0){                                                            // apply filter
        shortFiltered[k] += (shortUnfiltered[k-n] * coeff_values[n]);
      }
      else{
        shortFiltered[k] += 0;
      }
    }
  }
  char* filteredData = (char*)shortFiltered;

  //WRITE FILE
  if(write_pcm_wavefile(&header_p, filteredData, output_wavefilename)!=0){
    printf("ERROR: Filtered content could not be written to file. \n");
    return -1;
  }

  //FREE DATA
  free(coeff_values);
  free(filteredData);
  free(data_p);


  return 0;
}

