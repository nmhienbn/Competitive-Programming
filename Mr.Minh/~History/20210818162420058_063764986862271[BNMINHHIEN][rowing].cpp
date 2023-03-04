#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "rowing"
const int maxn = 4010;

using namespace std;

struct edge {
    int u, v, w;
    bool operator < (const edge& x) const {
        return w < x.w;
    }
} E[(int)1e7];

int n, h, cnt = 0, root[maxn], res;
pii a[maxn];

int get_root(int u){
    return root[u] ? root[u] = get_root(root[u]) : u;
}

bool unify(int u, int v){
    int p = get_root(u);
    int q = get_root(v);
    if (p == q) return 0;
    root[p] = q;
    return 1;
}

int ch(int a, int b){
    return (int)sqrt(a*a + b*b);
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> h;
    fi(i, 1, n){
        cin >> a[i].first >> a[i].second;
        E[++cnt] = {i, n+1, a[i].second};
        E[++cnt] = {i, n+2, h-a[i].second};
    }
    fi(i, 1, n){
        fi(j, i+1, n){
            int w = ch(a[i].first - a[j].first, a[i].second - a[j].second);
            E[++cnt] = {i, j, w};
        }
    }
    sort(E+1, E+cnt+1);
    fi(i, 1, cnt){
        if (unify(E[i].u, E[i].v)){
            res = max(res, E[i].w);
        }
        if (get_root(n+1) == get_root(n+2)) break;
    }
    cout << res;
}
