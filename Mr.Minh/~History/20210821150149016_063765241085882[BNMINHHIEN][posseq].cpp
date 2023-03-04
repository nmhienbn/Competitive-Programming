#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "posseq"
const int maxn = 1e5+5, mod = 1e9+9;

using namespace std;

int n, b[maxn], bit[maxn];
pii a[maxn];

int get(int x){
    int ans = 0;
    while (x > 0){
        ans += bit[x];
        ans %= mod;
        x -= x&-x;
    }
    return ans;
}

void update(int x, int val){
    while (x <= n+1){
        bit[x] += val;
        bit[x] %= mod;
        x += x&-x;
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i].first;
        a[i].first += a[i-1].first;
        a[i].second = i;
    }
    //fi(i, 1, n) cout << a[i].first << ' ';
    sort(a, a+n+1);
    int id = 0;
    b[a[0].second] = ++id;
    fi(i, 1, n){
        if (a[i].first != a[i-1].first){
            b[a[i].second] = ++id;
        }
        else if (a[i].first == a[i-1].first){
            b[a[i].second] = id;
        }
    }
    fi(i, 1, n){
        int cnt = get(b[i]-1);
        if (cnt == 0) cnt++;
        if (b[i] > b[0]) update(b[i], cnt);
    }
    cout << get(b[n]);
}
