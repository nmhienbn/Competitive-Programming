#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "lis"
const int maxn = 1e5+5;

using namespace std;

int n, b[maxn], bit[maxn], res;
pii a[maxn];

int get(int x){
    int ans = 0;
    while (x > 0){
        ans = max(ans, bit[x]);
        x -= x & -x;
    }
    return ans;
}

void update(int x, int val){
    while (x <= n){
        bit[x] = max(bit[x], val);
        x += x & -x;
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a+1, a+n+1);
    a[0].first = -1;
    int id = 0;
    fi(i, 1, n){
        if (a[i].first != a[i-1].first){
            b[a[i].second] = ++id;
        }
        else b[a[i].second] = id;
    }
    fi(i, 1, n){
        int len = get(b[i]);
        update(b[i], len+1);
        res = max(res, len+1);
    }
    cout << res;
}
