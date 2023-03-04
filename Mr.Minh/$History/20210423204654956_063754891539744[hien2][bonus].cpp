#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "bonus"
#define maxn 1005

using namespace std;

//fi(i, 1, n) cin >> arr[i];
//fi(i, 1, n) cout << arr[i] << ' ';

int n, k, a[maxn][maxn], sum[maxn][maxn], res, res1, sumdoc[maxn][maxn]; //sum: tong a[i][1] den a[i][j]

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n >> k;
    fi(i, 1, n)
        fi(j, 1, n){
            cin >> a[i][j];
            sum[i][j] = sum[i][j-1] + a[i][j];
        }

    fi(j, 1, n)
        fi(i, 1, n){
            sumdoc[i][j] = sumdoc[i-1][j] + a[i][j];
        }
    /*fi(i, 1, n){
        fi(j, 1, n)
            cout << sumdoc[i][j] << ' ';
        cout << endl;
    }*/
    fi(t, 1, k) res1 += sum[t][k];
    fi(i, 1, n-k+1){
        int res2 = res1;
        res = max(res, res1);
        fi(j, 2, n-k+1){
            res2 = res2 - (sumdoc[i+k-1][j-1] - sumdoc[i-1][j-1]) + (sumdoc[i+k-1][j+k-1] - sumdoc[i-1][j+k-1]);
            //cout << res2 << endl;
            res = max(res, res2);
        }
        res1 = res1 - sum[i][k] + sum[i+k-1][k];
    }
    cout << res;
}
