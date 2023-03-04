#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "seaports"
const int maxn = 1e5+5;

using namespace std;

struct dl {
    int f, s, id;
    bool operator < (const dl& x) const {
        return f != x.f ? f < x.f : s < x.s;
    }
};

int m, n, res[maxn], cnt;
dl a[maxn];
priority_queue<pii, vector<pii>, greater<pii>> q;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, n){
        cin >> a[i].f >> a[i].s;
        a[i].id = i;
    }
    sort(a+1, a+n+1);
    q.push({a[1].s, 1});
    res[a[1].id] = 1;
    cnt++;
    fi(i, 2, n){
        int kt = q.top().first, vt = q.top().second;
        if (kt <= a[i].f){
            cnt++;
            res[a[i].id] = vt;
            q.pop();
            q.push({a[i].s, vt});
        }
        else if ((int)q.size() < m){
            cnt++;
            vt = q.size() + 1;
            res[a[i].id] = vt;
            q.push({a[i].s, vt});
        }
    }
    cout << cnt << '\n';
    fi(i, 1, n) cout << res[i] << ' ';
}
