#include <bits/stdc++.h>

using namespace std;

long long n;

void compress(vector<long long> A)
{
    vector<long long> B = A;
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    for (long long i = 0; i < n; i++)
        cout << lower_bound(B.begin(), B.end(), A[i]) - B.begin() + 1 << ' ';
}

int main()
{
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++)
        cin >> v[i];
    compress(v);
}