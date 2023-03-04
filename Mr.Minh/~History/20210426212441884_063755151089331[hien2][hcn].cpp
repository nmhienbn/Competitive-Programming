#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "hcn"
#define maxn 1005

using namespace std;

int m, n, dem_ngang[maxn][maxn], dem_doc[maxn][maxn], res;
char a[maxn][maxn];

//fi(i, 1, n) cin >> arr[i];
//fi(i, 1, n) cout << arr[i] << ' ';


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> m >> n;
    fi(i, 1, m)
        fi(j, 1, n)
            cin >> a[i][j];
    fi(i, 1, m){
        int dem = 0;
        fid(j, n, 1)
            if (a[i][j] == '1') dem_ngang[i][j] = ++dem;
            else dem_ngang[i][j] = dem = 0;
    }

    fi(j, 1, n){
        int dem  = 0;
        fid(i, m, 1)
            if (a[i][j] == '1') dem_doc[i][j] = ++dem;
            else dem_doc[i][j] = dem = 0;
    }
    fi(i, 1, m)
        fi(j, 1, n){
            int minx = dem_ngang[i][j];
            res = max(res, minx);
            fi(k, i+1, i+dem_doc[i][j]-1){
                minx = min(minx, dem_ngang[k][j]);
                res = max(res, minx*(k-i+1));
            }
        }
    cout << res;
}
