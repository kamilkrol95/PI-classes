#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <utility>

using namespace std;

void make(vector<pair<int, int>> &vec, int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        pair <int, int> newPair(i,rand()%100);
        vec.push_back(newPair);
    }    
}

void write(vector<pair<int, int>> vec, int n){
    vector<pair<int, int>>::iterator it;
    for(it = vec.begin(); it != vec.end(); it++)
        printf("%d: %d\n",get<0>(*it),get<1>(*it));
}

int main(){

    int n;
    cin >> n;
    printf("ver. 3\n");
    vector<pair<int, int>> v;
    make(v,n);
    // sort(v.begin(),v.end());
    write(v,n);
    
    return 0;
}