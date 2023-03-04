#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "aznet"
const int maxn = 1e4 + 5, maxm = 1e5 + 5;
using namespace std;

int nt, n, m, ma, mb, fa, fb, id;
int root[maxn];
int a[maxn], b[maxn];
bool cl[maxm];

struct dl {
    int u, v, id;
} ea[maxm], eb[maxm];

int find(int u){
    return root[u] == 0 ? u : root[u] = find(root[u]);
}

bool unify(int p, int q){
    p = find(p);
    q = find(q);
    if (p == q) return 0;
    root[p] = q;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> nt;
    while (nt--){
        cin >> n >> m;
        fi(i, 1, n - 1) cin >> a[i];
        fi(i, 1, n - 1) cin >> b[i];
        ma = mb = fa = fb = 0;
        fi(i, 1, m){
            cl[i] = 0;
            int u, v, w;
            cin >> u >> v >> w;
            if (w == 1) ea[++ma] = {u, v, i};
            else eb[++mb] = {u, v, i};
        }
        //-----------------------------------------
        fi(i, 1, n) root[i] = 0;
        fi(i, 1, ma){
            fb += unify(ea[i].u, ea[i].v);
        }
        fb = n - 1 - fb;
        //-----------------------------------------
        fi(i, 1, n) root[i] = 0;
        fi(i, 1, mb){
            fa += unify(eb[i].u, eb[i].v);
        }
        fa = n - 1 - fa;
        fi(i, 1, ma){
            cl[ea[i].id] = unify(ea[i].u, ea[i].v);
        }
        //-----------------------------------------
        id = fa;
        fi(i, fa, n - 1 - fb){
            if (a[i] + b[n - 1 - i] < a[id] + b[n - 1 - id]){
                id = i;
            }
        }
        //-----------------------------------------
        fi(i, 1, n) root[i] = 0;
        fi(i, 1, ma) if (cl[ea[i].id]){
            id--;
            unify(ea[i].u, ea[i].v);
        }
        if (id) fi(i, 1, ma){
            if (!cl[ea[i].id] && unify(ea[i].u, ea[i].v)){
                id--;
                cl[ea[i].id] = 1;
                if (id == 0) break;
            }
        }
        fi(i, 1, mb){
            if (unify(eb[i].u, eb[i].v))
                cl[eb[i].id] = 1;
        }
        fi(i, 1, m) if (cl[i]) cout << i << ' ';
        cout << '\n';
    }
}
