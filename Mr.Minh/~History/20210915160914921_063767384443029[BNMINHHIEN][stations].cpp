#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "stations"
const int maxn = 205;

using namespace std;

int n, k, a, b, x[maxn], L[maxn][maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k >> a >> b;
    fi(i, 1, n) cin >> x[i];
    fi(i, 0, n) fi(j, 0, k) L[i][j] = 1e9;
    L[0][0] = 0;
    fi(i, a, n){
        fi(j, 1, min(i, k)){
            fi(t, max(i-b, j-1), i-a){
                L[i][j] = min(L[i][j], max(L[t][j-1], x[i] - x[t+1]));
            }
        }
    }
    cout << L[n][k];
}
