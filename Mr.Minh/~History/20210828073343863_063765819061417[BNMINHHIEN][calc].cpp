#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "calc"
const int maxn = 1e6+5;

using namespace std;

ll b, n, res;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> b >> n;
    fi(m, 1, n*2){
        if ((b*(2*m*n - m*m)) % (n*n) == 0 && m != n){
            res++;
        }
    }
    cout << res;
}
