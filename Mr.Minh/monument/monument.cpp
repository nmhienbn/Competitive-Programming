#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "monument"
const int maxn = 1e5+5;

using namespace std;

int n, bit[maxn], res, l[maxn];
pii a[maxn];

void update(int x, int val){
    while (x <= 1e5){
        bit[x] = max(bit[x], val);
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
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i].first >> a[i].second;
    sort(a+1, a+n+1);
    int j = 1;
    fi(i, 1, n){
        while (a[j].first < a[i].first && j < i){
            update(a[j].second, l[j]);
            j++;
        }
        l[i] = get(a[i].second - 1) + a[i].second;
        res = max(res, l[i]);
    }
    cout << res;
}
