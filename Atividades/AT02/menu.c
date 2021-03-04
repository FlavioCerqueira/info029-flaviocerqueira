#include <stdio.h>

int main(){
	
	int op;
	float num1, num2;

	scanf("%f",&num1);
	scanf("%f",&num2);
	scanf("%d",&op);

	switch(op){

		case 1:{
			printf("%f", num1+num2);
			break;
		}
		case 2:{
			printf("%f", num1-num2);
			break;
		}
		case 3:{
			printf("%f", num1*num2);
			break;
		}
		case 4:{
			printf("%f", num1/num2);
			break;
		}
		case 0:{
			printf("Finishing...");
			break;
		}
		default:{
			printf("Invalid Option");
		}
	}

	return 0;
}