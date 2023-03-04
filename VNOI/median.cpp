#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "median"
const int maxn = 2e5 + 5;
using namespace std;

int n, k, N, now;
int bit[maxn];
ll res;

void update(int x){
    while (x <= N){
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
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    N = n << 1;
    now = n;
    fi(i, 1, n){
        int x;
        cin >> x;
        update(now);
        if (x >= k) now++;
        else now--;
        res += get(now);
    }
    cout << res;
}
