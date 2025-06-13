#include <stdio.h>

int n1, n2, n3;
int main(){
    printf("digite tres numeros inteiros: \n");
    scanf("%d", &n1);
    printf("segundo numero: \n");
    scanf("%d", &n2);
    printf("terceiro numero: \n");
    scanf("%d", &n3);
    if(n1 == n2 && n2 == n3){
         printf("todos sao iguais");
    }
    else if(n1 > n2 && n2 > n3){
        printf("%d %d %d", n3, n2, n1);
    }
    else if(n2 > n1 && n1 > n3){
        printf("%d %d %d", n3, n1, n2);
    }
    else if(n3 > n2 && n2 > n1){
        printf("%d %d %d", n1, n2, n3);
    }
    
   

    system("pause");
}