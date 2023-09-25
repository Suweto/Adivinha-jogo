#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>


int start();
int p();

int main()
{ 
    // Texto de bem-vindo
    printf("   >===>\n >>    >=>\n >=>            >=> >=>  >===>>=>>==>    >==>\n >=>          >=>   >=>  >=>  >>  >=> >>   >=> \n >=>   >===> >=>    >=>  >=>  >>  >=> >>===>>=>\n >=>    >>   >=>   >=>   >=>  >>  >=>  >>\n  >====>      >==>>>==> >==>  >>  >=>  >====>");
    printf("\nBem-vindo ao jogo de adivinhacao!");

    // Inicio do jogo
    start();

}


int start()
{
    // Creditos
    const char *url = "https://github.com/Suweto";
    char comando[100];
    snprintf(comando, sizeof(comando), "start %s", url);
    // Variavel de opcao
    int option;
    
    // Inicio do jogo
    printf("Escolha a sua opcao:\n(1) - Começar jogo\n(2) - Sair do jogo\n(3) - Tutorial\n(4) - Creditos\n"); // Texto apresentando as opcoes
    scanf("%d",&option); // Input de texto

    // Verificacao
    switch (option)
    {
    case 1 : // Caso escolha a opcao 1
        printf("Estou escolhendo o numero secreto, aguarde\n");
        Sleep(1000);
        printf(".\n");
        Sleep(500);
        printf("..\n");
        Sleep(200);
        printf("...\n");
        Sleep(200);



        printf("Ja pensei em um numero, tente adivinhar! (Entre 0 a 100)\n");
        srand(time(NULL));
        int secreto = rand() % 100 + 1;
        int chute;
        int lidos = scanf("%d",&chute); 
        
        do {
        lidos = scanf("%d", &chute);
        if (lidos != 1) {
            printf("Entrada inválida! Digite um número: ");
            while (getchar() != '\n'); // Limpar o buffer de entrada
        } else {
            if (chute < secreto)
                printf("O número secreto é maior que o seu chute\n");
            else if (chute > secreto)
                printf("O número secreto é menor que o seu chute\n");
        }
    } while (chute != secreto);

            printf("Voce acertou!!\n");
            p();

        // Sair do Jogo

        break;
        case 3:

        printf("Voce irá tentar chutar o numero que o jogo escolheu\n");
        start();

        break;
        case 4:
        system(comando);
        start();
        break;
    default:
        printf("Voce selecionou uma opcao inexistente, tente novamente\n");
        start();
        break;
    }



}

int p()
{
    int x;
    scanf("%d", &x);
    printf("Voce deseja voltar para o menu?\n(1) - Sim\n(2) - Nao\n");


    switch(x){
    case 1:
        start();
        break;
    case 2:
        break;
    default:
        printf("Voce escolheu uma opcao inexistente, tente novamente");
        p();
        break;}

        
}