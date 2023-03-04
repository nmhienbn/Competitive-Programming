#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "sgloves"
const int maxn = 25, N = (1 << 20) + 10;
using namespace std;

int n, m, a[maxn], b[maxn], res1, res2, L[N], M[N], x, y, s1, s2;
pii c[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n) cin >> b[i];
    fi(i, 1, n){
        if (!b[i]) res1 += a[i];
        else if (!a[i]) res2 += b[i];
        else c[m++] = {a[i], b[i]}, s1 += a[i], s2 += b[i];
    }
    int u = (1 << m) - 1;
    fi(i, 1, u){
        L[i] = s1;
        M[i] = s2;
        fi(j, 0, m-1) if ((i >> j) & 1){
            L[i] -= c[j].first;
            M[i] -= c[j].second;
        }
    }
    x = y = u+1;
    L[x] = M[y] = 1e9;
    fi(j, 0, m-1){
        fi(i, 0, u) if (!((i >> j) & 1)){
            int t = u - i - (1 << j);
            if (L[i] + M[t] < L[x] + M[y]) x = i, y = t;
            if (L[t] + M[i] < L[x] + M[y]) x = t, y = i;
        }
    }
    cout << x << ' ' << y << '\n';
    cout << res1 + L[x] + 1 << '\n' << res2 + M[y] + 1;
}
