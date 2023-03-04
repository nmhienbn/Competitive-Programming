#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "photo"
const int maxn = 2005;
using namespace std;

int n, k, nex[maxn], nexr, res;
pii a[maxn];
vector<int> val;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, k){
        int l, r;
        cin >> l >> r;
        if (l > r) swap(l, r);
        a[i] = {l, r};
        val.pb(l);
        val.pb(r);
    }
    sort(val.begin(), val.end());
    val.resize(unique(val.begin(), val.end()) - val.begin());
    fi(i, 0, val.size()) nex[i] = 1e9;
    fi(i, 1, k){
        int l = lower_bound(val.begin(), val.end(), a[i].first) - val.begin();
        int r = lower_bound(val.begin(), val.end(), a[i].second) - val.begin();
        nex[l] = min(nex[l], r);
    }

    fid(i, int(val.size()) - 2, 0) nex[i] = min(nex[i], nex[i + 1]);
    while (nexr < int(val.size())){
        res++;
        nexr = nex[nexr];
    }
    cout << res;
}
