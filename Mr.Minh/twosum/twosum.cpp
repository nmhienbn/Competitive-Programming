#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "twosum"
const int maxn = 5005;

using namespace std;

int n, a[maxn], res;

int main(){
    faster
//    freopen(NunuAndWillump".inp", "r", stdin);
//    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i], a[i] += a[i-1];
    fi(i, 2, n){
        int k = 1;
        fi(j, 0, i-2){
            while (k < i && a[j] + a[i] > a[k] * 2) k++;
            if (k < i && a[i] + a[j] == a[k] * 2){
                res = max(res, i-j);
                break;
            }
        }
    }
    cout << res;
}
