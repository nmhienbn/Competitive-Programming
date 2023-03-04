#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "patrik"
const int maxn = 5e5 + 5;

using namespace std;

int n, st[maxn], top, x;
ll res;
int cnt[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> x;
        while (top && st[top] < x) res += cnt[top--];
        if (top && st[top] == x){
            res += cnt[top], cnt[top]++;
            if (top > 1) res++;
        }
        else {
            if (top) res++;
            st[++top] = x;
            cnt[top] = 1;
        }
    }
    cout << res;
}

