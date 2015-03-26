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
    *n = linha;
    fclose(f);
}

void leitor_notas(int* matriN, float *medias){
    int cont=0,mat;
    float n1,n2;
    FILE*f = fopen("notas.txt", "r");
    while(feof(f) == 0){
        if(fscanf(f, "%d %f %f\n", &mat, &n1, &n2) <= 0){
                break;
        }
           	matriN[cont] = mat;
            medias[cont] = (n1+n2)/2;
            cont++;
    }
    fclose(f);
}

void localiza_aluno(int* matri, int* matriN, char* nome, char** nomes, int *n, float* medias){
    int cont, cont2;
    for(cont=0;cont<*n;cont++){
    	cont2=0;
        if(strstr(nomes[cont], nome)!=NULL){
        	while(matri[cont]!=matriN[cont2] && matriN[cont2]>0)
    			cont2++;
            printf("%f %s\n", medias[cont2], nomes[cont]);
        }
    }
}

int main (int argc,char** argv){
    char *nome;
    float *medias;
    int *matri, *matriN, n, i;
    char** nomes;
    medias=(float*)malloc(50*sizeof(float));
    matri=(int*)malloc(50*sizeof(int));
    matriN=(int*)malloc(50*sizeof(int));
    nomes=(char**)malloc(50*sizeof(char*));
    if(argc > 1){
        nome = argv[1];
    }
    printf("%s \n", nome);
    leitor_alunos(matri,nomes,&n);
    leitor_notas(matriN, medias);
    localiza_aluno(matri, matriN, nome, nomes, &n, medias);
    if(nome==NULL || medias==NULL || matri==NULL || matriN==NULL){
        printf("\nErro na alocacao de memoria.\n");
        exit(1);
    }
    free(medias);
    free(matri);
    free(matriN);
    for(i=0;i<n;i++){
        free(nomes[i]);
    }
    free(nomes);
}
