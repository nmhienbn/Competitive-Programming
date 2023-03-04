#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "water"
const int maxn = 1e6+5;

using namespace std;

int n, a[maxn], nex[maxn];
ll s[maxn], res, ct;
int st[maxn], top;
vector<int> vt;

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    fi(j, 1, n){
        a[j]++;
        fi(i, 1, n) s[i] = s[i-1] + a[i];//, cout << a[i] << ' '; cout << endl;
        st[0] = n+1, top = 0;
        fid(i, n, 1){
            while (top > 0 && a[st[top]] < a[i]) top--;
            nex[i] = st[top];
            st[++top] = i;
        }
        int bd = 1;
        ll ans = 0;
        while (bd <= n){
            //vt.pb(bd);
            int kt = nex[bd];
            if (kt > n){
                bd++;
                continue;
            }
            int h = min(a[bd], a[kt]);
            ans += 1ll*h*(kt-bd-1) - s[kt-1] + s[bd];
            bd = kt;
        }
        a[j]--;
        res = max(res, ans);
    }
    cout << res;
//    int m = vt.size();
//    fi(i, 0, m-1){
//        ll now = 0;
//        if (i > 0 && a[vt[i]] < a[vt[i-1]]){
//            now += vt[i] - vt[i-1] - 1;
//        }
//        if (i < m-1 && a[vt[i]] < a[vt[i+1]]){
//            now += vt[i+1] - vt[i] - 1;
//        }
//        ct = max(ct, now);
//    }
//    cout << res + ct;
}
