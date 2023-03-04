#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "pairequa"
const int maxn = 1e5 + 5;
using namespace std;

int n, st[maxn], top, x;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    while (n--){
        cin >> x;
        st[++top] = x;
        while (top > 1 && st[top] == st[top - 1]) st[--top]++;
    }
    cout << top << '\n';
    fi(i, 1, top) cout << st[i] << ' ';
}
