#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "noel"
const int maxn = 2005;
using namespace std;

int n, a[maxn], d, res;
int bit[maxn];
vector<int> g[maxn];

void update(int x, int N, int len){
    while (x <= N){
        bit[x] = max(bit[x], len);
        x += x & -x;
    }
}

int get(int x){
    int ans = 0;
    while (x > 0){
        ans = max(ans, bit[x]);
        x -= x & -x;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> d;
    n <<= 1;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n){
        fid(j, n, 1) if (abs(a[i] - a[j]) <= d){
            g[i].pb(j);
        }
    }
    fi(mid, 1, n){
        fi(i, 1, mid) bit[i] = 0;
        fi(r, mid + 1, n){
            for (int l : g[r]) if (l <= mid){
                int len = get(l - 1) + 1;
                update(l, mid, len);
            }
        }
        res = max(res, get(mid));
    }
    cout << res;
}
