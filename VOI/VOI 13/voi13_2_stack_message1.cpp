#include <iostream>
#include <vector>
#include <string>
using namespace std;

int T, n, m, res;
string a[101], b[101];
int l[101], q[101], idx[101], f[101];
int low_i, high_i, low_j, high_j, delta, now;

void calc(int x, int y) {
    low_i = max(0, x);
    high_i = min(m, m + x);
    low_j = max(0, y);
    high_j = min(n, n + y);
    if ((high_i - low_i)*(high_j - low_j) <= res) return;
    delta = high_j - low_j;
    now = 0;
    for (int j=low_j; j < high_j; j++) f[j] = 0;
    for (int i=low_i; i < high_i; i++) {
        for (int j=low_j; j < high_j; j++) {
            if (a[i][j] == b[i-x][j-y]) {
                f[j]++;
            }
            else {
                f[j] = 0;
            }
        }
        now += delta;
        if (now <= res) continue;
        int top = 0;
        for (int j=low_j; j < high_j; j++) {
            if (f[j]) {
                while (top && q[top-1]>=f[j]) top--;
                if (!top) l[j] = low_j-1;
                else l[j] = idx[top-1];
                q[top] = f[j], idx[top] = j, top++;
            }
            else {
                q[0] = 0, idx[0] = j, top = 1;
            }
        }
        top = 0;
        int r;
        for (int j=high_j-1; j >= low_j; j--) {
            if (f[j]) {
                while (top && q[top-1]>=f[j]) top--;
                if (!top) r = high_j;
                else r = idx[top-1];
                res = max(res, f[j]*(r - l[j] - 1));
                q[top] = f[j], idx[top] = j, top++;
            }
            else {
                q[0] = 0, idx[0] = j, top = 1;
            }
        }
    }
}

int main() {
    cin >> T;
    while (T--) {
        cin >> m >> n;
        for (int i = 0; i < m; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        res = 0;
        for (int i=0; i<m; i++) for (int j=0; j<n; j++) {
            calc(i, j);
            if (i){
                calc(-i, j);
                if (j) calc(-i, -j);
            }
            if (j){
                calc(i, -j);
            }
        }
        cout << res << '\n';
    }
    return 0;
}
