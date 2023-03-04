#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "tien"
const int maxn = 105;

using namespace std;

int n, m, a[maxn], L[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    memset(L, 60, sizeof(L));
    L[0] = 0;
    fi(i, 1, n){
        cin >> a[i];
    }
    fi(i, 1, m){
        fi(j, 1, n){
            if (i >= a[j]){
                L[i] = min(L[i], L[i-a[j]] + 1);
            }
            else break;
        }
    }
    cout << L[m];
}
