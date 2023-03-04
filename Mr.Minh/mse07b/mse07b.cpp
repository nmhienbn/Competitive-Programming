#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "mse07b"

using namespace std;

set<pii> a;

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    int t, k, p;
    while (cin >> t){
        if (t == 0) break;
        if (t == 1) cin >> k >> p, a.insert({p, k});
        else if (t >= 2 && a.empty()){
            cout << 0;
        }
        else if (t == 2){
            cout << a.rbegin()->second;
            a.erase(prev(a.end()));
        }
        else if (t == 3){
            cout << a.begin()->second;
            a.erase(a.begin());
        }
        if (t >= 2) cout << '\n';
    }

}
