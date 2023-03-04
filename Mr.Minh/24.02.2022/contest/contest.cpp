#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<ll,ll>
#define pb push_back
#define ll long long
#define Irelia "contest"
const int maxn = 1e5 + 5;
using namespace std;

int n, m;
ll ans, kt;
int now, pre;
ll a[maxn];

//bool cmp(pii a, pii b){
//    return a.first * b.second < a.second * b.first;
//}
//
//ll get(pii a){
//    return pre * a.first - now * a.second;
//}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) cin >> a[i], a[i] += a[i - 1];

    cin >> now;
    fi(i, 2, m){
        pre = now;
        cin >> now;
        ll maxx = 0;
        fi(j, 1, n) maxx = max(maxx, pre * a[j] - now * a[j - 1]);
        ans += maxx;
        //ans += max(get(a[1]), get(a[n]));
    }
    cout << ans + now * a[n];
}
