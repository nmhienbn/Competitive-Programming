#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "fc135_revstr"
const int maxn = 1e5 + 5;
using namespace std;

int n, m;
bool a[maxn];
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> s;
    n = s.size();
    cin >> m;
    fi(i, 1, m){
        int x;
        cin >> x;
        a[x] ^= 1;
    }
    fi(i, 1, n / 2){
        a[i] ^= a[i - 1];
        if (a[i]) swap(s[i - 1], s[n - i]);
    }
    cout << s;
}
