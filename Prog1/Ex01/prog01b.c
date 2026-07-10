#include<stdio.h>

int main(){
  char n;

  printf("Input a character:");

  while(1){
    scanf("%c",&n);
    
    if(n == '\n'){
      break;
      
    }else{
      printf("'%c': %3d in Decimal / 0x%x in Hexadecimal\n", n,n,n);
    }
    
  }

  
  return 0;
}
