#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "firtree"
const int maxn = 1e5 + 5;

using namespace std;

int n, m, u, v;
ll a[maxn], b[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    fi(i, 2, n) cin >> b[i], b[i] = b[i - 1] - b[i];
    sort(b + 1, b + n + 1);
    cin >> m;
    while (m--){
        cin >> u >> v;
        cout << a[u] + a[v] + abs(b[v] - b[u]) << '\n';
    }
}
