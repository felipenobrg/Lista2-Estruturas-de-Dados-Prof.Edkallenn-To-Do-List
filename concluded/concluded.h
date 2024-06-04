#ifndef CONCLUIDAS_H
#define CONCLUIDAS_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../tarefa/tarefa.h"

typedef struct Concluidas
{
    int quantidade;
    struct PilhaTarefaNode *topo;
} Concluidas;

typedef struct PilhaTarefaNode
{
    Tarefa *tarefa;
    struct PilhaTarefaNode *proximo;
} PilhaTarefaNode;

Concluidas *criarPilhaConcluidas();
void adicionarConcluida(Concluidas *concluidas, Tarefa *tarefa);
void limparConcluidas(Concluidas *concluidas);
void exibirConcluidas(Concluidas *concluidas);

#endif