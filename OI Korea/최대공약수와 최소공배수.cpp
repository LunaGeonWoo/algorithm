#include <bits/stdc++.h>

#define LL long long

using namespace std;

LL gcd(LL a, LL b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

LL lcm(LL a, LL b)
{
    return a * b / gcd(a, b);
}

int main()
{
    LL a, b;
    cin >> a >> b;
    cout << gcd(a, b) << ' ' << lcm(a, b);
    return 0;
}