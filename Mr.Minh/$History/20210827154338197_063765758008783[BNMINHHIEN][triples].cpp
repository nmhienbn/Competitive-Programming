#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "triples"
const int maxn = 5005;

using namespace std;

int n, a[maxn], res;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    fi(i, 1, n-2){
        int k = i+2, cnt = 0;
        fi(j, i+1, n-1){
            if (a[j] != a[j-1]) cnt = 0;
            while (a[k] < a[i]+a[j] && k <= n) k++;
            while (a[k] == a[i]+a[j] && k <= n) cnt++, k++;
            res += cnt;
        }
    }
    cout << res;
}
