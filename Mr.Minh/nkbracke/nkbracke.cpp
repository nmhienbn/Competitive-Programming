#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "nkbracke"
const int maxn = 1e5+5;

using namespace std;

struct IT {
    int f, s;
};

int n, m, a[maxn];
IT st[maxn << 2];
string s;

void build(int id, int l, int r){
    if (l == r){
        st[id].f = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(id*2, l, m);
    build(id*2+1, m+1, r);
    st[id].f = min(st[id*2].f, st[id*2+1].f);
}

void lazy(int id){
    fi(i, id*2, id*2+1){
        st[i].f += st[id].s;
        st[i].s += st[id].s;
    }
    st[id].s = 0;
}

void update(int id, int l, int r, int d, int c, int val){
    if (r < d || l > c) return;
    if (d <= l && r <= c){
        st[id].f += val;
        st[id].s += val;
        return;
    }
    int m = (l+r) >> 1;
    lazy(id);
    update(id*2, l, m, d, c, val);
    update(id*2+1, m+1, r, d, c, val);
    st[id].f = min(st[id*2].f, st[id*2+1].f);
}

int get(int id, int l, int r, int d, int c){
    if (r < d || l > c) return 1e9;
    if (d <= l && r <= c) return st[id].f;
    int m = (l + r) >> 1;
    lazy(id);
    return min(get(id*2, l, m, d, c), get(id*2+1, m+1, r, d, c));
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> m >> s;
    s = ' ' + s;
    fi(i, 1, n){
        a[i] = a[i-1] + (s[i] == '(' ? 1 : -1);
    }
    build(1, 0, n);
    while (m--){
        int typ, u;
        cin >> typ >> u;
        if (typ == 0){
            char v;
            cin >> v;
            if (s[u] == v) continue;
            s[u] = v;
            if (v == ')') update(1, 0, n, u, n, -2);
            else update(1, 0, n, u, n, 2);
        }
        else {
            int v;
            cin >> v;
            if ((u-v+1) % 2){
                cout << 0;
                continue;
            }
            int uv = get(1, 0, n, u, v);
            int nu = get(1, 0, n, u-1, u-1);
            int nv = get(1, 0, n, v, v);
            //cout << uv << ' ' << nu << ' ' << nv << '\n';
            if (uv >= nu && nu == nv) cout << 1;
            else cout << 0;
        }
    }
}
