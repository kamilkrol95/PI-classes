#include <iostream>

using namespace std;

struct Node{
	string text;
	Node* next;
};

int length(string txt){
	int i = 0;
	while(txt[i] != '\0') i++;
	return i; 
}

unsigned long long  hashfunc(string txt, int n) {
	unsigned long long int hash = 0;
	for(int i = 0; i < length(txt); i++)
		hash ^= (int)txt[i] << ((i%8)*8);
		return hash%n;
}

void addNode(Node** hashtable, int n, string txt){
	unsigned long long int key = hashfunc(txt,n);
	hashtable[key] = new Node;
	hashtable[key]->text = txt;
	//hashtable[key]->next = new Node;
//	hashtable[key] = hashtable[key]->next;
	hashtable[key]->next = NULL; 
}

int main(){
	
	string txt = "ccccccam";
	unsigned long long int x = 0;
	//cout << length(txt) << endl;
	//cout << hashfunc(txt) << endl;	
	int n = 10;
	Node** hashtable = new Node*[n];
	for(int i = 0; i < n; i++)
		hashtable[i] = NULL;
		
	addNode(hashtable,n,txt);
	
	return 0;
}
