#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "maxcub"
const int maxn = 35;

using namespace std;

int n;
ll L[35][35][35], res;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    while (cin >> n){
        res = -1e18;
        fi(i, 1, n){
            fi(j, 1, n){
                fi(k, 1, n){
                    ll a;
                    cin >> a;
                    L[i][j][k] = a + L[i-1][j][k] + L[i][j-1][k] + L[i][j][k-1]
                                - L[i-1][j-1][k] - L[i][j-1][k-1] - L[i-1][j][k-1]
                                + L[i-1][j-1][k-1];
                }
            }
        }
        fi(v, 1, n){
            fi(i, 0, n-v){
                fi(j, 0, n-v){
                    fi(k, 0, n-v){
                        ll now = L[i+v][j+v][k+v] - L[i+v][j+v][k]
                        - L[i+v][j][k+v] - L[i][j+v][k+v] + L[i+v][j][k]
                        + L[i][j+v][k] + L[i][j][k+v] - L[i][j][k];
                        res = max(res, now);
                    }
                }
            }
        }
        cout << res << '\n';
    }
}
