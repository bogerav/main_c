#include <iostream>
#include <vector>

using namespace std;

double av(vector<int> v) {
  double c = 0;
  double d = 0;
  if (v.empty()) {
    d = 0;
  }
  else {
    for (auto i : v) {
      c += i;
    }
    d = c/v.size();
  }
  return d;
}

int main() {
  int n;
  int sum = 0;
  cin >> n;
  vector <int> v = {};
  while (n>0) {
    int t;
    cin >> t;
    v.push_back(t);
    n -= 1;
  }

  for (auto i : v){
    if (i > av(v))
      sum += i;
  }
  cout << sum;
}