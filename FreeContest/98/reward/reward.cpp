#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "reward"
const int maxn = 1e5 + 5;
using namespace std;

int n, x, pre, now;
ll f[2][3];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//    freopen(Irelia".inp", "r", stdin);
//    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> x;
        now = i & 1, pre = now ^ 1;
        f[now][1] = f[pre][0] + x;
        f[now][2] = f[pre][1] + x;
        f[now][0] = max({f[pre][0], f[pre][1], f[pre][2]});
    }
    cout << max({f[now][0], f[now][1], f[now][2]});
}
