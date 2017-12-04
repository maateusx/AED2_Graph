#include "grafo.h"


int main()
{
    //DECLARACAO DAS VARIAVEIS
    TipoGrafo* Grafo;
    TipoVertice v1, v2;
    TipoPeso peso;
    int n, opt, opt2, idade, relacionamento, i, aux, id;
    char nome[30], sobre[50];

    FILE *fp = fopen("Registro_de_Atividade.txt","w"); //ABRE ARQUIVO DE LOG

    Usuario *usuarios = Cria_Usuario(); //CRIA VETOR COM DE USUARIOS

    //INICIO FIRST STEP
    do
    {
        printf("=====================================\n");
        printf("             BEM VINDO               \n");
        printf("=====================================\n");
        printf("=====================================\n");
        printf(" (1)  CRIAR NOVA REDE SOCIAL\n");
        printf(" (2)  CARREGAR REDE SOCIAL\n");
        printf(" (3)  SAIR\n");
        printf("=====================================\n\n");

        printf("Digite a opcao desejada: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1: ///CRIA GRAFO

            // printf("\nNUMERO MAXIMO DE USUARIOS: "); //NUMERO DE VERTICE
            // scanf("%d", &n);

            Grafo = Cria_grafo(TAM); //CRIA GRAFO

            system("cls");
            if(Grafo != NULL)    //VERIFICA SE O GRAFO FOI CRIADO
            {
                printf("\n    REDE CRIADA COM SUCESSO!\n\n");
                fputs("CRIOU UMA NOVA REDE\n", fp);
            }
            else
            {
                printf("\n    ERRO NA CRIACAO DA REDE\n");
                fputs("ERRO NA CRIACAO DE UMA NOVA REDE\n", fp);
                exit(0);
            }
            break;

        case 2: //INFORMAOAO DE COMO USAR
            usuarios = importaDadosUsuario(usuarios);
            Grafo = importaDadosGrafo(usuarios);
            fputs("IMPORTOU UM REDE JA EXISTENTE\n", fp);
            break;

        case 3:
            printf("\n\n VOLTE SEMPRE!\n\n");
            exit(0);
            break;

        default: ///OPCAO INVALIDA
            fputs("DIGITOU UM OPCAO INVALIDA\n", fp);
            printf("Opcao Invalida!");
            break;
        }
    }
    while(opt!=1 && opt!=2);
    // FIM FIRST STEP

    // INICIO DA REDE SOCIAL
    do
    {

        printf("\n================================");
        printf("\n         MENU PRINCIPAL");
        printf("\n================================");
        printf("\n(1) CRIAR NOVO USUARIO");
        printf("\n(2) DELETAR USUARIO");
        printf("\n(3) ACESSAR USUARIO");
        printf("\n(4) IMPRIMIR USUARIOS");
        printf("\n(5) IMPRIMIR TODOS");
        printf("\n(6) EXPORTAR DADOS");
        printf("\n(7) IMPRIMIR TODAS ARESTAS");
        printf("\n(0) SAIR");
        printf("\n================================");

        printf("\nDIGITE UMA OPCAO: ");
        scanf("%d", &opt);

        printf("================================");

        system("cls"); //limpa tela

        printf("\n================================");
        printf("\nDIGITE UMA OPCAO: %d", opt);
        printf("\n================================\n");

        switch (opt)
        {
        case 1:

            if(cheioUsuario(usuarios)!=1)
            {
                fputs("CRIOU UM NOVO USUARIO\n", fp);
                printf("\n================================");
                printf("\n           NOVO USUARIO         ");
                printf("\n================================\n");

                printf("NOME: ");
                fflush(stdin);
                gets(nome);

                printf("\nDIGITE SUA IDADE: ");
                scanf("%d", &idade);

                printf("\nRELACIONAMENTO\n");
                printf(" (1) SOLTEIRO \n (2) NAMORANDO\n (3) CASADO\n (4) NAO INFORMADO\n\n");
                printf("DIGITE APENAS O NUMERO: ");
                scanf("%d", &relacionamento);

                printf("\nFALA UM POUCO MAIS SOBRE VOCE: ");
                fflush(stdin);
                gets(sobre);
                usuarios = InsereUsuario(usuarios, nome, idade, relacionamento, sobre);
                system("cls"); //limpa tela
                printf("\nUSUARIO INSERIDO COM SUCESSO!");
            }
            else
            {
                fputs("REDE CHEIA, ERRO NA CRIACAO DE NOVO USUARIO\n", fp);
                printf("\nREDE CHEIA!\nNUMERO MAXIMO DE USUARIOS ATINGIDOS\n");
            }
            break;

        case 2:
            if(vazioUsuario(usuarios)==0)
            {
                fputs("REMOVOU USUARIO\n", fp);
                printf("\nDIGITE A ID DO USUARIO QUE DESEJA DELETAR: ");
                scanf("%d", &aux);
                usuarios = removeUsuario(usuarios, aux);
            }
            else
                fputs("REDE VAZIA, ERRO NA REMOCAO\n", fp);
            printf("\nNAO HA NENHUM USUARIO PARA REMOVER!");
            break;

        case 3: ///INICIO MENU USUARIO

            printf("DIGITE ID DO USUARIO: ");
            scanf("%d", &id);

            if(verficaUsuario(usuarios, id) == 1)
            {
                fputs("ACESSOU CONTA DE USUARIO\n", fp);
                do
                {
                    printf("\n================================");
                    printf("\n        MENU DO USUARIO");
                    printf("\n================================");
                    printf("\n (1) IMPRIMIR MEUS DADOS");
                    printf("\n (2) SEGUIR USUARIO"); //INSERIR ARESTA
                    printf("\n (3) DESEGUIR USUARIO"); //REMOVER ARESTA
                    printf("\n (4) REMOVER SEGUIDOR");
                    printf("\n (5) IMPRIMIR MEUS SEGUIDORES");
                    printf("\n (6) IMPRIMIR QUEM EU SIGO");
                    //printf("\n (7) MOSTRAR LISTA DE ADJACENTES");
                    printf("\n (7) VERIFICAR SE USUARIO ME SEGUE");
                    printf("\n (8) VERIFICAR SE SIGO USUARIO");
                    printf("\n (0) VOLTAR");
                    printf("\n================================");
                    printf("\nDIGITE UMA OPCAO: ");
                    scanf("%d", &opt2);
                    printf("================================");
                    system("cls"); //limpa tela
                    switch(opt2)
                    {
                    case 1:
                        mostraUsuario(usuarios, id);
                        fputs("MOSTROU DADOS DO USUARIO\n", fp);
                        break;
                    case 2: //SEGUIR USUARIO - INSERIR ARESTA

                        printf("\nDIGITE ID DO USUARIO QUE DESEJA SEGUIR: "); //vertice 2
                        scanf("%d", &v2);

                        if(InsereAresta(Grafo, id, v2, 1) == 1)
                        {
                            printf("\nUSUARIO SEGUIDO COM SUCESSO!");
                            fputs("SEGUIU UM NOVO USUARIO\n", fp);
                        }
                        else
                        {
                            printf("\nERRO AO SEGUIR USUARIO.");
                            fputs("ERRO AO SEGUIR UM NOVO USUARIO\n", fp);
                        }
                        break;

                    case 3: //DESEGUIR USUARIO - REMOVER ARESTA
                        printf("\nDIGITE ID DO USUARIO QUE DESEJA DESEGUIR: ");
                        scanf("%d", &v2);

                        if(RetiraAresta(Grafo, id, v2) == 1)
                        {
                            printf("\nDESEGUIDO COM SUCESSO!");
                            fputs("DESEGUIU UM USUARIO\n", fp);
                        }
                        else
                        {
                            printf("\nVOCE NAO SEGUE ESSE USUARIO.");
                            fputs("ERRO AO DESEGUIR UM USUARIO\n", fp);
                        }
                        break;

                    case 4: //REMOVER SEGUIDOR - REMOVER ARESTA
                        printf("\nDIGITE ID DO USUARIO REMOVER: ");
                        scanf("%d", &v2);

                        if(RetiraAresta(Grafo, v2, id) == 1)
                        {
                            printf("\nREMOVIDO COM SUCESSO!");
                            fputs("REMOVEU UM SEGUIDOR\n", fp);
                        }
                        else
                        {
                            printf("\nUSUARIO NAO SEGUE VOCE.");
                            fputs("ERRO AO REMOVER SEGUIDOR\n", fp);
                        }
                        break;

                    case 5: //MOSTRA SEGUIDORES - MOSTRAR LISTA DE ADJACENTES
                        //printf("\nDIGITE ID DO USUARIO: ");
                        //scanf("%d", &v1);

                        MostraListaSeguidores(Grafo, id);
                        fputs("IMPRIMIU SEUS SEGUIDORES\n", fp);

                        break;

                    case 6: //MOSTRA QUEM EU SIGO - MOSTRAR LISTA DE ADJACENTES
                        fputs("IMPRIMIU QUEM SEGUE\n", fp);
                        MostraListaAdjacentes(Grafo, id);

                        break;

                    case 7: //VERIFICAR SE USUARIO SEGUE - VERIFICA SE ARESTA EXISTE
                        printf("\nDIGITE ID PARA VERIFICAR: ");
                        scanf("%d", &v2);

                        if(ExisteAresta(Grafo, v2, id) == 1)
                        {
                            printf("\nUSUARIO SEGUE VOCE!");
                            fputs("VERIFICO SE USUARIO SEGUE VOCE, E OBTEVE SUCESSO\n", fp);
                        }
                        else
                        {
                            printf("\nUSUARIO NAO SEGUE VOCE.");
                            fputs("VERIFICO SE USUARIO SEGUE VOCE, E OBTEVE FRACASSO\n", fp);
                        }
                        break;

                    case 8: //VERIFICAR SE SIGO USUARIO - VERIFICA SE ARESTA EXISTE
                        printf("\nDIGITE ID PARA VERIFICAR: ");
                        scanf("%d", &v2);

                        if(ExisteAresta(Grafo, id, v2) == 1)
                        {
                            printf("\nVOCE SEGUE ESSE USUARIO!");
                            fputs("VERIFICO SE VOCE SEGUE USUARIO, E OBTEVE SUCESSO\n", fp);
                        }
                        else
                        {
                            fputs("VERIFICO SE VOCE SEGUE USUARIO, E OBTEVE FRACASSO\n", fp);
                            printf("\nVOCE NAO SEGUE ESSE USUARIO.");
                        }
                        break;

                    case 0:
                        fputs("VOLTOU PARA MENU PRINICIPAL\n", fp);
                        break;

                    default:
                        printf("\nOPERACAO INVALIDA!");
                        fputs("DIGITOU OPCAO INVALIDA\n", fp);
                        break;
                    }

                }
                while(opt2!=0);
            }
            else
                printf("\nUSUARIO NAO ENCONTRADO!");
            break; ///FIM MENU USUARIO

        case 4: //MOSTRAR USUARIO
            printf("\nDIGITE ID DO USUARIO: ");
            scanf("%d", &aux);
            mostraUsuario(usuarios, aux);
            fputs("MOSTROU DADOS DE USUARIO\n", fp);
            break;

        case 5:
            fputs("MOSTROU TODOS DADOS OS USUARIOS\n", fp);
            mostraTodosUsuario(usuarios);
            break;

        case 6:
            exportaDados(usuarios, Grafo);
            fputs("EXPORTOU DADOS DA REDE\n", fp);
            printf("\nDADOS EXPORTATOS COM SUCESSO");
            break;

        case 7:
             MostraGrafo(Grafo);
            break;

        case 0:
            fputs("SAIU DA APLICACAO\n", fp);
            break;

        default:
            printf("Opcao Invalida!");
            fputs("DIGITOU UMA OPCAO INVALIDA\n", fp);
            break;

        }

    }
    while(opt != 0);
//FIM DA REDE SOCIAL

//LiberaGrafo(Grafo); ///LIBERAR GRAFO nao ta pegando

    fclose(fp);

    return 0;

}
