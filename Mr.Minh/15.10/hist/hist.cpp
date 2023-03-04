#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "hist"
const int maxn = 1e6+5;
using namespace std;

int n, a[maxn], nex[maxn];
int st[maxn], top;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    while (cin >> n){
        if (n == 0) break;
        ll res = 0;
        fi(i, 1, n) cin >> a[i];
        top = 0; st[0] = n+1;
        fid(i, n, 1){
            while (top > 0 && a[i] <= a[st[top]]) top--;
            nex[i] = st[top];
            st[++top] = i;
        }
        top = 0; st[0] = 0;
        int pre = 0;
        fi(i, 1, n){
            while (top > 0 && a[i] <= a[st[top]]) top--;
            pre = st[top];
            st[++top] = i;
            res = max(res, 1ll*a[i]*(nex[i]-pre-1));
        }
        cout << res << '\n';
    }
}
