#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    vector <char> v;
    string a;
    cin >> a;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == '(' or a[i] == '{' or a[i] == '[')
            v.push_back(a[i]);
        if (v.empty() and ((a[i] == ')') or (a[i] == '}') or (a[i] == ']'))) {
            cout <<"NO";
            return 0;
        }
        if ((a[i] == ')') and (!v.empty()) and (v.back() == '('))
            v.pop_back();
        if ((a[i] == '}') and (!v.empty()) and (v.back() == '{')) 
            v.pop_back();
        if ((a[i] == ']') and (!v.empty()) and (v.back() ==  '['))
            v.pop_back();
    }
    if (!v.empty())
        cout <<"NO";
    else
        cout <<"YES";
    return 0;
}
