#include <stdio.h>
#include <stdlib.h>

#define N 10

int myatoi(char *);

int main(){

    int age,gage,datac;
    char data[N];
    
    printf("和暦（S45, R6等）: ");
    scanf("%s",data);
   
    gage = myatoi(&data[1]);

    if(gage==0){
      printf("数字を読み取れません\n");
      exit(2);
    }

    switch(data[0]){
    case 'M':
    age = 1867;
    break;
    case 'T':
    age = 1911;
    break;
    case 'S':
    age = 1925;
    break;
    case 'H':
    age = 1988;
    break;
    case 'R':
    age = 2018;
    break;
    default:
    printf("%cに対応する元号が存在しません\n",data[0]);
    exit(1);
    break;
    }

    printf("西暦 (AD): %d\n",age+gage);

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