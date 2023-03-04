#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "dquery"
const int maxn = 3e4+5;

using namespace std;

int n, a[maxn], pre[int(1e6+6)], nex[maxn], bit[maxn];
vector<pii> q[maxn];

void update(int x, int val){
    while (x <= n){
        bit[x] += val;
        x += x & -x;
    }
}

int get(int x){
    int ans = 0;
    while (x > 0){
        ans += bit[x];
        x -= x & -x;
    }
    return ans;
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i], pre[a[i]] = n+1;
    fid(i, n, 1){
        nex[i] = pre[a[i]];
        pre[a[i]] = i;
    }
    fid(i, n, 1) a[i] = 1, a[nex[i]] = 0;
    fi(i, 1, n) if (a[i]) update(i, 1);
    int t;
    cin >> t;
    fi(i, 1, t){
        int l, r;
        cin >> l >> r;
        q[l].pb({r, i});
    }
    fi(l, 1, n){
        if (l > 1){
            update(l-1, -1);
            update(nex[l-1], 1);
        }
        int cnt = get(l-1);
        for (auto vt : q[l]){
            int r = vt.first, i = vt.second;
            pre[i] = get(r) - cnt;
        }
    }
    fi(i, 1, t) cout << pre[i] << '\n';
}
