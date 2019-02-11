#include <iostream>

using namespace std;

void wypisz(int tab[], int n){
	for(int i = 0; i < n; i++)
		cout << tab[i] << " ";
		cout << endl;
}

void swap(int t[], int a, int b){
	int tmp = t[a];
	t[a] = t[b];
	t[b] = tmp;
}
int partition(int tab[], int p, int r){
	int x = tab[r];
	int j = p-1;
	for(int i = p; i < r; i++)
		if(tab[i] <= x){
			j++;
			swap(tab,i,j);
		}
	swap(tab,j+1,r);
	return j+1;	
}

void quickSort(int tab[], int p, int r){
	if(p < r){
		int q = partition(tab,p,r);
		quickSort(tab,p,q-1);
		quickSort(tab,q+1,r);
	}
}
int main(){
	
	int n;
	cin >> n;
	
	int *tab = new int[n];
	
	for(int i = 0; i < n; i++)
		cin >> tab[i];
		
	quickSort(tab,0, n-1);
	wypisz(tab,n);
		
	delete [] tab;
	return 0;
}
