    #include <stdio.h>
     
    int main(){
     
      int data = 312;
      int *p;
      p = &data;
     
      printf("(1) %p\n", &data);
      printf("(2) %d\n", data);
      //printf("(3) %d\n", *data);
      printf("(4) %p\n", &p);
      printf("(5) %p\n", p);
      printf("(6) %d\n", *p);
      printf("(7) %p\n", &(*p));
     
      return 0;
    }