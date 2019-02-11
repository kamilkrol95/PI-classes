#include <iostream>
#include <queue>

using namespace std;

struct Event {
    int start, end;
    bool used;
};

bool operator< (Event a, Event b){
    if(a.end > b.end) return true;
    else return false;
}

void printQueue(priority_queue <Event> Q){
    while(!Q.empty()){
        Event e = Q.top();
        Q.pop();
        printf("S: %d E: %d\n",e.start,e.end);
    }
}

void printTab(Event* tab, int N){
    for(int i = 0; i < N; i++)
         printf("%d S: %d E: %d\n",i,tab[i].start,tab[i].end);
}

void sort(Event* tab, int N){
    priority_queue <Event> Q;
     for(int i = 0; i < N; i++){
        Q.push(tab[i]);
    }
    // printQueue(Q);
    int i = 0;
    while(!Q.empty()){
        tab[i] = Q.top();
        Q.pop(); i++;
    }
}

int how_many_rooms (Event* events, int N) {
    int amount = 0;
    sort(events,N);
    printTab(events,N);

    bool flag = true;
    bool allUsed = true;
    while(flag){    
        amount++;    
        int j = 0;
        flag = false; allUsed = true;

        while(j < (N-1) && events[j].used) j++;
        
        events[j].used = true;    
        for(int z = 0; z < N; z++)
            if(!events[z].used) allUsed = false;
        if(allUsed) return amount;    
        
        for(int i = j+1; i < N; i++){
            if(events[j].end <= events[i].start && events[i].used == false){
                j = i;
                events[i].used = true;
            }
            else 
                flag = true;
        }
    }
    return amount;
}

int main() {
    int N;
    cin >> N;
    Event *e = new Event[N];
    for (int i=0; i<N; i++){
        cin >> e[i].start >> e[i].end;
        e[i].used = false;
    }

    cout << how_many_rooms(e, N) << endl;

    delete[] e;
}