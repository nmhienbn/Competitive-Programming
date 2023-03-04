#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "test"
const int maxn = 205;
using namespace std;

int n, a[maxn], res[maxn];
set<pii> s;
priority_queue<pii> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i], s.insert({a[i], i}), q.push({a[i], i});
    while (q.size()){
        pii x = q.top(); q.pop();
        if (s.end() != s.begin()) s.erase(x);
        int nex = x.first / 2;
        auto it = s.upper_bound({nex, n});
        if (it != s.begin()) it--, res[it -> second] = x.second, s.erase(it);
        it = s.upper_bound({nex, n});
        if (it != s.begin()) it--, res[it -> second] = x.second, s.erase(it);
        if (s.empty()) break;
    }
    fi(i, 1, n) cout << res[i] << '\n';
}
