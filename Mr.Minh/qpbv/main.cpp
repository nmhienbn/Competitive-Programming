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

#define maxn 100005
#define maxm 1000006
#define MOD
#define Seraphine "g"

int m, n, a[25], L[maxn][25][2], maxL[maxn][25][2], res;

using namespace std;

int main(){
    faster
    freopen(Seraphine".inp","r",stdin);
    freopen(Seraphine".out","w",stdout);
    cin >> m >> n;
    fi(i, 1, m) cin >> a[i];
    fi(i, 1, n){
        int x;
        cin >> x;
        fi(j, 1, m){
            if (x >= a[j]){
                L[i][j][1] = maxL[i-1][j-1][0] + 1;
            }
            if (x <= a[j]){
                L[i][j][0] = maxL[i-1][j-1][1] + 1;
            }
            maxL[i][j][0] = max(maxL[i-1][j][0], L[i][j][0]);
            maxL[i][j][1] = max(maxL[i-1][j][1], L[i][j][1]);
            res = max({res, maxL[i][j][0], maxL[i][j][1]});
            cout << maxL[i][j][0] << ',' << maxL[i][j][1] << ' ';
        }
        cout << '\n';
        //cout << L[j][0] << ' ' << L[j][1] << '\n';
    }
    cout << res;
}
