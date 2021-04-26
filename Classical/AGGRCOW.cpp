/*
 ~ Author    : tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 5;

int n, c;
int arr[MAXN];

// check if the min. distance between two stalls can be 'd'
bool isCurrDistPossible(int d) {

    int prev = -INF, cnt = 0;

    for (int i = 0; i < n; ++i) {

        if (arr[i] - prev >= d) {

            if (++cnt >= c) {
                return true;
            }

            prev = arr[i];
        }
    }

    return false;
}

void solve() {

    cin >> n >> c;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    // perform binary search

    int maxDist = 0;
    int l = 0, h = INF;

    while (l <= h) {

        int mid = l + (h - l) / 2;

        if (isCurrDistPossible(mid)) {
            maxDist = mid;
            l = mid + 1; // try to maximize the min. distance
        }
        else {
            h = mid - 1; // must reduce the min. distance
        }
    }

    cout << maxDist;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    cin >> tc;

    while (tc--) {
        solve();
        cout << '\n';
    }

    return 0;
}
