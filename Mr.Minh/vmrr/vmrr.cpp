#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "vmrr"
const int maxn = 1e6+5;
using namespace std;

int cnt;
ll res;
string s;
char X, Y;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> s >> X >> Y;
    for (char c : s){
        if
            (c == Y) res += cnt;
        if (c == X) cnt++;
    }
    cout << res;
}
