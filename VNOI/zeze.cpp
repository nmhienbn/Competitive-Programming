#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "zeze"
const int maxn = 1e5 + 5;
using namespace std;

int n, a, v2, v5;

int v(int p, int& n){
    int ans = 0;
    while (n % p == 0){
        ans++;
        n /= p;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//    freopen(Irelia".inp", "r", stdin);
//    freopen(Irelia".out", "w", stdout);
    cin >> n;
    while (n--){
        cin >> a;
        v2 += v(2, a);
        v5 += v(5, a);
    }
    cout << min(v2, v5);
}
