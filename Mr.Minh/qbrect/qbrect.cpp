#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "qbrect"
const int maxn = 1005;

using namespace std;

int m, n, a[maxn], st[maxn], top, nex[maxn], pre[maxn], res;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m){
        fi(j, 1, n){
            bool t;
            cin >> t;
            if (t) a[j]++;
            else a[j] = 0;
        }
        top = 0; st[0] = 0;
        fi(j, 1, n){
            while (top > 0 && a[st[top]] >= a[j]) top--;
            pre[j] = st[top];
            st[++top] = j;
        }
        top = 0; st[0] = n+1;
        fid(j, n, 1){
            while (top > 0 && a[st[top]] >= a[j]) top--;
            nex[j] = st[top];
            st[++top] = j;
        }
        fi(j, 1, n){
            res = max(res, a[j] * (nex[j] - pre[j] - 1));
        }
    }
    cout << res;
}
