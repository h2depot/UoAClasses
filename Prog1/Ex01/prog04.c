#include <stdio.h>

char VowelChgCase(char);

int main(){
  char c;
  int status;
  
  while(1){

    status = scanf("%c", &c);
    if (status != 1)break;
    printf("%c", VowelChgCase(c));
  }

  return 0;
}

char VowelChgCase(char c){
  char result;

  switch (c){
  case 'a':
  case 'i':
  case 'u':
  case 'e':
  case 'o':
    result =  c - 32;
    break;
  case 'A':
  case 'I':
  case 'U':
  case 'E':
  case 'O':
    result =  c + 32;
    break;
  default:
    result = c;
  }
  return result;
  
}

