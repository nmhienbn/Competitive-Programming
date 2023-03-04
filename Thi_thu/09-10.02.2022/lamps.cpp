#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "lamps"
const int maxn = 1e6 + 6;
using namespace std;

int n, m, a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 0, n - 1) cin >> a[i];
    fi(rep, 1, m){
        a[n] = a[0];
        fi(i, 0, n - 1) a[i] ^= a[i + 1];
    }
    fi(i, 0, n - 1) cout << a[i] << '\n';
}
