#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "game2"
const int maxn = 505;

using namespace std;

int t, n;
ll a[maxn], L[maxn][maxn];

ll tinh(int u, int v){
    if (L[u][v] != -1) return L[u][v];
    if (u == v) return L[u][v] = u;
    if (u > v) return L[u][v] = 0;
    ll best = max(u - tinh(u+1, v), v - tinh(u, v-1));
    if (v > u) best = max(best, u*v - tinh(u+1, v-1));
    return L[u][v] = best;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> t;
    while (t--){
        cin >> n;
        memset(L, -1, sizeof(L));
        fi(i, 1, n){
            cin >> a[i];
        }
    }
    ll tt = tinh(1, n);
    if(tt > 0) cout << "HT\n";
    if(tt == 0) cout << "DRAW\n";
    if(tt < 0) cout << "ATM\n";
}
