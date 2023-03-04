#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define TwistedFate "ps"
const int maxn = 1e5+5;
using namespace std;

int n;
ll a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen(TwistedFate".inp", "r", stdin);
    //freopen(TwistedFate".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i], a[i] += a[i-1];
    fid(i, n, 1){
        fi(j, 1, n-i+1){
            if (a[j-1+i] > a[j-1]){
                cout << j << ' ' << j-1+i;
                exit(0);
            }
        }
    }

}
