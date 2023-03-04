#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "molecule"
const int maxn = 1e6+5;
using namespace std;

string s;
ll res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> s;
    s += s[0];
    fi(i, 0, int(s.size())-2)
        res += s[i] == 'B' && s[i+1] == 'W';
    cout << max(res-1, 0ll);
}
