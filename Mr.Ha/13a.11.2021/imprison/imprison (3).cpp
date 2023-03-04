#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "imprison"
const int maxn = 1e5+5;
using namespace std;

int n, res, pre[maxn], nex[maxn];
pii a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i].second >> a[i].first;
    sort(a+1, a+n+1);
    fi(i, 1, n-1){
        int l = i, r = i+1;
        while (a[r].first-a[l].first > min(a[r].second, a[l].second)){
            if (a[r].first-a[l].first > a[r].second) r++;
            else {
                r = max(r, nex[l-1]);
                l = pre[l-1];
            }
            if (l == 0 || r == n+1){
                res += a[i+1].first - a[i].first;
                break;
            }
        }
        pre[i] = l, nex[i] = r;
    }
    cout << a[n].first-a[1].first-res;
}
