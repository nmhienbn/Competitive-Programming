#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "shoes"
const int maxn = 1e5+5;

using namespace std;

struct pii {
    int f, s;
    bool operator < (const pii& x) const {
        return f < x.f;
    }
};

int n, m, res;
pii a[maxn], b[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n){
        cin >> a[i].f;
        a[i].s = i;
    }
    fi(i, 1, m){
        cin >> b[i].f >> b[i].s;
    }
    sort(a+1, a+n+1);
    sort(b+1, b+m+1);
    int j = 1;
    fi(i, 1, n){
        while (j <= m && (b[j].f < a[i].f || b[j].s <= 0)){
            j++;
        }
        res = max(res, b[j].f - a[i].f);
        b[j].s--;
    }
    cout << res;
}
