#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "ttrip"
const int maxn = 105;

using namespace std;

int n, a[maxn][maxn], L[maxn][maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        fi(j, 1, n){
            cin >> a[i][j];
            if (i != j){
                L[i][j] = 1e9;
            }
        }
    }

}
