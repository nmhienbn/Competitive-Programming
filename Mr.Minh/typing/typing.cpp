#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "typing"
const int maxn = 1e5+5, mod = 1e9+7;

using namespace std;

int q, pre[5], a[maxn], b[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> q;
    while (q--){
        int x, n;
        ll res = 0;
        string s;
        cin >> x >> s;
        n = s.size();
        s = ' ' + s;
        int cnt = 0;
        char pre = 'T';
        fi (i, 1, n){
            a[i] = cnt;
            b[i] = b[i-1];
            if (s[i] == 'T') cnt++;
            else {
                if (s[i] != pre) b[i]++;
                pre = s[i];
                cnt = 0;
            }
        }
        fi(i, 1, n) if (b[i] > 0) b[i]--;
        if (x == 0){
            res = b[n];
        }
        else {
            res = 0;
            ll sum = 0, tong = 0;
            fi(i, 1, n){
                if (s[i] != 'T'){
                    sum = (sum + 1ll*b[i]*(a[i]+1)) % mod;
                    tong = (tong + a[i] + 1) % mod;
                }
                res = (res + tong*b[i] - sum + mod) % mod;
            }
        }
        cout << res << '\n';
    }
}
