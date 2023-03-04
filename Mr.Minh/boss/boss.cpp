#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "boss"
const int maxn = 3e5+5;

using namespace std;

struct dl {
    int f, s, t;
    bool operator < (const dl& x) const {
        return t != x.t ? t < x.t : s < x.s;
    }
};

int n, q, test, sep[maxn], linh[maxn];
dl a[maxn];

struct cmp{
    bool operator() (int i, int j){
        return a[i].s != a[j].s ? a[i].s < a[j].s : i < j;
    }
};

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> test;
    while (test--){
        cin >> n >> q;
        fi(i, 1, n) cin >> a[i].f >> a[i].s >> a[i].t;
        sort(a+1, a+n+1);
        set<int, cmp> s;
        map<int, int> ma;
        fi(i, 1, n) ma[a[i].f] = i;
        fi(i, 1, n) linh[i] = 0;
        fid(i, n, 1){
            auto vt = s.upper_bound(i);
            sep[i] = vt == s.end() ? 0 : *vt;
            s.insert(i);
        }
        fi(i, 1, n) if (sep[i]) linh[sep[i]] += linh[i] + 1;
        fi(i, 1, q){
            int x;
            cin >> x;
            int id = ma[x];
            cout << a[sep[id]].f << ' ' << linh[id] << '\n';
        }
    }
}
