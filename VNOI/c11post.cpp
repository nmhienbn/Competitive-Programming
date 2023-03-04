#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "c11post"
const int maxn = 105;
const int ngg[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
const int doc[8] = {0, 0, -1, 1, -1, 1, 1, -1};

using namespace std;

int n, m, a[maxn][maxn];
int kt[maxn][maxn], cnt;
int sx, sy, maxa, mina;
vector<int> h;
vector<pii> vt;
queue<pii> q;

void bfs(int L, int R){
    q.push({sx, sy});
    while (q.size()){
        int i = q.front().first, j = q.front().second;
        q.pop();
        fi(t, 0, 7){
            int u = i + ngg[t], v = j + doc[t];
            if (L <= a[u][v] && a[u][v] <= R && kt[u][v] < cnt){
                kt[u][v] = cnt;
                q.push({u, v});
            }
        }
    }
}

bool check(int g){
    for (int val : h){
        if (val > mina) break;
        if (val + g < maxa) continue;
        cnt++;
        bfs(val, val + g);
        bool flag = 1;
        for (pii it : vt){
            if (kt[it.first][it.second] < cnt){
                flag = 0;
                break;
            }
        }
        if (flag) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m) fi(j, 1, n){
        char c;
        cin >> c;
        if (c == 'P') sx = i, sy = j;
        if (c == 'K') vt.pb({i, j});
    }
    fi(i, 0, m + 1) a[i][0] = a[i][n + 1] = -1;
    fi(i, 0, n + 1) a[0][i] = a[m + 1][i] = -1;
    fi(i, 1, m) fi(j, 1, n){
        cin >> a[i][j];
        h.pb(a[i][j]);
    }
    sort(h.begin(), h.end());
    h.resize(unique(h.begin(), h.end()) - h.begin());
    maxa = mina = a[sx][sy];
    for (pii it : vt){
        maxa = max(maxa, a[it.first][it.second]);
        mina = min(mina, a[it.first][it.second]);
    }
    int d = 0, c = h.back() - h.front();
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(g)) c = g - 1;
        else d = g + 1;
    }
    cout << d;
   // cout << ' ' << check(8);
}
