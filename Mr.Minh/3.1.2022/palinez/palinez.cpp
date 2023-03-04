#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "palinez"
const int maxn = 5005;
using namespace std;

int n, m;
bool f[maxn][maxn];
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> s >> m;
    n = s.size();
    s = ' ' + s;
    fi(i, 1, n) f[i][i] = 1;
    fi(i, 1, n - 1) if (s[i] == s[i + 1]) f[i][i + 1] = 1;
    fi(j, 2, n - 1){
        fi(i, 1, n - j){
            if (s[i] == s[i + j]){
                f[i][i + j] = f[i + 1][i + j - 1];
            }
        }
    }
    while (m--){
        int l, r;
        cin >> l >> r;
        cout << (f[l][r] ? "YES\n" : "NO\n");
    }
}
