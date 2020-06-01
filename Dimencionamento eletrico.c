/* autor: Tulio Gomides */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
/* Recomedações da para levantamento da carga de iluminação seguindo a NBR 5410:2004
   Recomedações da para levantamento da carga de tomadas seguindo a NBR 5410:2004 */
void iluminacao(float area){ /*Calculo potencia de iluminacao digitado a area */
    int maior,i,con=0;
        printf("\n Area %.2f em metros \n",area);
            if (area<=6){
                printf("\n Potencia de iluminacao 100 Va \n");
            }
                else{
                        i=area-6;
                        for(maior=0;maior<=i;i-=4){
                            con++;
                        }
                    printf("\n Potencia de iluminacao %d Va\n",(con*60)+100-60);
                }
}
void cozinhas(float perimetro){ /* Calculo de PTUG PTUE de Cozinhas, um ponto de tomada para cada 3.5 m ou fração de perimetro*/
    int tug,tugs,con,total;
            tug=((perimetro/3.5)+1);
        printf("\n Perimetro: %.2fm \n",perimetro);
        printf("\n %d PTUG para a cozinha \n Acima da bancada da pia devem ser previstas, no mínimo, duas tomadas de corrente, no mesmo ponto ou em pontos separados\n",tug);
               if(tug<=3){
                   printf("\n Potencias total das PTUGs %d \n 600 Va por PTUG \n\n",tug*600);
               }
               else{
                        con=tug-3;
                        tugs=tug-con;
                            total=((tugs*600)+(con*100));
                                printf("\n Potencias total das PTUGs %d Va \n 600 Va para cada uma das 3 primeiras PTUGs e 100 Va para cada uma PTUG excedentes \n\n",total);
               }
}
void copas(float perimetro){ /* Calculo de PTUG PTUE de Copas, um ponto de tomada para cada 3.5 m ou fração de perimetro*/
    int tug,tugs,con,total;
            tug=((perimetro/3.5)+1);
        printf("\n Perimetro: %.2fm\n",perimetro);
        printf("\n %d PTUG para copas e copas cozinhas\n",tug);
               if(tug<=3){
                   printf("\n Potencias total das PTUGs %d \n 600 Va por PTUG \n\n",tug*600);
               }
               else{
                        con=tug-3;
                        tugs=tug-con;
                            total=((tugs*600)+(con*100));
                                printf("\n Potencias total das PTUGs %d Va \n 600 Va para cada uma das 3 primeiras PTUGs e 100 Va para cada uma PTUG excedentes \n\n",total);
               }
}
void areaservicos(float perimetro){ /* Calculo de PTUG PTUE de Area Servicos, um ponto de tomada para cada 3.5 m ou fração de perimetro*/
    int tug,tugs,con,total;
            tug=((perimetro/3.5)+1);
        printf("\n Perimetro: %.2fm\n",perimetro);
        printf("\n %d PTUG para area servicos\n",tug);
               if(tug<=3){
                   printf("\n Potencias total das PTUGs %d \n 600 Va por PTUG \n\n",tug*600);
               }
               else{
                        con=tug-3;
                        tugs=tug-con;
                            total=((tugs*600)+(con*100));
                                printf("\n Potencias total das PTUGs %d Va \n 600 Va para cada uma das 3 primeiras PTUGs e 100 Va para cada uma PTUG excedentes \n\n",total);
               }
}
void subsolos(float perimetro){ /* Subsolos no mínimo um ponto de tomada */
    printf("\n Perimetro: %.2fm\n",perimetro);
    printf("\n Pelo menos 1 PTUG para subsolos\n\n");
}
void varandas(float perimetro){ /* Varandas no mínimo um ponto de tomada */
    printf("\n Perimetro: %.2fm\n",perimetro);
    printf("\n Pelo menos 1 PTUG para varandas\n\n");
}
void garagens(float perimetro){ /* Varandas no mínimo um ponto de tomada */
    printf("\n Perimetro: %.2fm\n",perimetro);
    printf("\n Pelo menos 1 PTUG para varandas\n\n");
}
void banheiros(float perimetro){ /* No mínimo um ponto de tomada junto ao lavatório com uma distância mínima de 60 cm do limite do boxe */
    printf("\n No mínimo 1 ponto de tomada junto ao lavatório com uma distância mínima de 60 cm do limite do boxe \n\n");
}
void salas(float perimetro){ /* Calculo de PTUG PTUE de Salas, um ponto de tomada para cada 5 m ou fração de perimetro */
     int tug;
        tug=((perimetro/5)+1);
        printf("\n Perimetro: %.2fm\n",perimetro);
        printf("\n %d PTUG para salas\n",tug);
            if(tug<=3){
                    printf("\n Potencias total das PTUGs %d \n 100 Va por PTUG \n\n",tug*100);
                }
                else{
                        printf("\n Potencias total das PTUGs %d Va \n 100 Va para cada PTUG \n\n",tug*100);
                }
}
void dormitorios(float perimetro){ /* Calculo de PTUG PTUE de Dormitórios, um ponto de tomada para cada 5 m ou fração de perimetro */
     int tug;
        tug=((perimetro/5)+1);
        printf("\n Perimetro: %.2fm\n",perimetro);
        printf("\n %d PTUG para dormitórios\n",tug);
            if(tug<=3){
                    printf("\n Potencias total das PTUGs %d \n 100 Va por PTUG \n\n",tug*100);
                }
                else{
                        printf("\n Potencias total das PTUGs %d Va \n 100 Va para cada PTUG \n\n",tug*100);
                }
}
void comodos(float perimetro){ /* Escolha do comodo que será calculado */
    int comodo;
        printf("\n 1 Cozinhas \n 2 Copas \n 3 Area de serviço \n 4 Subsolos \n 5 Varanda \n 6 Garagens \n 7 Banheiros \n 8 Salas \n 9 Dormitórios \n\n Digite o comodo a se dimencionar: ");
            scanf("%d",&comodo);
                switch(comodo){
                    case 1:{
                                cozinhas(perimetro);
                                    break;
                    }
                    case 2:{
                                copas(perimetro);
                                    break;
                    }
                    case 3:{
                                areaservicos(perimetro);
                                    break;
                    }
                    case 4:{
                                subsolos(perimetro);
                                    break;
                    }
                    case 5:{
                                varandas(perimetro);
                                    break;
                    }
                    case 6:{
                                garagens(perimetro);
                                    break;
                    }
                    case 7:{
                                banheiros(perimetro);
                                    break;
                    }
                    case 8:{
                                salas(perimetro);
                                    break;
                    }
                     case 9:{
                                dormitorios(perimetro);
                                    break;
                    }
                    
                }
}
void dados(){ /* Digite a area e perimetro que serão calculada */
    float area,perimetro;
        printf("Digite a area que deseja calcular: ");
            scanf("%f",&area);
        printf("Digite o perimetro que deseja calcular: ");
            scanf("%f",&perimetro);
                iluminacao(area);
                comodos(perimetro);
}
int main(int argc, char const *argv[]){ /* Tela inicial */
    setlocale(LC_ALL, "PORTUGUESE");
        dados();
    return 0;
}
