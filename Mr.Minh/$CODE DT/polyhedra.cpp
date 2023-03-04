#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "polyhedra"
const int maxn = 0;
using namespace std;

int a, b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> a >> b;
    cout << max(0, 2+b-a);

}
