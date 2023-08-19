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
void quicksort(int x[], int lb, int ub);
void partition(int x[], int lb, int ub, int *j);
void busca_sequencial(int file[], int inicio, int final, int key);


int main()
{       
    struct generator index[21];
    int *vetor = (int *)malloc(TAM * sizeof(int));


    load_file(vetor,TAM);
    //print_file(vetor,TAM);
    quicksort(vetor,0, TAM - 1);
    //print_file(vetor,TAM);
    

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
        for (int i = 1; i < INDEX && !achou; i++)
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
    while (inicio < final && file[inicio] < key)
    {
        inicio++;
    }
    if (inicio < final && file[inicio] == key)
    {
        printf("chave encontrada na posicao %d.\n\n",inicio);
    }

    else{
        printf("chave nao existe.\n\n");
    }
    
    
}

void load_file(int array[], int size){
    srand( (unsigned) time(NULL) );

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 1000000;
    }
}

void print_file(int array[], int size){
    for(int i = 0; i != size; i += 1){
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

void quicksort(int x[], int lb, int ub){

    int j = -1;

    if(lb >= ub)
        return;                     /* Vetor está classificado */

    partition(x, lb, ub, &j);       /* Particiona os elementos do subvetor
                                     * de modo que um dos elementos seja alocado
                                     * em sua posição correta. A variável j é a
                                     * posição onde este elemento foi alocada
                                     */

    quicksort(x, lb, j-1);          /* Classifica de forma recursiva o subvetor
                                     * entre a posição lb e j-1
                                     */

    quicksort(x, j+1, ub);          /* Classifica de forma recursiva o subvetor
                                     * entre a posição j+1 e ub
                                     */

}


void partition(int x[], int lb, int ub, int *j){

    int a, down, up, temp;
    
    /*
     * a é o elemento cuja posição 
     * final é procurada (pivô)
     */
    a = x[lb];

    /*
     * Inicialização dos ponteiros
     */
    up = ub;
    down = lb;

    while(down < up){
        while(x[down] <= a && down < ub){
            /*
             * Sobe no vetor
             */
            down++;
        }
        while(x[up] > a){
            /*
             * Desce no vetor
             */
            up--;
        }
        if(down < up){
            temp = x[down];
            x[down] = x[up];
            x[up] = temp;
        }
    }
    x[lb] = x[up];
    x[up] = a;
    *j = up;
}

