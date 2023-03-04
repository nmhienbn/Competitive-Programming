#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "tfield"
const int maxn = 1005;
using namespace std;

int n, m, k;
pair<ll, int> a[maxn];
int x[maxn], y[maxn];
bool cl[maxn];
ll res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen(Irelia".inp", "r", stdin);
    //freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n){
        cin >> m >> a[i].second;
        fi(j, 1, m) cin >> x[j] >> y[j];
        x[m + 1] = x[1], y[m + 1] = y[1];
        fi(j, 1, m){
            a[i].first += 1ll * x[j] * y[j + 1] - 1ll * y[j] * x[j + 1];
        }
        if (a[i].first < 0) a[i].first = - a[i].first;
    }
    sort(a + 1, a + n + 1, greater<pair<ll, int>>());
    fi(i, 1, n){
        a[i].first -= a[i + 1].first;
    }
    fi(i, 1, n) if (!cl[a[i].second]){
        cl[a[i].second] = 1;
        int cnt = 0;
        ll S = 0;
        int t = 1;
        fi(j, 1, n){
            S += a[j].first;
            cnt += (a[j].second != a[i].second);
            while (cnt > k){
                S -= a[t].first;
                cnt -= (a[t].second != a[i].second);
                t++;
            }
            if (S > res) res = S;
        }
    }
    cout << res / 2 << '.' << (res & 1 ? 5 : 0);
}
