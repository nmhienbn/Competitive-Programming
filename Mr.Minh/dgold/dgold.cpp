#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "dgold"
const int maxn = 540000;

using namespace std;

struct dl {
    int f, s;
    bool operator < (const dl& x) const {
        return f != x.f ? f < x.f : s < x.s;
    }
};

int n, m, a[15], b[15], mu[15], u, v, res;
dl L[maxn], M[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    m = n - n/2;
    n = n/2;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, m) cin >> b[i];
    mu[0] = 1;
    fi(i, 1, 12) mu[i] = mu[i-1] * 3;

    u = mu[n] - 1;
    v = mu[m] - 1;
    fi(x, 0, u){
        int y = x;
        fi(i, 0, n-1){
            L[x].f += (y%3 - 1) *a[i+1];
            L[x].s += (y%3 != 1)*a[i+1];
            y /= 3;
        }
    }
    fi(x, 0, v){
        int y = x;
        fi(i, 0, m-1){
            M[x].f += (y%3 - 1) *b[i+1];
            M[x].s += (y%3 != 1)*b[i+1];
            y /= 3;
        }
    }
    sort(L, L+u+1);
    sort(M, M+v+1);

    int j = v;
    fi(i, 0, u){
        while (L[i].f + M[j].f > 0 && j >= 0) j--;
        if (L[i].f + M[j].f == 0) res = max(res, L[i].s + M[j].s);
    }
    cout << res/2;
}
