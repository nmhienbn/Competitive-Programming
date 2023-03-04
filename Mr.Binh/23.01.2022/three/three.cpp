#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "three"
const int maxn = 5005;
const int m = 1000000;
using namespace std;

int n, q, a[maxn], cnt[2000005];
ll b[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> q;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n){
        fi(j, i + 1, n){
            if (abs(a[i] + a[j]) <= m){
                b[i][j] = cnt[m - a[i] - a[j]];
            }
            cnt[a[j] + m]++;
        }
        fi(j, i + 1, n){
            cnt[a[j] + m] = 0;
        }
    }
    fi(i, 1, n){
        fi(j, 1, n){
            b[i][j] += b[i + 1][j] + b[i][j - 1] - b[i + 1][j - 1];
        }
    }
    while (q--){
        int l, r;
        cin >> l >> r;
        cout << b[r][r] - b[l - 1][r] - b[r][l - 1] + b[l - 1][l - 1] << '\n';
    }
}
