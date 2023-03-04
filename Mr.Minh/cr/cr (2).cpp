#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "cr"
const int maxn = 15;

using namespace std;

struct dl {
    int f, s, k, t;
    bool operator < (const dl& x) const {
        return f != x.f ? f > x.f : s > x.s;
    }
};

ll L[maxn][maxn][2][5005];
int m, n, l, x, y, z;
priority_queue<dl> q;

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> m >> n >> l >> x >> y >> z;
    L[1][0][0][0] = 1;
    L[0][1][1][0] = 1;
    q.push({1, 0, 0, 0});
    q.push({0, 1, 1, 0});
    while (q.size()){
        int u = q.top().f, v = q.top().s, k = q.top().k, w = q.top().t;
        q.pop();
        if (k == 0){
            if (u < m && w + x <= l){
                L[u+1][v][0][w+x] += L[u][v][0][w];
                q.push({u+1, v, 0, w+x});
            }
            if (v < n && w + z*abs(u-v-1) <= l){
                L[u][v+1][1][w + z*abs(u-v-1)] += L[u][v][0][w];
                q.push({u, v+1, 1, w + z*abs(u-v-1)});
            }
        }
        else {
            if (u < m && w + z*abs(u+1-v) <= l){
                L[u+1][v][0][w+abs(u+1-v)] += L[u][v][1][w];
                q.push({u+1, v, 0, w+abs(u+1-v)});
            }
            if (v < n && w + y <= l){
                L[u][v+1][1][w+y] += L[u][v][1][w];
                q.push({u, v+1, 1, w+y});
            }
        }
    }
    ll res = 0;
    fi(j, 0, 1) fi(i, 0, l) res += L[m][n][j][i];
    cout << res;
}
