#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  int n;
  int i,j,k,l;
  double sum;

  scanf("%d",&n);
  double*K=(double*)malloc(n*sizeof(double));
  double*D=(double*)malloc((n+1)*sizeof(double));
  for(i=0;i<n;i++)scanf("%lf",&K[i]);
  for(i=0;i<=n;i++)scanf("%lf",&D[i]);
  double **dynamic=(double**)malloc((n+1)*sizeof(double*));
  for(i=0;i<=n;i++)dynamic[i]=(double*)malloc((n+1)*sizeof(double));

  for(i=0;i<=n;i++){
    for(j=0;j<=n-i;j++){
      k=i+j;
      dynamic[j][k]=INFINITY;
      sum=D[k];
      if(i==0){
        dynamic[j][k]=sum;
        continue;
      }
      for(l=j;l<k;l++){
        sum+=K[l]+D[l];
        dynamic[j][k]=(dynamic[j][k]>dynamic[j][l]+dynamic[l+1][k])?dynamic[j][l]+dynamic[l+1][k]:dynamic[j][k];
      }
      dynamic[j][k]+=sum;
    }
  }
  printf("%.12f\n",dynamic[0][n]);

  free(K);
  free(D);
  for (i =0;i<=n;i++)free(dynamic[i]);
  free(dynamic); 
  return 0;
}
