#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "seq2"
const int maxn = 10005;

using namespace std;

int n, a[maxn], L[maxn][maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n-1) if (a[i] < a[i+1]) L[i][i+1] = 1;
    fi(j, 2, n-1){
        fi(i, 1, n-j){
            L[i][i+j] = max({L[i+1][i+j], L[i][i+j-1], L[i+1][i+j-1] + (a[i] < a[i+j])});
        }
    }
    cout << L[1][n];
}
