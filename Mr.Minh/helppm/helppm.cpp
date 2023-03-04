#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "helppm"
const int maxn = 505;

using namespace std;

int m, n, x, y, z, t, res = 1e9;
ll s[maxn][maxn], k;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> m >> n >> k;
    fi(i, 1, m){
        fi(j, 1, n){
            int a;
            cin >> a;
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a;
        }
    }
    fi(i, 1, m){
        fi(j, 1, i){
            int v = 1;
            fi(u, 1, n){
                while (v <= u && s[i][u] - s[i][v] - s[j-1][u] + s[j-1][v] >= k) v++;
                if (v <= u && (i-j+1)*(u-v+1) < res && s[i][u] - s[i][v-1] - s[j-1][u] + s[j-1][v-1] >= k){
                    res = (i-j+1)*(u-v+1);
                    x = j, y = v, z = i, t = u;
                }
            }
        }
    }
    if (res == 1e9){
        cout << -1;
        exit(0);
    }
    cout << res << '\n' << x << ' ' << y << ' ' << z << ' ' << t;
}
