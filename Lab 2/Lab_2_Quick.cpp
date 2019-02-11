#include <stdio.h>
#include <algorithm>
using namespace std;

void wypisz(int tab[], int n){
	for(int i = 0; i < n; i++)
		printf("%d ",tab[i]);
		printf("\n");
}
void swap(int tab[], int a, int b){
	int tmp = tab[a];
	tab[a] = tab[b];
	tab[b] = tmp;
}

int partition(int tab[], int left, int right) {
    int x = tab[right];
    int j = left - 1;
 
    for (int i=left; i<right; i++) {
        if (tab[i] <= x) {
            j++;
            swap(tab,j,i);
        }
    }
    swap(tab,j+1,right);
    return j+1;
}

void quickSort(int tab[], int left, int right) {
    if (left < right) {
    	int q = partition(tab,left,right);
      	quickSort(tab,left,q-1);
      	quickSort(tab,q+1,right);
    }
}

int main() {
  int Z;

  scanf("%d", &Z);

  int val;

	while (Z--) {

		int n;
		scanf("%d", &n);
    	int *tab = new int[n];
		
		for(int i=0; i<n; i++) {
			scanf("%d", &tab[i]);
		}
        
	    quickSort(tab, 0, n-1);
	    wypisz(tab,n);
	    
	    delete [] tab;
    }
}
