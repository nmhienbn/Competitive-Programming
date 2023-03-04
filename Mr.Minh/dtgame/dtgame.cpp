#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "dtgame"
const int maxn = 2005;

using namespace std;

int n, m, a[maxn], L[maxn][maxn], s[maxn][maxn];

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i];
        a[i] += a[i-1];
        s[i][i] = i;
    }
    fi(j, 2, n){
        fid(i, j-1, 1){
            fi(k, s[i][j-1], s[i+1][j]){
                int ans = min(L[i][k] + a[k]-a[i-1], L[k+1][j] + a[j]-a[k]);
                if (L[i][j] < ans){
                    L[i][j] = ans;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << L[1][n];
}
