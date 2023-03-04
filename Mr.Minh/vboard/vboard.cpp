#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a; i<=b; i++)
#define fid(i,a,b) for(int i=a; i>=b; i--)
#define fir first
#define se second
#define bit(i,j) ((i>>j)&1)
#define bit2(i) (1<<(i-1))
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

#define maxn 505
#define maxm 1000006
#define MOD
#define Seraphine "vboard"

using namespace std;

int n;
ll a[maxn][maxn];

int main(){
    faster
    freopen(Seraphine".inp","r",stdin);
    freopen(Seraphine".out","w",stdout);
    cin >> n;
    fi(i, 1, n){
        fi(j, 1, n){
            cin >> a[i][j];
            if ((i+j)&1) a[i][j] = -a[i][j];
            a[i][j] += a[i][j-1];
        }
    }
    fi(j, 1, n){
        fi(i, 1, n){
            a[i][j] += a[i-1][j];
        }
    }
    int q;
    cin >> q;
    while (q--){
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        cout << abs(a[i2][j2] + a[i1-1][j1-1] - a[i2][j1-1] - a[i1-1][j2]) << '\n';
    }
}
