#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "blocks"
const int maxn = 1e5 + 5;
using namespace std;

int n, a[maxn], tmp, res[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n){
        tmp = min(tmp, a[i] - i);
        res[i] = tmp + i;
    }
    tmp = n + 1;
    fid(i, n, 1){
        tmp = min(tmp, a[i] + i);
        res[i] = min(res[i], tmp - i);
    }
    cout << *max_element(res + 1, res + n + 1);
}
