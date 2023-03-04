#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "bamique"
const int maxn = 1e5+5;

using namespace std;

struct dl{
    int f, s, id;
    bool operator < (const dl& x) const{
        return s < x.s;
    }
} a[maxn];

int n, D, res[maxn];
vector<int> b;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> D;
    b.pb(-1);
    fi(i, 1, n){
        cin >> a[i].f >> a[i].s;
        a[i].id = i;
        b.pb(a[i].f + D);
    }
    sort(a+1, a+n+1);
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    a[0].s = 1e9;
    fi(i, 1, b.size() - 1){
        int id = 0;
        fi(j, 1, n){
            if (b[i] + a[j].s >= a[j].f && !res[a[j].id] && a[j].s < a[id].s){
                id = j;
            }
        }
        res[a[id].id] = b[i] + a[id].s;
    }
    fi(i, 1, n) cout << res[i] << '\n';
}
