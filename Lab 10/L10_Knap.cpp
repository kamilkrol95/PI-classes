#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

struct Item {
    double value, weight;
    double ratio;
};

struct Knapsack {
    Item* items;
    int n_elems;
    double capacity;
};

bool operator< (Item a, Item b){
    if(a.ratio < b.ratio) return true;
    else return false;
}

void printQueue(priority_queue <Item> Q){
    while(!Q.empty()){
        Item tmp = Q.top();
        Q.pop();
        printf("%.0f %.0f, RATIO: %.2f\n", tmp.value,tmp.weight,tmp.ratio);
    }
}

double max_profit(Knapsack knapsack) {
    double tmpValue = 0;
    double tmpWeight = 0;
    priority_queue <Item> Q;
    for(int i = 0; i < knapsack.n_elems; i++){
        knapsack.items[i].ratio = knapsack.items[i].value/knapsack.items[i].weight;
        Q.push(knapsack.items[i]);
    }
    printQueue(Q);

    while(!Q.empty()){
        Item item = Q.top();
        Q.pop();
        
        if(tmpWeight + item.weight > knapsack.capacity){
            double part = abs(knapsack.capacity - tmpWeight)/item.weight;
            tmpWeight += item.weight*part; 
            tmpValue += item.value*part;
            return tmpValue;
        }
        else{
            tmpValue += item.value;
            tmpWeight += item.weight;
        }
        if(tmpWeight > knapsack.capacity){
            tmpValue -= item.value;
            return tmpValue;
        }
    }
    return tmpValue;
}

int main() {
    int N, cap;
    cin >> N >> cap;
    Knapsack k;
    k.n_elems = N;
    k.capacity = cap;
    k.items = new Item[N];
    for (int i=0; i<N; i++) {
        cin >> k.items[i].value >> k.items[i].weight;
    }
    printf("ver.3 \n");

    cout << max_profit(k);
    delete[] k.items;
}