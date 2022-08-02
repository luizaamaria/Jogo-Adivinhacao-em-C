
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("******Bem vindo ao Jogo de Advinhação!*******\n");
    printf("\n\n");
    printf("              P  /_\\  P            \n");
    printf("             /_\\_|_|_/_\\          \n");
    printf("         n_n | ||. .|| | n_n        \n");
    printf("         |_|_|nnnn nnnn|_|_|        \n");
    printf("        |" "  |  |_|  |"  " |       \n");
    printf("        |_____| ' _ ' |_____|       \n");
    printf("              \\__|_|__/            \n");
    printf("\n\n");                                               
    
    int segundos = time (0);
    srand(segundos);
    
    int numerogrande = rand();
     
    int numerosecreto = numerogrande % 100;
    int chute = 0;
    int tentativas = 1;
    double pontos = 1000;
    int acertou = 0;
    int nivel = 0;
     
    printf("Qual nivel de dificuldade?\n");
    printf("1- FÁCIL  2- MÉDIO  3- DIFICIL\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);
     
    int numerotentativas = 0;
    
    switch(nivel) {
        case 1:
            numerotentativas = 20;
            break;
            
        case 2:
            numerotentativas = 15;
            break;
            
        default:
            numerotentativas = 6;
            break;
    }
    
    for(int i =1; i <= numerotentativas; i++) {
         
        printf("tentativa %d\n", tentativas);
        printf("Qual é o seu chute? ");
         
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);
        
        if(chute < 0){
            printf("Você não pode chutar números negativos!\n");
            continue;
        }
        
        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;
        
        if(acertou) {
            break;
        }
        
        else if(maior) {
            printf("Seu chute foi maior que o número secreto\n");
        }
        
        else {
            printf("Seu chute foi menor que o número secreto\n");
        }
        
        tentativas++;
        
        double pontosperdidos = abs (chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;
     
    }
    
    printf("Fim de jogo!\n");
    
    if(acertou) {
        printf("    $$$_____$$$$$$$$$$$$$$$_$$$_______$$$_$$$$$$$$$$ \n");
        printf("    $$$____$$$____$$$____$$$_$$$_____$$$__$$$_______ \n");
        printf("    $$$____$$$___________$$$_$$$_____$$$__$$$_______ \n");
        printf("    $$$_____$$$_________$$$___$$$___$$$___$$$$$$$$__ \n");
        printf("    $$$______$$$_______$$$_____$$$_$$$____$$$_______ \n");
        printf("    $$$_______$$$_____$$$______$$$_$$$____$$$_______ \n");
        printf("    $$$$$$$$$___$$$_$$$_________$$$$$_____$$$$$$$$$$ \n");
        printf("\n\n");
        
        printf("Você ganhou!\n");
        printf("Você acertou em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
        
    } else {
        printf("Você perdeu, tente de novo!\n");
        printf("O número secreto era %d \n", numerosecreto);
        
        printf("        \\|/ ____ \\|/     \n");   
        printf("        @~/ ,. \\~@        \n");   
        printf("       /_( \\__/ )_\\      \n");  
        printf("          \\__U_/          \n");
        
    }
    
}





