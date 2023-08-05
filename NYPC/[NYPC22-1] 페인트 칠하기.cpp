#include <bits/stdc++.h>

using namespace std;

int N, M;
int grid[100][100];
stack<tuple<char, int, int>> ans;

int paintAll()
{
    int flag = 0, cnt = 0, color, line;
    for (int y = 0; y < N; y++)
    {
        map<int, int> m;
        for (int x = 0; x < M; x++)
        {
            if (grid[y][x])
                m[grid[y][x]]++;
        }
        if (m.size() == 1 && cnt < m.begin()->second)
        {
            flag = 1;
            line = y;
            color = m.begin()->first;
            cnt = m.begin()->second;
        }
    }

    for (int x = 0; x < M; x++)
    {
        map<int, int> m;
        for (int y = 0; y < N; y++)
        {
            if (grid[y][x])
                m[grid[y][x]]++;
        }
        if (m.size() == 1 && cnt < m.begin()->second)
        {
            flag = 2;
            line = x;
            color = m.begin()->first;
            cnt = m.begin()->second;
        }
    }

    if (flag == 1)
    {
        ans.push({'H', line + 1, color});
        for (int x = 0; x < M; x++)
            grid[line][x] = 0;
    }
    else if (flag == 2)
    {
        ans.push({'V', line + 1, color});
        for (int y = 0; y < M; y++)
            grid[y][line] = 0;
    }

    return flag;
}

int main()
{
    cin >> N >> M;

    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            cin >> grid[y][x];

    while (paintAll()) ;

    char a;
    int b, c;
    while (!ans.empty())
    {
        tie(a, b, c) = ans.top();
        ans.pop();
        cout << a << ' ' << b << ' ' << c << '\n';
    }
}