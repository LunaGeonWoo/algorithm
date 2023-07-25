#include <bits/stdc++.h>
#define n 3
#define ll long long

using namespace std;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool canSolve(ll a1, ll a2, ll m1, ll m2)
{
    if (abs(a1 - a2) % gcd(m1, m2))
        return false;
    return true;
}

int main()
{
    ll a[n], m[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i] >> m[i];
    ll result[2] = {a[0], m[0]};
    for (ll i = 1; i < n; i++)
    {
        ll a1 = result[0], m1 = result[1], a2 = a[i], m2 = m[i];
        if (!canSolve(a1, a2, m1, m2))
        {
            cout << -1;
            return 0;
        }
        ll toMult = m1 / gcd(m1, m2), toLeft = (a2 - a1) / gcd(m1, m2), tempM = m2 / gcd(m1, m2);
        toLeft %= tempM;
        toLeft = toLeft < 0 ? toLeft + tempM : toLeft;
        // cout << toMult << "y = " << toLeft << " (mod " << tempM << ")\n";
        for (ll l = 0; l < tempM; l++)
        {
            if ((toMult * l) % tempM == toLeft)
            {
                result[0] = m1 * l + a1;
                result[1] = tempM * m1;
                // cout << "y = " << l << '\n'
                //      << a1 << ' ' << m1 << '\n'
                //      << a2 << ' ' << m2 << '\n';
                // cout << result[0] << ' ' << result[1] << "\n\n";
                break;
            }
        }
    }

    cout << result[0] << ' ' << result[1];
}