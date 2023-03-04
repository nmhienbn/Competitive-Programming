#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "itmed"
const int maxn = 1e5 + 5;
using namespace std;

int n, k, d, c, x;
ll a[maxn], q[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    d = 1;
    fi(i, 1, n){
        cin >> x;
        while (d <= c && q[d] < i - k) d++;
        a[i] = max(0ll, a[q[d]]) + x;
        while (d <= c && a[q[c]] <= a[i]) c--;
        q[++c] = i;
    }
    cout << *max_element(a, a + n + 1);
}
