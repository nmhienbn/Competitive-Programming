#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "remove"
#define maxn 2005

using namespace std;

int n, L[maxn][maxn], a[maxn], b[maxn], res, s1, s2; //L[i][j] la gia tri i -> i-j+1

//fi(i, 1, n) cin >> arr[i];
//fi(i, 1, n) cout << arr[i] << ' ';


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n) cin >> b[i];
    fi(i, 1, n) {L[i][1] = a[i]*b[i]; res = max(res, L[i][1]);}
    fi(i, 1, n-1) {L[i][2] = a[i+1]*b[i] + a[i]*b[i+1]; res = max(res, L[i][2]);}
    fi(j, 3, n)
        fi(i, 1, n-j+1){
            L[i][j] = L[i+1][j-2] + a[i]*b[i+j-1] + a[i+j-1]*b[i];
            res = max(res, L[i][j]);
        }
    fi(i, 1, n)
        fi(j, 1, n)
            if (L[i][j] == res){
                s1 = i; s2 = j;
            }
    cout << s1-1 << ' ' << n-s2 << '\n' << res;
}
