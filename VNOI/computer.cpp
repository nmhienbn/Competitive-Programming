#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define ll long long
#define Irelia "computer"
const int maxn = 1005;
using namespace std;

int x, a, y, b, n;
pii f[maxn][maxn];

void maximize(pii& x, pii y){
    if (x < y) x = y;
}

bool check(int w){
    fi(i, 0, x) fi(j, 0, y) if (i + j){
        f[i][j] = {0, 0};
        if (i){
            if (f[i - 1][j].second + a >= w){
                maximize(f[i][j], mp(f[i - 1][j].first + 1, 0));
            }
            else {
                maximize(f[i][j], mp(f[i - 1][j].first, f[i - 1][j].second + a));
            }
        }
        if (j){
            if (f[i][j - 1].second + b >= w){
                maximize(f[i][j], mp(f[i][j - 1].first + 1, 0));
            }
            else {
                maximize(f[i][j], mp(f[i][j - 1].first, f[i][j - 1].second + b));
            }
        }
        if (f[i][j].first >= n) return 1;
    }
    return (f[x][y].first >= n);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    while (cin >> x >> a >> y >> b >> n){
        int d = 1, c = x * a + b * y;
        while (d <= c){
            int g = (d + c) >> 1;
            if (check(g)) d = g + 1;
            else c = g - 1;
        }
        cout << c << '\n';
    }
}
