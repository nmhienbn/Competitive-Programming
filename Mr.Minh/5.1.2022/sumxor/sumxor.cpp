#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "sumxor"
const int maxn = 1e5 + 5;
using namespace std;

int n, m, a[maxn], b[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n) b[i] = b[i - 1] ^ a[i];
    while (m--){
        int l, r;
        cin >> l >> r;
        cout << (b[r] ^ b[l - 1]) << '\n';
    }
}
