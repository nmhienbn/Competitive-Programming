#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "stdorm"
const int maxn = 105, maxm = 505;
using namespace std;

int n, m, k, a[maxn], x;
ll s[1000005], f[maxn][maxm];

void minimize(ll& x, ll y){
    if (x > y) x = y;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> k;
    fi(i, 1, n){
        cin >> x;
        a[x]++;
    }
    sort(a + 1, a + m + 1, greater<int>());
    fi(i, 1, m){
        if (a[i] == 0){
            m = i - 1;
            break;
        }
    }
    fi(i, 1, a[1]) s[i] = s[i - 1] + i;
    fi(i, 1, m) fi(j, 0, k){
        f[i][j] = 1e9;
        fi(t, 0, j){
            int u = a[i] / (t + 1), v = a[i] % (t + 1);
            minimize(f[i][j], f[i - 1][j - t] + s[u + 1] * v + s[u] * (t + 1 - v));
        }
    }
    cout << f[m][k];
}
