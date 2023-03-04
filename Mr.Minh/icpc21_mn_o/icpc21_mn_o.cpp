#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "icpc21_mn_o"
const int maxn = 2e5 + 5;
using namespace std;

int n, cnt;
pii a[maxn];
ll res;

bool cmp(pii a, pii b){
    return a.second == b.second ? a.first < b.first: a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1);
    cnt = 1;
    fi(i, 2, n + 1){
        if (i <= n && a[i].first == a[i - 1].first) cnt++;
        else {
            res += 1ll * cnt * (cnt - 1) / 2;
            cnt = 1;
        }
    }
    sort(a + 1, a + n + 1, cmp);
    cnt = 1;
    fi(i, 2, n + 1){
        if (i <= n && a[i].second == a[i - 1].second) cnt++;
        else {
            res += 1ll * cnt * (cnt - 1) / 2;
            cnt = 1;
        }
    }
    cnt = 1;
    fi(i, 2, n + 1){
        if (i <= n && a[i].first == a[i - 1].first && a[i].second == a[i - 1].second) cnt++;
        else {
            res -= 1ll * cnt * (cnt - 1) / 2;
            cnt = 1;
        }
    }
    cout << res;
}
