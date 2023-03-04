#include <bits/stdc++.h>
#define VanLoi "hanoi"
#define gb(i, j) ((i >> j) & 1)

using namespace std;

const int N = 1005, MOD = 1000000007;

int n, m, k, a[N][N], cl[N][N], ok, res, soho = 0, kq = 0;

struct data {
    int val, F, S;
    bool operator < (const data &x) const {
        return val < x.val;
    }
};

vector <data> q;

int ci[4] = {-1, 0, 0, 1};
int di[4] = {0, -1, 1, 0};

void DFS(int u, int v) {
    cl[u][v] = 1;
    res++;
    for (int i = 0; i <= 3; i++) {
        int x = u + ci[i];
        int y = v + di[i];
        if (x > 0 && x <= n && y > 0 && y <= m) {
            if (a[x][y] != -1 && cl[x][y] == 0) DFS(x, y);
        } else ok = 0;
    }
}

void process(int u, int v) {
    a[u][v] = -1;
    kq++;
    for (int i = 0; i <= 3; i++) {
        int x = u + ci[i];
        int y = v + di[i];
        if (x > 0 && x <= n && y > 0 && y <= m && a[x][y] == 0) process(x, y);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(VanLoi".inp", "r", stdin);
    freopen(VanLoi".out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) if (s[j - 1] == '#') a[i][j] = -1; else a[i][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) if (a[i][j] != -1 && cl[i][j] == 0) {
        res = 0;
        ok = 1;
        DFS(i, j);
        if (ok == 0) continue;
        q.push_back({res, i, j});
        soho++;
    }
    sort(q.begin(), q.end());
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cl[i][j] = 0;
    for (int i = 1; i <= soho - k; i++) process(q[i - 1].F, q[i - 1].S);
    cout << kq << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) if (a[i][j] == -1) cout << "#"; else cout << ".";
        cout << '\n';
    }
    return 0;
}

