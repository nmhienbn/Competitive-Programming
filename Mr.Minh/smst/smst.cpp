#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "smst"
const int maxn = 205, INF = 123456789;
using namespace std;

int n, m, k, root[maxn];

struct dl {
    int u, v, w;
} a[maxn];
int get(int u){
    return root[u] == 0 ? u : root[u] = get(root[u]);
}
bool unify(int u, int v){
    int p = get(u);
    int q = get(v);
    if (p == q) return 0;
    root[p] = q;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(rep, 1, m){
        fi(i, 1, n) root[i] = 0;
        ll res = 0;
        int cnt = 0;

        k++;
        cin >> a[k].u >> a[k].v >> a[k].w;
        int u = k;
        while (a[u].w < a[u - 1].w && u > 1){
            swap(a[u], a[u - 1]);
            u--;
        }

        fi(i, 1, k){
            if (unify(a[i].u, a[i].v)){
                a[++cnt] = a[i];
                res += a[i].w;
            }
            if (cnt == n-1) break;
        }

        k = cnt;
        if (cnt == n-1)
            cout << res << '\n';
        else
            cout << INF << '\n';
    }
}
