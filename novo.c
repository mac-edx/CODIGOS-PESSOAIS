#include <stdio.h>
#include <conio.h>
#include <windows.h>

double n1, n2;
int i = 0;
int tecla;


void menu(){
const char *opcoes[4] = {"Soma", "Subtração", "Multiplicação", "Divisão"};
system("cls");
printf("======Calculadora======\n");
 for (int j = 0; j < 4; j++){
    
    if(j == i){
        printf(" -> %s\n ", opcoes[j]);
    }
    else{
        printf(" %s\n", opcoes[j]);
    }
    
        
    }
 }

void opera(){
    switch (i) {
        case 0:
        printf("\nescolhido: Soma");
        printf("digite seu primeiro numero: \n");
        scanf("%lf", &n1);
        printf("agora digite o segundo numero: \n");
        scanf("%lf", &n2);
        printf("\no resultado é: %.2lf ", (n1 + n2));
        break;
        case 1:
        printf("\nescolhido: Subtracao");
          printf("digite seu primeiro numero: \n");
        scanf("%lf", &n1);
        printf("agora digite o segundo numero: \n");
        scanf("%lf", &n2);
        printf("\no resultado é: %.2lf ", (n1 - n2));
        break;
        case 2:
        printf("\nescolhido: Multiplicacao");
          printf("digite seu primeiro numero: \n");
        scanf("%lf", &n1);
        printf("agora digite o segundo numero: \n");
        scanf("%lf", &n2);
        printf("\no resultado é: %.2lf ", (n1 * n2));
        break;
        case 3:
        printf("\nescolhido: Divisao");
          printf("digite seu primeiro numero: \n");
        scanf("%lf", &n1);
        printf("agora digite o segundo numero: \n");
        scanf("%lf", &n2);
        printf("\no resultado é: %.2lf ", (n1 / n2));
        break;
    }
    printf("\n pressione qualquer tecla para voltar");
    _getch();
}

int main(){
    
    
    while(1){
        menu();
     int tecla = _getch();
        if (tecla == 224) {
            tecla = _getch();
            if (tecla == 72) i = (i + 3) % 4;  // seta cima
            if (tecla == 80) i = (i + 1) % 4;  // seta baixo
        } else if (tecla == 13){
            opera();
        }
    
    }
}