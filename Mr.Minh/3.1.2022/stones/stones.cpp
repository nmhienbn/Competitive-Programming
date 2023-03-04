#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "stones"
const int maxn = 2e5 + 5;
using namespace std;

int m, n;
set<pii> s;
multiset<int> a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n;
    while (m--){
        int typ;
        cin >> typ;
        if (typ == 1){
            int t, w;
            cin >> t >> w;
            if (a[t].empty()){
                a[t].insert(w);
                s.insert({w, t});
            }
            else {
                if (w < *a[t].begin()){
                    s.erase({*a[t].begin(), t});
                    s.insert({w, t});
                }
                a[t].insert(w);
            }
        }
        else {
            pii it = *s.rbegin();
            cout << it.first << '\n';
            a[it.second].erase(a[it.second].find(it.first));
            if (a[it.second].size()) s.insert({*a[it.second].begin(), it.second});
            s.erase(it);
        }
    }

}
