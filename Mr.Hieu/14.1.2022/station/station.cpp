#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "station"
const int maxn = 2e5 + 5;
using namespace std;

int n, a[maxn];
ll res;
int st[maxn], top;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n){
        while (top > 0 && a[st[top]] < a[i]){
            res++;
            top--;
        }
        res += (top > 0);
        while (top > 0 && a[st[top]] == a[i]){
            top--;
        }
        st[++top] = i;
    }
    cout << res;
}
