#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "substr"
const int maxn = 2e6+5;

using namespace std;

int n, m, z[maxn];
string a, b, c;

void Z_func(){
    int L = 0, R = 0;
    z[1] = 0;
    fi(i, 2, n){
        int x = 0;
        if (R >= i) x = min(z[i-L+1], R-i+1);
        while (c[x+i] == c[x+1] && x+i <= n) x++;
        z[i] = x;
        if (i+x-1 >= R){
            L = i;
            R = i+x-1;
        }
        if (z[i] >= m && i > m) cout << i-m-1 << ' ';
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> a >> b;
    c = " " + b + " " + a;
    n = c.size() - 1;
    m = b.size();
    Z_func();
}
