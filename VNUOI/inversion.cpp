#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "inversion"
const int maxn = 2e5 + 5;
using namespace std;

int n, bit[maxn], a[maxn];
ll f[maxn];
ll now, res, bd;
int pos;
pii b[maxn];

void updateUp(int x){
    while (x <= n){
        bit[x]++;
        x += x & -x;
    }
}
void updateDown(int x){
    while (x > 0){
        bit[x]++;
        x -= x & -x;
    }
}
int getUp(int x){
    int ans = 0;
    while (x <= n){
        ans += bit[x];
        x += x & -x;
    }
    return ans;
}
int getDown(int x){
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
    fi(i, 1, n){
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(b + 1, b + n + 1);
    fi(i, 1, n) a[i] = b[i].second;
    fid(i, n, 1){
        f[i] = f[i + 1] + getDown(a[i] - 1);
        updateUp(a[i]);
    }
    res = 1e18;
    bd = f[1];
    fi(i, 1, n) bit[i] = 0;
    fi(i, 1, n){
        if (res > now + f[i + 1]){
            res = now + f[i + 1];
            pos = b[i].first;
        }
        else if (res == now + f[i + 1]){
            pos = min(pos, b[i].first);
        }
        now += getUp(a[i] + 1);
        updateDown(a[i]);
    }
    cout << pos << ' ' << bd - res;
}
