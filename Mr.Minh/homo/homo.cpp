#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "homo"
const int maxn = 1e5 + 5;
using namespace std;

int n, homo, hete, x, now;
string s;
map<int, int> cnt;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    while (n--){
        cin >> s >> x;
        if (s[0] == 'i'){
            if (++cnt[x] == 2) homo++;
        }
        else {
            if (cnt.find(x) != cnt.end()){
                now = --cnt[x];
                if (now == 0) cnt.erase(x);
                else if (now == 1) homo--;
            }
        }
        hete = cnt.size() >= 2;

        if (homo && hete) cout << "both\n";
        else if (homo) cout << "homo\n";
        else if (hete) cout << "hetero\n";
        else cout << "neither\n";
    }
}
