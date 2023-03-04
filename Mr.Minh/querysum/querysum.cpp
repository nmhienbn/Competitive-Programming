#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "querysum"
const int maxn = 1e5+5;
using namespace std;

int n, m;
ll st[maxn << 2];

void update(int id, int l, int r, int vt, int val){
    if (l == r){
        st[id] = val;
        return;
    }
    int m = (l + r) >> 1;
    if (vt <= m) update(id*2, l, m, vt, val);
    else update(id*2+1, m+1, r, vt, val);
    st[id] = st[id*2] + st[id*2+1];
}

ll get(int id, int l, int r, int d, int c){
    if (r < d || l > c) return 0;
    if (d <= l && r <= c) return st[id];
    int m = (l+r) >> 1;
    return get(id*2, l, m, d, c) + get(id*2+1, m+1, r, d, c);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    while (m--){
        char typ;
        int u, v;
        cin >> typ >> u >> v;
        if (typ == 'S') update(1, 1, n, u, v);
        else cout << get(1, 1, n, u, v) << '\n';
    }
}
