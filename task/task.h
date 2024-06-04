#include <stdlib.h>
#include <string.h>
#include "../concluidas/concluidas.h"

typedef struct ListaTarefas
{
    int quantidade;
    struct ListaTarefaNode *inicio;
    struct ListaTarefaNode *fim;
} ListaTarefas;

typedef struct ListaTarefaNode
{
    Tarefa *tarefa;
    struct ListaTarefaNode *proximo;
    struct ListaTarefaNode *anterior;
} ListaTarefaNode;

ListaTarefas *criarListaTarefas();
void adicionarTarefaInicio(ListaTarefas *lista, Tarefa *tarefa);
void adicionarTarefaFim(ListaTarefas *lista, Tarefa *tarefa);
void adicionarTarefaPorPrioridade(ListaTarefas *lista, Tarefa *tarefa);
void concluirTarefa(ListaTarefas *lista, Concluidas *concluidas, int id);
void exibirListaTarefas(ListaTarefas *lista);