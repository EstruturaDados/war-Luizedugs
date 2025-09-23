#include <stdio.h>
#include <string.h>

#define TAM_NOME 50
#define TAM_COR 20
#define TAM_Territorio 5

// Definição da struct
//Ela armazena:
// - nome do territórioo, a cor do exército que ocupa o território e armazena a quantidades de tropas


struct Territorio { 

    char nome [30];
    char cor [10];
    int tropas;
};

int main () {
struct Territorio territorios[TAM_Territorio]; // Vetor de amarzenação dos 5 terriotiross
    int menu_principal = 1;
    while (menu_principal !=0) // Laço while permite que o menu seja exibido continuamente
    {   printf("==============================\n");
        printf("    MENU PRINCIPAL JOGO WAR   \n");
        printf("==============================\n");
        printf("1 - CADASTRAR TERRITORIOS     \n");
        printf("2 - VISUALIZAR CADASTRO       \n");
        printf("Escolha uma opcao: ");
        int opcao;
        scanf("%d", &opcao);


    switch (opcao) //Estrutura switch, serve para tratar as opções do menu do jogo
    {
    case 1: 
          printf("\n======= CADASTRO DE TERRITORIOS =======\n");
          for (int i = 0; i < TAM_Territorio; i++) {
                   
          printf("Cadastro dos territorios: \n");
          printf("Territorio %d\n", i + 1);
          printf("Nome :" );
          scanf("%s", territorios[i].nome); //Leitura do nome do territorio
          printf("Informe a cor do exercito: \n");
          scanf("%s", territorios[i].cor); //Leitura da cor do territorio
          printf("informe a qtnd de tropas: \n");
          scanf("%d", &territorios[i].tropas); //Leitura da quantidades de territorios que irá ser cadastrado
            }
        break;
    
    case 2:
         // Exibição dos dados que foram cadastrados
        printf("\n===CADASTRO DO JOGADOR===\n");
        for (int i = 0; i < TAM_Territorio; i++) {
        printf("Territorio %d:\n\n", i + 1);
        printf("============================\n");
        printf("Nome: %s\n", territorios[i].nome);
        printf("============================\n");
        printf("Cor: %s\n", territorios[i].cor);
        printf("============================\n");
        printf("Tropas: %d\n", territorios[i].tropas);
        printf("============================\n");
        }
            
        break;
      
      }
     }
    return 0;
}
    