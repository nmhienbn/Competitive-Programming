#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "labudovi"
const int maxn = 1505,
        doc[4] = {-1, 1, 0, 0},
        ngg[4] = {0, 0, -1, 1};

using namespace std;

int n, m, a[maxn][maxn], d, c;
pii st, fn;
pii q[maxn*maxn];
bool kt[maxn][maxn];

void bfs(int g){
    int d = 0, c = 0;
    q[++c] = st;
    kt[st.first][st.second] = 1;
    while (d <= c){
        int u = q[++d].first, v = q[d].second;
        fi(i, 0, 3){
            int uu = u + doc[i], vv = v + ngg[i];
            if (0 < a[uu][vv] && a[uu][vv] <= g && !kt[uu][vv]){
                kt[uu][vv] = 1;
                q[++c] = {uu, vv};
            }
        }
    }
}

bool check(int g){
    fi(i, 1, n) fi(j, 1, m) kt[i][j] = 0;
    bfs(g);
    return kt[fn.first][fn.second];
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n){
        fi(j, 1, m){
            char t;
            cin >> t;
            if (t == 'L'){
                a[i][j] = 1;
                q[++c] = {i, j};
                if (st.first != 0) fn = {i, j};
                else st = {i, j};
            }
            else if (t == 'X'){
                a[i][j] = 1e9;
            }
            else {
                a[i][j] = 1;
                q[++c] = {i, j};
            }
        }
    }
    while (d <= c){
        int u = q[++d].first, v = q[d].second;
        fi(i, 0, 3){
            int uu = u + doc[i], vv = v + ngg[i];
            if (a[uu][vv] > a[u][v] + 1){
                a[uu][vv] = a[u][v] + 1;
                q[++c] = {uu, vv};
            }
        }
    }
    d = 1, c = m*n+1;
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(g)) c = g-1;
        else d = g+1;
    }
    cout << d-1;
}
