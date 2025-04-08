// Cài đặt các thuật toán sắp xếp được cho trong đề bài
// Sử dụng dãy số {39, 8, 5, 1, 3, 6, 9, 12, 4, 7, 10} để kiểm tra các thuật toán sắp xếp
// Các thuật toán sắp xếp sẽ mặc định sắp xếp dãy số theo thứ tự tăng dần
#include <bits/stdc++.h>
using namespace std;

//Hàm gọi ra thuật toán Sắp Xếp đổi chỗ trực tiếp
void InterchangeSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
    cout << "Mang sau khi duoc sap xep la: " << endl;
    for (int k = 0; k < n; k++) {
        cout << arr[k] << " "; 
    }
    cout << endl;
}

//Hàm gọi ra thuật toán Sắp Xếp chọn trực tiếp
void SelectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }
    cout << "Mang sau khi duoc sap xep la: " << endl;
    for (int k = 0; k < n; k++) {
        cout << arr[k] << " "; 
    }
    cout << endl;
}

//Hàm gọi ra thuật toán Sắp Xếp chèn trực tiếp
void InsertionSort(int arr[], int n){
    for(int i = 0; i < n; i++) {
        int pivot = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > pivot) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = pivot;
    }
    cout << "Mang sau khi duoc sap xep la: " << endl;
    for (int k = 0; k < n; k++) {
        cout << arr[k] << " "; 
    }
    cout << endl;
}

//Hàm gọi ra thuật toán Sắp Xếp nổi bọt
void BubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        bool swapped = false;
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
    }
    cout << "Mang sau khi duoc sap xep la: " << endl;
    for (int k = 0; k < n; k++) {
        cout << arr[k] << " "; 
    }
    cout << endl;
}

int main() {
// Kích thước của mảng ví dụ là 11, hãy nhập giá trị của n = 11
    int n;
    cout << "Nhap vao kich thuoc cua mang: "; cin >> n;

//    39 8 5 1 3 6 9 12 4 7 10
    int arr[n];
    cout << "Nhap vao cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

// Có thể chọn 1 trong 4 thuật toán sắp xếp để kiểm thử thay vì phải tách ra 4 file với 4 hàm int main khác nhau
    cout << "Co 4 thuat toan sap xep: " << endl;
    cout << "1. Sap Xep doi cho truc tiep (Interchange Sort)" << endl;
    cout << "2. Sap Xep chon truc tiep (Selection Sort)" << endl;
    cout << "3. Sap Xep chen truc tiep (Insertion Sort)" << endl;
    cout << "4. Sap Xep noi bot (Bubble Sort)" << endl;
    cout << "Nhap vao so tu 1 toi 4 de chon 1 thuat toan sap xep muon thuc hien!" << endl;
    int number; cin >> number;

// Kiểm tra số vừa nhập vào 
    switch(number) {
        case 1:
            InterchangeSort(arr, n);
            break;
        case 2:
            SelectionSort(arr, n);
            break;
        case 3:
            InsertionSort(arr, n);
            break;
        case 4:
            BubbleSort(arr, n);
            break;
        default:
            cerr << "So khong hop le!" << endl;
            break;
    }

    system("pause");
    return 0;
}