#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "kagain"
const int maxn = 3e4+5;

using namespace std;

int n, a[maxn], t, st[maxn], top, nex[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> t;
    while (t--){
        int res = 0, l, r;
        cin >> n;
        fi(i, 1, n) cin >> a[i];
        top = 0, st[top] = n+1;
        fid(i, n, 1){
            while (top > 0 && a[st[top]] >= a[i]) top--;
            nex[i] = st[top];
            st[++top] = i;
        }
        top = 0, st[top] = 0;
        fi(i, 1, n){
            while (top > 0 && a[st[top]] >= a[i]) top--;
            int now = a[i] * (nex[i]-st[top]-1);
            if (res < now){
                res = now;
                l = st[top]+1;
                r = nex[i]-1;
            }
            st[++top] = i;
        }
        cout << res << ' ' << l << ' ' << r << '\n';
    }

}
