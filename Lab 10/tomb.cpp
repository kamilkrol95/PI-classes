#include <iostream>

using namespace std;

int how_many_ways(string map, int N) {
}

int main() {
    int N;
    cin >> N;
    string map;
    cin >> map;
    if (map.size() != N) {
        cout << "Incorrect map size" << endl;
        return -1;
    }
    cout << how_many_ways(map, N) << endl;
}