#include <iostream>
using namespace std;
 
int main() {
    int n, k;
    cin >> n >> k;
    int p = 0;
    for (int i = 2; i <= n; i++) p = (p + k) % i;
    cout << p+1;
    return 0;
}
