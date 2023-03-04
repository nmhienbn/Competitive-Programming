#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "2mst"
const int maxn = 5e4+5;

using namespace std;

struct dl {
    int u, v, w;
    bool operator < (const dl& x) const {
        return w < x.w;
    }
} E[maxn];

int n, m, root[maxn];
ll res, res2 = 1e18;
bool check[maxn];
int last;

int get_root(int u){
    return (root[u] == 0 ? u : root[u] = get_root(root[u]));
}

bool unify(int u, int v){
    int p = get_root(u);
    int q = get_root(v);
    if (p == q) return 0;
    root[p] = q;
    return 1;
}

int main(){
    freopen(Seraphine".in", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    scanf("%d %d", &n, &m);
    fi(i, 1, m){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        E[i] = {u, v, w};
    }
    sort(E+1, E+m+1);
    fi(i, 1, m){
        if (unify(E[i].u, E[i].v)){
            res += E[i].w;
            check[i] = 1;
            last = i;
        }
    }
    printf("%lld\n", res);
    fi(i, 1, last){
        if (check[i]){
            ll kq = 0;
            check[i] = 0;
            fi(j, 1, n) root[j] = 0;
            fi(j, 1, last){
                if (check[j]){
                    unify(E[j].u, E[j].v);
                    kq += E[j].w;
                }
            }
            check[i] = 1;
            bool ok = 0;
            fi(j, 1, m){
                if (!check[j]){
                    if (unify(E[j].u, E[j].v)){
                        kq += E[j].w;
                        ok = 1;
                        break;
                    }
                }
            }
            if (ok) res2 = min(res2, kq);
        }
    }
    printf("%lld", res2);
}
