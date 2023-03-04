#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "unicow"
const int maxn = 2e5 + 5;
using namespace std;

int n, now[maxn], nex[maxn],
    a[maxn], bit[maxn];
ll res;

void init(){
    fi(i, 1, n) now[i] = n + 1;
    fid(i, n, 1){
        nex[i] = now[a[i]];
        now[a[i]] = i;
    }
    fid(i, n, 1) a[i] = 1, a[nex[i]] = 0;
}

void update(int x, int val){
    while (x <= n){
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
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    init();
    //fi(i, 1, n) cout << nex[i] << ' ';
    fi(i, 1, n) if (a[i]) update(i, 1);
    fi(i, 1, n){
        update(i, -1);
        update(nex[i], 1);
        res += get(nex[i] - 1);
        //cout << res << ' ' ;
    }
    cout << res;
}
