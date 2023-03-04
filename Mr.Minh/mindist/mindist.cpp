#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "mindist"
const int maxn = 1e5+5;

using namespace std;

int n, c;
ll res;

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> c;
    fi(i, 1, n){
        int x;
        cin >> x;
        res += x;
    }
    cout << (res >= c ? "YES" : "NO");
}
