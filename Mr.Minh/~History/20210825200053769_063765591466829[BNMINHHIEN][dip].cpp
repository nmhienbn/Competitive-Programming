#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "dip"
const int maxn = 1e5+5;

using namespace std;

int n, m, a[maxn], cnt[maxn], nex[maxn], VieteJumping[maxn];
map<int, int> pre;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n){
        cin >> a[i];
        pre[a[i]] = n+1;
    }
    nex[n+1] = 1e9;
    fid(i, n, 1){
        nex[i] = min(nex[i+1], pre[a[i]]);
        pre[a[i]] = i;
    }
    //fi(i, 1, n) cout << nex[i] << ' '; cout << endl;
    nex[n+1] = n+1;
    int previous = n+1;
    fid(i, n, 1){
        if (nex[i] != nex[i+1]){
            previous = i+1;
        }
        VieteJumping[i] = previous;
    }
    //fi(i, 1, n) cout << VieteJumping[i] << ' '; cout << endl;
    while (m--){
        int l, r;
        cin >> l >> r;
        l++, r++;
        int d = l, c = n, res = 0;
        while (d <= r){
            c = nex[d]-1;
            //cout << d << ' ' << c << '\n';
            res = max(res, min(c, r) - max(l, d) + 1);
            d = VieteJumping[d];
        }
        cout << res << '\n';
    }
}
