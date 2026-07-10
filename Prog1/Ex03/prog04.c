#include <stdio.h>
#include <stdlib.h>

#define MAX_W 256
#define MAX_H 256
#define BUF 256

int w, h, i_img[MAX_W * MAX_H], o_img[MAX_W * MAX_H];

int read();
void write();
void superpose();
 
int main(){
	superpose();
	write();
	return 0;
}

int read(){
	FILE *fp;
	char filename[BUF];
	int r;
    int i;
	
	printf("ファイル名を入力してください: ");
	
	if((r = scanf("%s", filename)) == EOF)
		return EOF;
		
	if((fp = fopen(filename, "r")) == NULL){
		fprintf(stderr, "ファイル %s を開けません！\n", filename);
		exit(1);
	}
    if (fgetc(fp) != 'P' || fgetc(fp) != '1'){
    fprintf(stderr,"data style was incorrect\n");
    exit(4);
    }
    fscanf(fp,"%d",&w);
    fscanf(fp,"%d",&h);

    for(i=0;i<w*h;i++){
    fscanf(fp,"%d",&i_img[i]);
    }
    fclose(fp);
}

void write(){
    int i,j;
    FILE *fpout;
	if((fpout = fopen("out.pbm", "w")) == NULL){
		fprintf(stderr, "ファイル out.pbm を開けません！\n");
		exit(3);
	}
    fprintf(fpout,"P1\n");
    fprintf(fpout,"%d %d\n",w,h);
    for(i=0;i<w*h;i++){
    fprintf(fpout,"%d",o_img[i]);
    }
    fclose(fpout);
}

void superpose(){
	int pw,ph,test=0,test2=0;
    int i;

    while(1){
      if(read() == EOF){
        printf("\n");
        break;
      }
      if(test==0){
      pw=w;
      ph=h;
      test=1;
      }      
      printf("width = %d, height = %d\n", w,h);
      if(w!=pw || h!=ph){
      printf("Each size of files are not identical\n");
      exit(2);
      }
      if(test2==0){
      for (i=0;i<w*h;i++){
        o_img[i]=i_img[i];
      }
      test2=1;
      }else{
      for (i=0;i<w*h;i++){
        if(o_img[i]==0 && i_img[i]==0)o_img[i]=0;
        else o_img[i]=1;
      }
      }
    }
}