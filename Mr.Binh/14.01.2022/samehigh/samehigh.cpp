#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "samehigh"
const int maxn = 705, maxm = 1e6 + 5;
using namespace std;

int n, h[maxn][maxn], v[maxn][maxn];
int lab[maxm], lab2[maxm], res, id, cnt;
pair<pii, pii> g[maxm];
int st[maxm * 2], top;

int get(int u){
    while (lab[u] > 0)
        u = lab[u];
    return u;
}

bool unify(int u, int v){
    int p = get(u);
    int q = get(v);
    st[++top] = p;
    st[++top] = q;
    if (p == q) return 0;
    if (lab[p] < lab[q]) swap(p, q);
    lab[q] += lab[p];
    lab[p] = q;
    res = max(res, -lab[q]);
    return 1;
}

void rg(int& a, int& b){
    if (a == 0 && b == 0) return;
    int x = __gcd(a, b);
    a /= x;
    b /= x;
    if (a < 0 && b < 0) a = -a, b = -b;
}

bool kt(int u, int v){
    return (u >= 0 && v > 0) || (u <= 0 && v < 0) || (u == 0 && v == 0);
}

int vt(int i, int j){
    return (i - 1) * n + j;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) fi(j, 1, n){
        cin >> h[i][j];
    }
    fi(i, 1, n) fi(j, 1, n){
        cin >> v[i][j];
    }
    fi(i, 1, n * n) lab[i] = -1;
    fi(i, 1, n) fi(j, 1, n - 1){
        int x = h[i][j + 1] - h[i][j];
        int y = v[i][j] - v[i][j + 1];
        if (kt(x, y)){
            rg(x, y);
            if (!x && !y){
                unify(vt(i, j), vt(i, j + 1));
            }
            else
                g[++id]= {{x, y}, {vt(i, j), vt(i, j + 1)}};
        }
    }
    fi(i, 1, n - 1) fi(j, 1, n){
        int x = h[i + 1][j] - h[i][j];
        int y = v[i][j] - v[i + 1][j];
        if (kt(x, y)){
            rg(x, y);
            if (!x && !y){
                unify(vt(i, j), vt(i + 1, j));
            }
            else
                g[++id]= {{x, y}, {vt(i, j), vt(i + 1, j)}};
        }
    }
    sort(g + 1, g + id + 1);
    fi(i, 1, n * n) lab2[i] = lab[i];
    fi(i, 1, id){
        pii x = g[i].second;
        if (g[i].first == g[i - 1].first){
            unify(x.first, x.second);
        }
        else {
            pii y;
            while (top > 0){
                lab[st[top]] = lab2[st[top]];
                top--;
            }
            unify(x.first, x.second);
        }
    }
    cout << res;
}
