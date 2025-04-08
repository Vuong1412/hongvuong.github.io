#include <iostream>
using namespace std;
#include <cmath>

bool ktsnt(int n) {
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n);i++) {
		if (n % i==0) return false;
	}
	return true;
}

int findmax(int** mang, int m, int n) {
	int maxPrime = -1;
	for (int i = 0;i < m;i++) {
		for (int j = 0; j < n;j++) {
			if ((ktsnt(mang[i][j]))&&(mang[i][j]>maxPrime)) {
				maxPrime = mang[i][j];
			}
		}
	}
	return maxPrime;
}

void timdongcosonguyento(int** mang, int m, int n) {
	bool rowprime = false;

	for (int i = 0; i < m;i++) {
		bool hasprime = false;
		for (int j = 0; j < n; j++) {
			if (ktsnt(mang[i][j])) {
				hasprime = true;
				break;
			}
		}
		if (hasprime) {
			rowprime = true;
			cout << "dong " << i + 1 << ":  ";
			for (int j = 0;j < n;j++) {
				cout << mang[i][j] << " ";
			}
			cout << endl;
		}
		if (rowprime == false) {
			cout << "khong co dong nao co so nguyen to " << endl;
		}
	}
}

void timdongdeulasonguyento(int** mang, int m, int n) {
	bool dongcosonguyento = false;

	for (int i = 0; i < m;i++) {
		bool allprime = true;

		for (int j = 0; j < n;j++) {
			if (!ktsnt(mang[i][j])) {
				allprime = false;
				break;
			}
		}
		if (allprime) {
			dongcosonguyento = true;
			cout << "dong " << i + 1 << ": ";
				for (int j = 0;j < n;j++) {
					cout << mang[i][j] << " ";
				}
				cout << endl;
		}
		if (!dongcosonguyento) {
			cout << "khong co dong nao toan la so nguyen to ";
		}
	}
}


int main() {
	int m, n;
	cout << "nhap m hang : ";
	cin >> m;
	cout << "nhap n cot : ";
	cin >> n;

	int** mang = new int* [m];
	for (int i = 0; i < m; i++) {
		mang[i] = new int[n];
	}

	cout << "nhap phan tu cho mang " << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n;j++) {
			cin >> mang[i][j];
		}
	}

	cout << "_________________________________________________" << endl;

	int max = findmax(mang, m, n);
	if (max != -1) {
		cout << "so nguyen to lon nhat trong mang la " << max << endl;
	}
	else {
		cout << "mang khong co so nguyen to nao " << endl;
	}

	cout << "_________________________________________________" << endl;

	cout << "cac dong co chua so nguyen to " << endl;
	timdongcosonguyento(mang, m, n);

	cout << "_________________________________________________" << endl;


	cout << "dong chi chua toan so nguyen to la " << endl;
	timdongdeulasonguyento(mang, m, n);


	for (int i = 0; i < m;i++) {
		delete[] mang[i];
	}
	delete[] mang;

	return 0;
}