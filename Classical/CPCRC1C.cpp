/*
 ~ Author    : tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[18][2]; // dp[digits][tight];

ll cnt(string& num, int n, bool tight) {

    if (tight == 0)
        return (pow(10, n) + 0.1);

    if (n == 0)
        return 1;

    int maxDigit = 9;

    if (tight)
        maxDigit = num[num.length() - n] - '0';

    ll numCnt = 0;

    for (int dig = 0; dig <= maxDigit; ++dig) {
        numCnt += cnt(num, n - 1, tight & (dig == maxDigit));
    }

    return numCnt;
}

ll solve(string& num, int n, bool tight) {

    if (n == 0)
        return 0;

    if (dp[n][tight] != -1)
        return dp[n][tight];

    int maxDigit = 9;

    if (tight)
        maxDigit = num[num.length() - n] - '0';

    ll ans = 0;

    for (int dig = 0; dig <= maxDigit; ++dig) {
        ans += dig * cnt(num, n - 1, tight & (dig == maxDigit));
        ans += solve(num, n - 1, tight & (dig == maxDigit));
    }

    return dp[n][tight] = ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    // cin >> tc;

    while (tc) {

        ll l, r;
        cin >> l >> r;

        if (l == -1 && r == -1)
            break;

        if (l != 0)
            --l;

        string L = to_string(l);
        string R = to_string(r);

        memset(dp, -1, sizeof(dp));
        ll r_ans = solve(R, R.length(), 1);

        memset(dp, -1, sizeof(dp));
        ll l_ans = solve(L, L.length(), 1);

        cout << r_ans - l_ans << '\n';
    }

    return 0;
}
