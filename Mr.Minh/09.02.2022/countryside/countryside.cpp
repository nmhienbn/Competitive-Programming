#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "countryside"
const int maxn = 1005;
using namespace std;

int n, a[maxn], res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n){
        int ans = 1;
        fid(j, i-1, 1){
            if (a[j] <= a[j + 1]) ans++;
            else break;
        }
        fi(j, i + 1, n){
            if (a[j] <= a[j - 1]) ans++;
            else break;
        }
        if (res < ans) res = ans;
    }
    cout << res;
}
