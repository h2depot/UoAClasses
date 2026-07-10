#include <stdio.h>
#include <string.h>
#define N 100
 
/* 適宜プロトタイプ宣言を追加 */
 
int main(){
	char str1[N], str2[N];
    int judge,i,n=0;
	/* 適宜変数を追加すること */
	
	printf("Input string: ");
	scanf("%s", str1); /* 文字列を標準入力から入力 */
	
    str2[0]='[';

    for(i=0;str1[i] != '\0';i++){ 
    if(str1[i]=='A'||str1[i]=='a'||str1[i]=='I'||str1[i]=='i'||str1[i]=='U'||str1[i]=='u'||str1[i]=='E'||str1[i]=='e'||str1[i]=='O'||str1[i]=='o'){
      judge=1;
    }else{
      judge=0;    
    }
    if(judge==0){
        str2[n+1]=str1[i];
        n++;
    }else if(judge==1)continue;
    }

    str2[n+1]=']';
    str2[n+2]='\0';
	
	printf("str1 : %s\n", str1);
	printf("str2 : %s\n", str2);
	
	return 0;
}
 