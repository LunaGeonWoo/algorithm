#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

vector<ull> primes;
ull q, bigest, a[100000], b[100000];

ull EvalGap(ull index)
{
    return upper_bound(primes.begin(), primes.end(), b[index]) - lower_bound(primes.begin(), primes.end(), a[index]);
}

void Eratos()
{
    vector<ull> check(bigest + 1);
    primes.push_back(2);
    for (ull i = 3; i <= bigest; i += 2)
    {
        if (!check[i])
        {
            primes.push_back(i);
            for (ull j = i * i; j <= bigest; j += i)
                check[j] = 1;
        }
    }
}

int main()
{
    cin >> q;
    for (ull i = 0; i < q; i++)
    {
        cin >> a[i] >> b[i];
        bigest = max(bigest, b[i]);
    }
    Eratos();
    for (ull i = 0; i < q; i++)
    {
        cout << EvalGap(i) << '\n';
    }
}
