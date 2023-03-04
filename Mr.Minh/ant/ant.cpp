#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "ant"
const int maxn = 2e5+5;

using namespace std;

int n, q;
ll a[maxn];

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> q;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, q){
        int l, r;
        cin >> l >> r;
        int sz = r-l+1;
        if (sz % 2) cout << "1\n";
        else cout << a[l+sz/2] - a[l+sz/2-1] + 1 << '\n';
    }

}
