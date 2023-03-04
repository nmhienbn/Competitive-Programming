#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "count"
const int maxn = 2005, mod = 1e9 + 7;
using namespace std;
int n, k, res;
int C[maxn * 2][maxn];

void PREPARE(){
    C[0][0] = 1;
    fi(i, 1, n * 2){
        C[i][0] = 1;
        fi(j, 1, i){
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }
}

int Query(int i){
    int ans = 1;
    for (int j = 2; j * j <= i; j++) if (i % j == 0){
        int cnt = 0;
        while (i % j == 0){
            cnt++;
            i /= j;
        }
        ans = 1ll * ans * C[cnt + k - 1][cnt] % mod;
    }
    if (i > 1) ans = 1ll * ans * k % mod;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    PREPARE();
    fi(i, 1, n){
        res = (res + Query(i)) % mod;
    }
    cout << res;
}
