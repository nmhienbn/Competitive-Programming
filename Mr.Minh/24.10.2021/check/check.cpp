#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "check"
const int maxn = 2005;

using namespace std;

int n, t[maxn];
string s[maxn], res;
map<string, int> a;

bool cmp(string a, string b){
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

void xuli(int n){
    string ss;
    fi(i, 1, n) ss += s[t[i]];
//    fi(i, 1, n) cout << t[i];
//    cout << ' ' << ss << '\n';
    int cnt = ++a[ss];
    if (cnt > 1){
        if (res == "") res = ss;
        else res = min(res, ss, cmp);
    }
}

void ql(int i){
    fi(j, 1, n){
        t[i] = j;
        xuli(i);
        if (i < n) ql(i+1);
    }
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> s[i];
    ql(1);
    if (res == "") cout << -1;
    else cout << res;
}
