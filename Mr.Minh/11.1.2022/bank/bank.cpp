#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "bank"
const int N = 1 << 20;
using namespace std;

int n, m, a[21], b[31], nt;

ll f[N];
void sub1(){
    int u = (1 << m) - 1;
    fi(x, 1, u){
        fi(i, 0, m - 1) if (gb(x, i)){
            f[x] = f[x - (1 << i)] + b[i + 1];
            break;
        }
        if (f[x] == a[1]){
            fi(i, 0, m - 1) cout << gb(x, i) << ' ';
            return;
        }
    }
}

bool g[1001][1051];
pii pre[1001][1051];
int kq[35];
void sub2(){
    n = 0;
    memset(g, 0, sizeof g);
    g[0][0] = 1;
    fi(k, 1, m){
        fid(i, a[1], 0) fid(j, a[2], 0){
            if (i >= b[k] && g[i - b[k]][j] && !g[i][j]){
                g[i][j] = 1;
                pre[i][j] = {k, 1};
            }
            if (j >= b[k] && g[i][j - b[k]] && !g[i][j]){
                g[i][j] = 1;
                pre[i][j] = {k, 2};
            }
        }
    }
    if (!g[a[1]][a[2]]){
        cout << -1;
        return;
    }
    while (a[1] > 0 || a[2] > 0){
        pii x = pre[a[1]][a[2]];
        kq[x.first] = x.second;
        a[x.second] -= b[x.first];
    }
    fi(i, 1, m) cout << kq[i] << ' ';
}



void sub3(){
    int u = (1 << m) - 1;
    fi(x, 1, u){
        fi(i, 0, m - 1) if (gb(x, i)){
            f[x] = f[x - (1 << i)] + b[i + 1];
            break;
        }
    }
    memset(g, 0, sizeof g);
    g[0][0] = 1;
    fi(i, 1, n){
        fi(j, 0, u) fi(k, 0, u) if ((j & k) == 0 && f[j] == a[i] && g[i - 1][k]){
            g[i][j ^ k] = 1;
        }
    }
    fi(x, 0, u) if (g[n][x]){
        fi(i, 0, m - 1) cout << gb(x, i) << ' ';
        return;
    }
    cout << -1;
}

void sub4(){

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> nt;
    while (nt--){
        cin >> n >> m;
        fi(i, 1, n) cin >> a[i];
        fi(i, 1, m) cin >> b[i];
        if (n == 1 && m <= 20) sub1();
        else if (n <= 2 && m <= 30) sub2();
        else if (n <= 10 && m <= 10) sub3();
        else sub4();
        cout << '\n';
    }
}
