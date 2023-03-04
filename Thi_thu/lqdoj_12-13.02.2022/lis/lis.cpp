#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "lis"
const int maxn = 2005;
using namespace std;

int n, a[maxn], b[maxn];
ll f[3][maxn], res;

bool check(int a[], int n){
    int k = 0;
    int b[25] = {};
    fi(i, 1, n){
        int d = 1, c = k;
        while (d <= c){
            int g = (d + c) >> 1;
            if (b[g] < a[i]) c = g - 1;
            else d = g + 1;
        }
        if (d > k) b[++k] = 0;
        b[d] = max(b[d], a[i]);
        if (k > 2) return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    fi(x, 1, (1 << n) - 1){
        int m = 0;
        fi(i, 0, n - 1) if (gb(x, i)){
            b[++m] = a[i + 1];
        }
        if (m > 1) res += check(b, m);
    }
    cout << res;
}
