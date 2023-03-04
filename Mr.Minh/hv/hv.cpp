#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "hv"
const int maxn = 1805;
using namespace std;

int t, n, a[maxn*4], b[maxn*4], nex[maxn*4];
int st[maxn*4], top;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> t;
    while (t--){
        int res = 0;
        cin >> n;
        n *= 2;
        int m = n*2;
        fi(j, 1, m) b[j] = 0;
        fi(i, 1, n){
            fi(j, 1, n){
                cin >> a[j];
                a[j+n] = a[j];
            }
            fi(j, 1, m){
                if (a[j]) b[j]++;
                else b[j] = 0;
            }
            top = 0, st[0] = m+1;
            fid(j, m, 1){
                while (top > 0 && b[st[top]] >= b[j]) top--;
                nex[j] = st[top]-1;
                st[++top] = j;
            }
            top = 0, st[0] = 0;
            fi(j, 1, m){
                while (top > 0 && b[st[top]] >= b[j]) top--;
                res = max(res, min(nex[j]-st[top], b[j]));
                st[++top] = j;
            }
        }
        cout << res*res << '\n';
    }
}
