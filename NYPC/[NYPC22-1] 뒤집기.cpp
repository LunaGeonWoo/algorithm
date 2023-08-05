#include <bits/stdc++.h>
#define int int64_t
#define NN 1000003
using namespace std;

int a[NN];
int left_dp[NN], right_dp[NN], max_right[NN];
int n, ans = 0;

int32_t main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    left_dp[0] = a[0];
    for (int i = 1; i < n; i++)
        left_dp[i] = max(a[i], left_dp[i - 1] + a[i]);

    max_right[n - 1] = right_dp[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right_dp[i] = max(a[i], right_dp[i + 1] + a[i]);
        max_right[i] = max(max_right[i + 1], right_dp[i]);
    }
    ans = max_right[0];

    for (int i = 0; i < n - 2; i++)
    {
        ans = max(ans, left_dp[i] + max_right[i + 1]);
    }

    cout << ans;
}
