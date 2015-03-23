#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leitor_alunos(int* matri,char* nomes,int* n ){


}


int main (int argc,char** argv){
    char *nome;
    nome=(char*)malloc(50*sizeof(char));
    if(nome==NULL){
        printf("\nErro na alocacao de memoria.\n");
        exit(1);
    }
    float *medias;
    medias=(float*)malloc(50*sizeof(float));
    if(medias==NULL){
        printf("\nErro na alocacao de memoria.\n");
        exit(1);
    }
    int *matri,*n,i,j;
    n=matri=(int*)malloc(50*sizeof(int));
    if(n==NULL || matri==NULL ){
        printf("\nErro na alocacao de memoria.\n");
        exit(1);
    }
    char* nomes;
    nomes=(char*)malloc(50*50*sizeof(char));
    if(nomes==NULL){
        printf("\nErro na alocacao de memoria.\n");
        exit(1);
    }
    if(argv > 1){
        nome = argv[1];
    }
    printf("%s \n", nome);
    leitor_alunos(matri,nomes,n);
}
