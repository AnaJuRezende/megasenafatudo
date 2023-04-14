#include <stdio.h>
#include <stdlib.h> //necessário para usar a função system()
#include <locale.h> //biblioteca dos caracteres
#include <time.h> //biblioteca do tempo

int main(){
    
    //a mega sena
    
    printf("\n------------------ \n");
    printf("--- MEGA SENA ---");
    printf("\n------------------ \n");
    
    setlocale(LC_ALL, "Portuguese"); //chamando a blibioteca e escolhendo a linguagem dela
    
    int x, aposta[6], vet[6], y, z, igual, aux; //variáveis
    y = 0;
    aux = 0;
    
    printf("\n Digite a sua aposta com 6 números de 1 a 60: \n"); //usuário digita sua aposta
    
    for(x = 0; x < 6; x++){ //percorrer o vetor
        scanf("%d", &aposta[x]); //ler os numeros
    }
    
    srand(time(NULL)); //nao ser sempre os mesmos numeros sorteados
    
    //gerando numeros aleatorios sem repeti-los
    
    do{
       vet[y] = 1 + rand() % 60; //sorteia de 1 a 60 aleatoriamente
       igual = 0;
       for(z = 0; z < y; z++){ //percorre o vetor que já foi preenchido
           if(vet[z] == vet[y]){
               igual = 1; //se achar numero repetido
           }
       }
       if(igual == 0){ //quando o numero nao se repetir
           y++;
       }
    }while(y < 6); //enquanto não tiver 6 numeros diferentes
    
    //resultado desses numeros aleatorios
    
    printf("\n Números sorteados pela MEGA-SENA: \n");
    for(y = 0; y < 6; y++){
        printf("%d ", vet[y]);
    }
    
    printf("\n");
    
    //comparando vetores
    
    printf("\n Números repetidos: ");
    for(x = 0; x < 6; x++){
        for(y = 0; y < 6; y++){
            if(aposta[x] == vet[y]){
                aux = 1; //se achou numero repetido
                printf("%d " ,vet[y]);
            }
        }
    }
    
    if(aux == 0){
        printf("Nenhum número igual!");
    }
    
}
