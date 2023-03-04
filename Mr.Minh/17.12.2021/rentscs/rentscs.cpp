#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "rentscs"
const int maxn = 1e4+5;

using namespace std;

struct dl {
    int l, r, ok, id;
    bool operator < (const dl& x) const {
        return l != x.l ? l < x.l : r < x.r;
    }
} a[maxn];

int n, m, k, now;
bool kt[maxn];
priority_queue<pii, vector<pii>, greater<pii>> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> k;
    fi(i, 1, k){
        int t, l, g;
        cin >> t >> l >> g;
        a[i] = {t, l+t, g, i};
    }
    sort(a+1, a+k+1);

    q.push({a[1].r, a[1].ok});
    now += a[1].ok;
    kt[a[1].id] = 1;
    fi(i, 2, k){
        pii u = q.top();
        if (u.first <= a[i].l && now - u.second + a[i].ok <= m){
            kt[a[i].id] = 1;
            now += a[i].ok - u.second;
            q.pop();
            q.push({a[i].r, a[i].ok});
        }
        else if ((int)q.size() < n && now + a[i].ok <= m){
            kt[a[i].id] = 1;
            q.push({a[i].r, a[i].ok});
            now += a[i].ok;
        }
    }
    fi(i, 1, k){
        cout << (kt[i] ? "Yes\n" : "No\n");
    }
}
