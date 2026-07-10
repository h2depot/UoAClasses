#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LCS(char*,char*);


char X[1000],Y[1000];

int main(){
  int n;
  int i;

    scanf("%s",X);
    scanf("%s",Y);
    printf("%d\n",LCS(X,Y));

  //printf("%s\n%s\n",X,Y);

  return 0;
}

int LCS(char*X,char*Y){
  int m=strlen(X),n=strlen(Y);
  int i,j;
  int **lcs=(int**)malloc((m+1)*sizeof(int*));
  for(i=0;i<=m;i++)lcs[i]=(int*)malloc((n+1)*sizeof(int));
 
  for(i=1;i<=m;i++)lcs[i][0]=0;
  for(i=0;i<=n;i++)lcs[0][i]=0;

  for(i=1;i<=m;i++){
    for(j=1;j<=n;j++){
      if(X[i-1]==Y[j-1])lcs[i][j]=lcs[i-1][j-1]+1;
      else if(lcs[i-1][j]>=lcs[i][j-1])lcs[i][j]=lcs[i-1][j];
      else lcs[i][j]=lcs[i][j-1];
    }
  }
  j=lcs[m][n];

  for (i=0;i<m;i++)free(lcs[i]);
  free(lcs);
  return j;
}
