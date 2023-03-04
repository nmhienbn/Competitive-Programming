#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "gems"
#define maxn 100005
#define maxk 680

using namespace std;

int n, k, tanso[maxn][30], dem[30];
char s[maxn];
ll res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n >> k;
    fi(i, 1, n){
        cin >> s[i];
        fi(j, 1, 26) tanso[i][j] = tanso[i-1][j];
        tanso[i][s[i] - 'a' +1] = tanso[i-1][s[i] - 'a' +1] +1;
    }
    //fi(i, 1, 26){ fi(j, 1, n) cout << tanso[j][i] << ' '; cout << '\n';}
    fi(i, 1, k) {
        char a, b;
        cin >> a >> b;
        fi(j, 1, n)
            if (s[j] == a){
                res += (tanso[n][b - 'a' +1] - tanso[j][b - 'a' +1]);
            }
    }
    cout << res;
}
