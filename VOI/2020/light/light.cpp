#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "light"
const int maxn = 1e5 + 5;
using namespace std;

int m, n, k;
vector<int> a[maxn];
vector<int> b[maxn];
vector<int> c[maxn];
pii d[maxn];
int res;

int calc(int cl){
    int ans = 0;
    fi(i, 0, m + 1) c[i].assign(n + 2, 0);
    fi(i, 1, m){
        fi(j, 1, n){
            c[i][j] += c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
            while ((a[i][j] + c[i][j]) % 3 != cl){
                if (!b[i][j]) return 1e9;
                int u = d[b[i][j]].first;
                int v = d[b[i][j]].second;
                ans++;
                c[i][j]++;
                c[i][v + 1]--;
                c[u + 1][j]--;
                c[u + 1][v + 1]++;
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n >> k;
    fi(i, 1, m) a[i].assign(n + 2, 0);
    fi(i, 1, m) b[i].assign(n + 2, 0);
    fi(i, 1, m) fi(j, 1, n) cin >> a[i][j];
    fi(i, 1, k){
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        d[i] = {x, y};
        b[u][v] = i;
    }
    int res = min(calc(1), calc(2));
    if (res != 1e9) cout << res;
    else cout << -1;
}
