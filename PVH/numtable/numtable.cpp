#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "numtable"
const int maxn = 1e6 + 5, N = 1e7;
using namespace std;

struct dl {
    int u, v, w;
    bool operator < (const dl& x) const {
        return w < x.w;
    }
};

int sub, m, n, cnt, res = 1;
int a[maxn];
int p[N + 5];
dl E[N];
void Erathosenes(){
    fi(i, 1, N) p[i] = i;
    fi(i, 2, 3162) if (p[i] == i){
        for (int j = i * i; j <= N; j += i){
            p[j] = i;
        }
    }
}

int vt(int i, int j){
    return (i - 1) * n + j;
}

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
    res = max(res, -lab[p]);
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    Erathosenes();
    cin >> sub >> m >> n;
    fi(i, 1, m) fi(j, 1, n){
        cin >> a[vt(i, j)];
    }
    fi(i, 1, m * n) lab[i] = -1;
    fi(i, 1, m) fi(j, 1, n){
        int pos = vt(i, j);
        int x = a[pos];
        while (x > 1){
            int u = p[x];
            while (x % u == 0) x /= u;
            if (i < m && a[pos + n] % u == 0) E[++cnt] = {pos, pos + n, u};
            if (j < n && a[pos + 1] % u == 0) E[++cnt] = {pos, pos + 1, u};
        }
    }
    sort(E + 1, E + cnt + 1);
    int j = 1;
    fi(i, 1, cnt){
        if (E[i].w != E[i - 1].w){
            fi(t, j, i - 1) lab[E[t].u] = lab[E[t].v] = -1;
            j = i;
        }
        unify(E[i].u, E[i].v);
    }
    cout << res;
}
