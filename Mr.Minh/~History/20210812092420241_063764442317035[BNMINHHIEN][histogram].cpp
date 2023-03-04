#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "histogram"
const int maxn = 20;

using namespace std;

int n, dem[(1 << 15) + 5][20], cnt;
ll L[(1 << 15) + 5][20], a[20], res;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    while (cin >> n){
        if (!n) break;
        res = cnt = 0;
        memset(L, 0, sizeof(L));
        memset(dem, 0, sizeof(dem));
        fi(i, 0, n-1) cin >> a[i];
        fi(i, 0, n-1) L[1 << i][i] = a[i]*2, dem[1 << i][i] = 1;
        fi(x, 1, (1 << n) - 1){
            fi(i, 0, n-1){
                if ((x >> i)&1){
                    fi(j, 0, n-1){
                        if (!((x >> j)&1)){
                            if (L[x|(1 << j)][j] < L[x][i] + (a[j]-a[i])*2*(a[j] > a[i])){
                                L[x|(1 << j)][j] = L[x][i] + (a[j]-a[i])*2*(a[j] > a[i]);
                                dem[x|(1 << j)][j] = dem[x][i];
                            }
                            else if (L[x|(1 << j)][j] == L[x][i] + (a[j]-a[i])*2*(a[j] > a[i])){
                                dem[x|(1 << j)][j] += dem[x][i];
                            }
                        }
                    }
                }
            }
        }
        fi(i, 0, n-1){
            if (L[(1 << n) - 1][i] > res){
                res = L[(1 << n) - 1][i];
                cnt = dem[(1 << n) - 1][i];
            }
            else if (L[(1 << n) - 1][i] == res){
                cnt += dem[(1 << n) - 1][i];
            }
        }
        cout << res + n*2 << ' ' << cnt << '\n';
    }
}
