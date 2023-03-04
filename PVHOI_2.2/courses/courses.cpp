#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "courses"
const int maxn = 2005, maxm = 3e5 + 5;
using namespace std;

int n, m, a[maxn];
int f[maxm];
pair<ll, int> q[maxm];

int getAns(ll x){
    priority_queue<int, vector<int>, greater<int>> q;
    fi(i, 1, n){
        x += a[i];
        q.push(a[i]);
        while (x < 0){
            x -= q.top();
            q.pop();
        }
    }
    return q.size();
}

void solve(int l, int r, int minA, int maxA){
    if (l > r) return;
    if (minA == maxA){
        fi(i, l, r) f[q[i].second] = minA;
        return;
    }
    int m = (l + r) >> 1;
    int tmp = getAns(q[m].first);
    f[q[m].second] = tmp;
    solve(l, m - 1, minA, tmp);
    solve(m + 1, r, tmp, maxA);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n){
        cin >> a[i];
    }
    fi(i, 1, m){
        ll x;
        cin >> x;
        q[i] = {x, i};
    }
    sort(q + 1, q + m + 1);
    solve(1, m, 0, n);
    fi(i, 1, m) cout << f[i] << ' ';
}
