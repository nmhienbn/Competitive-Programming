#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "triangle"
const int maxn = 1e5+5;

using namespace std;

set<pii> a, b;
int n, q;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> q;
    fi(i, 1, n){
        int u, v;
        cin >> u >> v;
        a.insert({u, v});
        b.insert({v, u});
    }
    while (q--){
        int typ, u, v;
        cin >> typ >> u >> v;
        if (typ == 1){
            a.insert({u, v});
            b.insert({v, u});
        }
        else if (typ == 2){
            a.erase({u, v});
            b.erase({v, u});
        }
        else {
            pii t = {u, -1e9-1};
            int maxu = -1e9-1, maxv = -1e9-1, minu = 1e9+1, minv = 1e9+1;
            auto it = a.lower_bound(t);
            while (it->first == u){
                maxv = max(maxv, it->second);
                minv = min(minv, it->second);
                it++;
            }
            t = {v, -1e9-1};
            it = b.lower_bound(t);
            while (it->first == v){
                maxu = max(maxu, it->second);
                minu = min(minu, it->second);
                it++;
            }
            if ((maxu == -1e9-1 && minu == 1e9+1) || (maxv == -1e9-1 && minv == 1e9+1)){
                cout << 0 << '\n';
                continue;
            }
            //cout << maxu << ' ' << maxv << ' ' << minu << ' ' << minv << ' ';
            ll res = 1ll*max(maxu-u, u-minu)*max(maxv-v, v-minv);
            cout << res/2;
            if (res%2) cout << ".5";
            cout << '\n';
        }
    }
}
