#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int> pq;
    int q;
    cin >> q;
    while (q--)
    {
        int input;
        cin >> input;
        if (input == 1)
        {
            cin >> input;
            pq.push(input);
        }
        else
        {
            cout << pq.top() << '\n';
            pq.pop();
        }
    }
}