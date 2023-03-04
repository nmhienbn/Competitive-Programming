#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "bwpoints"
const int maxn = 2e5 + 5;
using namespace std;

int n, res;
pii a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//    freopen(Irelia".inp", "r", stdin);
//    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n << 1) cin >> a[i].first;
    fi(i, n + 1, n << 1) a[i].second = 1;
    n <<= 1;
    sort(a + 1, a + n + 1);
    fi(i, 2, n){
        if (a[i].second != a[i - 1].second){
            res++;
            i++;
        }
    }
    cout << res;
}
