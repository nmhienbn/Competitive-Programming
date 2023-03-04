#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "seq1"
const int maxn = 505;

using namespace std;

int n, a[maxn], L[maxn][maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    fi(t, 1, n){
        fi(i, 1, t){
            fi(j, t+1, n){
                L[i][j] = max({L[i][j], L[i-1][j],
                L[i][j-1], L[i-1][j-1] + (a[i] < a[j])});
            }
        }
    }
    cout << L[1][n];
}
