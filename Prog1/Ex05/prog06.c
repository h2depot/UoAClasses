    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
     
    int main(){
      int a[] = {1, 2, 4, 8, 16, 32};
      int b[2][3] = {{1, 3, 9}, {-1, -3, -9}};
      int *ptr;
      char str[][10] = { "Aizu", "Univ", "Bandai" };
      char *p, *q;
      printf( "(1) %d\n",  sizeof( str ) );
  p = &str[1][0];  q = &str[0][2];
  printf( "(2) %c\n",  p[3]); /* ここはポインタ演算(+,-)を使用しない方法で記述 */
  printf( "(3) %c\n",  *q-2 );
  for ( p=str[2] ; *p!='\0' ; p++ );
  printf( "(4) %c\n",  *(p-1) );

  printf( "(5) %s\n",  &str[2][3] );
  strcpy( str[1]+4,  str[0] );
  printf( "(6) %s\n",  str[1] );
    
      ptr = a;
      printf("(1) *ptr = %d    \t= %d\n", *ptr, a[0]); /* aを用いて配列風に */
      printf("(2) &a[2] = %p   \t= %p\n", &a[2], ptr+2); /* ptrでポインタ演算 */
      printf("(3) *(ptr+3) = %d\t= %d\n", *(ptr+3), a[3]); /* aを用いて配列風に */
      ptr = &a[2];
      printf("(4) ptr[2] = %d  \t= %d\n", ptr[2], a[4]); /* aを用いて配列風に */
      printf("(5) *ptr-- = %d  \t= %d\n", *ptr--, a[2]); /* aを用いて配列風に */
      printf("(6) *ptr = %d    \t= %d\n", *ptr, a[1]); /* aを用いて配列風に */
      ptr = b[0];
      printf("(7) *++ptr = %d  \t= %d\n", *++ptr, b[0][1]); /* bを用いて配列風に */
      printf("(8) *(ptr+3) = %d\t= %d\n", *(ptr+3), b[1][1]); /* bを用いて配列風に */
      return 0;
    }