#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h> 
/* Desemvolvido por Gomides.Ts*/

typedef struct Possicoes{
    int linha;
    int coluna;
} possicoes;
int **alocar(int **matriz,int linhas,int colunas){
    int i;
        matriz = (int **) calloc (linhas, sizeof(int *));
            if (matriz == NULL) {
                printf ("\n Erro: Memória Insuficiente \n\n");
            }
                for ( i = 0; i < linhas; i++ ){
                    matriz[i] = (int*) calloc (colunas, sizeof(int));
                        if (matriz[i] == NULL){
                            printf ("\n Erro: Memória Insuficiente \n\n");
                        }
                }
    return matriz;
}
void preencher(int **matriz,int linhas,int colunas, int linQueijo,int colQueijo){
    int i,j;
    srand(time(NULL));
        for ( i = 0; i < linhas; i++ ){
            for ( j = 0; j < colunas; j++ ){
                matriz[i][j] = rand()%2-1;
                    if( i== linQueijo && j == colQueijo){
                        matriz[i][j]=1;
                    }
            }
        }
}

void numera(int **matriz,int linhas,int colunas,possicoes p){
    int aux,cont;
        aux=matriz[p.linha][p.coluna];
        do{
            cont=0;
                for (p.linha=0; p.linha<linhas; p.linha++){
                    for (p.coluna=0; p.coluna<colunas; p.coluna++){
                        if (matriz[p.linha][p.coluna]==aux){
                            if (p.linha>0&&matriz[p.linha-1][p.coluna]==0){
                                matriz[p.linha-1][p.coluna]=aux+1;
                                cont++;
                            }
                             if (p.linha<linhas-1&&matriz[p.linha+1][p.coluna]==0){
                                matriz[p.linha+1][p.coluna]=aux+1;
                                cont++;
                            }
                            if (p.coluna<colunas-1&&matriz[p.linha][p.coluna+1]==0){
                                matriz[p.linha][p.coluna+1]=aux+1;
                                cont++;
                            }
                            if (p.coluna>0&&matriz[p.linha][p.coluna-1]==0){
                                matriz[p.linha][p.coluna-1]=aux+1;
                                cont++;
                            }
                        }
                    }
                }
            aux++;
        }
            while(cont>0); 
}
void imprimir(int **matriz,int linhas,int colunas){
    int i,j;
        for ( i = 0; i < linhas; i++ ){
            for ( j = 0; j < colunas; j++ ){
                    printf("\t %d",matriz[i][j]);
            }
        printf("\n");
        }
}
void ratoAcha(int **matriz,int linRato,int colRato){
    if(matriz[linRato][colRato]==0){
        printf(" O rato não chega ao queijo\n\n");
    }
     if(matriz[linRato][colRato]==-1){
        printf(" O rato esta em uma parede\n\n");
    }
     if(matriz[linRato][colRato]>0){
        printf(" O rato esta a %d de distancia do queijo\n\n",matriz[linRato][colRato]);
    }
}
void desalocar(int **matriz,int linhas,int colunas){
    int i;
        for ( i = 0; i < colunas; i++ ){
            free(matriz[i]);
        }
        free(matriz);
}
int main(int argc, char const *argv[]){
    setlocale(LC_ALL, "PORTUGUESE");
        possicoes p;
            int linhas,colunas,**matriz=NULL,linRato,colRato,linQueijo,colQueijo;
                printf("\n Defina a quantidades de linhas da matriz: ");
                    scanf("%d",&linhas);
                printf("\n Defina a quantidades de colunas da matriz: ");
                    scanf("%d",&colunas);
                printf("\n Digite a possição da linha que estara o queijo: ");
                    scanf("%d",&linQueijo);
                printf("\n Digite a possição da coluna que estara o queijo: ");
                    scanf("%d",&colQueijo);
                            p.linha=linQueijo;
                            p.coluna=colQueijo;
                                matriz=alocar(matriz,linhas,colunas);
                                preencher(matriz,linhas,colunas,p.linha,p.coluna);
                                numera(matriz, linhas, colunas, p);
                                imprimir(matriz,linhas,colunas);
                printf("\n Digite a possição da linha que estara o rato: ");
                    scanf("%d",&linRato);
                printf("\n Digite a possição da coluna que estara o rato: ");
                    scanf("%d",&colRato);
                                imprimir(matriz,linhas,colunas);
                                ratoAcha(matriz,linRato,colRato);
                                desalocar(matriz,linhas,colunas);
    return 0;
}
/* Desemvolvido por Gomides.Ts*/
