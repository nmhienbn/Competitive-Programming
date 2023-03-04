#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "fc128_strict"
const int maxn = 2e5+5, mod = 1e9+7;

using namespace std;

int n, a[maxn], cnt = 2;
ll res = 1;

int main(){
    faster
//    freopen(NunuAndWillump".inp", "r", stdin);
//    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    sort(a+1, a+n+1);
    fi(i, 2, n+1){
        if (a[i] == a[i-1] && i <= n) cnt++;
        else {
            res = res * cnt % mod;
            cnt = 2;
        }
    }
    cout << res;
}
