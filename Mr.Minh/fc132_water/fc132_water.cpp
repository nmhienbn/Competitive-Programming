#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "fc132_water"
const int maxn = 1e6+5;

using namespace std;

ll n, a[maxn], pre[maxn], nex[maxn], maxx,
    res, top, st[maxn], pre1[maxn], nex1[maxn];

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    top = 0;
    fi(i, 1, n){
        pre[i] = top;
        if (a[i] >= a[top]) top = i;
    }
    top = n+1;
    fid(i, n, 1){
        nex[i] = top;
        if (a[i] >= a[top]) top = i;
    }
    top = 0, st[0] = 0;
    fi(i, 1, n){
        while (top > 0 && a[i] >= a[st[top]]) top--;
        pre1[i] = st[top];
        st[++top] = i;
    }
    top = 0, st[0] = n+1;
    fid(i, n, 1){
        while (top > 0 && a[i] >= a[st[top]]) top--;
        nex1[i] = st[top];
        st[++top] = i;
    }
    //fi(i, 1, n) cout << pre[i] << ' ' << nex[i] << '\n';
    fi(i, 1, n){
        maxx += max(min(a[pre[i]], a[nex[i]]) - a[i], 0ll);
    }
    fi(i, 1, n){
        if (a[i] < a[pre[i]] && a[i] < a[nex[i]]) continue;
        if (a[i] >= a[pre[i]] && a[i] >= a[nex[i]]) continue;
        if (a[i] < a[pre[i]]){
            res = max(i - pre1[i] - 1, res);
            //cout << i - pre[i] - 1 << '\n';
        }
        else {
            res = max(nex1[i] - i - 1, res);
            //cout << i << ' ' << nex[i] - i - 1 << '\n';
        }
    }
    cout << maxx + res;
}
