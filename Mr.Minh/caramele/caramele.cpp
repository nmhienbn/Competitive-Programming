#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "caramele"
const int maxn = 1e4 + 5, N = (1 << 10) + 10;
using namespace std;

int n, m, d[15], c[15], a[maxn], vt[maxn];
int L[N], M[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) cin >> a[i], c[a[i]]++, d[a[i]] += i;
    int u = (1 << m) - 1;
    fi(x, 1, u){
        fi(i, 0, m - 1) if (gb(x, i)){
            M[x] = M[x - (1 << i)] + c[i + 1];
            break;
        }
        L[x] = 1e9;
        fi(i, 0, m - 1) if (gb(x, i)){
            int pre = M[x - (1 << i)];
            pre = (pre + c[i + 1]) * (pre + c[i + 1] + 1) - pre * (pre + 1);
            pre /= 2;
            L[x] = min(L[x], L[x - (1 << i)] + abs(d[i + 1] - pre));
        }
    }
    fi(i, 1, u) cout << L[i] << ' ';
    cout << L[u];
}
