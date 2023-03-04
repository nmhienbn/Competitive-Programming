#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "zero"
const int maxn = 1e6+5;

using namespace std;

int t, a[maxn];

void sieve(){
    fi(i, 1, 1e6) a[i] = 1e9;
    fi(i, 1, 1e6){
        a[i] = min(a[i], a[i-1]+1);
        for (int j = 2; j <= i && j*i <= 1e6; j++){
            a[j*i] = min(a[j*i], a[i]+1);
        }
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    sieve();
    cin >> t;
    while (t--){
        int x;
        cin >> x;
        cout << a[x] << '\n';
    }
}
