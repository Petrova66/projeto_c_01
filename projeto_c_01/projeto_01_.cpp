#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_RESERVAS 100

typedef struct {
    char nome[100];
    char cpf[15];
    int dia;
    int num_pessoas;
} Reserva;

void fazer_reserva(Reserva reservas[], int *total_reservas);
void listar_reservas(Reserva reservas[], int total_reservas);
void total_pessoas_por_dia(Reserva reservas[], int total_reservas, int dia);

int main() {
    setlocale(LC_ALL, "Portuguese");

    Reserva reservas[MAX_RESERVAS];
    int total_reservas = 0;
    int opcao, dia;

    do {
        printf("\nMenu:\n");
        printf("1 - Fazer Reserva\n");
printf("2 - Listar Reservas\n");
        printf("3 - Total de Pessoas por Dia\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        fflush(stdin);  

        switch(opcao) {
            case 1:
                fazer_reserva(reservas, &total_reservas);
                break;
            case 2:
                listar_reservas(reservas, total_reservas);
                break;
            case 3:
                printf("Digite o dia (1 - Quinta, 2 - Sexta, 3 - Sábado, 4 - Domingo): ");
                scanf("%d", &dia);
                fflush(stdin);
                total_pessoas_por_dia(reservas, total_reservas, dia);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }

        system("pause");
        system("cls");

    } while(opcao != 4);
return 0;
}

void fazer_reserva(Reserva reservas[], int *total_reservas) {
    if (*total_reservas < MAX_RESERVAS) {
        printf("\n--- Fazer Reserva ---\n");
        printf("Nome do Responsável: ");
        fgets(reservas[*total_reservas].nome, 100, stdin);
        printf("CPF do Responsável: ");
        fgets(reservas[*total_reservas].cpf, 15, stdin);
        printf("Dia da Reserva (1 - Quinta, 2 - Sexta, 3 - Sábado, 4 - Domingo): ");
        scanf("%d", &reservas[*total_reservas].dia);
        printf("Número de Pessoas: ");
        scanf("%d", &reservas[*total_reservas].num_pessoas);
        fflush(stdin);

        (*total_reservas)++;
        printf("Reserva realizada com sucesso!\n");
    } else {
        printf("Limite de reservas atingido.\n");
    }
}

void listar_reservas(Reserva reservas[], int total_reservas) {
    if (total_reservas == 0) {
        printf("\nNenhuma reserva realizada.\n");
    } else {
        printf("\n--- Listagem de Reservas ---\n");
        for (int i = 0; i < total_reservas; i++) {
            printf("Nome: %s", reservas[i].nome);
            printf("CPF: %s", reservas[i].cpf);
            printf("Dia: %d\n", reservas[i].dia);
            printf("Número de Pessoas: %d\n", reservas[i].num_pessoas);
            printf("===============================\n");
        }
    }
}

void total_pessoas_por_dia(Reserva reservas[], int total_reservas, int dia) {
    int total_pessoas = 0;
    for (int i = 0; i < total_reservas; i++) {
        if (reservas[i].dia == dia) {
            total_pessoas += reservas[i].num_pessoas;
        }
    }
    
    switch(dia) {
        case 1: printf("Quinta-feira: ");
                break;
        case 2: printf("Sexta-feira: ");
                break;
        case 3: printf("Sábado: ");
                break;
        case 4: printf("Domingo: ");
                break;
        default: printf("Dia inválido.\n");
                 return;
    }
    printf("Total de Pessoas: %d\n", total_pessoas);
}

