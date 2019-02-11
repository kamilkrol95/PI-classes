#include <stdio.h>

int n;

int* my_first_sort(int tab[]) {
    
    for(int i = 1; i < n; i++){
        int j = i-1;
        int tmp = tab[i];
        
        while(tmp < tab[j] && j >= 0){
            tab[j+1] = tab[j];
            j--;
        }
        tab[j+1] = tmp;
    }
    
    return tab;    
}

int main() {
    
    scanf("%d", &n);
    
    int *tab = NULL;
    tab = new int[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &tab[i]);     
    }
    
    int *res = my_first_sort(tab);
    
    for (int i = 0; i < n; i++) {
        printf("%d\n", res[i]);     
    }

    delete[] tab;    
}
