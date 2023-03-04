#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "increasing"
const int maxn = 2e5+5;
using namespace std;

int n, h, a[maxn], L[maxn][20];
ll s[maxn], res = 1e18, now;

int get(int l, int r){
    int t = log2(r-l+1);
    return max(L[l][t], L[r+1 - (1 << t)][t]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> h;
    fi(i, 1, n) cin >> a[i], s[i] = s[i-1] + a[i];
    fi(i, 1, n) L[i][0] = a[i]-i;
    int zz = log2(n);
    fi(j, 1, zz){
        fi(i, 1, n+1 - (1 << j)){
            L[i][j] = max(L[i][j-1], L[i + (1 << (j-1))][j-1]);
        }
    }
    now = 1ll*h*(h+1)/2;
    fi(i, 1, n-h+1){
        if (get(i, i+h-1) <= 1-i){
            res = min(res, now-s[i+h-1]+s[i-1]);
        }
    }
    cout << (res == 1e18 ? -1 : res);
}
