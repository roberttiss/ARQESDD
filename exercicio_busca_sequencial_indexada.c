#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
#define TAM 1000000
#define INDEX 21

struct generator
{
    int chave; 
    int posicao;
};

void load_file(int array[], int size);
void print_file(int array[], int size);
void busca_sequencial(int file[], int inicio, int final, int key);


int main()
{       
    struct generator index[21];
    int *vetor = (int *)malloc(TAM * sizeof(int));


    load_file(vetor,TAM);   

    int total = 0;
    int indexx = 0;

    while (total < TAM && indexx < INDEX)
    {
    index[indexx].chave = vetor[total];
    index[indexx].posicao = total;

    if (total == 0)
    {
        total += 49999; 
    }
    else
    {
        total += 50000; 
    }
    indexx++;
    }

    //for ( int i = 0; i != INDEX; i++)
    //{
        //printf("posicao[%d] = chave [%d]\n\n",index[i].posicao,index[i].chave);
    //}

    int key;
    printf("Digite a chave: \n");
    scanf("%d",&key);
    int inicio;
    int final;
    int achou = FALSE;
        for (int i = 1; i < INDEX && achou == FALSE; i++)
        {
            if (key <= index[i].chave)
            {
                busca_sequencial(vetor,index[i-1].posicao,index[i].posicao+1,key);
                achou = TRUE;
            }
        }
    
    free(vetor);    
    return 0;
}


void busca_sequencial(int file[], int inicio, int final, int key){
    while (inicio < final && file[inicio] < key) {
        inicio++;
    }

    if (inicio < final && file[inicio] == key) {
        printf("chave encontrada na posicao %d.\n\n", inicio);
    } else {
        printf("chave nao existe.\n\n");
    }
}


void load_file(int array[], int size){
    srand( (unsigned) time(NULL) );

    array[0] = rand() % 1000;
    for (int i = 1; i != size; i++)
    {
        array[i] = array[i-1] + ( rand() % 100 );
    }
}

void print_file(int array[], int size){
    for(int i = 0; i != size; i += 1){
        printf("%d ", array[i]);
    }
    printf("\n\n");
}


