#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "construct"
const int maxn = 100005;

using namespace std;

int n, m, nt, a[maxn], l, r, k, typ;
int st[maxn], top;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> nt;
    while (nt--){
        cin >> n >> m;
        fi(i, 1, n) cin >> a[i];
        while (m--){
            cin >> typ;
            if (typ == 1){
                cin >> l >> r >> k;
                fi(i, l, r) a[i] += k;
            }
            else {
                cin >> l >> r;
                ll res = 0;
                int pre = 0;
                fi(i, l, r){
                    res += max(0, a[i] - pre);
                    pre = a[i];
                }
                cout << res << '\n';
            }
        }
    }
}
