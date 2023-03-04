#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "ezgame"
const int maxn = 5005;

using namespace std;

int n, m, w, b;
int16_t L[maxn][maxn];
bool M[maxn][maxn];
vector<int> g[maxn][2];

void calc(int u, int v){
    if (L[u][v] != -1) return;
    fi(t, 0, 1){
        int win = 1e9, los = 0;
        for (int v1 : g[u][0]){
            calc(v1, v);
            if (M[v1][v]) los = max(los, L[v1][v]+1);
            else win = min(win, L[v1][v]+1);
        }
        for (int u1 : g[v][1]){
            calc(u, u1);
            if (M[u][u1]) los = max(los, L[u][u1]+1);
            else win = min(win, L[u][u1]+1);
        }
        if (win < 1e9) L[u][v] = win, M[u][v] = 1;
        else L[u][v] = los, M[u][v] = 0;
    }
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> m >> w >> b;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[u][0].pb(v);
        g[v][1].pb(u);
    }
    fi(i, 1, n) fi(j, 1, n) L[i][j] = -1;
    calc(w, b);
    cout << L[w][b];
}
