#include <iostream>
using namespace std;

void PrintNarcissus();
int main() {
	PrintNarcissus();
	system("pause");
	return 0;
}

void PrintNarcissus() {
	int i, j, k;
	for (i = 1; i <= 9; i++) {
		for (j = 0; j <= 9; j++) {
			for (k = 0; k <= 9; k++) {
				int num = 100 * i + 10 * j + k;
				if (num == i*i*i + j*j*j + k*k*k) cout << num << endl;
			}
		}
	}
}