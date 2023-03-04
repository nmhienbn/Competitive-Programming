#include <bits/stdc++.h>
using namespace std;

int fin(int& k, int n){
	if (n == 1)
		return 0;
	n--;
	int ans;
	int ft = n;
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
	for (int i = 1; i <= n; i++) s.insert(i);
	auto itr = s.begin();
	k = k - 1;

	for (int i = 0; i < n; i++) {
		int id = fin(k, n - i);
		advance(itr, id);
		cout << *itr << ' ';
		s.erase(itr);
		itr = s.begin();
	}
}

int main(){
    int n, k;
	cin >> n >> k;
	calc(n, k);
	return 0;
}
