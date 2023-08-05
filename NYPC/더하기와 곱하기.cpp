#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Plus { int sum, profit; };

int pow2[20];

void init() {
    pow2[0] = 1;
    for(int i=1; i<20; i++) pow2[i] = pow2[i-1] << 1;
}

int32_t main() {
    init();
    vector<Plus> v = {{1,0}};
    int K;
    string X;
    cin >> K >> X;

    int onlyMult;
    if(X.find('1') == string::npos) {
        cout << 0;
        return 0;
    } else {
        for(int i=0; i<K; i++) {
            if(X[K-i-1] == '1') {
                onlyMult = K - i;
                break;
            }
        }
    }
    for(int i=0; i<K; i++) {
        if(X[K-i-1] == '1') v.back().profit++;
        else if(onlyMult < v.back().sum + pow2[i]) break;
        else v.push_back({v.back().sum + pow2[i], v.back().profit + 1});
    }
    int mini = onlyMult;
    for(auto k : v) mini = min(mini, K - k.profit + k.sum);
    cout << mini;
}