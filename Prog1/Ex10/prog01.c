#include <stdio.h>
 
int myatoi(char *);
 
int main()
{
  char str2[][20]={ "  2024",
                    " -21.50",
                    "+16m",
                    " 654,321",
                    "+-40",
                    "x86",
                    "-x86",
                    "2024/1/31",
                    ""};
  int ival, i;
 
  for ( i=0; str2[i][0]!='\0'; i++ ){
    ival = myatoi( str2[i] );
    printf("String:%s\n", str2[i]);
    printf("Value:%d\n", ival);
  }
  return 0;
}

int myatoi(char *cp){
    int minus=0,data=0;
    int i,j=0;

    while(cp[j]==' '){
      j++;
    }
    //printf("%c\n",cp[j]);
    if(cp[j]=='-'){
      //printf("minus = 1\n");
      minus = 1;
    }else if(cp[j]=='+'){
    
    }else if(cp[j] >= '0' && cp[j] <= '9'){
      j -= 1;
    }else return 0;

    //printf("%d\n",minus);


    for(i=j+1;cp[i]!='\0';i++){
        //data=0;
        if(cp[i] >= '0' && cp[i] <= '9'){
          if(data==0){
            data = (int)(cp[i]- '0');
            //printf("%d\n",data);
          }else{
            data = data*10 + (int)(cp[i]- '0');
            //printf("%d\n",data);
          }
        }else{
            if(i==j+1){
                //printf("else moved!\n");
                return 0;
            }else break;
        }
    }

    if(minus==1){
        printf("minus moved\n");
        data = data *(-1);
    }

    return data;
}
