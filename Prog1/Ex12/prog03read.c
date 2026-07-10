#include <stdio.h>
#include <stdlib.h>
#include "prog03header.h"

int read_planets(Planet *planets){
  int i;
  FILE *fp;
  
  fp = fopen("planet.txt","r");
  if(fp == NULL){
    //printf("Error in files\n");
    return -1;
  }

  for(i=0;i<NPLANETS;i++){
    if(fscanf(fp,"%s",planets[i].name)==EOF)break;
    fscanf(fp,"%lf",&planets[i].radius);
    fscanf(fp,"%lf",&planets[i].density);
    fscanf(fp,"%lf",&planets[i].semi_major_axis);
  }

  fclose(fp);
  return 0;
}