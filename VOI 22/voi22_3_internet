#include <bits/stdc++.h>
#define fi(i, a, b)  for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define X first
#define Y second
#define Irelia "internet"

using namespace std;

inline void minimize(int& x, int y){
    if (x > y) x = y;
}

struct dl {
    int u, v, w;
    bool operator < (const dl& x) const {
        return w < x.w;
    }
};

const int maxn = 1e5 + 5;

int n, s, k;
pii a[maxn];
ll res;

//DSU
int lab[maxn];
int Find(int u){
    return lab[u] < 0 ? u : lab[u] = Find(lab[u]);
}
bool unify(int p, int q){
    p = Find(p);
    q = Find(q);
    if (p == q) return false;
    if (lab[p] > lab[q]) swap(p, q);
    lab[p] += lab[q];
    lab[q] = p;
    return true;
}

//sub1
int d[1005][1005], f[1005][1005];
int cl[1005];
dl E[1000005];
void dfs(int u, int p, int gt){
    cl[u] = gt;
    fi(v, 1, n) if (!cl[v] && d[u][v] <= s){
        dfs(v, u, gt);
    }
}
void sub1(){
    fi(i, 1, n) fi(j, i + 1, n){
        d[i][j] = abs(a[i].X - a[j].X) + abs(a[i].Y - a[j].Y);
        d[j][i] = d[i][j];
    }
    int cnt = 0;
    fi(i, 1, n) if (!cl[i]){
        dfs(i, 0, ++cnt);
    }
    fi(i, 1, n) fi(j, 1, n){
        f[i][j] = 2e9;
    }
    fi(i, 1, n) fi(j, i + 1, n){
        minimize(f[cl[i]][cl[j]], d[i][j]);
        minimize(f[cl[j]][cl[i]], d[i][j]);
    }
    int sl = 0;
    fi(i, 1, cnt) fi(j, i + 1, cnt){
        E[++sl] = {i, j, f[i][j]};
    }
    sort(E + 1, E + sl + 1);
    fi(i, 1, cnt) lab[i] = -1;
    fi(i, 1, sl){
        if (unify(E[i].u, E[i].v)){
            res += E[i].w;
            k--;
        }
        if (k == 0) break;
    }
    cout << res;
    exit(0);
}

//sub2
int kc[maxn];
void sub2(){
    sort(a + 1, a + n + 1);
    int dem = 0;
    fi(i, 2, n){
        kc[++dem] = abs(a[i].X - a[i - 1].X) + abs(a[i].Y - a[i - 1].Y);
        if (kc[dem] <= s) dem--;
    }
    sort(kc + 1, kc + dem + 1);
    fi(i, 1, k) res += kc[i];
    cout << res;
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> s >> k;
    fi(i, 1, n) cin >> a[i].X >> a[i].Y;
    if (n <= 1000) sub1();
    sub2();
}
