#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "qbrobot"
const int maxn = 505, maxc = 1e4+5;

using namespace std;

struct dl{
    int f, s, t;
    bool operator < (const dl& x) const {
        return t > x.t;
    }
};

int n, m, res, L[maxn][maxc], minx;
bool kt[maxn];
vector<dl> g[maxn];

bool check(int x){
    priority_queue<dl> q;
    fi(i, 1, n) fi(j, 0, x) L[i][j] = 1e9;
    L[1][x] = 0;
    q.push({1, x, 0});
    while (q.size()){
        int u = q.top().f, l = q.top().s, C = q.top().t;
        q.pop();
        if (L[u][l] < C) continue;
        if (u == n){
            cout << C << ' ';
            if (C <= minx) return false;
            else return true;
        }
        for (auto vt : g[u]){
            int v = vt.f, t = vt.s, c = vt.t;
            if (kt[v]){
                if (l >= c && L[v][x] > L[u][l] + t){
                    L[v][x] = L[u][l] + t;
                    q.push({v, x, L[v][x]});
                    //cout << v << ' ' << x << ' ' << L[v][x] << '\n';
                }
            }
            else {
                if (l >= c && L[v][l-c] > L[u][l] + t){
                    L[v][l-c] = L[u][l] + t;
                    q.push({v, l-c, L[v][l-c]});
                    //cout << v << ' ' << l-c << ' ' << L[v][l-c] << '\n';
                }
            }
        }
    }
    return false;
}


int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> kt[i];
    cin >> m;
    while (m--){
        int i, j, t, c;
        cin >> i >> j >> t >> c;
        g[i].pb({j, t, c});
    }
    check(1e4);
    int minx = *min_element(L[n], L[n]+10001);
    cout << minx << ' ';
    int d = 0, c = 1e4;
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(g)) c = g-1;
        else d = g+1;
    }
    cout << d;
}
