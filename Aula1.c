#include <stdio.h>

main(){
	int m;
	char nome[100];
	FILE *f;
	printf("Digite seu numero de matricula.\n");
	scanf("%d", &m);
	printf("Digite seu nome\n");
	scanf("%s", nome);
	f=fopen("saida.txt", "w");
	fprintf(f, "%d %s\n", m, nome);
	fclose(f);
}

