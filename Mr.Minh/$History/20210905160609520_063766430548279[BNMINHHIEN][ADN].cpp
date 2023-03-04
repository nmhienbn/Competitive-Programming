#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "ADN"
const int maxn = 1e4+5;

using namespace std;

int n, m, L[maxn][maxn], u, v;
string a, b;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> a >> b;
    a += a;
    b += b;
    n = a.size();
    fi(i, 1, n){
        fi(j, 1, n){
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (a[i-1] == b[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = 0;
            if (L[i][j] >= L[u][v]){
                u = i, v = j;
            }
        }
    }
    cout << L[u][v] << '\n';
    fi(i, u-n/2+1, u) cout << a[i-1];
    cout << '\n';
    fi(i, v-n/2+1, v) cout << b[i-1];
}
