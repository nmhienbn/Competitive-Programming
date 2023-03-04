#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "permutationlist"
const int maxn = 0;
using namespace std;

int fin(int& k, int n){
	if (n == 1)
		return 0;
	n--;
	int ans, ft = n;
	while (k >= ft && n > 1) {
		ft = ft * (n - 1);
		n--;
	}
	ans = k / ft;

	k = k % ft;

	return ans;
}

void calc(int n, int k){
	set<int> s;
	fi(i, 1, n) s.insert(i);
	auto itr = s.begin();
	k = k - 1;

	fi(i, 0, n-1){
		int id = fin(k, n - i);
		advance(itr, id);
		cout << *itr << ' ';
		s.erase(itr);
		itr = s.begin();
	}
}

int gt[15];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    gt[0] = 1;
    fi(i, 1, 12) gt[i] = gt[i-1] * i;
    int n, k;
	cin >> n >> k;
	if (n <= 12 && k > gt[n]) cout << -1;
	else calc(n, k);
}
