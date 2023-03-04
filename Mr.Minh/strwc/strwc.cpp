#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "strwc"
const int maxn = 1e5+5;
using namespace std;

int nt, n, k, a[maxn], pre[maxn],
    L[maxn], d[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> nt;
    while (nt--) {
        cin >> n >> k;
        fi(i, 1, n){
            char c;
            cin >> c;
            a[i] = c == '*' ? 0 : c - 'a' + 1;
        }
        fi(i, 1, k) {
            L[i] = 1;
            pre[i] = a[i];
            d[i] = a[i] == 0;
        }
        fi(i, k+1, n) {
            if (a[i]){
                if (pre[i-k] == 0 || a[i] == pre[i-k]) L[i] = L[i-k] + 1;
                else if (a[i-k] == 0) L[i] = d[i-k] + 1;
                else L[i] = 1;
                pre[i] = a[i];
                d[i] = 0;
            }
            else {
                d[i] = d[i-k] + 1;
                L[i] = L[i-k] + 1;
                pre[i] = pre[i-k];
            }
        }
        priority_queue<pii, vector<pii>, greater<pii>> q;
        fi(i, 1, k-1){
            q.push({L[i], i});
        }
        int res = 0;
        fi(i, k, n){
            q.push({L[i], i});
            while (q.top().second <= i-k) q.pop();
            res = max(res, q.top().first*k);
        }
        cout << res << '\n';
    }
}
