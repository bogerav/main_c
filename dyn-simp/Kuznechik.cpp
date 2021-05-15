#include <iostream>

using namespace std;

int f(int *a, int n, int m) {
	int k = 0;
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	if (a[n] > 0)
		return a[n];
	for (int i = 1; i <= m; ++i)
		k += f(a, n - i, m);
	return  a[n] = k;
}

int main()
{
	int n;
	cin >> n;
	int *a = new int[n + 1];
	cout << f(a, n, 3);
	return 0;
}
