#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "pushups"
const int maxn = 5005;

using namespace std;

int a[15], m, n, res;
bool L[maxn][maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m){
        cin >> a[i];
        L[a[i]][a[i]] = a[i];
    }
    fi(i, 1, n){
        fi(j, 1, n){
            if (L[i][j]){
                fi(t, 1, m){
                    if (i+j+a[t] <= n){
                        L[i+j+a[t]][j+a[t]] = 1;
                    }
                }
                if (i == n && L[n][j]) res = max(res, j);
            }
        }
    }
    cout << res;
}
