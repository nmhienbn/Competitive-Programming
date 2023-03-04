#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "seq3n"
const int maxn = 1e5 + 5;
using namespace std;

int n;
int a[maxn * 3];
priority_queue<int, vector<int>, greater<int>> q1;
priority_queue<int> q2;
ll f[maxn], now, res = -1e18;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//    freopen(Irelia".inp", "r", stdin);
//    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n * 3) cin >> a[i];
    fi(i, 1, n) f[0] += a[i], q1.push(a[i]);
    fi(i, 1, n){
        q1.push(a[i + n]);
        f[i] = f[i - 1] + a[i + n] - q1.top();
        q1.pop();
    }
    fi(i, n * 2 + 1, n * 3) q2.push(a[i]), now += a[i];
    fid(i, n, 0){
        res = max(res, f[i] - now);
        q2.push(a[i + n]);
        now += a[i + n] - q2.top();
        q2.pop();
    }
    cout << res;
}
