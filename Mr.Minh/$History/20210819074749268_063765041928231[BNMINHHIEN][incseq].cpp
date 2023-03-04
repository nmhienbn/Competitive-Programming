#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "incseq"
const int maxn = 1e6+5;

using namespace std;

int n, b[maxn], L[maxn], cnt;
vector<int> a, res;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> b[i];
        int t = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        if (t >= a.size()) a.pb(b[i]);
        else a[t] = min(a[t], b[i]);
        L[i] = t;
    }
    cout << a.size() << '\n';
    fi(i, 1, n) L[i] = a.size() - L[i];
    fid(i, n, 1){
        if (L[i] == res.size()+1) res.pb(b[i]);
        else {
            if (b[i] > res[L[i]-1]){
                res.resize(L[i]);
                res.back() = b[i];
            }
        }
    }
    for(auto i = res.rbegin(); i != res.rend(); i++) cout << *i << '\n';
}
