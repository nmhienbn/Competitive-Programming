#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "krect"
const int maxn = 105;
using namespace std;

int16_t n, m, k, b[26][maxn][maxn];
int res;
char c;

int cnt(int u, int v, int i, int j){
    int ans = 0;
    fi(t, 0, 25){
        ans += b[t][i][j] + b[t][u-1][v-1] > b[t][u-1][j] + b[t][i][v-1];
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n >> k;
    fi(i, 1, m) fi(j, 1, n){
        cin >> c;
        fi(t, 0, 25){
            b[t][i][j] = b[t][i-1][j] + b[t][i][j-1] - b[t][i-1][j-1];
        }
        b[c - 'A'][i][j]++;
    }
    fi(u, 1, m){
        fi(v, 1, n){
            int l = n, r = n;
            fi(i, u, m){
                while (cnt(u, v, i, r) > k && r >= v) r--;
                l = min(l, r);
                while (cnt(u, v, i, l) >= k && l >= v) l--;
                if (r == v - 1) break;
                res += r - l;
            }
        }
    }
    cout << res;
}
