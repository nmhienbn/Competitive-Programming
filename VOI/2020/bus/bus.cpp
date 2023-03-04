#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "bus"
const int maxn = 5e4 + 5;
using namespace std;

struct dl {
    int u, v, w;
    bool operator < (const dl& x){
        return w < x.w;
    }
};

int n, m, st, fn;
int ma, mb;
dl a[maxn], b[maxn];
int lab[maxn];

int reset(){
    fi(i, 1, n) lab[i] = -1;
}

int Find(int u){
    return lab[u] < 0 ? u : lab[u] = Find(lab[u]);
}

bool check(int x){
    int d = 1, c = ma;
    while (d <= c){
        int g = (d + c) >> 1;
        if (kt(g))
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> st >> fn;
    fi(i, 1, m){
        int c, u, v, w;
        cin >> c >> u >> v >> w;
        if (c == 1) a[++ma] = {u, v, w};
        else b[++mb] = {u, v, w};
    }
    sort(a + 1, a + ma + 1);
    sort(b + 1, b + mb + 1);
    int d = 0, c = a[ma].w + b[mb].w;
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(g)) c = g - 1;
        else d = g + 1;
    }
    cout << d;
}
