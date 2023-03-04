#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "game"
const int maxn = 10005;
using namespace std;

int n, m, nt, a[maxn], b[maxn], A, B;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> nt;
    while (nt--){
        cin >> n >> m;
        fi(i, 1, n) cin >> a[i];
        fi(i, 1, n) cin >> b[i];
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1, greater<int>());
        A = B = 0;
        fi(i, 1, m) A += a[i], B += b[i];
        if (A > B) cout << "YES\n";
        else cout << "NO\n";
    }

}
