#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "balloon"
const int maxn = 2e5 + 5;
using namespace std;

int n, m, k, now, pre, a[maxn];
ll f[2][maxn];
int q[maxn], d, c;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> k;
    fi(i, 1, n) cin >> a[i], f[1][i] = a[i];
    fi(t, 2, k){
        now = t & 1;
        pre = now ^ 1;
        d = 1, c = 0;
        fi(i, 1, t - 1){
            while (d <= c && f[pre][q[c]] <= f[pre][i]) c--;
            q[++c] = i;
        }
        fi(i, t, n){
            while (q[d] < i - m) d++;
            f[now][i] = f[pre][q[d]] + 1ll * t * a[i];
            while (d <= c && f[pre][q[c]] <= f[pre][i]) c--;
            q[++c] = i;
        }
    }
    cout << *max_element(f[now] + k, f[now] + n + 1);
}
