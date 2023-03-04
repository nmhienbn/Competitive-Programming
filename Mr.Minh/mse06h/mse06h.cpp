#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "mse06h"
const int maxn = 1005;

using namespace std;

int n, m, k, t, bit[maxn];
pii a[maxn];

bool cmp(pii a, pii b){
    return a.first != b.first ? a.first < b.first : a.second > b.second;
}

void update(int x){
    while (x <= m){
        bit[x]++;
        x += x & -x;
    }
}

int get(int x){
    int ans = 0;
    while (x > 0){
        ans += bit[x];
        x -= x & -x;
    }
    return ans;
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> t;
    fi(i, 1, t){
        ll res = 0;
        memset(bit, 0, sizeof(bit));
        cin >> n >> m >> k;
        fi(i, 1, k) cin >> a[i].first >> a[i].second, a[i].second = m-a[i].second+1;
        sort(a+1, a+k+1, cmp);
        fi(i, 2, k){
            update(a[i-1].second);
            res += get(a[i].second-1);
        }
        cout << "Test case " << i << ": " << res << '\n';
    }

}
