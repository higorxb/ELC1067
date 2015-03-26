#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leitor_alunos(int* matri,char** nomes,int* n ){
    int mat,i,linha;
    char c;
    char *nome;
    nome=(char*)malloc(50*sizeof(char));
    if(nome==NULL){
        printf("\nErro na alocacao de memoria.\n");
        exit(1);
    }
    FILE*f = fopen("alunos.txt", "r");
    linha = 0;
    while(feof(f) == 0){
        if(fscanf(f, "%d", &mat) <= 0)
        break;
        i = 0;
        c = fgetc(f);
        while(c != '\n' && feof(f)==0){
            nome[i] = c;
            c = fgetc(f);
            i++;
        }
        nome[i] = '\0';
        matri[linha]=mat;
        nomes[linha]=(char*)malloc((strlen(nome)+1)*sizeof(char));
        strcpy(nomes[linha],nome);
        linha++;
    }
}



void leitor_notas(float *medias){
    int cont=0,mat;
    float n1,n2;
    FILE*f = fopen("notas.txt", "r");
    while(feof(f) == 0){
        if(fscanf(f, "%d %f %f\n", &mat, &n1, &n2) <= 0){
		break;
        }
            medias[cont]=(n1+n2)/2;
            cont++;
    }
    fclose(f);
}

void localiza_aluno(char* nome, char** nomes, int* n, float* medias){
    int cont;
    for(cont=0;cont<*n;cont++){
        if(strstr(nomes[cont], nome)!=NULL){
            printf("%f %s\n", medias[cont], nomes[cont]);
        }
    }
}


int main (int argc,char** argv){
    char *nome;
    float *medias;
    int *matri,*n,i;
    char** nomes;
    nome=(char*)malloc(50*sizeof(char));
    medias=(float*)malloc(50*sizeof(float));
    n=matri=(int*)malloc(50*sizeof(int));
    nomes=(char**)malloc(50*sizeof(char*));
    if(nome==NULL || medias==NULL || n==NULL || matri==NULL){
        printf("\nErro na alocacao de memoria.\n");
        exit(1);
    }
    if(argc > 1){
        busca = argv[1];
    }
    printf("%s \n", nome);
    leitor_alunos(matri,nomes,n);
    leitor_notas(medias);
    localiza_aluno(nome,nomes,n,medias);
    free(nome);
    free(medias);
    free(matri);
    free(n);
    for(i=0;i<*n;i++){
        free(nomes[i]);
    }
    free(nomes);
}
