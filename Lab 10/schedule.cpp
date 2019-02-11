#include <iostream>

using namespace std;

struct Event {
    int start, end;
};

int how_many_rooms (Event* events, int N) {
    // put your code here
}

int main() {
    int N;
    cin >> N;
    Event e[N];
    for (int i=0; i<N; i++) cin >> e[i].start >> e[i].end;

    cout << how_many_rooms(e, N) << endl;
}