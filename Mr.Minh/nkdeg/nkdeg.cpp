#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "nkdeg"
const int maxn = 15;

using namespace std;

ll L[maxn][maxn], n, k;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    fi(i, 0, 9) L[1][i] = 1;
    fi(i, 2, 9){
        fi(j, 0, 9){
            fi(t, 0, 9){
                if (abs(i - t) % k == 0){
                    L[i][j] += L[i-1][t];
                }
            }
        }
    }
    ll res = 0;
    fi(i, 0, 9) res += L[9][i];
    cout << res;
}
