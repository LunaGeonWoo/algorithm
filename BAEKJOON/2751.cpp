#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0, input; i < n; i++)
    {
        cin >> input;
        q.push(input);
    }
    while (q.size())
    {
        cout << q.top() << '\n';
        q.pop();
    }
}