#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "stores"
const int maxn = 1e5+10;
using namespace std;

int n, res, bit1[maxn*2], bit2[maxn*2];
pii a[maxn];

void update(int x, int val, int bit[]){
    while (x <= n*2){
        bit[x] = min(bit[x], val);
        x += x & -x;
    }
}

int get(int x, int bit[]){
    int ans = 1e9;
    while (x > 0){
        ans = min(ans, bit[x]);
        //cout << x << ' ' << bit[x] << ' ';
        x -= x & -x;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        char c;
        cin >> a[i].first >> c;
        a[i].second = (c == 'G' ? 1 : -1);
    }
    sort(a+1, a+n+1);
    memset(bit1, 60, sizeof(bit1));
    memset(bit2, 60, sizeof(bit2));
    a[0].second = n;
    update(n, a[1].first, bit1);
    fi(i, 1, n){
        a[i].second += a[i-1].second;
        if (i < n){
            if (i%2 == 0){
                update(a[i].second, a[i+1].first, bit1);
            }
            else {
                update(a[i].second, a[i+1].first, bit2);
            }
        }
    }
    fi(i, 1, n){
        int vt;
        if (i%2 == 0){
            vt = get(a[i].second, bit1);
            res = max(res, a[i].first-vt);
        }
        else {
            vt = get(a[i].second, bit2);
            res = max(res, a[i].first-vt);
        }
        //cout << vt << '\n';
    }
    cout << res;
}
