#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "pinball"
const int maxn = 1e5 + 5;
using namespace std;

int n, a[maxn], bit[maxn];
ll res;
pii b[maxn];

void update(int x){
    while (x > 0){
        bit[x]++;
        x -= x & -x;
    }
}

int get(int x){
    int ans = 0;
    while (x <= n){
        ans += bit[x];
        x += x & -x;
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
    a[b[1].second] = 1;
    fi(i, 2, n){
        a[b[i].second] = a[b[i - 1].second];
        if (b[i].first != b[i - 1].first) a[b[i].second]++;
    }
    fi(i, 1, n){
        res += get(a[i] + 1);
        update(a[i]);
    }
    cout << fixed << setprecision(2) << double(res + n)/n;
}
