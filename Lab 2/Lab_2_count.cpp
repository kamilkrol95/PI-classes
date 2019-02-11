#include <stdio.h>
#include <algorithm>
using namespace std;

void wypisz(int t[], int N){
	for(int i = 0; i < N; i++)
		printf("%d ",t[i]);
	printf("\n");
}
void countSort(int tab[], int n, int k) {
    int *counters = new int[k];
    int *result = new int[n];
    for(int i=0; i<k; i++) counters[i] = 0;
    
    for(int i = 0; i < n; i++) counters[tab[i]]++;
    //wypisz(counters,k);
    for(int i=1; i<k; i++) counters[i] += counters[i-1];
    //wypisz(counters,k);
    for(int i=n-1; i>=0; i--) {
        counters[tab[i]]--;
        result[counters[tab[i]]] = tab[i];
    }
    
    for(int i = 0; i < n; i++)
    	tab[i]=result[i];
    
    delete [] counters;
    delete [] result;
}

int main() {
    int Z;

    scanf("%d", &Z);

    int val;

	while (Z--) {

		int n, k;
		scanf("%d", &n);
		scanf("%d", &k);
        int *tab = new int[n];
		for(int i=0; i<n; i++) {
			scanf("%d", &tab[i]);
            if (tab[i] >= k) {
                printf("Value too high, max: %d\n", k);
                return -1;
            }
		}

        countSort(tab, n, k);
        for(int i=0; i<n; i++) {
            printf("%d\n", tab[i]);
        }
        delete [] tab;
    }
}
