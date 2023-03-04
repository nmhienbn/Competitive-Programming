#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "c11prime"
const int maxn = 1e6 + 5;
using namespace std;

ll n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    if (n == 1){
        cout << 0;
        exit(0);
    }
    fi(i, 2, 1000000) if (n % i == 0){
        int cnt = 0;
        while (n % i == 0){
            cnt++;
            n /= i;
        }
        if (n > 1 || cnt < 2) cout << 0;
        else cout << i << ' ' << cnt;
        exit(0);
    }
    cout << int(sqrt(n)) << ' ' << 2;
}
