#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "main"

using namespace std;

multiset<double> b;
int M, N;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M >> N;
    f(i, 1, M) {double n; cin >> n; b.insert(n);}
    f(i, 1, N) {double n; cin >> n; b.erase(n);}
    for (std::multiset<double>::iterator i = b.begin(); i != b.end(); i++){
            cout << *i << " ";
    }
    return 0;
}
