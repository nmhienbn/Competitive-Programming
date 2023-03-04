#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "oaks"
const int maxn = 205, INF = 1e9;
using namespace std;

int n, a[maxn], d[maxn][maxn], f[maxn];
int trace[maxn], g[maxn][maxn], st[maxn], top;

bool kt(int i, int x, int j){
    return (i < x && x > j) || (i > x && x < j);
}

void print(int i, int j){
    if (i >= j - 1) return;
    print(i, g[i][j]);
    print(g[i][j], j);
    cout << g[i][j] << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n - 1) d[i][i + 1] = 1;
    fi(len, 2, n - 1) fi(i, 1, n - len){
        int j = i + len;
        fi(k, i + 1, j - 1){
            if (kt(a[i], a[k], a[j]) && d[i][k] && d[k][j]){
                d[i][j] = 1;
                g[i][j] = k;
                break;
            }
        }
    }
    f[1] = 1;
    fi(i, 2, n){
        fid(j, i - 1, 1){
            if (f[j] && d[j][i] && f[i] < f[j] + 1 && a[j] <= a[i]){
                f[i] = f[j] + 1;
                trace[i] = j;
            }
        }
    }
    if (f[n] == 0){
        cout << -1;
        exit(0);
    }
    cout << n - f[n] << '\n';
    st[++top] = n;
    fi(i, 1, f[n]){
        n = trace[n];
        st[++top] = n;
    }
    fid(i, top, 2) print(st[i], st[i - 1]);
}
