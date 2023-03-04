#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "key"
const int maxn = 0;

using namespace std;

int t, n;
string s;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> t;
    while (t--){
        int cnt = 0, res = 0, vt = 0;
        cin >> s;
        n = s.size();
        s = ' ' + s + '*';
        fi(i, 1, n+1){
            if (s[i] == s[n+1-i]){
                cnt++;
            }
            else {
                if (res < cnt){
                    res = cnt;
                    vt = i-1;
                }
                cnt = 0;
            }
        }
        fi(i, vt-res+1, vt) cout << s[i];
        cout << '\n';
    }

}
