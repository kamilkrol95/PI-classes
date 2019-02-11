#include <iostream>
#include <climits>
#include <utility>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void print_queue(priority_queue<int, vector<int>, less<int>> queue){
    while(!queue.empty()){
        printf("%d ",queue.top());
        queue.pop();
    }
}

int main(){

    priority_queue<int, vector<int>, less<int>> q;
    for(int n : {1,4,6,2,8,9,3,7,5,0})
        q.push(n);
    
    print_queue(q);
}