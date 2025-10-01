#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
//Função de cadastramento de territorios
void cadastrarTerritorios(Territorio* territorios, int qtd) {
    printf("\n======= CADASTRO DE TERRITORIOS =======\n");
    for (int i = 0; i < qtd; i++) {
        printf("Cadastro do Territorio %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", territorios[i].nome);
        printf("Cor do exercito: ");
        scanf("%s", territorios[i].cor);
        printf("Quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
        limparBuffer();
    }
}
//Função de exibir o cadastro de territorios
void exibirTerritorios(Territorio* territorios, int qtd) {
    printf("\n======= EXIBIÇÃO DOS TERRITORIOS =======\n");
    for (int i = 0; i < qtd; i++) {
        printf("Territorio %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
        printf("-----------------------------\n");
    }
}
//Função de atacar os territorios
void atacar(Territorio* atacante, Territorio* defensor) {
    printf("\nSimulando ataque de '%s' para '%s'...\n", atacante->nome, defensor->nome);

    if (atacante->tropas < 2) {
        printf("O atacante precisa de pelo menos 2 tropas para atacar!\n");
        return;
    }

    int dadoAtacante = (rand() % 6) + 1;
    int dadoDefensor = (rand() % 6) + 1;

    printf("Dado do atacante: %d\n", dadoAtacante);
    printf("Dado do defensor: %d\n", dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("O atacante venceu!\n");

        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas / 2;
        atacante->tropas -= defensor->tropas;

    } else {
        printf("O defensor defendeu seu territorio com sucesso\n");
        atacante->tropas -= 1;
    }
}

void liberarMemoria(Territorio* territorios) {
    free(territorios); //Libera a memoria alocada
    printf("A memória liberada com sucesso!\n");
}

int main() {
    int opcao; //Menu de opções para usuario escolher
    int qtdTerritorios = 0;
    Territorio* territorios = NULL;
    
    do {
        printf("\n======= MENU PRINCIPAL =======\n");
        printf("1 - Cadastrar Territorios\n");
        printf("2 - Exibir Territorios\n");
        printf("3 - Atacar\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                 srand(time(NULL)); // Inicializa aleatoriedade
                 int qtdTerritorios;
                 printf("Quantos territorios deseja cadastrar? ");
                 scanf("%d", &qtdTerritorios);
                 limparBuffer();
                 // Aloca memória para o número de territórios informados
                Territorio* territorios = (Territorio*) malloc(qtdTerritorios * sizeof(Territorio));
                 if (territorios == NULL) {
                    printf("Erro ao alocar memória.\n");
                    return 1;
                 }
                
                cadastrarTerritorios(territorios, qtdTerritorios);
                break;
            case 2:
                 // Verifica se há territórios cadastrados
                exibirTerritorios(territorios, qtdTerritorios);
                break;
            // Verifica se há pelo menos dois territórios para realizar um ataque
            case 3: {
                if (territorios == NULL || qtdTerritorios < 2) {
                printf("Cadastre pelo menos 2 territórios antes de atacar.\n");
                break;
                }
                int idAtacante, idDefensor;
                exibirTerritorios(territorios, qtdTerritorios);

                printf("Escolha o numero do territorio ATACANTE (1 a %d): ", qtdTerritorios);
                scanf("%d", &idAtacante);
                printf("Escolha o numero do territorio DEFENSOR (1 a %d): ", qtdTerritorios);
                scanf("%d", &idDefensor);
                limparBuffer();

                if (idAtacante == idDefensor || 
                    idAtacante < 1 || idAtacante > qtdTerritorios || 
                    idDefensor < 1 || idDefensor > qtdTerritorios) {
                    printf("IDs inválidos para ataque.\n");
                } else {
                    atacar(&territorios[idAtacante - 1], &territorios[idDefensor - 1]);
                }
                break;
            }
            case 0:
                liberarMemoria(territorios);
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0); // Repete o menu até o usuário escolher sair escolhendo a opção "0"
        if (territorios != NULL) {
        liberarMemoria(territorios);
         }
    return 0; //Finliza o progama
}