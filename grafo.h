#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAM 15

typedef int TipoPeso;
typedef int TipoVertice;

struct usuario
{
    int id; //vertice
    char nome[30];
    int idade;
    int relacionamento;
    char sobre[50];
};
typedef struct usuario Usuario;

struct grafo
{
    int NumVertices;
    int NumArestas;
    TipoPeso **Mat;
};
typedef  struct grafo TipoGrafo;

TipoGrafo* Cria_grafo(int NVertices);
int InsereAresta(TipoGrafo *Grafo, TipoVertice v1, TipoVertice v2, TipoPeso peso);
int ExisteAresta(TipoGrafo *Grafo, TipoVertice v1, TipoVertice v2);
int RetiraAresta(TipoGrafo *Grafo, TipoVertice  v1, TipoVertice v2);
int ConsultaAresta(TipoGrafo *Grafo, TipoVertice v1, TipoVertice v2, TipoPeso* peso);
void MostraListaAdjacentes(TipoGrafo *Grafo, TipoVertice v);
void MostraListaSeguidores(TipoGrafo *Grafo, TipoVertice v);
void MostraGrafo(TipoGrafo *Grafo);
TipoGrafo* LiberaGrafo(TipoGrafo* Grafo);

Usuario* Cria_Usuario();
Usuario* InsereUsuario(Usuario *usuarios, char *nome, int idade, int relacionamento, char *sobre);
Usuario* removeUsuario(Usuario *usuario, int id);
int vazioUsuario(Usuario *usuarios);
int cheioUsuario(Usuario *usuarios);
void mostraUsuario(Usuario *usuarios, int id);
void mostraTodosUsuario(Usuario *usuarios);
int verficaUsuario(Usuario *usuario, int id);

void exportaDados(Usuario *usuario, TipoGrafo* Grafo);
Usuario* importaDadosUsuario(Usuario* usuario);
TipoGrafo* importaDadosGrafo(Usuario* usuario);
