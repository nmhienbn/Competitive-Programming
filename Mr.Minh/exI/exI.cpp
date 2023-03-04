#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "exI"
const int maxn = 1e5 + 5;
using namespace std;

int n, a[maxn], y, z, res;
ll sum;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen(Irelia".inp", "r", stdin);
    //freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i];
    }
    cin >> y >> z;
    fi(i, 1, n){
        a[i] = abs(z - a[i]);
    }
    y = abs(y - z);
    sort(a + 1, a + n + 1);
    fi(i, 1, n){
        if (sum + a[i] < y){
            sum += a[i];
            res++;
        }
    }
    cout << res;
}
