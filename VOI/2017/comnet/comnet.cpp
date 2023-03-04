#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "comnet"
const int maxn = 1e5 + 5, maxm = 1e6 + 5;
using namespace std;

struct dl {
    int u, v, w;
};

int nt, n, m, q;
dl a[maxm];
int lab[maxn];
pii w[105];

int Find(int u){
    return lab[u] < 0 ? u : lab[u] = Find(lab[u]);
}
bool unify(int p, int q){
    p = Find(p);
    q = Find(q);
    if (p == q) return 0;
    if (lab[p] > lab[q]) swap(p, q);
    lab[p] += lab[q];
    lab[q] = p;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> nt;
    while (nt--){
        cin >> n >> m >> q;
        fi(i, 1, m){
            int u, v, w;
            cin >> u >> v >> w;
            a[i] = {u, v, w};
        }
        while (q--){
            fi(i, 1, n) lab[i] = -1;
            int id, s;
            cin >> id >> s;
            fi(i, 1, s){
                int t, z;
                cin >> t >> z;
                w[i] = {t, a[t].w};
                a[t].w = z;
            }
            fi(i, 1, m) if (a[i].w < a[id].w){
                unify(a[i].u, a[i].v);
            }
            if (unify(a[id].u, a[id].v)) cout << "NO\n";
            else cout << "YES\n";
            fi(i, 1, s) a[w[i].first].w = w[i].second;
        }
    }
}
