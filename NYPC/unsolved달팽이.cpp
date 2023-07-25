#include <bits/stdc++.h>

using namespace std;

int n;

int calc(int k)
{
    return int(round(sqrt(ceil(k / 8.0) * 2)));
}

pair<int, int> GetPos(int se)
{
    int p, x = 0, y = 0;
    x = y = p = calc(n * n - se);
    int n1 = p * 2;
    int s = p * (p + 1) * 4 + 1;

    int gap = s - (n * n - se);

    cout << gap / (n1 + 1) << ' ';
    switch (gap / (n1))
    {
    case 0:
        x -= gap % p;
        break;
    case 1:
        x = -x;
        y -= gap % n1;
        break;
    case 2:
        x += n1 - ((gap + 1) % n1);
        y = -y;
        break;
    case 3:
        y += n1 - (gap % n1);
        break;
    }
    return {x, y};
}

bool IsSquare(pair<int, int> p, pair<int, int> q)
{
    return abs(p.first - q.first) == abs(p.second - q.second);
}

int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;

    for (int s, e; t--;)
    {
        cin >> n >> s >> e;
        if (IsSquare(GetPos(s), GetPos(e)))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}