#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define reset(a) memset(a, 0, sizeof(a))
#define pb push_back
#define Irelia "antiqueen"
const int maxn = 230, mod = 998244353;
using namespace std;

int r, c, n, L[2][maxn][maxn], now, nex,
    ngg[maxn], doc[maxn], chc[maxn*2], chp[maxn*2];

void add(int& x, int y){
    x += y;
    if (x >= mod) x -= mod;
}

void sub(int& x, int y){
    x -= y;
    if (x < 0) x += mod;
}

int main(){
    ios_base::sync_with_stdio(true);

    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> r >> c >> n;
    fi(i, 1, r) fi(j, 1, c) L[1][i][j] = 1;
    fi(t, 1, n){
        now = t & 1;
        nex = now ^ 1;
        reset(ngg);
        reset(doc);
        reset(chc);
        reset(chp);
        int sum = 0;
        fi(i, 1, r) fi(j, 1, c){
            add(sum, L[now][i][j]);
            add(ngg[i], L[now][i][j]);
            add(doc[j], L[now][i][j]);
            add(chc[i - j + maxn], L[now][i][j]);
            add(chp[i + j], L[now][i][j]);
        }
        reset(L[nex]);
        fi(i, 1, r) fi(j, 1, c){
            L[nex][i][j] = sum;
            sub(L[nex][i][j], ngg[i]);
            sub(L[nex][i][j], doc[j]);
            sub(L[nex][i][j], chc[i - j + maxn]);
            sub(L[nex][i][j], chp[i + j]);
            fi(k, 1, 3) add(L[nex][i][j], L[now][i][j]);
        }
    }
    int sum = 0;
    fi(i, 1, r) fi(j, 1, c){
        add(sum, L[(n + 1) & 1][i][j]);
    }
    cout << sum << endl;
}
