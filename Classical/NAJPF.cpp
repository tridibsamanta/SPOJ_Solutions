/*
 ~ Author    : @tridib_2003
 ~ Title     : NAJPF - Pattern Find
 ~ Link      : https://www.spoj.com/problems/NAJPF/
*/

#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000009
#define prime 101

vector<int> patternSearch(string text, string pattern) {

	int n = text.length();
	int m = pattern.length();

	vector<long long> prime_powers(max(n, m));
	prime_powers[0] = 1;

	for (int i = 1; i < (int)prime_powers.size(); ++i) {
		prime_powers[i] = (prime_powers[i - 1] * prime) % MOD;
	}

	vector<long long> hash_text(n + 1, 0);

	for (int i = 0; i < n; ++i) {
		hash_text[i + 1] = (hash_text[i] + (text[i] - 'a' + 1) * prime_powers[i]) % MOD;
	}

	long long hash_pattern = 0;

	for (int i = 0; i < m; ++i) {
		hash_pattern = (hash_pattern + (pattern[i] - 'a' + 1) * prime_powers[i]) % MOD;
	}

	vector <int> index;

	for (int i = 0; i < n - m + 1; ++i) {
		long long curr_hash = (hash_text[i + m] + MOD - hash_text[i]) % MOD;
		if (curr_hash == hash_pattern * prime_powers[i] % MOD)
			index.emplace_back(i);
	}

	return index;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		string a, b;
		cin >> a;
		cin.ignore();
		cin >> b;

		vector<int> occurrences;

		occurrences = patternSearch(a, b);

		if (occurrences.size() == 0)
			cout << "Not Found" << '\n';
		else {
			cout << occurrences.size() << '\n';
			for (auto i : occurrences)
				cout << i + 1 << ' ';
			cout << '\n';
		}

		cout << '\n';
	}

	return 0;
}