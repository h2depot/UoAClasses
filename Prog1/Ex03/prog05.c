#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    int num1,num2,status1,status2;
	FILE *fpin1, *fpin2;
	
	if ((fpin1 = fopen(argv[1], "r")) == NULL){
		printf("Failed to open: %s\n", argv[1]);
		exit(1);
	}
	
	if ((fpin2 = fopen(argv[2], "r")) == NULL){
		printf("Failed to open: %s\n", argv[2]);
		fclose(fpin1);
		exit(2);
	}

    fscanf(fpin1,"%d",&num1);
    fscanf(fpin2,"%d",&num2);
	while(1){
    if(num1>num2){
		printf("%d\n",num2);
       status2=fscanf(fpin2,"%d",&num2);
		}
    else if(num2>num1){
		printf("%d\n",num1);
	    status1=fscanf(fpin1,"%d",&num1);
		}
	else if(num2==num1){
		printf("%d\n",num1);
        status1=fscanf(fpin1,"%d",&num1);
	}
    
    if(status1 == EOF){
		printf("%d\n",num2);
		while(1){
			status2 = fscanf(fpin2,"%d",&num2);
			if(status2 == EOF)break;
			printf("%d\n",num2);
		}
		break;
	}
    if(status2 == EOF){
		printf("%d\n",num1);
		while(1){
			status1 = fscanf(fpin1,"%d",&num1);
			if(status1 == EOF)break;
			printf("%d\n",num1);
		}
		break;
	}
	}

	fclose(fpin1);
	fclose(fpin2);
	return 0;
}