#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "mine"
const int maxn = 2005, mod = 1e6 + 3;

using namespace std;

int n, m, a[maxn], pre[maxn];
int L[maxn][maxn], T[maxn][maxn];

void add(int& x, int y){
    x += y;
    while (x >= mod) x -= mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    n *= 2;
    fi(i, 1, n) cin >> a[i];
    int j = 1;
    fi(i, 1, n){
        while (a[i] - a[j] > m) j++;
        pre[i] = j;
    }
    fi(i, 1, n - 1)
        if (a[i + 1] - a[i] <= m)
            T[i][i + 1] = L[i][i + 1] = 1;
    for (int x = 4; x <= n; x += 2){
        fi(i, 1, n - x + 1){
            int j = i + x - 1;
            if (a[j] - a[i] <= m){
                L[i][j] = L[i + 1][j - 1];
            }
            if (n <= 200){
                for (int t = i + 1; t < j; t += 2)
                    if (a[j] - a[t + 1] <= m){
                        add(L[i][j], L[i][t]);
                    }
            }
            else {
                int t = max(pre[j], i + 1);
                if ((t - i) % 2 == 0) t++;
                add(L[i][j], T[i][j - 2] - T[i][t - 2] + mod);
                T[i][j] = (T[i][j - 2] + L[i][j]) % mod;
            }
        }
    }
//    fi(i, 1, n) {fi(j, i + 1, n) cout << L[i][j] << ' '; cout << endl;}
//    fi(i, 1, n) {fi(j, i + 1, n) cout << T[i][j] << ' '; cout << endl;}
    //cout << L[3][6] << ' ';
    cout << L[1][n];
}
