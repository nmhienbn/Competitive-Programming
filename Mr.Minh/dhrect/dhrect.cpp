#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "dhrect"
const int maxn = 3e5+5;

using namespace std;

int n, a[maxn], k;

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> k;
    while (k--){
        int x = -1, y = -1;
        cin >> n;
        fi(i, 1, n){
            cin >> a[i];
        }
        sort(a+1, a+n+1);
        fid(i, n-1, 1){
            if (a[i] == a[i+1]){
                if (x == -1) x = a[i], i--;
                else {
                    y = a[i];
                    cout << 1ll*x*y;
                    goto xuli;
                }
            }
        }
        cout << -1;
        xuli : cout << '\n';
    }

}
