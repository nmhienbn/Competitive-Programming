#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "mstick"
const int maxn = 20005;

using namespace std;

struct dl {
    int f, s;
    bool operator < (const dl& x) const {
        return f != x.f ? f < x.f : s > x.s;
    }
};

int t, n, k, s[maxn];
dl a[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> t;
    while (t--){
        cin >> n;
        fi(i, 1, n) cin >> a[i].f >> a[i].s;
        sort(a+1, a+n+1);
        k = 1;
        s[1] = a[1].s;
        fi(i, 2, n){
            int j = k;
            while (j > 0 && s[j] < a[i].s) j--;
            if (j == k) s[++k] = a[i].s;
            s[j+1] = a[i].s;
        }
        cout << k << '\n';
    }
}
