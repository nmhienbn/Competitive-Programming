#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "lcs2x"
const int maxn = 1505;
using namespace std;

int nt, m, n, res;
int a[maxn], b[maxn];
int c[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> nt;
    while (nt--){
        cin >> m >> n;
        fi(i, 1, n) c[i] = 0;
        fi(i, 1, m) cin >> a[i];
        fi(i, 1, n) cin >> b[i];
        fi(i, 1, m){
            int cur = 0;
            fi(j, 1, n){
                int pre = cur;
                if (b[j] * 2 <= a[i]) cur = max(c[j], cur);
                if (b[j] == a[i]){
                    c[j] = max(c[j], pre + 1);
                }
            }
        }
        cout << *max_element(c + 1, c + n + 1) << '\n';
    }
}
