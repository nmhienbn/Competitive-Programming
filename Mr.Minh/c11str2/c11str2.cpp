#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "c11str2"
const int maxn = 2e5+5;

using namespace std;

string a, b, c;
int n, z[maxn], res;

void Z_func(){
    int L = 0, R = 0;
    z[1] = 0;
    fi(i, 2, n){
        int x = 0;
        if (R >= i) x = min(z[i-L+1], R-i+1);
        while (c[i+x] == c[x+1] && i+x <= n) x++;
        z[i] = x;
        if (i+x-1 >= R){
            L = i;
            R = i+x-1;
        }
        if (R >= n){
            res = x;
            return;
        }
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> a >> b;
    c = b + ' ' + a;
    n = c.size();
    c = ' ' + c;
    Z_func();
    cout << a;
    fi(i, res, int(b.size()) - 1) cout << b[i];
}
