#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "skwlth"
const int maxn = 3e4+5;

using namespace std;

struct dl {
    int f, s, t;
    bool operator < (const dl& x) const {
        return f != x.f ? f < x.f : s < x.s;
    }
} a[maxn];

int n, s[maxn], k = 1, res[maxn];

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i].f >> a[i].s, a[i].t = i;
    sort(a+1, a+n+1);
    s[1] = a[1].s;
    res[a[1].t] = 1;
    fi(i, 2, n){
        int d = 1, c = k;
        while (d <= c){
            int g = (d + c) >> 1;
            if (s[g] > a[i].s) d = g+1;
            else c = g-1;
        }
        if (c == k) k++;
        s[c+1] = max(s[c+1], a[i].s);
        res[a[i].t] = c+1;
    }
    fi(i, 1, n) cout << res[i] << '\n';
}
