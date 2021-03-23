#include <stdio.h>

struct Numeros{

	int a, b, c, d;
};

void ler4Numeros(struct Numeros *num);

int main(){

	struct Numeros num;

	ler4Numeros(&num);

	printf("%d ",num.a);
	printf("%d ",num.b);
	printf("%d ",num.c);
	printf("%d",num.d);

	return 0;
}

void ler4Numeros(struct Numeros *num){

	scanf("%d",&(*num).a);
	scanf("%d",&(*num).b);
	scanf("%d",&(*num).c);
	scanf("%d",&(*num).d);
}