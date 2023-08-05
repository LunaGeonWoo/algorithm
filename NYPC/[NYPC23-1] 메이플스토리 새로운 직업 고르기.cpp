#include <bits/stdc++.h>

using namespace std;

set<string> heros, myHeros;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K;
    string input;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> input;
        heros.insert(input);
    }
    cin >> K;
    for(int i=0; i<K; i++) {
        cin >> input;
        myHeros.insert(input);
    }
    for(auto hero : myHeros) {
        heros.erase(heros.find(hero));
    }
    cout << heros.size() << '\n';
    for(auto hero : heros) {
        cout << hero << '\n';
    }
}