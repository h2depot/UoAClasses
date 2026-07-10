    #include <stdio.h>
    #include <string.h>
     
    #define NWORD 7
     
    int main()
    {
      char str2[NWORD][20];   /* 入力用の文字配列 */
      char newstr[120];       /* 出力用の文字配列 */
      int i;
      int j,count=0,char_len;
      /* ここにその他の変数宣言 */
     
      printf( "Input %d words: \n", NWORD );
     
      for( i = 0; i < NWORD; i++ ){
        scanf("\n%s",&str2[i]);
      }
     
      /* 入力されたstr2をもとに、newstrを作成する処理を書く */
      for( i = 0; i < NWORD; i++ ){
        for(j=0;str2[i][j]!='\0';j++){
            newstr[count]=str2[i][j];
            count++;
        }
           if(i < NWORD-1){
            newstr[count]=' ';
            count++;   
           }else{
            newstr[count]='\0';
           }
    
      }
      /* 単語の間にスペースを入れながら、各単語をつないだ一つの文字列にする */
     
      printf("%s\n", newstr);   /* 新しい文字列全体を表示 */
     
      /* ここで、newstrの文字数を表示 */
      char_len=strlen(newstr);
      printf("Total: %d characters\n",char_len);
     
      return 0;
    }