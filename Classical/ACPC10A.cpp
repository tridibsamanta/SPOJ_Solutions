/*
 ~ Author    : @tridib_2003
 ~ Title     : ACPC10A - What’s Next
 ~ Link      : https://www.spoj.com/problems/ACPC10A/
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

    int a, b, c;
    cin >> a >> b >> c;

    while (a || b || c) {

        if ((b - a) == (c - b)) {
            cout << "AP " << c + (b - a) << '\n';
        }
        else {
            cout << "GP " << c * (b / a) << '\n';
        }

        cin >> a >> b >> c;

    }

    return 0;
}