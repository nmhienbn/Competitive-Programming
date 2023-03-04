#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "cutseq"
const int maxn = 100005;

using namespace std;

int n, b[maxn];
ll m, a[maxn], sum, ahri, c[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    bool w = 0;
	cin >> n >> m;
	fi(i, 1, n){
		cin >> a[i];
		if (a[i] > m){
			w = 1;
		}
	}
	if (w){
		cout << -1;
		exit(0);
	}
	sum = ahri = c[1] = a[1];
	b[1] = 1;
	int pt = 1;
	fi(i, 2, n){
		c[i] = 1e18;
		sum += a[i];
		while (sum > m)	sum -= a[pt++];
		if (ahri >= a[i] && b[i - 1] >= pt){
			c[i] = c[i - 1];
			b[i] = b[i - 1];
		}
		else {
			ahri = a[i];
			int st = i;
			if (b[i - 1] >= pt)	st = b[i - 1];
			fid (j, st, pt){
				if (a[j] > ahri) ahri = a[j];
				if (c[i] > ahri + c[j - 1]){
					b[i] = j;
					c[i] = ahri + c[j - 1];
				}
			}
			ahri = c[i] - c[b[i] - 1];
		}
	}
	cout << c[n];
}
