#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "fct020_xortable"
const int maxn = 105;

using namespace std;

int n, b[maxn];

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> b[i];
    fi(i, 1, n){
        fi(j, 1, n){
            cout << (b[i]^b[j]) << ' ';
        }
        cout << '\n';
    }

}
