#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "str"
const int maxn = 1005, mod = 1000000007;

using namespace std;

int n, m, q;
int L[maxn][maxn]; // L[i][j] la so vt khac nhau den a[i], b[j]
ll res;
string a, b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    getline(cin, a);
    getline(cin, b);
    n = a.size();
    m = b.size();
    a = ' ' + a;
    b = ' ' + b;
    fi(i, 1, n){
        fi(j, 1, m){
            L[i][j] = L[i - 1][j - 1];
            if (a[i] != b[j]) L[i][j]++;
        }
    }
    cin >> q;
    fi(nt, 1, q){
        int i, j, k;
        cin >> i >> j >> k;
        res = (res + 1ll * nt *(L[i + k - 1][j + k - 1] - L[i - 1][j - 1])) % mod;
    }
    cout << res;
}
