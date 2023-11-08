#include <iostream>
using namespace std;

void countSort(int vetor[], int n) {
    int count[11]; //armazena a contagem de cada elemento
    int saida[11]; //armazena o aray original apos a contagem
    int max = vetor[0]; //valor da posisao do array

    //encontar maior elemento no array
    for (int i=1; i<n; i++) {
        if (vetor[i] > max)
        max = vetor[i];
    }

    //iniciar todos os indices em 0
    for (int i=0; i<=max; i++) {
        count[i] = 0;
    }

    //armazena a contagem de cada elemento
    for (int i=0; i<n; i++) {
        count[vetor[i]]++;
    }

    //acumula a contagem de cada vetor
    for (int i=1; i<=max; i++) {
        count[i] += count[i-1];
    }

    //encontra o indice de cada elemento e os coloca no array de saida
    for (int i=n-1; i>=0; i--) {
        saida[count[vetor[i]]-1] = vetor[i];
        count[vetor[i]]--;
    }

    //copia os elementos ordenados e retorna para o array original
    for (int i=0; i<n; i++) {
        vetor[i] = saida[i];
    }
}


int main() {
    int vetor[] = {9,10,7,5,1,2,1,3,7,7};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    cout << "Vetor antes da ordenacao: " << endl;
    for (int i = 0; i < tamanho; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;

    cout << "Vetor apos a ordenacao: " << endl;
    countSort(vetor, tamanho);
    for (int i = 0; i < tamanho; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;

    return 0;
}