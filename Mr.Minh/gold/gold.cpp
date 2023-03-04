#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "gold"
const int maxn = 1e5+5;

using namespace std;

int n, s, w, bit[maxn], res;
pii a[maxn];

void update(int x, int val){
    while (x <= 6e4){
        bit[x] += val;
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
    cin >> s >> w >> n;
    fi(i, 1, n){
        cin >> a[i].first >> a[i].second;
        a[i].first += 3e4;
        a[i].second += 3e4;
    }
    sort(a+1, a+n+1);
    int j = 1;
    fi(i, 1, n){
        update(a[i].second, 1);
        while (a[j].first < a[i].first-s){
            update(a[j].second, -1);
            j++;
        }
        res = max(res, get(a[i].second) - get(a[i].second-w));
    }
    cout << res;
}
