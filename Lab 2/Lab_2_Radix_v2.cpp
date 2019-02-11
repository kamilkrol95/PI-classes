#include <iostream>
#include <string>

using namespace std;

void wypisz(string tab[], int n){
	for(int i = 0; i < n; i++)
		cout << tab[i] << " ";
		cout << endl;
}

int digit(string number, int pos){
	return (int)(number[pos] - '0');
}
void sortByPosition(string tab[], int n, int pos){
	int k = 10;
	int *counters = new int[k];
	string *result = new string[n];
	
	for(int i = 0; i < k; i++) counters[i] = 0;
	for(int i = 0; i < n; i++) counters[digit(tab[i],pos)]++;
	for(int i = 1; i < k; i++) counters[i] = counters[i] + counters[i-1];
	for(int i = n-1; i >= 0; i--){
		counters[digit(tab[i],pos)]--;
		result[counters[digit(tab[i],pos)]] = tab[i];
	}
	for(int i = 0; i < n; i++) tab[i] = result[i];
	delete [] counters;
	delete [] result;	
}

void radixSort(string tab[], int n, int length){
	for(int i = length-1; i >= 0; i--)
		sortByPosition(tab, n, i);
}

int main(){
	
	int n,k;
	cin >> n; // ilosc liczb
	cin >> k; // ilosc cyfr w liczbie
	
	string *tab = new string[n];
	
	for(int i = 0; i < n; i++){
		cin >> tab[i];
		if(tab[i].length() != k){
			 cout << "Number length: " << tab[i].length() << " Expected number length: " << k << endl;
			 i--;
		}
	}
	
	radixSort(tab,n,k);
	wypisz(tab,n);
	
	//cout << digit(tab[1], 2) << endl;
	delete [] tab;
	return 0;
}
