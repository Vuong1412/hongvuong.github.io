#include<iostream>
using namespace std;

//Sap xep noi bot (bubbleSort)
void BubbleSort(int *arr, int n) {
	for (int i = 0; i < n - 1;i++) {
		for (int j = 0; j < n - i - 1;j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
int main() {
	int n;
	cout << "nhap so phan tu mang : ";
	cin >> n;
	int* arr = new int[n];
	cout << "nhap phan tu cua mang"<<endl;
	for (int i = 0; i < n; i++) {
		cin>> arr[i];
	}
	BubbleSort(arr, n);
	cout << "mang sau khi sap xep: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i]<<" ";
	}
	cout << endl;
	delete[] arr;
	return 0;
}