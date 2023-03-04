#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "fibseq"
const int maxn = 1e6 + 5;
using namespace std;

int nt, n, k, f[maxn];
ll st;
int vt[maxn];

struct matrix {
    ll a[2][2];
    friend matrix operator * (matrix A, matrix B){
        matrix C;
        fi(i, 0, 1) fi(j, 0, 1){
            C.a[i][j] = 0;
            fi(t, 0, 1) C.a[i][j] = (C.a[i][j] + A.a[i][t] * B.a[t][j]) % k;
        }
        return C;
    }
    friend matrix binpow(matrix A, ll k){
        if (k == 1) return A;
        matrix tg = binpow(A, k >> 1);
        tg = tg * tg;
        if (k & 1) return tg * A;
        return tg;
    }
    void print(){
        fi(i, 0, 1) fi(j, 0, 1) cout << a[i][j] << ' ';
        cout << endl;
    }
};

matrix cs, A;

int add(int x, int y){
    x += y;
    if (x >= k) return x - k;
    return x;
}

void solve(){
    cin >> n >> st >> k;
    A = binpow(cs, st);
    f[1] = A.a[1][0];
    f[2] = A.a[0][0];
    fi(i, 3, n) f[i] = add(f[i - 1], f[i - 2]);
    fi(i, 2, n) f[i] = add(f[i], f[i - 1]);
    fi(i, 0, n){
        vt[i] = -1;
    }
    fi(i, 0, n){
        if (~vt[f[i]]){
            cout << i - vt[f[i]] << ' ';
            fi(j, vt[f[i]], i - 1) cout << st + j << ' ';
            cout << '\n';
            return;
        }
        else vt[f[i]] = i;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> nt;
    cs.a[0][0] = 1;
    cs.a[0][1] = 1;
    cs.a[1][0] = 1;
    while (nt--){
        solve();
    }

}
