#include <iostream>
#include <sstream>
#include <vector>

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
  bool k = podbor(v, a, 0);
  if (k) 
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
