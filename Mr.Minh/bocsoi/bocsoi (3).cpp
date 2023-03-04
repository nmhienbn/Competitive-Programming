#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "bocsoi"
const int maxn = 5005;
using namespace std;

int n, sum, f[maxn][maxn], a[3];
queue<pii> q;

void xuli(int i, int j, int k, int w){
    int b[3] = {i - j, j * 2, k};
    sort(b, b + 3);
    if (!f[b[0]][b[1]]){
        f[b[0]][b[1]] = w + 1;
        q.push({b[0], b[1]});
    }
}

void bfs(){
    f[a[0]][a[1]] = 1;
    q.push({a[0], a[1]});
    while (q.size()){
        int i = q.front().first, j = q.front().second;
        int k = sum - i - j;
        q.pop();
        xuli(j, i, k, f[i][j]);
        xuli(k, i, j, f[i][j]);
        xuli(k, j, i, f[i][j]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    fi(i, 0, 2) cin >> a[i], sum += a[i];
    sort(a, a + 3);
    bfs();
    cout << f[0][0] - 1;
}
