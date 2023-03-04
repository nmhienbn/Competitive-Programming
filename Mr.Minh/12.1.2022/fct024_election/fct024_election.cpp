#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "fct024_election"
const int maxn = 105;
using namespace std;

int n, k, sum, a, maxa;
int nt;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> nt;
    while (nt--){
        cin >> n >> k;
        sum = k;
        maxa = 0;
        fi(i, 1, n){
            cin >> a;
            maxa = max(maxa, a);
            sum += a;
        }
        if (sum % n != 0){
            cout << "NO\n";
            continue;
        }
        sum /= n;
        if (sum >= maxa) cout << "YES\n";
        else cout << "NO\n";
    }
}
