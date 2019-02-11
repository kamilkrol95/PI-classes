#include <iostream>

using namespace std;

struct Item {
    double value, weight;
};

struct Knapsack {
    Item* items;
    int n_elems;
    double capacity;
};

double max_profit(Knapsack knapsack) {

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

    cout << max_profit(k);
    delete[] k.items;
}