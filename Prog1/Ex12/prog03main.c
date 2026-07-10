    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "prog03header.h"
     
    int main() {
      int i;
      Planet planets[NPLANETS];
      
      if( read_planets( planets ) != 0 ){
          fprintf(stderr, "Input Error!\n");
          exit(3);
      }
     
      for (i = 0; i < NPLANETS; i++) {
        printf("Name: %s\n", planets[i].name);
        printf("  Radius: %.0f [km]\n", planets[i].radius);          /* 半径 */
        printf("  Density: %.2f [g/cm3]\n", planets[i].density);     /* 密度 */
        printf("  Semi-Major Axis: %.3e [km]\n", planets[i].semi_major_axis);   /* 軌道長半径 */
      }
     
      return 0;
    }
     
    #ifdef TEST0 /* 単体テスト用 read_planets 正常動作（戻り値 0 ）の場合 */
    int read_planets(Planet *planets) {
      int i;
      for (i = 0; i < NPLANETS; i++) {
        strcpy(planets[i].name, "Sample");     /* テスト用のサンプルデータ */
        planets[i].radius = 1000;
        planets[i].density = 1.00;
        planets[i].semi_major_axis = 100000000;
      }
      return 0;
    }
    #elif TEST1 /* 単体テスト用 read_planets 異常動作（戻り値 -1 ）の場合 */
    int read_planets(Planet *planets) {
      return -1;
    }
    #endif