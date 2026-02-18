#include <stdio.h>
#include <time.h>

#define TAM1 100
#define TAM2 1000
#define TAM3 10000

// Definição da struct com typedef (ESSENCIAL no C)
typedef struct {
    double tempo_ms;
    long long comparacoes;
    long long movimentacoes;
} Resultado;


// Criar vetor em ordem decrescente
void criarVetorDecrescente(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i;
    }
}


// Bubble Sort
Resultado bubbleSort(int vetor[], int tamanho) {

    Resultado r;
    r.comparacoes = 0;
    r.movimentacoes = 0;

    clock_t inicio = clock();

    for (int i = 0; i < tamanho - 1; i++) {

        for (int j = 0; j < tamanho - i - 1; j++) {

            r.comparacoes++;

            if (vetor[j] > vetor[j + 1]) {

                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;

                r.movimentacoes++;
            }
        }
    }

    clock_t fim = clock();

    r.tempo_ms = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;

    return r;
}


// Selection Sort
Resultado selectionSort(int vetor[], int tamanho) {

    Resultado r;
    r.comparacoes = 0;
    r.movimentacoes = 0;

    clock_t inicio = clock();

    for (int i = 0; i < tamanho - 1; i++) {

        int min = i;

        for (int j = i + 1; j < tamanho; j++) {

            r.comparacoes++;

            if (vetor[j] < vetor[min]) {
                min = j;
            }
        }

        if (min != i) {

            int temp = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = temp;

            r.movimentacoes++;
        }
    }

    clock_t fim = clock();

    r.tempo_ms = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;

    return r;
}


// Teste Bubble
void testarBubble(int tamanho) {

    int vetor[tamanho];

    criarVetorDecrescente(vetor, tamanho);

    Resultado r = bubbleSort(vetor, tamanho);

    printf("Bubble Sort\t%d\t%.3f\t\t%lld\t\t%lld\n",
           tamanho,
           r.tempo_ms,
           r.comparacoes,
           r.movimentacoes);
}


// Teste Selection
void testarSelection(int tamanho) {

    int vetor[tamanho];

    criarVetorDecrescente(vetor, tamanho);

    Resultado r = selectionSort(vetor, tamanho);

    printf("Selection Sort\t%d\t%.3f\t\t%lld\t\t%lld\n",
           tamanho,
           r.tempo_ms,
           r.comparacoes,
           r.movimentacoes);
}


int main() {

    printf("Algoritmo\tTamanho\tTempo(ms)\tComparacoes\tMovimentacoes\n");
    printf("-----------------------------------------------------------------\n");

    testarBubble(TAM1);
    testarBubble(TAM2);
    testarBubble(TAM3);

    testarSelection(TAM1);
    testarSelection(TAM2);
    testarSelection(TAM3);


    /*
    CONCLUSÃO:

    Ambos os algoritmos possuem complexidade O(n²).

    O Selection Sort apresentou melhor desempenho geral,
    pois realiza menos movimentações que o Bubble Sort.

    O Bubble Sort realiza muitas trocas, o que aumenta
    o tempo de execução em vetores grandes.

    Portanto, o Selection Sort é mais eficiente neste cenário.
    */

    return 0;
}
