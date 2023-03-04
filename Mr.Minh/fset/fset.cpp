#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "fset"
const int maxn = 1e6 + 5;

using namespace std;

int n, m, a[maxn], scp[1005], res = 1, cnt;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, 1000){
        scp[i] = i * i;
    }
    fi(i, 1, n) if (a[i] == 0){
        cnt = 1;
        fi(j, 1, 1000){
            if (scp[j] > n / i) break;
            a[i * scp[j]] = i;
            cnt++;
        }
        res = 1ll * res * cnt % m;
    }
    cout << res;
}
