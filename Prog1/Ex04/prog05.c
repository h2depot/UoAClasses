#include <stdio.h>
#include <string.h>
#define N 256

int main(){
char buf[N]="[Wakamatsu]",string[N];
int data,status,count_str,count_buf;
int i;

while(1){
count_buf=0;
for(i=0;;i++){
    if(buf[i]=='\0')break;
    count_buf++;
}

printf("Current string: ");
for(i=0;;i++){
    if(buf[i]=='\0')break;
    printf("%c",buf[i]);
}
printf("\n");

printf("input-> ");
status = scanf("%d %s",&data,string);
if(status!=2)break;
else if(data>count_buf){
    printf("Error in Position\n");
    continue;
}

/*for(i=0;;i++){
    if(string[i]=='\0')break;
    printf("%c",string[i]);
}
printf("\n");*/

count_str=2;
for(i=0;;i++){
    if(string[i]=='\0')break;
    count_str++;
}
if(count_str+count_buf>255){
    printf("Error is length\n");
    continue;
}
//printf("count_str=%d\n",count_str);

for(i=count_buf;i>=0;i--){
buf[data+count_str+i]=buf[data+i];
}
/*for(i=0;;i++){
    if(buf[i]=='\0')break;
    printf("%c",buf[i]);
}
printf("\n");*/
buf[data]='{';
for(i=0;i<count_str-2;i++){
buf[data+i+1]=string[i];
}
buf[data+i+1]='}';
buf[count_buf+count_str]='\0';
}
printf("\n");
return 0;
}