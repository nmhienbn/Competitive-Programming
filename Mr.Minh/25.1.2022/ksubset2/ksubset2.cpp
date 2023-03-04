#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "ksubset2"
const int maxn = 25;
const int N = 1 << 20;
const ll INF = 1e18;
using namespace std;

int n, k;
int a[maxn];
ll b[maxn], sa, sb;
pair<int, ll> f[N];
int pre[N], kq[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n) cin >> a[i], sa += a[i];
    fi(i, 1, k) cin >> b[i], sb += b[i];
    if (sa != sb){
        cout << "NO\n";
        exit(0);
    }
    b[k + 1] = 1e18;
    int u = (1 << n) - 1;
    fi(i, 1, u) f[i].second = -INF;
    fi(x, 0, u - 1){
        fi(i, 1, n) if (!gb(x, i - 1)){
            pair<int, ll> tg = f[x];
            tg.second += a[i];
            if (tg.second == b[tg.first + 1]) tg.first++, tg.second = 0;
            if (tg > f[x | (1 << (i - 1))]){
                f[x | (1 << (i - 1))] = tg;
                pre[x | (1 << (i - 1))] = i - 1;
            }
        }
    }
    if (f[u].first < k){
        cout << "NO\n";
        exit(0);
    }
    fi(rep, 1, n){
        int vt = pre[u] + 1;
        u -= (1 << pre[u]);
        kq[vt] = f[u].first + 1;
    }
    cout << "YES\n";
    fi(i, 1, n) cout << kq[i] << ' ';
}
