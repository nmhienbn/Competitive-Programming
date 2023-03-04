#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "virus"
const int maxn = 3005;
using namespace std;

int nt, n, ans[maxn];
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> nt >> s;
    n = s.size();
    s = ' ' + s;
    fid(j, n >> 1, 1){
        int cnt = 0;
        fi(i, 1, j) cnt += (s[i] != s[i + j]);
        ans[j] = cnt;
        fi(i, j + 1, n - j){
            cnt += (s[i] != s[i + j]) - (s[i - j] != s[i]);
            if (ans[j] > cnt){
                ans[j] = cnt;
            }
        }
    }
    n >>= 1;
    while (nt--){
        int k;
        cin >> k;
        fid(i, n, 0){
            if (ans[i] <= k){
                cout << i << '\n';
                break;
            }
        }
    }

}
