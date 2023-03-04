#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "difference"
const int maxn = 1e6 + 5;
using namespace std;

int n, cnt[26], res;
bool xd[26];
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> s;
    for (char c : s) xd[c - 'a'] = 1;
    s = ' ' + s;
    fi(t, 0, 25) if (xd[t]){
        bool ok = 0;
        fi(i, 0, 25) cnt[i] = 0;
        fi(i, 1, n){
            int u = s[i] - 'a';
            if (t == u){
                ok = 1;
                fi(j, 0, 25) cnt[j]--;
            }
            else {
                if (cnt[u] < 0) ok = 0, cnt[u] = 1;
                else cnt[u]++;
                if (ok) res = max(res, cnt[u]);
                else res = max(res, cnt[u] - 1);
            }
        }
    }
    cout << res;
}
