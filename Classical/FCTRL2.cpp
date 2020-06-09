/*
 ~ Author    : @tridib_2003
 ~ Title     : FCTRL2 - Small factorials
 ~ Link      : https://www.spoj.com/problems/FCTRL2/
*/

#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;
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

        int n;
        cin >> n;

        cpp_int fact = 1;
        for (int i = 1; i <= n; ++i)
            fact *= i;

        cout << fact << '\n';

    }

    return 0;
}