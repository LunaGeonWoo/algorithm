#include <bits/stdc++.h>

using namespace std;

queue<pair<int, int>> q;
int num = 0;

void hanoi(int n, int from, int by, int to)
{
    if (n == 1)
    {
        num++;
        q.push(make_pair(from, to));
        return;
    }
    hanoi(n - 1, from, to, by);
    hanoi(1, from, by, to);
    hanoi(n - 1, by, from, to);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    hanoi(n, 1, 2, 3);
    cout << num << '\n';
    while (q.size())
    {
        cout << q.front().first << ' ' << q.front().second << '\n';
        q.pop();
    }
}