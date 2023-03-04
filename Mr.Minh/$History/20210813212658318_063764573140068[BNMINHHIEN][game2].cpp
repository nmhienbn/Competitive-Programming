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

int t, n, a[maxn], b[2], L[maxn][maxn][2];

int tinh(int u, int v, int id){
    if (L[u][v][id] != -1) return L[u][v][id];
    if (u > v){
        if (b[0] > b[1]) return L[u][v][id] = 1;
        if (b[0] == b[1]) return L[u][v][id] = 0;
        if (b[0] < b[1]) return L[u][v][id] = -1;
    }
    if (u == v){
        b[id] += a[u];
        if (b[0] > b[1]){
            b[id] -= a[u];
            return L[u][v][id] = 1;
        }
        if (b[0] == b[1]){
            b[id] -= a[u];
            return L[u][v][id] = 0;
        }
        if (b[0] < b[1]){
            b[id] -= a[u];
            return L[u][v][id] = -1;
        }
    }
    int best = -2;
    b[id] += a[u];
    best = max(best, tinh(u+1, v, id^1));
    b[id] += a[v] - a[u];
    best = max(best, tinh(u, v-1, id^1));
    b[id] = b[id] - a[v] + a[u]*a[v];
    if (v-u > 1) best = max(best, tinh(u+1, v-1, id^1));
    b[id] -= a[u]*a[v];
    return L[u][v][id] = best;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> t;
    while (t--){
        cin >> n;
        memset(L, -1, sizeof(L));
        b[0] = b[1] = 0;
        fi(i, 1, n){
            cin >> a[i];
        }
    }
    int tt = tinh(1, n, 0);
    if(tt == 0) cout << "DRAW\n";
    if(tt == 1) cout << "HT\n";
    if(tt == -1) cout << "ATM\n";
}
