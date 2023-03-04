#include <bits/stdc++.h>

using namespace std;

int main()
{
    int d=0;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    for (int k = 2; k < n; k++){
        for (int i = 0; i < k; i++){
             for (int j = i+1; j < k; j++){
                if ((a[i]+a[j]) == a[k])
                    d++;
            }
        }
    }
    cout << d;
    return 0;
}
