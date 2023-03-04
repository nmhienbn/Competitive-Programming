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

int n, m, w, b, d[maxn][2];
int16_t L[maxn][maxn][2];
bool M[maxn][maxn][2];
vector<int> g[maxn][2];

void calc(int u, int v, int t){
    if (L[u][v][t] != -1) return;
    if (t == 0){
        if (g[u][0].empty()){
            L[u][v][0] = 0;
            M[u][v][0] = 0;
        }
        else {
            int win = 1e9, los = -1;
            for (int v1 : g[u][0]){
                calc(v1, v, 1);
                if (M[v1][v][1]) los = max(los, L[v1][v][1]+1);
                else win = min(win, L[v1][v][1]+1);
            }
            if (win < 1e9) L[u][v][0] = win, M[u][v][0] = 1;
            else L[u][v][0] = los, M[u][v][0] = 0;
        }
    }
    else {
        if (g[v][1].empty()){
            L[u][v][1] = 0;
            M[u][v][1] = 0;
        }
        else {
            int win = 1e9, los = -1;
            for (int u1 : g[v][1]){
                calc(u, u1, 0);
                if (M[u][u1][0]) los = max(los, L[u][u1][0]+1);
                else win = min(win, L[u][u1][0]+1);
            }
            if (win < 1e9) L[u][v][1] = win, M[u][v][1] = 1;
            else L[u][v][1] = los, M[u][v][1] = 0;
        }
    }
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> m >> w >> b;
    fi(i, 1, n){
        int u, v;
        cin >> u >> v;
        g[u][0].pb(v);//co cung xuoi
        g[v][1].pb(u);//co cung nguoc
        d[u][0]++;
        d[v][1]++;
    }
    fi(u, 1, n){
        fi(i, 0, 1){
            if (d[u][i] == 0){
                for (int v : g[u][1-i]){

                }
            }
        }
    }
}
