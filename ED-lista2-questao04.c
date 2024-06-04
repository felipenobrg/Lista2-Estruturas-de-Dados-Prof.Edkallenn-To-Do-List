/*
** Função: Sistema de Gerenciamento de Tarefas
** Autor: Felipe Nóbrega de Almeida
** Data: 04/06/2024
** Observações:
*/

#include <locale.h>

#include "concluidas/concluidas.h"
#include "listaTarefas/listaTarefas.h"

void menu();
int menuConcluirTarefa();
Tarefa *cadastrarTarefa();
void limparTerminal();

int main()
{
    setlocale(LC_ALL, "Portugese");

    ListaTarefas *listaTarefas = criarListaTarefas();
    Concluidas *PilhaTarefasConcluidas = criarPilhaConcluidas();

    int opcao;
    do
    {
        menu();
        printf("\nOpção: ");
        scanf("%d", &opcao);
        fflush(stdin);
        switch (opcao)
        {
        case 1:
            limparTerminal();
            exibirListaTarefas(listaTarefas);
            break;
        case 2:;
            limparTerminal();
            Tarefa *tarefa = cadastrarTarefa();
            adicionarTarefaPorPrioridade(listaTarefas, tarefa);
            break;
        case 3:;
            limparTerminal();
            int id = menuConcluirTarefa();
            concluirTarefa(listaTarefas, PilhaTarefasConcluidas, id);
            printf("Tarefa concluída com sucesso!\n");
            break;
        case 4:
            limparTerminal();
            exibirConcluidas(PilhaTarefasConcluidas);
            break;
        case 5:
            limparTerminal();
            limparConcluidas(PilhaTarefasConcluidas);
            printf("Tarefas concluídas limpas com sucesso!\n");
            break;
        case 6:
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 6);

    return 0;
}

void menu()
{
    printf("\n------ To-Do List ------\n");
    printf("1. Exibir tarefas\n");
    printf("2. Adicionar tarefa\n");
    printf("3. Concluir tarefa\n");
    printf("4. Exibir tarefas concluídas\n");
    printf("5. Limpar tarefas concluídas\n");
    printf("6. Sair\n");
    printf("------------------------\n");
}

int menuConcluirTarefa()
{
    int id;
    printf("\nDigite o id da tarefa que deseja concluir: \n");
    scanf("%d", &id);
    fflush(stdin);
    return id;
}

Tarefa *cadastrarTarefa()
{
    char nome[50], descricao[100];
    int dia, mes, ano;
    int prioridade = 0;

    printf("\nInsira os dados abaixo para adicionar uma tarefa:\n");
    printf("Nome: ");
    fgets(nome, sizeof(nome), stdin);
    fflush(stdin);
    nome[strcspn(nome, "\n")] = 0;
    printf("Descrição: ");
    fgets(descricao, sizeof(descricao), stdin);
    fflush(stdin);
    descricao[strcspn(descricao, "\n")] = 0;
    while (1)
    {
        printf("Prioridade (1, 2, 3, 4 ou 5): ");
        scanf("%d", &prioridade);
        fflush(stdin);
        if (prioridade < 1 || prioridade > 5)
        {
            printf("Prioridade inválida! Digite novamente.\n");
            continue;
        }
        break;
    }
    Data *vencimento;
    while (1)
    {
        printf("Data de vencimento (dia/mês/ano): ");
        scanf("%d %d %d", &dia, &mes, &ano);
        fflush(stdin);
        vencimento = criarData(dia, mes, ano);
        if (vencimento == NULL)
        {
            printf("Data inválida! Digite novamente.\n");
            continue;
        }
        break;
    }
    return criarTarefa(nome, descricao, vencimento, prioridade);
}

void limparTerminal()
{
    system("cls");
}