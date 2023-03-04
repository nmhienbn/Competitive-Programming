#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "bits"
const int maxn = 5005;
using namespace std;

string s, t;
int n, cnt0, cnt1, dem0, dem1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> s >> t;
    n = s.size();
    s = ' ' + s;
    t = ' ' + t;
    fi(i, 1, n) if (s[i] != t[i]){
        if (s[i] == '0') cnt0++;
        if (s[i] == '1') cnt1++;
        if (s[i] == '?'){
            if (t[i] == '0') dem0++;
            else dem1++;
        }
    }
    if (cnt1 > cnt0 + dem1){
        cout << -1;
        exit(0);
    }
    cout << cnt0 + dem0 + dem1 + (cnt0 < cnt1) * (cnt1 - cnt0);
}
