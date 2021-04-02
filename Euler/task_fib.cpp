#include <iostream>
#include <cmath>

int f(int n){
    if (n == 1) return 1;
    else if (n == 2) return 2;
        else return f(n - 1) + f(n - 2);
}

int main(){
    int N;
    int s = 0;
    std::cin >> N;
    for (int i = 2; i < N + 1; i += 3){
            s += f(i);
    }
    std::cout << s;
    return 0;
}
