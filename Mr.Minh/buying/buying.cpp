#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "buying"
const int maxn = 3005;

using namespace std;

int n;
pii b[maxn];
ll suma, res = 1e18, d[maxn], c[maxn], e[maxn][2], f[maxn][2];

bool cmp(pii a, pii b){
    return a.first - a.second < b.first - b.second;
}

int a(int n){
    return n*(n-1) >> 1;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        int a;
        cin >> a >> b[i].first >> b[i].second;
        b[i].first -= a;
        b[i].second -= a;
        suma += a;
    }
    sort(b+1, b+n+1, cmp);
    fi(i, 1, n){
        d[i] = 1e9;
        fi(j, 1, i){
            e[j][1] = e[j-1][0] + b[i].first - j + 1;
            if (j < i) e[j][1] = min(e[j][1], e[j][0]);
            d[i] = min(d[i], e[j][1]);
        }
        fi(j, 0, i+1){
            e[j][0] = e[j][1];
        }
    }
    fid(i, n, 1){
        c[i] = 1e9;
        fi(j, 1, n-i+1){
            f[j][1] = f[j-1][0] + b[i].second - j + 1;
            if (j < n-i+1) f[j][1] = min(f[j][1], f[j][0]);
            c[i] = min(c[i], f[j][1]);
        }
        fi(j, 0, i+1){
            f[j][0] = f[j][1];
        }
    }
    fi(i, 0, n){
        res = min(res, d[i] + c[i+1]);
    }
    cout << res + suma;
}
