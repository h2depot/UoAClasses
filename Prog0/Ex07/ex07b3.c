#include <stdio.h>

int main()
{
  int i;
  int in = 0, en = 0, on = 0;
  int input[100], odd[100], even[100];

  for ( i = 0 ; i < 100 ; i++ )
    {


      if ( input[ i - 1 ] != 0 || i == 0)
	{
           scanf("%d", &input[in++]);
	   if (input[i] %2 == 0) even[en++] = input[i];
	   else odd[on++] = input[i];
	}
      else  break;
    }

  printf("Input: ");
  for ( i = 0 ; i < in - 1 ; i++ )
    {
      printf("%d ", input[i]);
    }
  printf("\n");

  printf("Odd:  ");
  for ( i = 0 ; i < on ; i++ )
    {
      printf("%d ", odd[i]);
    }
  printf("\n");

  printf("Even: ");
  for ( i = 0 ; i < en - 1 ; i++ )
    {
      printf("%d ", even[i]);
    }
  printf("\n");

  return 0;

}
