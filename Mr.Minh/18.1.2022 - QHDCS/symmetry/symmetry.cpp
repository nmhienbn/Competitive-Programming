#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define file freopen(Ahri".inp", "r", stdin); freopen(Ahri".out", "w", stdout);
#define Ahri "symmetry"
const int maxn = 2e5+5;

using namespace std;

int n, a[maxn], b[maxn], Z[maxn], res;

void Tinh_Z(){
    Z[0] = 0;
    int L, R = 0;
    fi(i, 1, n){
		int x = 0;
		if (i <= R){
            x = min(Z[i-L+1], R-i+1);
		}
		while (i+x <= n && b[x+1] == a[i+x]){
            x++;
		}
		Z[i] = x;
		if (R < i + x - 1){
			L = i;
			R = i + x - 1;
		}
		if (R >= n){
            res = i-1;
            return;
		}
	}
}

int main(){
    faster file
    cin >> n;
    fi(i, 1, n){
        cin >> a[i];
        b[n+1-i] = a[i];
    }
    Tinh_Z();
    cout << res << '\n';
    fid(i, res, 1) cout << a[i] << ' ';
}
