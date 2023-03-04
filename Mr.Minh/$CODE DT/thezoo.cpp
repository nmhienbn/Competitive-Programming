#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia ""
const int N = 1e6 + 5;

using namespace std;

int pơ

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen(Irelia".inp", "r", stdin);
    //freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    if (m % 2 || n % 2 || m < n || m > n * 2) cout << "IMPOSSIBLE";
    else cout << (m - n) / 2 << ' ' << n - m / 2;

}
