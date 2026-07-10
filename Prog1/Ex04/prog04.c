    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
     
    int main()
    {
      FILE *fp;
      char code[4], airport[30]; 
      char buf[4]; 
      int status; 
      int i,j,n,flag=0;

     
      while(1) {
        flag=0;
        printf("Input IATA code: ");
        if (scanf("%s",buf)==EOF) break;
      

        if ((fp=fopen("IATA-jp.txt","r"))==NULL) {
          printf("Code file open error!!\n");
          exit(2);
        }
        
        for(i=0;;i++){
          if((status=fscanf(fp,"%s",code))==EOF)break;
            //printf("%s ",code);

          fscanf(fp,"%s",airport);
            //printf("%s\n",airport);
            
        if(strcmp(code,buf)==0){
            flag=1;
            break;
            }
        }
        if(flag==1){
        printf("%s is %s Airport\n",code,airport);
        }else if(flag==0){
        printf("%s is not found.\n",buf);
        }
        fclose(fp);
      }
      printf("\n");
     
      return 0;
    }