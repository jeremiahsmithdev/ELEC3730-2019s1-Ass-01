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

int16_t *samples = NULL;
char* data;
pcm_wavefile_header_t *header;
int read_pcm_wavefile(pcm_wavefile_header_t *header_p, char **data_p, char *filename)
{
  return 1;
}
