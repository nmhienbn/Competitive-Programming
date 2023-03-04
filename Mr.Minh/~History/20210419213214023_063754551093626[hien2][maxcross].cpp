#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "maxcross"
#define maxn 1005

using namespace std;

int n, b[maxn][maxn], a1[maxn][maxn], b1[maxn][maxn], c1[maxn][maxn], d1[maxn][maxn], a2[maxn][maxn], b2[maxn][maxn], c2[maxn][maxn], d2[maxn][maxn], a[maxn][maxn];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n;
    fi(i, 1, n)
        fi(j, 1, n){
            char c;
            cin >> c;
            if (c == 'X') a[i][j] = 1;
        }

    fi(i, 1, n)
        fi(j, 1, n){
            a1[i][j] = (a1[i][j-1] + 1) * a[i][j];
            b1[i][j] = (b1[i-1][j-1] + 1) * a[i][j];
            c1[i][j] = (c1[i-1][j] + 1) * a[i][j];
            d1[i][j] = (d1[i-1][j+1] + 1) * a[i][j];
        }
    fid(i, n, 1)
        fid(j, n, 1){
            a2[i][j] = (a2[i][j+1] + 1) * a[i][j];
            b2[i][j] = (b2[i+1][j+1] + 1) * a[i][j];
            c2[i][j] = (c2[i+1][j] + 1) * a[i][j];
            d2[i][j] = (d2[i+1][j-1] +1) * a[i][j];
        }

    fi(i, 1, n){
        fi(j, 1, n)
            cout << max(max(b[i][j], max(a1[i][j]+a2[i][j]-1, b1[i][j]+b2[i][j]-1)), max(c1[i][j]+c2[i][j]-1, d1[i][j]+d2[i][j]-1)) << ' ';
        cout << '\n';
    }

}
