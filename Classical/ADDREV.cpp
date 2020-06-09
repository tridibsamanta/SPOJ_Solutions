/*
 ~ Author    : @tridib_2003
 ~ Title     : ADDREV - Adding Reversed Numbers
 ~ Link      : https://www.spoj.com/problems/ADDREV/
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

int main() {

    FIO;

    int tc = 1;
    cin >> tc;
    while (tc--) {

        int n1, n2;
        cin >> n1 >> n2;

        int rev_n1 = 0, rev_n2 = 0, d, sum = 0, rev_sum = 0;

        while (n1) {
            d = n1 % 10;
            rev_n1 = rev_n1 * 10 + d;
            n1 /= 10;
        }

        while (n2) {
            d = n2 % 10;
            rev_n2 = rev_n2 * 10 + d;
            n2 /= 10;
        }

        sum = rev_n1 + rev_n2;

        while (sum) {
            d = sum % 10;
            rev_sum = rev_sum * 10 + d;
            sum /= 10;
        }

        cout << rev_sum << '\n';

    }

    return 0;
}