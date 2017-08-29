#include <stdio.h>
//#include <conio.h>  // getche
#include <stdlib.h> // exit
#include <string.h> // strcmp
#include <locale.h> // setlocale
//#include <ctype.h>  // toupper


#define N_MAX   20      // n�mero m�ximo de registros na lista


/***********************************************/
/* Defini��o dos Registros                     */
/***********************************************/
typedef struct {       // registro para uma pessoa
    int  codigo;
    char nome[ 30 ];
    char cpf[ 11 ];
    char endereco[40];
    char email[40];
} NODO;

typedef struct {
    NODO info[N_MAX];  // lista de N_MAX registros
    int  f;            // n�mero de registro(s) ocupado(s) na lista
} LISTASEQ;



/***********************************************/
/* Defini��o das Fun��es                       */
/***********************************************/
void entrada_dados   ( NODO *aux );       // leitura dos dados de entrada
void imprime_lista   ( LISTASEQ lista );  // visualiza��o da lista em tela
void cria_lista      ( int *fim );        // inicializa lista com tamanho 0
void inclui_fim      ( LISTASEQ *lista ); // inclui um novo registro no final da lista
void inclui_inicio   ( LISTASEQ *lista ); // inclui um novo registro no in�cio da lista
int  procura_nodo    ( int cod, LISTASEQ lista ); // procura por um c�digo na lista
void inclui_antes    ( LISTASEQ *lista ); // inclui um novo registro antes de um c�digo de refer�ncia
void inclui_depois   ( LISTASEQ *lista ); // inclui um novo registro depois de um c�digo de refer�ncia
void exclui_nodo     ( LISTASEQ *lista ); // exclui um regitro por c�digo
void ordena_lista    ( LISTASEQ *lista ); // ordena por c�digo - ordem crescente
void altera_nodo     ( LISTASEQ *lista ); // altera um regitro a partir de um c�digo de refer�ncia
void inclui_ordenado ( LISTASEQ *lista ); // inlcui em ordem crescente de c�digo
void busca_binaria   ( LISTASEQ lista );  // realiza busca bin�rios por c�digo
void exclui_repetidos( LISTASEQ *lista ); // verifica c�digos repetidos e exclui


/***********************************************/
/* Programa Principal                          */
/***********************************************/
int main( void )
{
    int op;           // op��o do menu
    LISTASEQ lista;   // vari�vel do tipo lista sequencial = vetor de registros
    setlocale(LC_ALL, "Portuguese");
    
    while( 1 ){
        printf( "\n /-------------------------------------------------------/" );
        printf( "\n Programa registro de pessoas - Menu                      " );
        printf( "\n [1] Cria lista                                           " );
        printf( "\n [2] Inclui registro no final da lista                    " );
        printf( "\n [3] Inclui registro no in�cio da lista                   " );
        printf( "\n [4] Inclui registro antes de um c�digo de refer�ncia     " );
        printf( "\n [5] Inclui registro depois de um c�digo de refer�ncia    " );
        printf( "\n [6] Exclui registro                                      " );
        printf( "\n [7] Ordena lista                                         " );
        printf( "\n [8] Altera registro                                      " );
        printf( "\n [9] Inclui ordenado por c�digo                           " );
        printf( "\n [10] Busca bin�ria por c�digo                            " );
        printf( "\n [11] Exclui repetidos                                    " );
        printf( "\n [12] Imprime lista                                       " );
        printf( "\n [0] Para sair do programa                                " );
        printf( "\n /-------------------------------------------------------/" );
        printf( "\n Op��o: " );
        scanf("%i", &op);// tecla de op��o do menu
        
        switch( op ) {
            case 1:  // rotina cria lista
                cria_lista( &lista.f );
                break;
                
            case 2:  // rotina inclui registro no final da lista
                inclui_fim( &lista );
                break;
                
            case 3:  // rotina inclui registro no in�cio da lista
                inclui_inicio( &lista );
                break;
                
            case 4:  // rotina inclui registro antes de um c�digo
                inclui_antes( &lista );
                break;
                
            case 5:  // rotina inclui registro depois de um c�digo
                inclui_depois( &lista );
                break;
                
            case 6:  // rotina exclui registro conforme c�digo
                exclui_nodo( &lista );
                break;
                
            case 7: // rotina ordena lista
                ordena_lista( &lista );
                break;
                
            case 8: // rotina altera registro
                altera_nodo( &lista );
                break;
                
            case 9: // rotina iinclui ordenado na lista
                inclui_ordenado( &lista );
                break;
                
            case 10: // rotina busca bin�ria na lista
                busca_binaria( lista );
                break;
                
            case 11: // rotina exclui repetidos
                exclui_repetidos( &lista );
                break;
                
            case 12: // rotina imprime lista
                imprime_lista( lista );
                break;
                
            case 0: // t�rmino do programa
                exit( 1 );
                break;
                
            default :
                printf( "\n Digite uma op��o!" );
                break;
        } // switch( op )
        
        
        fflush( stdin ); // limpa buffer do teclado, funciona junto com entrada de dados
        getchar();     // parada na tela
        
        printf( "\n" );
    } // fim do while( 1 )
    
    return 0;
} // fim do programa principal



/************************************************
 * entrada_dados                                *
 * objetivo: rotina para ler dados              *
 * entrada : registro aux (auxiliar)            *
 * sa�da   : aux atualizado com dados           *
 ************************************************/
void entrada_dados( NODO *aux )
{
    printf( "\n\n Digite o c�digo: " );
    fflush( stdin );     // limpa buffer do teclado, funciona junto com entrada de dados
    scanf( "%d", &aux->codigo );
    
    printf( "\n Digite o nome: " );
    fflush( stdin );     // limpa buffer do teclado, funciona junto com entrada de dados
    gets(aux->nome);
    
    printf( "\n Digite o cpf: " );
    fflush( stdin );     // limpa buffer do teclado, funciona junto com entrada de dados
    strcpy(aux->cpf, "1111111111");
    printf( "%s", aux->cpf );
    
    printf( "\n Digite o endere�o: " );
    fflush( stdin );     // limpa buffer do teclado, funciona junto com entrada de dados
    strcpy(aux->endereco, "endereco");
    printf( "%s", aux->endereco);
    
    printf( "\n Digite o email: " );
    fflush( stdin );     // limpa buffer do teclado, funciona junto com entrada de dados
    strcpy(aux->email, "email");
    printf( "%s \n", aux->email );
}



/*************************************************
 * imprime_lista                                 *
 * objetivo: rotina para imprimir dados          *
 * entrada : lista                               *
 * sa�da   : nenhuma, apenas em tela             *
 *************************************************/
void imprime_lista( LISTASEQ lista )
{
    int i; // �ndice do laco
    
    if ( lista.f == 0 ) // lista vazia
        printf( "\n Lista vazia!" );
    
    for( i = 0 ; i < lista.f ; i++ ) {
        printf( "\n C�digo...: %d", lista.info[ i ].codigo );
        printf( "\n Nome.....: %s", lista.info[ i ].nome );
        //printf( "\n CPF......: %s", lista.info[ i ].cpf );
        //printf( "\n Endere�o.: %s", lista.info[ i ].endereco );
        //printf( "\n Email....: %s", lista.info[ i ].email );
    } // fim for( i = 0 ; i < lista.f ; i++ )
}



/************************************************
 * cria_lista                                   *
 * objetivo: rotina para inicializar a lista    *
 * entrada : fim da lista                       *
 * sa�da   : fim da lista atualizado, com 0     *
 ************************************************/
void cria_lista( int *fim )
{
    *fim = 0;  // iniciliza lista, tamanho da lista = 0
    printf( "\n Lista criada!" );
}



/************************************************
 * inclui_fim                                   *
 * objetivo: rotina para inserir no fim da lista*
 * entrada : lista                              *
 * sa�da   : lista com novo elemento            *
 ************************************************/
void inclui_fim( LISTASEQ *lista )
{
    if(lista->f == N_MAX) {
        printf("\n Lista cheia!");
    } else {
        NODO newElement;
        entrada_dados(&newElement);
        
        lista->info[lista->f] = newElement;
        lista->f++;
        
        printf("\n Registro incluido no fim com sucesso!");
    }
}



/************************************************
 * inclui_in�cio                                *
 * objetivo: inserir no in�cio da lista         *
 * entrada : lista                              *
 * sa�da   : lista com novo elemento            *
 ************************************************/
void inclui_inicio( LISTASEQ *lista )
{
    int i;    // i = �ndice
    
    if( lista->f == N_MAX )                      // verifica se a lista esta cheia
        printf( "\n Lista cheia!" );
    else {
        NODO aux;                           // auxiliar para a entrada de dados
        entrada_dados( &aux );              // l� dados
        for( i = lista->f ; i > 0 ; i-- )   // desloca lista at� abrir esp�o no in�cio = posi��o 0
            lista->info[ i ] = lista->info[ i - 1 ];
        
        lista->info[ 0 ] = aux; // insere na lista //mencpy(&lista.info[lista.f], &aux, sizeof(NODO));
        lista->f++;             // incrementa o tamanho da lista
        printf( "\n Registro inclu�do no in�cio!" );
    } // fim if( lista->f == N_MAX )
}



/************************************************
 * procura_nodo                                 *
 * objetivo: achar posi��o a partir de um campo *
 * entrada : c�digo de refer�ncia e lista       *
 * sa�da   : posi��o f�sica da refer�ncia ou -1 *
 ************************************************/
int procura_nodo( int cod, LISTASEQ lista )
{
    int i= 0; // i = �ndice
    
    while((i < lista.f) && (cod != lista.info[ i ].codigo)) // anda pela lista at� o final ou ate encontrar c�digo desejado
        i++;
    if(cod == lista.info[ i ].codigo)
        return( i );  // posi��o f�sica do nodo de refer�ncia
    else
        return( -1 ); // valor n�o encontrado
}



/************************************************
 * inclui_antes                                 *
 * objetivo: inserir antes de um c�digo         *
 * entrada : lista                              *
 * sa�da   : lista com novo elemento            *
 ************************************************/
void inclui_antes( LISTASEQ *lista )
{
    if(lista->f > N_MAX) {
        printf("\n Lista cheia!");
    } else if(lista->f == 0) {
        printf("\n Lista vazia!");
    } else {
        int cod;
        int pf;
        
        printf("Informe o codigo do registro de referencia: ");
        fflush( stdin );
        scanf("%d", &cod);
        
        pf = procura_nodo(cod, *lista);
        
        if((pf >= 0) && (pf < lista->f) && (lista->info[pf].codigo == cod)) {
            NODO newElement;
            int i;
            
            entrada_dados(&newElement);
            
            for(i = lista->f; i >= pf; i--) {
                lista->info[i] = lista->info[i-1];
            }
            
            lista->info[pf] = newElement;
            lista->f++;
            
            printf("\n Registro inserido com sucesso!");
        }
    }
}



/************************************************
 * inclui_depois                                *
 * objetivo: inserir depois de um c�digo        *
 * entrada : lista                              *
 * sa�da   : lista com novo elemento            *
 ************************************************/
void inclui_depois( LISTASEQ *lista )
{
    if(lista->f > N_MAX) {
        printf("\n Lista cheia!");
    } else if(lista->f == 0) {
        printf("\n Lista vazia!");
    } else {
        int cod;
        int pf;
        
        printf("Informe o codigo do registro de referencia: ");
        fflush( stdin );
        scanf("%d", &cod);
        
        pf = procura_nodo(cod, *lista);
        
        if((pf >= 0) && (pf < lista->f) && (lista->info[pf].codigo == cod)) {
            NODO newElement;
            int i;
            
            entrada_dados(&newElement);
            
            for(i = lista->f; i > pf; i--) {
                lista->info[i] = lista->info[i-1];
            }
            
            lista->info[pf+1] = newElement;
            lista->f++;
            
            printf("\n Registro inserido com sucesso!");
        }
    }
}



/************************************************
 * exclui_nodo                                  *
 * objetivo: rotina para excluir registro       *
 * entrada : lista                              *
 * sa�da   : lista com um elemento removido     *
 ************************************************/
void exclui_nodo( LISTASEQ *lista )
{
    int i, cod, pf = 0; // i= indice; cod= c�digo de refer�ncia; pf= posi��o f�sica
    
    if( lista->f == 0 )    // verifica se a lista est� vazia
        printf( "\n Lista vazia!" );
    else {
        printf( "\n C�digo de refer�ncia: " );
        fflush( stdin );
        scanf( "%d", &cod );            // limpa buffer do teclado, funciona junto com entrada de dados
        pf = procura_nodo( cod, *lista );// procura c�digo de refer�ncia
        
        if ( ( pf >= 0 ) && ( pf < lista->f ) && ( lista->info[ pf ].codigo == cod ) ){ // verifica se a posicao e o c�digo s�o v�lidos
            for( i = pf; i < lista->f - 1 ; i++ )   // desloca a lista at� que fiquei cont�gua
                lista->info[ i ] = lista->info[ i + 1 ];
            
            lista->f--;                  // decrementa o tamanho da lista  //mencpy(&lista.info[lista.f], &aux, sizeof(NODO));
            printf( "\n Registro exclu�do!" );
        } // fim if (( pf >= 0 ) && ( pf < lista->f ) && ( lista->info[pf].codigo == cod ))
        else
            printf( "\n Nodo de refer�ncia n�o existe!" );
    } // fim if( lista->f == N_MAX )
}



/************************************************
 * ordena_lista                                  *
 * objetivo: rotina para ordenar lista por c�digo*
 * entrada : lista                               *
 * sa�da   : lista ordenada                      *
 ************************************************/
void ordena_lista( LISTASEQ *lista )
{
    int i, j; // i, j = �ndices
    
    if( lista->f == 0 ) // verifica se a lista est� vazia
        printf( "\n Lista vazia!" );
    else
        if( lista->f == 1 ) // verifica se a lista tem apenas um registro
            printf( "\n Lista com apenas um registro!" );
        else
        {
            NODO aux; // auxiliar para a troca de dados
            for( i = 0; i < lista->f-1; i++) // percorre a lista realizando a compara��o entre registros
                for( j = i + 1; j < lista->f; j++)
                    if( lista->info[ j ].codigo < lista->info[ i ].codigo )
                    {
                        aux = lista->info[ j ]; // realiza a troca
                        lista->info[ j ] = lista->info[ i ];
                        lista->info[ i ] = aux;
                    } // fim if( lista->info[ j ].codigo > lista->info[ i ].codigo )
            printf( "\n Lista ordenada!" );
        }
}



/************************************************
 * altera_nodo                                  *
 * objetivo: rotina para alterar registro       *
 * entrada : lista                              *
 * sa�da   : lista com um elemento alterado     *
 ************************************************/
void altera_nodo( LISTASEQ *lista )
{
    if(lista->f == 0) {
        printf("\n Lista vazia!");
    } else {
        int cod;
        int pf;
        
        printf("\n Informe o codigo do nodo a ser alterado: ");
        fflush( stdin );
        scanf("%d", &cod);
        
        pf = procura_nodo(cod, *lista);
        
        if((pf >= 0) && (pf < lista->f) && (lista->info[pf].codigo == cod)) {
            NODO changedElement;
            entrada_dados(&changedElement);
            
            lista->info[pf] = changedElement;
            
            printf("\n Registro alterado com sucesso!");
        } else {
            printf("\n Registro nao encontrado. Tente novamente.");
        }
    }
}



/************************************************
 * inclui_ordenado                              *
 * objetivo: rotina que inclui registro ordenado*
 * entrada : lista                              *
 * sa�da   : lista com novo elemento            *
 ************************************************/
void inclui_ordenado ( LISTASEQ *lista )
{
    printf("\n Implementar!");
}



/************************************************
 * busca_bin�ria                                *
 * objetivo: rotina busca bin�ria por c�digo    *
 * entrada : lista                              *
 * sa�da   : nenhuma                            *
 ***********************************************/
void busca_binaria( LISTASEQ lista )
{
    if( lista.f == 0 ) // verifica se a lista est� vazia
        printf( "\n Lista vazia!" );
    else {
        //ordena_lista(lista);    // ordena toda lista para garantir que ir� incluir o novo registro em ordem
        int cod, meio, inicio= 0, fim= lista.f-1; // iniciliza inicio e fim
        printf( "\n C�digo de refer�ncia: " );
        fflush( stdin );
        scanf( "%d", &cod );                      // limpa buffer do teclado, funciona junto com entrada de dados
        do{
            meio= (int)(inicio + fim)/2;       // encontra o �ndice do meio
            if( cod < lista.info[meio].codigo )// verifica se c�digo procurado � menor do que aquele que est� na lista no �ndice do meio
                fim= meio - 1;    // se c�digo menor, possiciona novo fim
            else
                inicio= meio + 1; // se c�digo maior, possiciona novo in�cio
        }while( inicio <= fim && lista.info[meio].codigo != cod); // enquanto n�o encontrar o c�digo, repete
        
        if( lista.info[meio].codigo == cod) // verifica se encontrou o c�digo
            printf("\n Nome: %s", lista.info[meio].nome);
        else
            printf("\n Registro n�o encontrado!");
    }
}



/************************************************
 * exclui_repetidos                             *
 * objetivo: rotina compara e eexclui registros *
 * entrada : lista                              *
 * sa�da   : nenhuma                            *
 ************************************************/
void exclui_repetidos ( LISTASEQ *lista )
{
    printf("\n Implementar!");
}
