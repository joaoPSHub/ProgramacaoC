/**
 * @file jokenpô.c
 * @brief Jogo de Jokenpô (Pedra, Papel e Tesoura) contra o computador.
 *
 * O jogador escolhe uma opção via teclado e o computador
 * gera uma escolha aleatória. O resultado é exibido ao final.
 *
 * @author João Paulo
 * @date 2025
 */

#include <stdio.h>   // Funções de entrada e saída (printf, scanf)
#include <stdlib.h>  // Funções rand() e srand() para números aleatórios
#include <time.h>    // Função time() para semente do gerador aleatório

int main() {

    /* -------------------------------------------------------
     * Declaração de variáveis
     * escolhaJogador   : armazena a opção digitada pelo jogador (1, 2 ou 3)
     * escolhaComputador: armazena a opção gerada aleatoriamente (1, 2 ou 3)
     * ------------------------------------------------------- */
    int escolhaJogador, escolhaComputador;

    /* Inicializa o gerador de números aleatórios com o tempo atual
     * Garante que a sequência seja diferente a cada execução */
    srand(time(0));

    /* -------------------------------------------------------
     * Interface com o usuário — exibição do menu
     * ------------------------------------------------------- */
    printf("*** Jogo de Jokenpô ***\n");
    printf("Escolha uma opção:\n");
    printf("1. Pedra\n");
    printf("2. Papel\n");
    printf("3. Tesoura\n");
    printf("Escolha: ");
    scanf("%d", &escolhaJogador);

    /* Gera a escolha do computador:
     * rand() % 3 retorna 0, 1 ou 2
     * + 1 ajusta para o intervalo 1, 2 ou 3 */
    escolhaComputador = rand() % 3 + 1;

    /* -------------------------------------------------------
     * Exibição da escolha do jogador
     * ------------------------------------------------------- */
    switch (escolhaJogador) {
        case 1:
            printf("Jogador: Pedra - ");
            break;
        case 2:
            printf("Jogador: Papel - ");
            break;
        case 3:
            printf("Jogador: Tesoura - ");
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }

    /* -------------------------------------------------------
     * Exibição da escolha do computador
     * ------------------------------------------------------- */
    switch (escolhaComputador) {
        case 1:
            printf("Computador: Pedra\n");
            break;
        case 2:
            printf("Computador: Papel\n");
            break;
        case 3:
            printf("Computador: Tesoura\n");
            break;
    }

    /* -------------------------------------------------------
     * Lógica de resultado
     *
     * Empate   : escolhas iguais
     * Jogador vence:
     *   Pedra (1) vence Tesoura (3)
     *   Papel (2) vence Pedra   (1)
     *   Tesoura (3) vence Papel (2)
     * Computador vence: qualquer outro caso
     * ------------------------------------------------------- */
    if (escolhaComputador == escolhaJogador) {
        printf("### É um empate! ###\n");
    } else if ((escolhaJogador == 1 && escolhaComputador == 3) ||
               (escolhaJogador == 2 && escolhaComputador == 1) ||
               (escolhaJogador == 3 && escolhaComputador == 2)) {
        printf("*** Parabéns, você ganhou! ***\n");
    } else {
        printf("### Você perdeu! ###\n");
    }

    return 0;
}
