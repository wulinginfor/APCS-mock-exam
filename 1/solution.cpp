#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    long long ans = 0;
    cin >> n >> k;
    vector<int> c(n);
    for(int i=0;i<n;i++) cin >> c[i];
    for(int i=0;i<k;i++){
        int m;
        cin >> m;
        for(int j=0;j<m;j++){
            int a, b;
            cin >> a >> b;
            ans += b * c[a];
        }
    }

    cout << ans << endl;
}