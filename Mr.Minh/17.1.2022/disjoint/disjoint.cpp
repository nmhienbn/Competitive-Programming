#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "disjoint"
const int maxn = 1e6 + 5;
using namespace std;

int n, m;
int lab[maxn];

int find(int u){
    return lab[u] < 0 ? u : lab[u] = find(lab[u]);
}

bool unify(int u, int v, bool flag){
    int p = find(u);
    int q = find(v);
    if (p == q || flag) return 1;
    if (lab[p] < lab[q]) swap(p, q);
    lab[q] += lab[p];
    lab[p] = q;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 0, n) lab[i] = -1;
    fi(i, 1, m){
        int typ, u, v;
        cin >> typ >> u >> v;
        if (typ == 1) unify(u, v, 1);
        else cout << unify(u, v, 0) << '\n';
    }
}
