#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leitor_alunos(int* matri, char nomes[][50], int* n){
    int mat,i,linha;
    char nome[50],c;
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
        strcpy(nomes[linha],nome);
        linha++;
    }
    *n = linha;
    fclose(f);
}

void leitor_notas(float* medias){
    int cont=0,mat;
    float n1,n2;
    FILE*f = fopen("notas.txt", "r");
    while(feof(f) == 0){
        if(fscanf(f, "%d %f %f\n", &mat, &n1, &n2) <= 0){
            break;
            medias[cont]=(n1+n2)/2;
            cont++;
        }
    }
    fclose(f);
}

void localiza_aluno(char nome, char nomes[][50], int n, float* medias){
    int cont;
    for(cont=0;cont<n,cont++){

    }

int main(int argc, char** argv){
    char* nome;
    float medias[50];
    int n,matri[50];
    char nomes[50][50];
    if(argc > 1){
        strcpy(nome, argv[1]);
    }
    printf("%s\n", nome);
    leitor_alunos(matri, nomes, &n);
    leitor_notas(medias);
    localiza_aluno(nome,nomes,n,medias);
}
