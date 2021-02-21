#include <iostream>
using std::cin;
using std::cout;
using std::endl;


int main() {
    int a, b;
    cin >> a >> b;

    cout << do_some_awesome_work(&a, &b);
}