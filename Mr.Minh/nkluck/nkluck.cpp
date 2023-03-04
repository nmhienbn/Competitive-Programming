#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "nkluck"
const int maxn = 5e5+5;

using namespace std;

int n, x, a[maxn], bit[maxn*2], b[maxn];
ll res, ome;

void update(int x){
    while (x <= n*2+1){
        bit[x]++;
        x += x&(-x);
    }
}

ll get(int x){
    ll ans = 0;
    while (x > 0){
        ans += bit[x];
        x -= x&(-x);
    }
    return ans;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> x;
    ome = 1ll*n*(n+1)/2;
    fi(i, 1, n){
        cin >> b[i];
        if (b[i] >= x) a[i] = a[i-1] + 1;
        else a[i] = a[i-1] - 1;
    }
    fi(i, 0, n){
        a[i] += n + 1;
        res += get(a[i]-1);
        update(a[i]);
    }
    memset(bit, 0, sizeof(bit));
    a[0] = 0;
    fi(i, 1, n){
        if (b[i] <= x) a[i] = a[i-1] + 1;
        else a[i] = a[i-1] - 1;
    }
    fi(i, 0, n){
        a[i] += n + 1;
        res += get(a[i]-1);
        update(a[i]);
    }
    cout << double(res-ome)/ome;
}
