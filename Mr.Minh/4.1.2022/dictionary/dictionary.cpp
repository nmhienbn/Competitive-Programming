#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define ll long long
#define Irelia "dictionary"
const int maxn = 1e4 + 5;
using namespace std;

struct node {
    int child[26];
    int deg;
} a[maxn * 40], b[maxn * 40];

int n, m, ai, bi, pa[maxn * 40], pb[maxn * 40];
ll res;
string s;

void add(string s, int u){
    int x = 0;
    fid(i, u, 1){
        int c = s[i] - 'a';
        if (!a[x].child[c]) a[x].child[c] = ++ai, pa[ai] = x;
        x = a[x].child[c];
    }
    if (!a[x].deg){
        a[x].deg++;
        fi(i, 1, u){
            x = pa[x];
            a[x].deg++;
        }
    }
}

void addr(string s, int u){
    int x = 0;
    fi(i, u, m){
        int c = s[i] - 'a';
        if (!b[x].child[c]) b[x].child[c] = ++bi, pb[bi] = x;
        x = b[x].child[c];
    }
    if (!b[x].deg){
        b[x].deg++;
        fid(i, m, u){
            x = pb[x];
            b[x].deg++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> s;
        m = s.size();
        s = ' ' + s;
        fi(j, 1, m) add(s, j), addr(s, j);
    }
    fi(i, 0, 25){
        if (a[0].child[i] && a[a[0].child[i]].deg > 1) res += a[a[0].child[i]].deg;
    }
    cout << a[0].deg * b[0].deg - res;

}
