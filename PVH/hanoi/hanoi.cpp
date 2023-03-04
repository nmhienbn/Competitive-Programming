#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "hanoi"
const int maxn = 1005;
const int ngg[] = {-1, 0, 1, 0};
const int doc[] = {0, -1, 0, 1};
using namespace std;

int m, n, k, res;
int8_t a[maxn][maxn];
bool cl[maxn][maxn];
pii f[maxn * maxn];
int cnt;
queue<pii> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n >> k;
    fi(i, 1, m) fi(j, 1, n){
        char c;
        cin >> c;
        if (c == '.') a[i][j] = 1;
        else a[i][j] = 2;
    }
    fi(i, 1, m) fi(j, 1, n) if (a[i][j] == 1 && !cl[i][j]){
        bool flag = 1;
        int dem = 1;
        cl[i][j] = 1;
        q.push({i, j});
        while (q.size()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            fi(t, 0, 3){
                int u = i + ngg[t];
                int v = j + doc[t];
                if (a[u][v] == 0) flag = 0;
                if (a[u][v] == 1 && !cl[u][v]){
                    dem++;
                    cl[u][v] = 1;
                    q.push({u, v});
                }
            }
        }
        if (flag) f[++cnt] = {dem,  i * n + j - 1};
    }
    sort(f + 1, f + cnt + 1, greater<pii>());
    fi(rep, k + 1, cnt){
        res += f[rep].first;
        q.push({f[rep].second / n, f[rep].second % n + 1});
        a[q.front().first][q.front().second] = 2;
        while (q.size()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            fi(t, 0, 3){
                int u = i + ngg[t];
                int v = j + doc[t];
                if (a[u][v] == 1){
                    a[u][v] = 2;
                    q.push({u, v});
                }
            }
        }
    }
    cout << res << '\n';
    fi(i, 1, m){
        fi(j, 1, n) cout << (a[i][j] == 1 ? '.' : '#');
        cout << '\n';
    }
}
