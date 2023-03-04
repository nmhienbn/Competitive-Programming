#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "nt"
const int maxn = 3e6+5;

using namespace std;

int a[maxn], n, k, res;

void Erathosenes(){
    int m = 3e6;
    int mm = sqrt(m);
    fi(i, 2, mm) if (!a[i]){
        for (int j = i; j <= m; j += i){
            a[j]++;
        }
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    Erathosenes();
    cin >> n >> k;
    fi(i, 1, n) res += (a[i] >= k);
    cout << res;
}
