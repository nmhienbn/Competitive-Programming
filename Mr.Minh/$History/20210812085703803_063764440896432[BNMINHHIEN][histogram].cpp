#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "histogram"
const int maxn = 0;

using namespace std;

int n, dem[(1 << 15) + 5][20], cnt;
ll L[(1 << 15) + 5][20], a[maxn], res;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    while (cin >> n){
        res = cnt = 0;
        if (!n) break;
        fi(i, 1, n) cin >> a[i];
        fi(i, 1, n) L[1 << (i-1)][i] = a[i]*2, dem[1 << (i-1)][i] = 1;
        fi(x, 1, (1 << n) - 1){
            fi(i, 1, n){
                if ((x >> (i-1))&1){
                    fi(j, 1, n){
                        ll now = L[x ^ (1 << (i-1))][j] + (a[i] - a[j]) * 2 * (a[i] > a[j]);
                        if (now > L[x][i]){
                            L[x][i] = now;
                            dem[x][i] = 1;
                        }
                        else if (now == L[x][i]){
                            dem[x][i]++;
                        }
                    }
                }
            }
        }
        fi(i, 1, n){
            //cout << L[(1 << n) - 1][i] << ' ';
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
