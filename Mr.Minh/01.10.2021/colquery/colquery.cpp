#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "colquery"
const int maxn = 1e5+5;

using namespace std;

int n, m, root[maxn];
multiset<int> t[maxn];

int get_root(int u){
    return root[u] == 0 ? u : root[u] = get_root(root[u]);
}

void unify(int u, int v){
    int p = get_root(u);
    int q = get_root(v);
    if (p == q) return;
    if (t[p].size() > t[q].size()) swap(p, q);
    root[p] = q;
    for (auto x : t[p]){
        t[q].insert(x);
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n){
        int x;
        cin >> x;
        t[i].insert(x);
    }
    while (m--){
        int typ, u, v;
        cin >> typ >> u >> v;
        if (typ == 1) unify(u, v);
        else {
            int p = get_root(u);
            cout << t[p].count(v) << '\n';
        }
    }
}
