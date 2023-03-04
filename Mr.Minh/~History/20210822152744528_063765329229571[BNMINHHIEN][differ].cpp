#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "differ"
const int maxn = 1e6+5;

using namespace std;

int n, cnt[30], res;
string s;

int main(){
    faster
    //freopen(Seraphine".inp", "r", stdin);
    //freopen(Seraphine".out", "w", stdout);
    cin >> n >> s;
    s = ' ' + s;
    fi(u, 0, 25){
        fi(j, 0, 25) cnt[j] = 0;
        int xd = 0, ans = 0, aa = 0, kt = 0;
        fi(i, 1, n){
            int t = s[i] - 'a';
            if (t == u){
                xd = 1, kt = 1;
                fi(j, 0, 25) cnt[j]--;
            }
            else {
                if (cnt[t] <= 0) cnt[t] = 0, xd = 0;
                cnt[t]++;
                aa = max(aa, cnt[t]);
                if (xd) ans = max(ans, cnt[t]);
            }
        }
        res = max(res, ans);
        if (kt) res = max(res, aa-1);
    }
    cout << res;
}
