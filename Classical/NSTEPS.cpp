/*
 ~ Author    : @tridib_2003
 ~ Title     : NSTEPS - Number Steps
 ~ Link      : https://www.spoj.com/problems/NSTEPS/
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

        int x, y;
        cin >> x >> y;

        if (x & 1) {
            if (y == x || y == (x - 2))
                cout << x + y - 1 << '\n';
            else
                cout << "No Number\n";
        }
        else {
            if (y == x || y == (x - 2))
                cout << x + y << '\n';
            else
                cout << "No Number\n";
        }

    }

    return 0;
}