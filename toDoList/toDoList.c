#include "listaTarefas.h"

ListaTarefas *criarListaTarefas()
{
  ListaTarefas *lista = (ListaTarefas *)malloc(sizeof(ListaTarefas));
  lista->quantidade = 0;
  lista->inicio = NULL;
  lista->fim = NULL;
  return lista;
}

void adicionarTarefaInicio(ListaTarefas *lista, Tarefa *tarefa)
{
  ListaTarefaNode *novo = (ListaTarefaNode *)malloc(sizeof(ListaTarefaNode));
  novo->tarefa = tarefa;
  novo->proximo = lista->inicio;
  novo->anterior = NULL;

  if (lista->quantidade == 0)
  {
    lista->fim = novo;
  }
  else
  {
    lista->inicio->anterior = novo;
  }

  lista->inicio = novo;
  lista->quantidade++;
}

void adicionarTarefaFim(ListaTarefas *lista, Tarefa *tarefa)
{
  ListaTarefaNode *novo = (ListaTarefaNode *)malloc(sizeof(ListaTarefaNode));
  novo->tarefa = tarefa;
  novo->proximo = NULL;
  novo->anterior = lista->fim;

  if (lista->quantidade == 0)
  {
    lista->inicio = novo;
  }
  else
  {
    lista->fim->proximo = novo;
  }

  lista->fim = novo;
  lista->quantidade++;
}

void adicionarTarefaPorPrioridade(ListaTarefas *lista, Tarefa *tarefa)
{
  ListaTarefaNode *novo = (ListaTarefaNode *)malloc(sizeof(ListaTarefaNode));
  novo->tarefa = tarefa;

  if (lista->quantidade == 0)
  {
    novo->proximo = NULL;
    novo->anterior = NULL;
    lista->inicio = novo;
    lista->fim = novo;
    lista->quantidade++;
    return;
  }

  ListaTarefaNode *atual = lista->inicio;
  while (atual != NULL && atual->tarefa->prioridade >= tarefa->prioridade)
  {
    atual = atual->proximo;
  }

  if (atual == NULL)
  {
    novo->proximo = NULL;
    novo->anterior = lista->fim;
    lista->fim->proximo = novo;
    lista->fim = novo;
  }
  else if (atual == lista->inicio)
  {
    novo->proximo = lista->inicio;
    novo->anterior = NULL;
    lista->inicio->anterior = novo;
    lista->inicio = novo;
  }
  else
  {
    novo->proximo = atual;
    novo->anterior = atual->anterior;
    atual->anterior->proximo = novo;
    atual->anterior = novo;
  }

  lista->quantidade++;
}

void removerTarefa(ListaTarefas *lista, int id)
{
  ListaTarefaNode *atual = lista->inicio;
  while (atual != NULL && atual->tarefa->id != id)
  {
    atual = atual->proximo;
  }

  if (atual == NULL)
  {
    return;
  }

  if (atual == lista->inicio)
  {
    lista->inicio = atual->proximo;
  }
  else
  {
    atual->anterior->proximo = atual->proximo;
  }

  if (atual == lista->fim)
  {
    lista->fim = atual->anterior;
  }
  else
  {
    atual->proximo->anterior = atual->anterior;
  }

  free(atual);
  lista->quantidade--;
}

void concluirTarefa(ListaTarefas *lista, Concluidas *concluidas, int id)
{
  ListaTarefaNode *atual = lista->inicio;
  while (atual != NULL && atual->tarefa->id != id)
  {
    atual = atual->proximo;
  }

  if (atual == NULL)
  {
    return;
  }

  adicionarConcluida(concluidas, atual->tarefa);
  removerTarefa(lista, id);
}

void exibirListaTarefas(ListaTarefas *lista)
{
  int i = 0;
  ListaTarefaNode *atual = lista->inicio;
  printf("\n------ Lista de Tarefas ------\n");
  if (atual == NULL)
  {
    printf("Nenhuma tarefa cadastrada!\n");
    printf("------------------------------\n");
    return;
  }
  while (atual != NULL)
  {
    printf("------ Tarefa %d ------\n", ++i);
    printf("ID: %d\n", atual->tarefa->id);
    printf("Nome: %s\n", atual->tarefa->nome);
    printf("Descrição: %s\n", atual->tarefa->descricao);
    printf("Criação: %d/%d/%d\n", atual->tarefa->criacao.dia, atual->tarefa->criacao.mes, atual->tarefa->criacao.ano);
    printf("Vencimento: %d/%d/%d\n", atual->tarefa->vencimento.dia, atual->tarefa->vencimento.mes, atual->tarefa->vencimento.ano);
    printf("Prioridade: %d\n", atual->tarefa->prioridade);
    printf("------------------------\n");
    atual = atual->proximo;
  }
}