#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "rect"
const int maxn = 10;

using namespace std;

int n, a[maxn], b[maxn], c[maxn], A, B;
bool xd[maxn];
vector<pii> res;

void backtrack(int i){
    if (i == n + 1){
        res.pb({A, B});
    }
    if (a[c[i]] == A){
        B += b[c[i]];
        bool flag = 0;
        if (A > B) swap(A, B), flag = 1;
        backtrack(i + 1);
        if (flag) swap(A, B);
        B -= b[c[i]];
    }
    if (a[c[i]] != b[c[i]] && b[c[i]] == A){
        B += a[c[i]];
        bool flag = 0;
        if (A > B) swap(A, B), flag = 1;
        backtrack(i + 1);
        if (flag) swap(A, B);
        B -= a[c[i]];
    }
    if (b[c[i]] == B && A != B){
        A += a[c[i]];
        bool flag = 0;
        if (A > B) swap(A, B), flag = 1;
        backtrack(i + 1);
        if (flag) swap(A, B);
        A -= a[c[i]];
    }
    if (a[c[i]] == B && A != B){
        A += b[c[i]];
        bool flag = 0;
        if (A > B) swap(A, B), flag = 1;
        backtrack(i + 1);
        if (flag) swap(A, B);
        A -= b[c[i]];
    }
}

void xuli(){
    A = a[c[1]];
    B = b[c[1]];
    backtrack(2);
}

void ql(int i){
    fi(j, 1, n) if (!xd[j]){
        xd[j] = 1;
        c[i] = j;
        if (i < n) ql(i + 1);
        else xuli();
        xd[j] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i] >> b[i];
        if (a[i] > b[i]) swap(a[i], b[i]);
    }
    ql(1);
    sort(res.begin(), res.end());
    res.resize(unique(res.begin(), res.end()) - res.begin());
    for (pii vt : res){
        cout << vt.first << ' ' << vt.second << '\n';
    }
}
