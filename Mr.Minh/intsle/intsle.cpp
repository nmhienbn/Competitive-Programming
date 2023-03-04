#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "intsle"
using namespace std;

int gcd(int a, int b){
    if (a == 0 && b == 0) return 1e6;
    if (a == 0) return b;
    if (b == 0) return a;
    if (a%b == 0) return b;
    else return gcd(b, a%b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    int t;
    cin >> t;
    fi(i, 1, t){
        int a1, b1, c1, a2, b2, c2;
        ll D, Dx, Dy;
        cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
        if (c1%gcd(a1, b1) != 0 || c2%gcd(a2, b2) != 0) {cout << "NO SOLUTION\n"; continue;}
        D = a1 * b2 - a2 * b1;
        Dx = c1 * b2 - c2 * b1;
        Dy = a1 * c2 - a2 * c1;
        if (D == 0){
            if (Dx == 0 && Dy == 0) cout << "INFINITE\n";
            else cout << "NO SOLUTION\n";
        }
        else {
            if (Dx%D != 0 || Dy%D != 0) cout << "NO SOLUTION\n";
            else cout << Dx / D << ' ' << Dy / D << '\n';
        }
    }
    return 0;
}
