#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "arithdig"
const int maxn = 1e5+5;
using namespace std;

string l, r;
int nt;

int get(string s){
    if (s.size() == 1) return s[0] - '0';
    return 10*s[0] + s[1] - 11*'0';
}

ll calc(string l){
    int n = l.size();
    ll p = get(l);
    if (n > 2){
        p += 90 * (n-2) - 1;
        int k = (l[1] - l[0] + 10) % 10;
        fi(i, 2, n-1){
            if (l[i] - '0' > (l[i-1] - '0' + k) % 10) p++;
            if (l[i] - '0' != (l[i-1] - '0' + k) % 10) break;
            if (i == n-1) p++;
        }
    }
    return p;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> nt;
    while (nt--){
        cin >> l >> r;
        int n = l.size();
        fid(i, n-1, 0){
            if (l[i] == '0') l[i] = '9';
            else {
                l[i]--;
                break;
            }
        }
        if (l[0] == '0' && n > 1){
            n--;
            fi(i, 0, n-1) l[i] = l[i+1];
            l.pop_back();
        }
        int p = calc(l);
        int q = calc(r);
        cout << q - p << '\n';
    }

}
