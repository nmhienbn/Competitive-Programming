#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "sport"
const int maxn = 1005;
using namespace std;

int n, a[maxn], b[maxn], res = 1e9;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i], b[i] = a[i];
    sort(b + 1, b + n + 1);
    fi(rep, 1, n){
        int dem = n;
        int j = rep;
        fi(i, 1, n) if (a[i] == b[j]){
            dem--;
            j++;
        }
        res = min(res, dem);
    }
    cout << res;
}
