#include <bits/stdc++.h>
#define int int64_t
#define MOD 1000000007LL
using namespace std;

vector<int> mm[64];

vector<int> mulMatrix(vector<int> a, vector<int> b)
{
    vector<int> c(4);
    c[0] = (a[0] * b[0] + a[1] * b[2]) % MOD;
    c[1] = (a[0] * b[1] + a[1] * b[3]) % MOD;
    c[2] = (a[2] * b[0] + a[3] * b[2]) % MOD;
    c[3] = (a[2] * b[1] + a[3] * b[3]) % MOD;
    return c;
}

void Init(vector<int> a)
{
    mm[0] = a;
    for (int i = 1; i < 64; i++)
    {
        mm[i] = mulMatrix(mm[i - 1], mm[i - 1]);
    }
}

int32_t main()
{

    Init({1, 1, 1, 0});

    int n;
    cin >> n;

    vector<int> ans = {1, 0, 0, 1};
    for (int i = 0; n; i++, n >>= 1)
    {
        if (n & 1)
            ans = mulMatrix(ans, mm[i]);
    }

    cout << ans.front();
}