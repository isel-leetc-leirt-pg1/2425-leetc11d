#include <stdio.h>

/**
 * função auxiliar para apresentar os elementos de um array
 */
void show_array(int vals[], int sz) {
    for(int i=0; i < sz; ++i) {
        printf("%d ", vals[i]);
    }
    printf("\n");
}

/**
 * esta função remove os elementos duplicados
 * do array vals, assumindo que o array está ordenado por
 * ordem crescente de valores
 */
int rm_sorted_dups(int vals[], int sz) {
    if (sz <= 0) return 0;
    int i =1, j =1, ref = vals[0];
    while (i < sz) {
        if (vals[i] != ref) {
            ref = vals[i];
            vals[j++] = vals[i];
        }
        i++;
    }
    return j;
}

/**
 * esta função remove os elementos duplicados
 * do array vals, sem assumir nenhuma ordenação
 * particular do array
 */
int rm_dups(int vals[], int sz) {
    if (sz <= 0) return 0;
    int i =1, j =1;
    while (i < sz) {
        int k = 0;
        while (k < i && vals[k] != vals[i]) k++;
        if (k == i) {
            vals[j++] = vals[i];
        }
        i++;
    }
    return j;
}



//teste
int main() {
    // teste para um array ordenado
    int vals1[] = { 2,2,3,5,5,7,9, 20, 22, 22};
    int sz1 = sizeof(vals1)/ sizeof(vals1[0]);
    int nsz1 = rm_sorted_dups(vals1, sz1);
    printf("new size1=%d\n", nsz1);
    show_array(vals1, nsz1);

    // teste para um array não ordenado
    int vals2[] = { 2,5, 2,7,3, 5,5,7,9, 3, 20, 22, 33, 33};
    int sz2 = sizeof(vals2)/ sizeof(vals2[0]);
    int nsz2 = rm_dups(vals2, sz2);
    printf("new size2=%d\n", nsz2);
    show_array(vals2, nsz2);
    
    return 0;
}
