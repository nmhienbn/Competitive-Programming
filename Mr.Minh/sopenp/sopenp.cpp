#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "sopenp"
const int maxn = (1 << 20) + 5;

using namespace std;

int n, l, r, cnt[maxn], a[maxn], res;
pii b[maxn];

ll calc(int k){
    ll ans = 0;
    int j = 1, now = 0;
    fi(i, 1, n) cnt[i] = 0;
    for(int i = 1; i <= n; i++){
        if (!cnt[a[i]]) now++;
        cnt[a[i]]++;
        while (now > k){
            cnt[a[j]]--;
            if (!cnt[a[j]]) now--;
            j++;
        }
        ans += i-j+1;
    }
    return ans;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> l >> r;
    fi(i, 1, n) cin >> b[i].first, b[i].second = i;
    sort(b+1, b+n+1);
    a[b[1].second] = 1;
    int id = 1;
    fi(i, 2, n){
        if (b[i].first != b[i-1].first) ++id;
        a[b[i].second] = id;
    }
    cout << calc(r) - calc(l-1);
}
