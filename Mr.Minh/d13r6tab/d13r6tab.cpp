#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "d13r6tab"
const int maxn = 105, N = (1 << 16) + 5;
using namespace std;

int n, a[maxn][maxn], b[maxn][maxn], st, fn[maxn], m, f[N], pre[N];
pii luu[N], gt[N];
bool kt[N];

int tt(int a[][maxn]){
    int cnt = 0, ans = 0;
    fi(i, 1, n) fi(j, 1, n){
        ans += (a[i][j] << cnt);
        cnt++;
    }
    return ans;
}

void bfs(){
    st = tt(a);
    fn[++m] = tt(b);
    fi(i, 1, n) fi(j, 1, n){
        b[i][j] ^= 1;
        fn[++m] = tt(b);
        b[i][j] ^= 1;
    }
    fi(i, 1, m) kt[fn[i]] = 1;
    queue<int> q;
    q.push(st);
    f[st] = 1;
    while (q.size()){
        int u = q.front();
        q.pop();
        int uu = u;
        fi(i, 1, n) fi(j, 1, n){
            a[i][j] = (uu & 1);
            uu = uu >> 1;
        }
        fi(t, 1, n - 1){
            fi(i, 1, n) swap(a[i][t], a[i][t + 1]);
            int v = tt(a);
            if (!f[v]){
                f[v] = f[u] + 1;
                pre[v] = u;
                luu[v] = {1, t};
                if (kt[v]) return;
                q.push(v);
            }
            fi(i, 1, n) swap(a[i][t], a[i][t + 1]);
        }
        fi(t, 1, n){
            fi(i, 1, n) a[t][i] ^= 1;
            int v = tt(a);
            if (!f[v]){
                f[v] = f[u] + 1;
                pre[v] = u;
                luu[v] = {2, t};
                if (kt[v]) return;
                q.push(v);
            }
            fi(i, 1, n) a[t][i] ^= 1;
        }
    }
}

void sub1(){
    bfs();
    fi(i, 1, m) if (f[fn[i]] > 0){
        int u = fn[i];
        cout << f[fn[i]] - 1 << '\n';
        fid(j, f[fn[i]] - 1, 1){
            gt[j] = luu[u];
            u = pre[u];
        }
        fi(j, 1, f[fn[i]] - 1) cout << gt[j].first << ' ' << gt[j].second << '\n';
        exit(0);
    }
    cout << -1;
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) fi(j, 1, n) cin >> a[i][j];
    fi(i, 1, n) fi(j, 1, n) cin >> b[i][j];

    if (n <= 4) sub1();
    cout << -1;
}
