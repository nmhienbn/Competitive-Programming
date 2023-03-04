#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "v8score"
const int maxn = 22;
using namespace std;
int s, k, n, a[maxn][maxn], l[202], luu[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> s >> k >> n;
    fi (i, 1, n)
        fi (j, 1, k) cin >> a[i][j];
    fi (i, 1, s) l[i] = 1e9;
    fi (t, 1, s)
        fi (j, 1, k)
            fi (i, 1, n)
                l[i] =





}
