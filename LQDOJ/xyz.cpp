#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "xyz"
const int maxn = 105;
using namespace std;

struct dl {
    int x, y, z;
    bool operator < (const dl& b) const{
        return x == b.x ? (y == b.y ? z < b.z : y < b.y) : x < b.x;
    }
};

int n;
ll res = 1e18;
pii b[maxn];
dl a[maxn];

ll calc(pii a[], int n){
    int m = 1e9, M = -1e9, res = 2e9;
    fi(l, 1, n){
        int g = m, G = M;
        fid(r, n, l) {
            if (r - l + 1 < n){
                res = min(res, a[r].first - a[l].first + G - g);
            }
            g = min(g, a[r].second);
            G = max(G, a[r].second);
        }
        m = min(m, a[l].second);
        M = max(M, a[l].second);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i].x >> a[i].y >> a[i].z;
    sort(a + 1, a + n + 1);
    fi(l, 1, n){
        int cnt = 0;
        fi(i, 1, l - 1) b[++cnt] = {a[i].y, a[i].z};
        sort(b + 1, b + cnt + 1);
        fid(r, n, l){
            if (r - l + 2 < n){
                res = min(res, a[r].x - a[l].x + calc(b, cnt));
                //cout << l << ' ' << r << ' ' << calc(b, cnt) << '\n';
            }
            b[++cnt] = {a[r].y, a[r].z};
            int tmp = cnt;
            while (b[tmp] < b[tmp - 1] && tmp > 1){
                swap(b[tmp], b[tmp - 1]);
                tmp--;
            }
        }
    }
    cout << res;
}
