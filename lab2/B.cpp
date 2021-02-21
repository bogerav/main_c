#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k, j, y, x;
    cin >> n >> k >> j;
    vector <vector <int>> v(n, vector <int> (k, 0));
    for (int i = 0; i < j; i++){
        cin >> y >> x;
        v[y - 1][x - 1] = -1;
        if (y > 1 && x > 1 && v[y - 2][x - 2] != -1) 
          v[y - 2][x - 2] += 1;
        if (y > 1 && v[y - 2][x - 1] != -1) 
          v[y - 2][x - 1] += 1;
        if (y > 1 && x < k && v[y - 2][x] != -1) 
          v[y - 2][x] += 1;
        if (x > 1 && v[y - 1][x - 2] != -1) 
          v[y - 1][x - 2] += 1;
        if (x < k && v[y - 1][x] != -1) 
          v[y - 1][x] +=1;
        if (y < n && x > 1 && v[y][x - 2] != -1) 
          v[y][x - 2] += 1;
        if (y < n && v[y][x - 1] != -1) 
          v[y][x - 1] += 1;
        if (y < n && x < k && v[y][x] != -1) 
          v[y][x] += 1;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}