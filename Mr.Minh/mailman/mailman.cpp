#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "mailman"
const int maxn = 105,
            ngg[8] = {-1, 1, 0, 0, -1, 1, -1, 1},
            doc[8] = {0, 0, -1, 1, -1, 1, 1, -1};

using namespace std;

int n, a[maxn][maxn];
int kt[maxn][maxn], cnt;
int sx, sy, maxa, mina;
vector<int> h;
vector<pii> vt;

void dfs(int i, int j, int L, int R){
    fi(t, 0, 7){
        int u = i + ngg[t], v = j + doc[t];
        if (L <= a[u][v] && a[u][v] <= R && kt[u][v] < cnt){
            kt[u][v] = cnt;
            dfs(u, v, L, R);
        }
    }
}

bool check(int g){
    for (int val : h){
        if (val > mina) break;
        if (val + g < maxa) continue;
        cnt++;
        dfs(sx, sy, val, val + g);
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
    cin >> n;
    fi(i, 1, n) fi(j, 1, n){
        char c;
        cin >> c;
        if (c == 'P') sx = i, sy = j;
        if (c == 'K') vt.pb({i, j});
    }
    fi(i, 1, n) fi(j, 1, n){
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
}
