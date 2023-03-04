#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "bocsoi"
const int maxn = 5e3+5;

using namespace std;

int a[3], sum, L[maxn][maxn];
pii q[maxn*maxn];
int d, c;

void xuli(int u1, int v1, int u, int v){
    int t[3] = {u1, v1, sum-u1-v1};
    sort(t, t+3);
    u1 = t[0], v1 = t[1];
    if (L[u1][v1] > L[u][v] + 1){
        L[u1][v1] = L[u][v] + 1;
        q[++c] = {u1, v1};
    }
}

void bfs(){
    d = 1, c = 0;
    q[++c] = {a[0], a[1]};
    while (d <= c){
        int u = q[d].first, v = q[d++].second;
        int b[3] = {u, v, sum-u-v};
        sort(b, b+3);
        u = b[0], v = b[1];

        xuli(b[0]*2, b[1]-b[0], u, v);
        xuli(b[0]*2, b[2]-b[0], u, v);
        xuli(b[1]*2, b[2]-b[1], u, v);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    fi(i, 0, 2){
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a+3);
    memset(L, 60, sizeof(L));
    L[a[0]][a[1]] = 0;
    bfs();
    cout << (L[0][0] > 1e9 ? -1 : L[0][0]);
}
