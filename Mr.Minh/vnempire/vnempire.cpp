#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "vnempire"
const int maxn = 1e5+5;

using namespace std;

struct dl {
    int x, y, z, id;
};
struct edge {
    int u, v, w;
    bool operator < (const edge& x) const {
        return w < x.w;
    }
};

bool cmp1(dl a, dl b){
    return a.x < b.x;
}
bool cmp2(dl a, dl b){
    return a.y < b.y;
}
bool cmp3(dl a, dl b){
    return a.z < b.z;
}

int n, m;
dl a[maxn];
edge E[maxn];

int dis(int i, int j){
    return min({abs(a[i].x-a[j].x), abs(a[i].y-a[j].y), abs(a[i].z-a[j].z)});
}

int root[maxn];

int get_root(int u){
    return root[u] == 0 ? u : root[u] = get_root(root[u]);
}

bool unify(int u, int v){
    int p = get_root(u);
    int q = get_root(v);
    if (p == q) return 0;
    root[p] = q;
    return 1;
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i].x >> a[i].y >> a[i].z, a[i].id = i;

    sort(a+1, a+n+1, cmp1);
    fi(i, 2, n) E[++m] = {a[i].id, a[i-1].id, dis(i, i-1)};
    sort(a+1, a+n+1, cmp2);
    fi(i, 2, n) E[++m] = {a[i].id, a[i-1].id, dis(i, i-1)};
    sort(a+1, a+n+1, cmp3);
    fi(i, 2, n) E[++m] = {a[i].id, a[i-1].id, dis(i, i-1)};

    ll res = 0;
    sort(E+1, E+m+1);
    fi(i, 1, m){
        int u = E[i].u, v = E[i].v, w = E[i].w;
        if (unify(u, v)){
            res += w;
        }
    }
    cout << res;
}
