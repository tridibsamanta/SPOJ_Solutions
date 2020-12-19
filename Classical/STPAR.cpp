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

void solve(int n) {

	vi trucks(n);

	FOR (i, n) {
		cin >> trucks[i];
	}

	stack<int> s;
	int curr = 1;

	FOR (i, n) {
		if (trucks[i] == curr) {
			++curr;

			while (!s.empty() && s.top() == curr) {
				s.pop();
				++curr;
			}
		}
		else {
			s.push(trucks[i]);
		}
	}

	if (curr == n + 1)
		cout << "yes";
	else
		cout << "no";
}

int main() {

	FIO;

	int n = 1;

	while (n != 0) {

		cin >> n;

		if (n == 0)
			break;

		solve(n);

		cout << '\n';
	}

	return 0;
}
