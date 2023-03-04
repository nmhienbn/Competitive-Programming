#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "post"
const int maxn = 1e5 + 5;
using namespace std;

int n, s1, s2, res;
int a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> s1 >> s2;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n) res = max(res, abs(a[i]))
    int d = abs(s2 - s1), c = 1e9;
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(g, s1, s2)) c = g - 1;
        else d = g + 1;
    }
    cout << d;
}
