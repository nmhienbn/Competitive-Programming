#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "exd"
const int maxn = 0;
using namespace std;

int a, b, c = 6;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> a >> b;
    a = c - max(a, b) + 1;
    b = __gcd(a, c);
    a /= b;
    c /= b;
    cout << a << '/' << c;
}
