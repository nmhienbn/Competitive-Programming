#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "pageant"
const int maxn = 55,
            ngg[4] = {1, -1, 0, 0},
            doc[4] = {0, 0, -1, 1};

using namespace std;

int n, m, res = 1e9;
int a[maxn][maxn];
vector<pii> typ[3];

void mark(){
    fi(i, 1, m) fi(j, 1, n){
        if (!a[i][j]) continue;
        queue<pii> q;
        q.push({i, j});
        a[i][j] = 2;
        while (q.size()){
            int u = q.front().first;
            int v = q.front().second;
            q.pop();
            fi(t, 0, 3){
                int uu = u + ngg[t];
                int vv = v + doc[t];
                if (a[uu][vv] == 1){
                    a[uu][vv] = 2;
                    q.push({uu, vv});
                }
            }
        }
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m){
        fi(j, 1, n){
            char c;
            cin >> c;
            a[i][j] = (c == 'X');
        }
    }
    mark();
    fi(i, 1, m){
        fi(j, 1, n){
            if (a[i][j]){
                typ[a[i][j]].pb({i, j});
            }
        }
    }
    for (pii u : typ[1]){
        for (pii v : typ[2]){
            res = min(res, abs(u.first - v.first) + abs(u.second - v.second) - 1);
        }
    }
    cout << res;
}
