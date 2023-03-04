#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "vobignum"
const int maxn = 1000, mod = 1e9+7;

using namespace std;

int n, q;
ll a[maxn], b[maxn];

ll calc(){
    ll res = 0;
    int x1, x2;
    char x;
    cin >> x1 >> x2 >> x;
    if (x == '+') res = (a[x1] + a[x2]) % mod;
    else if (x == '-') res = (a[x1] - a[x2] + mod) % mod;
    else if (x == '*') res = (a[x1] * a[x2]) % mod;
    return res;
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> q;
    fi(i, 0, n-1){
        string s;
        cin >> s;
        for(auto c : s){
            if (c < '0' || c > '9') continue;
            a[i] = (a[i] * 10 + c - '0') % mod;
        }
        if (s[0] == '-'){
            if (a[i]) a[i] = mod - a[i];
        }
    }
    while (q--){
        if (calc() == calc()) cout << "YES\n";
        else cout << "NO\n";
    }
}
