#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "beads"
const int maxn = 1e5+5;

using namespace std;

int n, a[maxn], lis[maxn], lds[maxn], b[maxn], k;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    k = 1;
    b[1] = a[n];
    lis[n] = 1;
    fid(i, n-1, 1){
        int d = 1, c = k;
        while (d <= c){
            int g = (d + c) >> 1;
            if (b[g] > a[i]) d = g+1;
            else c = g-1;
        }
        if (c == k) b[++k] = 0;
        b[c+1] = max(b[c+1], a[i]);
        lis[i] = c+1;
    }
    fi(i, 1, k) b[i] = 0;
    k = 1;
    b[1] = a[n];
    lds[n] = 1;
    fid(i, n-1, 1){
        int d = 1, c = k;
        while (d <= c){
            int g = (d + c) >> 1;
            if (b[g] < a[i]) d = g+1;
            else c = g-1;
        }
        if (c == k) b[++k] = 1e9+1;
        b[c+1] = min(b[c+1], a[i]);
        lds[i] = c+1;
    }
    int res = 0;
    fi(i, 1, n) res = max(res, lis[i]+lds[i]-1);
    cout << res;
}
