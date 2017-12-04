#include "grafo.h"

TipoGrafo* Cria_grafo(int NVertices)
{
    int i, k;
    TipoGrafo *Grafo ;

    if (NVertices <= 0)
        return NULL;

    Grafo = (TipoGrafo*) malloc(sizeof(TipoGrafo));

    if (Grafo == NULL)
        return NULL;

    Grafo->Mat = (TipoPeso **) malloc(NVertices*sizeof(TipoPeso*));

    if (Grafo->Mat == NULL)
    {
        free(Grafo);
        return NULL;
    }

    for(i=0; i<NVertices; i++)
    {
        Grafo->Mat[i] = (TipoPeso*) calloc(NVertices,sizeof(TipoPeso)); //aloca e preenche com zeros

        if (Grafo->Mat[i]  == NULL) // não conseguiu alocar a linha i da matriz
        {
            for (k=0; k<i; k++)
                free(Grafo->Mat[k]); //libera todas a linhas previamente alocadas

            free(Grafo) ;
            return NULL;
        }
    }

    Grafo->NumVertices = NVertices;
    Grafo->NumArestas = 0;

    return Grafo;
}

int InsereAresta(TipoGrafo *Grafo, TipoVertice v1, TipoVertice v2, TipoPeso peso)
{
    if (Grafo == NULL)
        return -1; //grafo nao existe

    if (Grafo->Mat[v1][v2] != 0 || peso == 0)
        return 0;  //ja existe aresta entre v1 e v2

    Grafo->Mat[v1][v2] = peso;
    Grafo->NumArestas ++;

    return 1;
}

int ExisteAresta(TipoGrafo *Grafo, TipoVertice v1, TipoVertice v2)
{
    if (Grafo == NULL)
        return -1;

    if( Grafo->Mat[v1][v2] == 0)
        return 0; //aresta nao existe ligando v1 e v2

    else return 1; //existe aresta ligando v1 e v2
}

int RetiraAresta(TipoGrafo *Grafo, TipoVertice  v1, TipoVertice v2)
{
    if (Grafo == NULL) // grafo nao existe
        return -1;

    if( Grafo->Mat[v1][v2] == 0) // aresta nao existe
        return 0;

    Grafo->Mat[v1][v2] = 0; //remove aresta
    Grafo->NumArestas--;

    return 1;
}

int ConsultaAresta(TipoGrafo *Grafo, TipoVertice v1, TipoVertice v2, TipoPeso* peso)
{
    if (Grafo == NULL)
        return -1;

    if ( Grafo->Mat[v1][v2] == 0)
        return 0;

    *peso = Grafo->Mat[v1][v2];

    return 1;
}

void MostraListaAdjacentes(TipoGrafo *Grafo, TipoVertice v)
{
    int i, cont =0 ;

    if (Grafo == NULL)
        printf("\nGRAFO NAO EXISTE");

    else
    {
        printf("\nESTOU SEGUIDO:");

        for (i=0; i<Grafo->NumVertices; i++)
            if (Grafo->Mat[v][i] != 0)
            {
                printf("%2d", i);
                cont = 1;
            }
        if (cont == 0)
            printf("\nVOCE AINDA NAO SEGUE NINGUEM");
    }
}

void MostraListaSeguidores(TipoGrafo *Grafo, TipoVertice v)
{
    int i, cont =0 ;

    if (Grafo == NULL)
        printf("\nGRAFO NAO EXSITE");

    else
    {
        printf("\nMEUS SEGUIDORES SAO:");

        for (i=0; i<Grafo->NumVertices; i++)
            if (Grafo->Mat[i][v] != 0)
            {
                printf("%2d ", i);
                cont = 1;
            }
        if (cont == 0)
            printf("\nVOCE NAO POSSUI SEGUIDORES", v);
    }
}

void MostraGrafo(TipoGrafo *Grafo)
{
    int i, j;

    if (Grafo == NULL || Grafo->NumArestas == 0)
        printf("\nGRAFO NAO EXISTE OU NAO POSSUI ARESTAS");

    else
        for (i=0; i<Grafo->NumVertices; i++)
        {
            printf("\nADJACENTES A [%d] ---- ", i);

            for (j=0; j < Grafo->NumVertices; j++)

                if (Grafo->Mat[i][j] != 0)
                    printf(" %d ",j);
        }
}

TipoGrafo* LiberaGrafo(TipoGrafo* Grafo )
{
    int i;

    if (Grafo == NULL)
        return NULL;

    for(i=0; i< Grafo->NumVertices; i++)
        free(Grafo->Mat[i]);

    free(Grafo->Mat);
    free(Grafo);

    Grafo = NULL;

    return Grafo;
}

Usuario* Cria_Usuario()
{
    int i;
    Usuario *vetor = malloc((TAM) * sizeof(Usuario));

    for(i=0; i<TAM; i++)
        vetor[i].id = -1;

    return vetor;
}

Usuario* InsereUsuario(Usuario *usuarios, char *nome, int idade, int relacionamento, char *sobre)
{
    int i=0;

    while(usuarios[i].id != -1)
        i++;

    usuarios[i].id = i;
    strcpy(usuarios[i].nome, nome);
    usuarios[i].idade = idade;
    usuarios[i].relacionamento = relacionamento;
    strcpy(usuarios[i].sobre, sobre);

    return usuarios;
}

Usuario* removeUsuario(Usuario *usuario, int id)
{
    int i;
    if(id >= 0 && id < TAM)
    {
        if(usuario[id].id != -1)
        {
            usuario[id].id = -1;
            printf("\nUSUARIO REMOVIDO COM SUCESSO!");
        }
        else
            printf("\nUSUARIO NAO ENCONTRADO!");
    }
    else
        printf("\nID INCORRETO!");

    return usuario;
}

int vazioUsuario(Usuario *usuarios)
{
    int i;

    for(i=0; i<TAM; i++)
    {
        if(usuarios[i].id != -1)
            return 0;
    }

    return 1;
}

int cheioUsuario(Usuario *usuarios)
{
    int i;

    for(i=0; i<TAM; i++)
    {
        if(usuarios[i].id == -1)
            return 0;
    }

    return 1;
}

void mostraUsuario(Usuario *usuarios,int id)
{

    if(TAM >= 0 && id < TAM)
    {
        if(usuarios[id].id!=-1)
        {
            printf("ID: %d\nNOME: %s\nIDADE: %d\nRELACIONAMENTO: ", id, usuarios[id].nome, usuarios[id].idade);
            if(usuarios[id].relacionamento == 1)
                printf("SOLTEIRO\n");
            else if(usuarios[id].relacionamento == 2)
                printf("NAMORANDO\n");
            else if(usuarios[id].relacionamento == 3)
                printf("CASADO\n");
            else
                printf("NAO INFORMADO\n");
        }
        else
            printf("USUARIO NAO EXSITE!\n");
    }
    else
        printf("ID INCORRETO\n");
}

void mostraTodosUsuario(Usuario *usuarios)
{
    int i;

    for(i=0; i<TAM; i++)
    {
        if(usuarios[i].id!=-1)
        {
            printf("2");
            printf("ID: %d\nNOME: %s\nIDADE: %d\nRELACIONAMENTO: ", i, usuarios[i].nome, usuarios[i].idade);
            if(usuarios[i].relacionamento == 1)
                printf("SOLTEIRO\n");
            else if(usuarios[i].relacionamento == 2)
                printf("NAMORANDO\n");
            else if(usuarios[i].relacionamento == 3)
                printf("CASADO\n");
            else
                printf("NAO INFORMADO\n");
            printf("SOBRE: %s\n", usuarios[i].sobre);
        }
        else
        {
            printf("ID: %d\nPOSICAO DISPONIVEL\n", i);
        }
        printf("================================\n");
    }
}

int verficaUsuario(Usuario *usuario, int id)
{
    int i;
    for(i=0; i<TAM; i++)
        if(id == i)
            return 1;
    return 0;
}

void exportaDados(Usuario *usuario, TipoGrafo* Grafo)
{
    int i, j;
    FILE *arq = fopen("dados.txt","w");

    for(i=0; i<TAM; i++)
    {
        fputc('[', arq);
        if(usuario[i].id==-1)
        {
            fprintf(arq, "(%d) - NULL", i);
        }
        else
        {
            fprintf(arq, "(%d),%s,%d,%d,%s", i, usuario[i].nome, usuario[i].idade, usuario[i].relacionamento, usuario[i].sobre);
        }
        fprintf(arq, "]\n");
    }

    fprintf(arq, "*");

    if (Grafo == NULL)//|| Grafo->NumArestas == 0
        fprintf(arq, "\nNULL"); //nao possui arestas
    else
        for (i=0; i<Grafo->NumVertices; i++)
        {
            fprintf(arq, "\n[%d]", i);

            for (j=0; j < Grafo->NumVertices; j++)

                if (Grafo->Mat[i][j] != 0)
                    fprintf(arq, "%d ", j);
        }

    fclose(arq);
}

Usuario* importaDadosUsuario(Usuario* usuario)
{
    char c, vet[250], sobre[50], nome[30];
    int i=0, j=0, k = 0, idade=0, rel=0, id=0, vig=0;
    FILE *arq = fopen("dados.txt", "r");

    fflush(stdin);

    while(c != '*')
    {
        c = ' ';
        i=0; j=0; k = 0; idade=0; rel=0; id=0; vig=0;

        while(c!='\n')
        {
            c = fgetc(arq);
            vet[k] = c;
            if(c == '*')
                break;
            k++;
        }


        for(i=0; i<k; i++)
        {
            if(vet[i]=='-' && vet[i+1]=='N' &&vet[i+2]=='U' && vet[i+3]=='L' && vet[i+4]=='L')
                break;
            else
            {
                if(vet[i] == ']')
                {
                    usuario = InsereUsuario(usuario, nome, idade, rel, sobre);
                    idade = vig = j = rel = 0;
                }
                else if(vet[i] == ',')
                {
                    vig++;
                    j = 0;
                }
                else if(vig == 0 && vet[i]>=48 && vet[i]<=57) //id
                    id = id*10 + vet[i]-48;
                else if(vig == 1) //nome
                {
                    nome[j] = vet[i];
                    j++;
                }
                else if(vig == 2) //idade
                    idade = idade*10 + vet[i]-48;
                else if(vig == 3) //relacionamento
                    rel = vet[i]-48;
                else if(vig == 4) //sobre
                {
                    sobre[j] = vet[i];
                    j++;
                }
            }
        }
    }

    fclose(arq);
    return usuario;
}

TipoGrafo* importaDadosGrafo(Usuario* usuario)
{
    TipoGrafo *Grafo = Cria_grafo(TAM);
    FILE *arq = fopen("dados.txt", "r");
    char vet[250];
    int i, id, k, vig, aux, id2;
    i = id = k = vig = id2 = 0;
    char c =' ';

    while(c!='*')
    {
        k = 0;
        c = ' ';
        while(c!='\n')
        {
            c = fgetc(arq);
            vet[k] = c;
            if(c == '*')
                break;
            k++;
        }
    }

    c = fgetc(arq);

    for(i=0; i<TAM-2; i++)
    {
        c = ' ';
        id=k=vig=0;

        while(c!='\n')
        {
            c = fgetc(arq);
            //printf("%c", c);
            vet[k] = c;
            if(vet[k] == ']')
                vig++;
            else if(vig!=0)
            {
                if(vet[k] != ' ')
                {
                    id = id*10 + vet[k]-48;
                    id2++;
                }
                else
                {
                    if(id2!=0){
                        if(verficaUsuario(usuario, i)==1)
                            InsereAresta(Grafo, i, id, 1);
                        id = id2 = 0;
                    }
                }
            }
            k++;
        }
        //MostraListaAdjacentes(Grafo, i);printf("\n");

    }

    fclose(arq);
    return Grafo;
}
