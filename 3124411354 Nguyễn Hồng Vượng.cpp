#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool isprime(int n) {
	if (n < 2)
		return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
void swap(int* a, int* b) {
	int temp=*a;
	*a = *b;
	*b = temp;

}
int sapxepmang(int n, int* arr) {

}

int main() {
	fstream FILEINPUT;
	FILEINPUT.open("C:\\Users\\mr\\OneDrive\\Desktop\\code\\De03.INP");
	if (!FILEINPUT) {
		cout << "khong tim duoc file";
		return 1;
	}
	int N;
	FILEINPUT >> N;
	int *arr;
	arr = new int[N];
	for (int i = 0; i < N; i++) {
		FILEINPUT >> arr[i];
	}

	string s, x;
	FILEINPUT.ignore();
	getline(FILEINPUT, s);
	getline(FILEINPUT, x);
	FILEINPUT.close();

	cout << "gia tri cua N la :" << N << endl;
	cout << " gia tri cua mang la : " <<  endl;
	for (int i = 0; i < N; i++) {
		cout << arr[i]<<" ";
	}
	cout << "\n";
	cout << "chuoi s " << s<<endl;
	cout << " chuoi x " << x << endl;
	cout << "mang sau khi duoc sap xep la : " << sapxepmang(arr,n) << endl;
	delete[] arr;
	return 0;
}