#include <bits/stdc++.h>
using namespace std;

bool possible(string &s, int n, int k, int len) {
    int ops = 0;

    for (int i = 0; i < n; ) {
        if (s[i] == '1') {
            ops++;
            i += len;
        } else {
            i++;
        }
    }

    return ops <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int l = 1, r = n, ans = n;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (possible(s, n, k, mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans;

    return 0;
}
