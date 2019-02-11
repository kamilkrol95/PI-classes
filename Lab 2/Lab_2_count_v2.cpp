#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void wypisz(int tab[], int n){
	for(int i = 0; i < n; i++)
		cout << tab[i] << " ";
		cout << endl;
}

void countSort(int tab[], int n, int k){
	int *counters = new int[k];
	int *result = new int[n];
	
	for(int i = 0; i < k; i++) counters[i] = 0;
	for(int i = 0; i < n; i++) counters[tab[i]]++;
	for(int i = 1; i < k; i++) counters[i] = counters[i] + counters[i-1];
	for(int i = n-1; i >=0; i--){
		counters[tab[i]]--;
		result[counters[tab[i]]] = tab[i];
	}
	for(int i = 0; i < n; i++) tab[i] = result[i];
	
	delete [] counters;
	delete [] result;
}
int main(){
	
	int n, k;
	cin >> n;
	cin >> k;
	
	int *tab = new int[n];
	
	for(int i = 0; i < n; i++){
		cin >> tab[i];
		if(tab[i] < 0 || tab[i] >= k){
			cout << "Wartosc poza przedzialem!";
			i--;
		}	
	}	
	
	countSort(tab,n,k);
	wypisz(tab,n);
	
	delete [] tab;
	return 0;
}

