#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "divide"
const int maxn = 1e5+5, mod = 1e9+7;

using namespace std;

int n, a[maxn];
ll b[maxn][2];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 2, n){
        int u;
        cin >> u;
        u++;
        a[i] = u;
    }
    fi(i, 1, n){
        int x;
        cin >> x;
        b[i][x] = 1;
    }
    fid(i, n, 1){
        b[a[i]][1] = (b[a[i]][1] * (b[i][0] + b[i][1]) % mod + b[a[i]][0] * b[i][1] % mod) % mod;
        b[a[i]][0] = b[a[i]][0] * (b[i][0] + b[i][1]) % mod;
    }
    cout << b[1][1];
}
