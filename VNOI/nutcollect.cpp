#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define minimize(x,y) x = x > y ? y : x
#define pb push_back
#define ll long long
#define Irelia "nutcollect"
const int maxn = 305;
const int sx[4] = {-1, 0, 1, 0};
const int sy[4] = {0, -1, 0, 1};
using namespace std;

int m, n, dx, dy, k;
char a[maxn][maxn];
string s;
vector<pii> g[26];
int f[maxn][maxn][maxn];
deque<tuple<int, int, int>> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n >> dx >> dy;
    fi(i, 1, m) fi(j, 1, n){
        cin >> a[i][j];
    }
    cin >> s;
    k = s.size();
    memset(f, -1, sizeof f);
    f[0][dx][dy] = 0;
    q.push_front({0, dx, dy});
    while (q.size()){
        int i = get<0>(q.front());
        int u = get<1>(q.front());
        int v = get<2>(q.front());
        q.pop_front();
        if (i == k){
            cout << f[i][u][v];
            exit(0);
        }
        if (a[u][v] == s[i] && f[i + 1][u][v] == -1){
            f[i + 1][u][v] = f[i][u][v];
            q.push_front({i + 1, u, v});
        }
        fi(j, 0, 3){
            int x = u + sx[j], y = v + sy[j];
            if (a[x][y] < 'a' || a[x][y] > 'z') continue;
            if (f[i][x][y] == -1){
                f[i][x][y] = f[i][u][v] + 1;
                q.push_back({i, x, y});
            }
        }
    }
}
