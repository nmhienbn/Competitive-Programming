#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "lqddiv"
const int maxn = 66000;

using namespace std;

int n, m, a[maxn], b[maxn], u, v;
ll L[maxn], M[maxn], e[maxn], f[maxn], res = 1e9, cnt;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    m = n - n/2;
    n = n/2;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, m) cin >> b[i];
    u = (1 << n) - 1;
    v = (1 << m) - 1;

    fi(x, 0, u){
        fi(i, 0, n-1){
            if ((x >> i) & 1) L[x] += a[i+1];
            else L[x] -= a[i+1];
        }
    }
    fi(x, 0, v){
        fi(i, 0, m-1){
            if ((x >> i) & 1) M[x] += b[i+1];
            else M[x] -= b[i+1];
        }
    }

    sort(L, L+u+1);
    sort(M, M+v+1);

    m = n = 0;
    fi(i, 0, u){
        if (i == 0 || L[i] != L[i-1]){
            e[++n] = L[i];
            a[n] = 0;
        }
        a[n]++;
    }
    fi(i, 0, v){
        if (i == 0 || M[i] != M[i-1]){
            f[++m] = M[i];
            b[m] = 0;
        }
        b[m]++;
    }
    fi(i, 1, n){
        int d = 1, c = m;
        while (d <= c){
            int g = (d + c) >> 1;
            if (e[i] + f[g] >= 0) c = g-1;
            else d = g+1;
        }
        if (abs(e[i] + f[d]) < res && d <= m){
            res = abs(e[i] + f[d]);
            cnt = 1ll*a[i]*b[d];
        }
        else if (abs(e[i] + f[d]) == res && d <= m){
            cnt += 1ll*a[i]*b[d];
        }
        if (abs(e[i] + f[d-1]) < res && d > 0){
            res = abs(e[i] + f[d-1]);
            cnt = 1ll*a[i]*b[d-1];
        }
        else if (abs(e[i] + f[d-1]) == res && d > 0){
            cnt += 1ll*a[i]*b[d-1];
        }
    }
    cout << res << ' ' << cnt/2;
}
