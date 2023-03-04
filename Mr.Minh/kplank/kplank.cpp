#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "kplank"
const int maxn = 1e6+5;

using namespace std;

int n, a[maxn], st[maxn], top, pre[maxn], nex[maxn], res;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    top = 0, st[0] = 0;
    fi(i, 1, n){
        while (a[st[top]] >= a[i] && top > 0) top--;
        pre[i] = st[top];
        st[++top] = i;
    }
    top = 0, st[0] = n+1;
    fid(i, n, 1){
        while (a[st[top]] >= a[i] && top > 0) top--;
        nex[i] = st[top];
        st[++top] = i;
    }
    fi(i, 1, n){
        if (nex[i] - pre[i] - 1 >= a[i]){
            res = max(res, a[i]);
        }
    }
    cout << res;
}
