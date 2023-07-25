#include <bits/stdc++.h>

using namespace std;

int numbers[2001];

int main()
{
    int n;
    cin >> n;
    for (int i = 0, input; i < n; i++)
    {
        cin >> input;
        numbers[input + 1000]++;
    }
    for (int i = 0; i < 2001; i++)
    {
        while (numbers[i])
        {
            cout << i - 1000 << '\n';
            numbers[i]--;
        }
    }
}