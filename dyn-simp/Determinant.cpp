#include <iostream>
#include <cmath>
 
using namespace std;
 
    int findDet(int** a, int n) {
        if (n == 1)
            return a[0][0];
        else if (n == 2)
            return a[0][0] * a[1][1] - a[0][1] * a[1][0];
        else {
            int d = 0;
            for (int k = 0; k < n; k++) {
                int** b = new int*[n-1];
                for (int i = 0; i < n - 1; i++) {
                    b[i] = new int[n-1];
                }
                for (int i = 1; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (j == k)
                            continue;
                        else if (j < k)
                            b[i-1][j] = a[i][j];
                        else
                            b[i-1][j-1] = a[i][j];
                    }
                }
                d += pow(-1, k + 2) * a[0][k] * findDet(b, n - 1);
            }
            return d;
        }
    }
 
int main() {
    int n;
    cin >> n;
    int** a = new int * [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout << findDet(a, n);
    return 0;
}
