#include "concluidas.h"

Concluidas *criarPilhaConcluidas()
{
    Concluidas *concluidas = (Concluidas *)malloc(sizeof(Concluidas));
    concluidas->quantidade = 0;
    concluidas->topo = NULL;
    return concluidas;
}

void adicionarConcluida(Concluidas *concluidas, Tarefa *tarefa)
{
    PilhaTarefaNode *novo = (PilhaTarefaNode *)malloc(sizeof(PilhaTarefaNode));
    novo->tarefa = tarefa;
    novo->proximo = concluidas->topo;
    concluidas->topo = novo;
    concluidas->quantidade++;
}

void limparConcluidas(Concluidas *concluidas)
{
    PilhaTarefaNode *atual = concluidas->topo;
    while (atual != NULL)
    {
        PilhaTarefaNode *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    concluidas->topo = NULL;
    concluidas->quantidade = 0;
}

void exibirConcluidas(Concluidas *concluidas)
{
    PilhaTarefaNode *atual = concluidas->topo;
    printf("------ Tarefas concluídas ------\n");
    while (atual != NULL)
    {
        printf("\n");
        printf("ID: %d\n", atual->tarefa->id);
        printf("Nome: %s\n", atual->tarefa->nome);
        printf("Descrição: %s\n", atual->tarefa->descricao);
        printf("Prioridade: %d\n", atual->tarefa->prioridade);
        printf("Data de criação: %d/%d/%d\n", atual->tarefa->criacao.dia, atual->tarefa->criacao.mes, atual->tarefa->criacao.ano);
        printf("Data de vencimento: %d/%d/%d\n", atual->tarefa->vencimento.dia, atual->tarefa->vencimento.mes, atual->tarefa->vencimento.ano);
        atual = atual->proximo;
    }
    printf("\n-------------------------------\n");
}