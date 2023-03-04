#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "L1L2"
const int maxn = 5005;

using namespace std;

int n, a[maxn], L[maxn][3], res;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        int x;
        cin >> x;
        a[x] = i;
    }
    fi(i, 1, n){
        fi(u, 0, 2){
            fi(j, 0, i-1){
                fi(v, 0, 2){
                    if (j+v > 0 && a[j+v-1] < a[i+u-1]){
                        L[i][u] = max(L[i][u], L[j][v] + 1);
                    }
                }
            }
            if (L[i][u] > res) res = L[i][u];
        }
    }
    cout << res;
}
