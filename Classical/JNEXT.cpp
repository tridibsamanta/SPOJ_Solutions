/*
 ~ Author    : @tridib_2003
 ~ Title     : JNEXT - Just Next !!!
 ~ Link      : https://www.spoj.com/problems/JNEXT/
*/

#include<bits/stdc++.h>
using namespace std;

#define ll                  long long
#define PI                  3.1415926535897932384626
#define MOD                 1000000007
#define vi                  vector<int>
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(a, c)           for (int(a) = 0; (a) < (c); (a)++)
#define w(x)                int x; cin >> x; while(x--)
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

void solve() {

	int n;
	cin >> n;

	vi nums(n);

	FOR (i, n) {
		cin >> nums[i];
	}

	int idx = n - 2;

	for (; idx >= 0; --idx) {
		if (nums[idx] < nums[idx + 1]) {
			break;
		}
	}

	if (idx == -1) {
		cout << -1;
	}
	else {

		for (int i = n - 1; i > idx; --i) {
			if (nums[i] > nums[idx]) {
				swap(nums[i], nums[idx]);
				break;
			}
		}

		reverse(nums.begin() + ++idx, nums.end());

		FOR (i, n) {
			cout << nums[i];
		}
	}
}

int main() {

	FIO;

	int tc = 1;
	cin >> tc;
	while (tc--) {

		solve();

		cout << '\n';
	}

	return 0;
}
