    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
     
    #define MAXLEN 1024
     
    int main(){
    	int i;
    	char c;
    	FILE *fp;
    	char buffer[MAXLEN];
    	char query[MAXLEN];
    	char buffer_prev[MAXLEN];
    	int status;
    	int arg1, arg2;
    	int in_len, buf_len;
        int count_buf=0;
        int count_que=0; 
    	                    
    	/* ファイルのオープン */
    	fp = fopen("myedit_in.txt","r");
    	if(fp == NULL){
    		printf("Cannot open input file.\n");
    		exit(1);
    	}
    	
    	/* データの読み出し（最後に'\0'を忘れないこと） */
    	buf_len = 0;
    	while(1){
    		c = fgetc(fp);
    		if(c == EOF){
    			buffer[buf_len++] = '\0';
    			break;
    		}
    		else{
    			buffer[buf_len++] = c;
    		}
    	}
    	fclose(fp);
    	
    	/* コマンド入力のためのループ */
    	while(1){
    		status = scanf("%s", query);
    		if(status != 1)
    			break;
     
    		/* 現在のテキストの長さを取得する */
    		buf_len = strlen(buffer);
     
    		/* それぞれのコマンドのチェック */
    		if(strcmp("print", query) == 0){ /* printコマンド */
    			for(i=0;;i++){
                    if(buffer[i]=='\0')break;
                    printf("%c",buffer[i]);
                }
                printf("\n");
    			continue;
    		}
    		else if(strcmp("insert", query) == 0){ /* insertコマンド */
    			if(scanf("%d %s", &arg1, query) == 2){
                    strcpy(buffer_prev,buffer);
                    count_buf=0;
                    for(i=0;;i++){
                    if(buffer[i]=='\0')break;
                    count_buf++;
                    }
                    count_que=0;
    				for(i=0;;i++){
                    if(query[i]=='\0')break;
                    count_que++;
                    }
                    for(i=count_buf;i>=0;i--){
                    buffer[arg1+count_que+i]=buffer[arg1+i];
                    }
                    for(i=0;i<count_que;i++){
                    buffer[arg1+i+1]=query[i];
                    }
                    buffer[count_buf+count_que]='\0';
                    count_buf=0;
                    for(i=0;;i++){
                    if(buffer[i]=='\0')break;
                    count_buf++;
                    }
                    if(count_buf>1023){
                      printf("Error occored in Length\n");
                      exit(2);
                    }
    				continue;
    			}
    		}
            else if(strcmp("cut",query)){
                if(scanf("%d %d",&arg1,&arg2)==2){
                    count_buf=0;
                    for(i=0;;i++){
                    if(buffer[i]=='\0')break;
                    count_buf++;
                    }
                    if(arg2>count_buf){
                        printf("Error occured in Length\n");
                        exit(2);
                    }
                    strcpy(buffer_prev,buffer);
                    for(i=0;;i++){
                        if(buffer[arg2+i]=='\0')break;
                        buffer[arg1+i]=buffer[arg2+i];
                    }
                    buffer[arg1+i+1]='\0';
                    continue;
                }
            }
            else if(strcmp("space",query)){
                if(scanf("%d",&arg1)==1){
                    strcpy(buffer_prev,buffer);
                    count_buf=0;
                    for(i=0;;i++){
                    if(buffer[i]=='\0')break;
                    count_buf++;
                    }
                    for(i=count_buf;i>arg1;i--){
                    if(buffer=='\0')break;
                    buffer[i]=buffer[i-1];
                    }
                    buffer[count_buf+1]='\0';
                    buffer[arg1]=' ';
                    count_buf=0;
                    for(i=0;;i++){
                    if(buffer[i]=='\0')break;
                    count_buf++;
                    }
                    if(count_buf>1023){
                      printf("Error occored in Length\n");
                      exit(3);
                    }
                    continue;
                }
            }
            else if(strcmp("enter",query)){
                if(scanf("%d",&arg1)==1){
                    strcpy(buffer_prev,buffer);
                    count_buf=0;
                    for(i=0;;i++){
                    if(buffer[i]=='\0')break;
                    count_buf++;
                    }
                    for(i=count_buf;i>arg1;i--){
                    if(buffer=='\0')break;
                    buffer[i]=buffer[i-1];
                    }
                    buffer[count_buf+1]='\0';
                    buffer[arg1]='\n';
                    count_buf=0;
                    for(i=0;;i++){
                    if(buffer[i]=='\0')break;
                    count_buf++;
                    }
                    if(count_buf>1023){
                      printf("Error occored in Length\n");
                      exit(4);
                    }
                    continue;
                }
            }
            else if(strcmp("undo", query)){
                strcpy(buffer,buffer_prev); 
                continue;
            }
            else if(strcmp("quit", query)){
                fp = fopen("myedit_out.txt","w");
                in_len=0;
                while(1){
                if(buffer[in_len]=='\0')break;
                fprintf(fp,"%c",buffer[in_len]);
                in_len++;
                }
                fclose(fp);
                break;
            }
            else{
    		printf("ERROR\n");
    		exit(1);
            }
        }
    	return 0;
    }