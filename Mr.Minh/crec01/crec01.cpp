#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "crec01"
const int maxn = 1005;

using namespace std;

int m, n, a[maxn], st[maxn], top, soh[maxn];
ll res;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m){
        fi(j, 1, n){
            char t;
            cin >> t;
            if (t == '1') a[j]++;
            else a[j] = 0;
        }
        top = 0; st[0] = 0, soh[0] = 0;
        fi(j, 1, n){
            while (a[st[top]] >= a[j] && top > 0) top--;
            int flag = st[top];
            st[++top] = j;
            soh[j] = a[j]*(j-flag) + soh[flag];
            res += soh[j];
        }
    }
    cout << res;
}
