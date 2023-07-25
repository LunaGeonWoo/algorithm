#include <bits/stdc++.h>
#define int int64_t
#define NN 200002
using namespace std;

int ans = 0;

struct AXIS
{
private:
    map<int, int> M, Sum;
    vector<pair<int, int>> SE;

public:
    void SetM(int k, int v) { M[k] = v; }
    void SetSE(int p, int q) { SE.push_back({p, q}); }

    void Solve()
    {
        M[-1e9] = 0;
        int s = 0;
        for (auto p : M)
        {
            s += p.second;
            Sum[p.first] = s;
        }

        for (auto p : SE)
        {
            auto it1 = Sum.upper_bound(p.first);
            auto it2 = Sum.upper_bound(p.second);
            ans += (--it2)->second - (--it1)->second;
        }
    }
};

map<int, AXIS> X, Y;

void getItems(int d, int v)
{
    static int x = 1, y = 1;
    switch (d)
    {
    case 0:
        if (Y.find(y) != Y.end())
        {
            Y[y].SetSE(x, x + v);
        }
        x += v;
        break;
    case 1:
        if (X.find(x) != X.end())
        {
            X[x].SetSE(y, y + v);
        }
        y += v;
        break;
    case 2:
        if (Y.find(y) != Y.end())
        {
            Y[y].SetSE(x - v - 1, x - 1);
        }
        x -= v;
        break;
    case 3:
        if (X.find(x) != X.end())
        {
            X[x].SetSE(y - v - 1, y - 1);
        }
        y -= v;
        break;
    }
}

int32_t main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0, x, y, w; i < n; i++)
    {
        cin >> x >> y >> w;
        X[x].SetM(y, w);
        Y[y].SetM(x, w);
    }
    for (int i = 0, d, v; i < q; i++)
    {
        cin >> d >> v;
        getItems(d, v);
    }

    for (auto p : X)
        p.second.Solve();
    for (auto p : Y)
        p.second.Solve();

    cout << ans;
}