/*
 ~ Author    : @tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 100000000;

void solve() {

    vector<bool> isPrime(MAXN, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < MAXN; ++i) {

        if (isPrime[i]) {
            for (int j = i * i; j < MAXN; j += i)
                isPrime[j] = false;
        }
    }

	int cnt = 0;

	for (int i = 2; i < MAXN; ++i) {

        if (isPrime[i]) {
            if (++cnt % 100 == 1)
                cout << i << '\n';
        }
	}
}

int main() {

	FIO;

	int tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}
