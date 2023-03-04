#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "bwtree"
const int maxn = 0;

using namespace std;

int nt;

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> nt;
    while (nt--){
        int u, v;
        cin >> u >> v;
        while (u != v){
            if (u > v) swap(u, v);
            v /= 2;
        }
        cout << u << '\n';
    }

}
