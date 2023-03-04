#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "pushups"
const int maxn = 5005;

using namespace std;

int L[maxn], T[maxn], a[15], m, n;

int calc(int u, int n){
    int best = -1e9;
    if (u == 0) return 0;
    fi(i, 1, m){
        if (u >= n*a[i]) best = max(best, calc(u-n*a[i], n+1) + a[i]);
    }
    return best;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) L[i] = -1;
    fi(i, 1, m){
        cin >> a[i];
    }
    cout << calc(n, 1);
}
