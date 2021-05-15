#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

bool podbor(vector<int> a, int cor, int n) {

  if (n == a.size()) {
    int s = 0;
    for (int i = 0; i < n; i++)
      s += a[i];
    if (cor == s)
      return 1;
    else 
      return 0;
  }
  vector<int> b = a;
  b[n] *= -1;
  if (podbor(b, cor, n + 1) or podbor(a, cor, n + 1))
    return 1;
  
  return 0;
}

int main() {
  int a;
  int b = 0;
  cin >> a;
  string s;
  vector<int> v;
  getline(cin, s);
  getline(cin, s);
  stringstream ss(s);
  for (int i = 0; !ss.eof(); i++) {
    int t = 0;
    ss >> t;
    v.push_back(t);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    if (v[i+1] - v[i] <= a) 
      b = v[i];
    else
      b += a;
  }
  cout << b;
  return 0;
}
