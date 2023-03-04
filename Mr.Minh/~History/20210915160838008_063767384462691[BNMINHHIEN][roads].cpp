#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "roads"
const int maxn = 1e5+5, n1 = 1e3+5;

using namespace std;

int n, a[maxn], maxa;

struct edge {
    int u, v, w;
    bool operator < (const edge& x) const {
        return w < x.w;
    }
} E[n1*n1];

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

void sub1(){
    int cnt = 0;
    fi(i, 1, n){
        fi(j, 1, i-1){
            E[++cnt] = {i, j, min(a[i]%a[j], a[j]%a[i])};
        }
    }
    sort(E+1, E+cnt+1);
    ll res = 0;
    fi(i, 1, cnt){
        int u = E[i].u, v = E[i].v, w = E[i].w;
        if (unify(u, v)){
            res += w;
        }
    }
    cout << res;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i];
        maxa = max(maxa, a[i]);
    }
    if (n <= 1e3){
        sub1();
        exit(0);
    }
    sort(a+1, a+n+1);
}
