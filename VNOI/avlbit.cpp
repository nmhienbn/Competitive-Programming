#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define mu2(x) (1 << (x))
#define pb push_back
#define ll long long
#define Irelia "avlbit"
const int maxn = 1e5 + 5;
using namespace std;

int lg2[maxn];

struct SpareTable{
    int a[maxn][17];
    void build(const int b[], const int n, int func(int, int)){
        fi(i, 1, n) a[i][0] = b[i];
        fi(j, 1, lg2[n]){
            fi(i, 1, n + 1 - mu2(j)){
                a[i][j] = func(a[i][j - 1], a[i + mu2(j - 1)][j - 1]);
            }
        }
    }
    int query(int l, int r, int func(int, int)){
        int t = lg2[r - l + 1];
        return func(a[l][t], a[r + 1 - mu2(t)][t]);
    }
} stmax, stmin, stgcd, stpos;

int n, q, a[maxn], b[maxn], p[maxn];
map<int, int> idx;

inline int fmax(int x, int y) {return max(x, y);}
inline int fmin(int x, int y) {return min(x, y);}
inline int fgcd(int x, int y) {return __gcd(x, y);}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> q;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n - 1) b[i] = a[i + 1] - a[i];
    fi(i, 1, n){
        p[i] = 1e9;
        int pos = idx[a[i]];
        if (pos) p[pos] = i;
        idx[a[i]] = i;
    }
    //build
    fi(i, 2, n) lg2[i] = lg2[i >> 1] + 1;
    stmax.build(a, n, fmax);
    stmin.build(a, n, fmin);
    stgcd.build(b, n - 1, fgcd);
    stpos.build(p, n, fmin);
    //query
    while (q--){
        int l, r;
        cin >> l >> r;
        int M = stmax.query(l, r, fmax);
        int m = stmin.query(l, r, fmin);
        int dif = M - m, num = r - l;
        if (!dif || dif % num){
            cout << "NO\n";
            continue;
        }
        int d = dif / num;
        int GCD = abs(stgcd.query(l, r - 1, fgcd));
        int pos = stpos.query(l, r, fmin);
        if (pos > r && GCD == d){
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
