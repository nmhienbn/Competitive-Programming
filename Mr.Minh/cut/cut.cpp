#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "cut"
const int maxn = 0;
using namespace std;

int n, m, k, a, b;
ll res = 1;

void calc(int a, int b){
    a = min(a, n);
    b = min(b, m);
    res = max(res, 1ll * a * b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> k;
    k += 2;
    calc(k/2, k-k/2);
    calc(k-k/2, k/2);
    calc(min(n, k), k-min(n, k));
    calc(k-min(m, k), min(m, k));
    cout << res;
}
