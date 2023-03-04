#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "ham12"
const int maxn = 2005;
using namespace std;

int n, m, k, ans = maxn;
string s;
string t;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//    freopen(Irelia".inp", "r", stdin);
//    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> k;
    cin >> s;
    s += s;
    fi(rep, 1, k){
        cin >> t;
        fi(i, 0, n - 1){
            int now = 0;
            fi(j, 0, m - 1){
                now += (s[i + j] != t[j]);
            }
            ans = min(ans, now);
        }
    }
    cout << ans << '\n';

}
