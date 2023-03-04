#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "scales"
const int maxn = 25, N = (1 << 20) + 10;
using namespace std;

int n, m, u, v, c, a[maxn], b[maxn];
ll L[N], M[N], res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> c;
    m = n - n/2;
    n /= 2;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, m) cin >> b[i];

    u = (1 << n) - 1;
    fi(i, 1, u){
        fi(j, 0, n-1) if ((i >> j) & 1){
            L[i] = L[i - (1 << j)] + a[j+1];
            break;
        }
    }
    sort(L+1, L+u+1);

    v = (1 << m) - 1;
    fi(i, 1, v){
        fi(j, 0, m-1) if ((i >> j) & 1){
            M[i] = M[i - (1 << j)] + b[j+1];
            break;
        }
    }
    sort(M+1, M+v+1);

    int j = v;
    fi(i, 0, u){
        while (L[i] + M[j] > c && j >= 0) j--;
        if (L[i] + M[j] <= c && j >= 0) res = max(res, L[i] + M[j]);
    }
    cout << res;
}
