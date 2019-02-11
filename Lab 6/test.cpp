#include <iostream>

int main(){
	
	int n = 10;
	int* tab = new int[n];
	for(int i = 0; i < n; i++){
		tab[i] = i;
		printf("%d ",tab[i] );	
	} 

}
