#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "ptc"
const int maxn = 5e5 + 5, maxk = 1e5 + 5;
using namespace std;

int k, n, N[maxk],a[maxn], b[maxn], m, cnt = 1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> k;
    a[0] = -2e9;
    fi(i, 1, k) cin >> N[i];
    fi(rep, 1, k){
        n = N[rep];
        fi(i, 1, n) cin >> a[i];
        sort(a + 1, a + n + 1);
        if (n) b[++m] = a[1];
        fi(i, 2, n) if (a[i] != a[i - 1]){
            b[++m] = a[i];
        }
    }
    sort(b + 1, b + m + 1);
    fi(i, 2, m){
        if (b[i] == b[i - 1]){
            cnt++;
            if (cnt >= k){
                cout << b[i];
                exit(0);
            }
        }
        else cnt = 1;
    }
    cout << 'x';
}
