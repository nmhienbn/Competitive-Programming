#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "bluenred"
const int maxn = 1005;

using namespace std;

struct dl {
    int u, v, t;
    bool operator < (const dl& x) const {
        return u == x.u ? v < x.v : u < x.u;
    }
} E[maxn];

int n, a[maxn][maxn], b[maxn][maxn], m, k, res, S;

int get(int a[][maxn], int i, int j, int u, int v){
    return a[u][v] - a[i-1][v] - a[u][j-1] + a[i-1][j-1];
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        int u, v, t;
        cin >> u >> v >> t;
        u++, v++;
        m = max(m, u);
        k = max(k, v);
        E[i] = {u, v, t};
        if (t) a[u][v]++;
        else b[u][v]++;
    }
    sort(E+1, E+n+1);
    fi(i, 1, m) fi(j, 1, k){
        a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
    }
    fi(i, 1, n) fi(j, i+1, n) if (E[i].t && E[j].t){
        int u1 = E[i].u;
        int u2 = E[j].u;
        int v1 = min(E[i].v, E[j].v);
        int v2 = max(E[i].v, E[j].v);
        if (get(b, u1, v1, u2, v2)) continue;
        fid(t, i-1, 1) if (v1 <= E[t].v && E[t].v <= v2){
            if (!get(b, E[t].u, v1, u2, v2)) u1 = E[t].u;
            else break;
        }
        fi(t, j+1, n) if (v1 <= E[t].v && E[t].v <= v2){
            if (!get(b, u1, v1, E[t].u, v2)) u2 = E[t].u;
            else break;
        }
        int cnt = get(a, u1, v1, u2, v2);
        if (res < cnt){
            //cout << u1 << ' ' << v1 << ' ' << u2 << ' ' << v2 << '\n';
            //cout << E[j].u << ' ' << E[j].v << '\n';
            res = cnt;
            S = (u2-u1)*(v2-v1);
        }
        else if (res == cnt){
            S = min(S, (u2-u1)*(v2-v1));
        }
    }
    cout << res << '\n' << S;
}
