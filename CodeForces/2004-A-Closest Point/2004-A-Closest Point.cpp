#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    if(n > 2) {
		    cout << "NO" << endl;
		  return;
    }
  	if (arr[1] == arr[0] + 1) {
  		  cout << "NO" << endl;
  	} else {
  		  cout << "YES" << endl;
  	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        pranavjawale01();
    }
    
    return 0;
}
