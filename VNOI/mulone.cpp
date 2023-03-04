#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "mulone"
const int maxn = 1e6 + 5;
using namespace std;

int nt, n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> nt;
    while (nt--){
        cin >> n;
        n--;
        fi(i, 1, n / 9) cout << "123456790";
        fi(i, 1, n % 9) cout << i;
        fid(i, n % 9 + 1, 2) cout << i;
        fi(i, 1, n / 9) cout << "098765432";
        cout << "1\n";
    }
}
