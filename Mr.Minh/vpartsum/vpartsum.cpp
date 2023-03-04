#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "vpartsum"
const int maxn = 1e5+5;

using namespace std;

int n, k, p, sum, res = 1e9;
set<int> a;

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> k >> p;
    a.insert(0);
    fi(i, 1, n){
        int x;
        cin >> x;
        sum = (sum + x) % p;
        int now = (sum - k + p) % p;
        auto it = a.upper_bound(now);
        if (it == a.begin()) it = a.end();
        if (it != a.begin()) it = prev(it);
        res = min(res, (sum-*it+p) % p);
        a.insert(sum);
    }
    cout << res;
}
