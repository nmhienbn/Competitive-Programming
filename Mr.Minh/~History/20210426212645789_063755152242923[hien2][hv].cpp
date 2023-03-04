#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "hv"
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
        fi(j, 1, n)
            if (a[i][j] == '1'){
                int maxres = 1;
                int minx = min(dem_ngang[i][j], dem_doc[i][j]);
                fi(k, 1, minx-1){
                    if (min(dem_ngang[i+k][j], dem_doc[i][j+k]) >= k+1)
                        maxres = (k+1)*(k+1);
                    else break;
                }
                res = max(res, maxres);
            }
    cout << res;
}
