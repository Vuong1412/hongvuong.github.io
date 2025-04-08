// Cài đặt các thuật toán sắp xếp được cho trong đề bài
// Sử dụng dãy số {8, 5, 1, 3, 6, 9, 12, 4, 7, 10} để kiểm tra các thuật toán sắp xếp
// Các thuật toán sắp xếp sẽ mặc định sắp xếp dãy số theo thứ tự tăng dần

#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

// Quick Sort
// tạo hàm chia phân vùng cho hàm Quick Sort
int partition(int arr[], int first, int last) {
    int pivot = arr[last];
    int i = first - 1;

    for (int j = first; j < last; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[last]);
    return i+1;
}
// hàm gọi ra Quick Sort
void QuickSort(int arr[], int first, int last) {
    if (first < last) {
        int p = partition(arr, first, last);
        QuickSort(arr, first, p - 1);
        QuickSort(arr, p + 1, last);
    }
}

// Merge Sort
// tạo hàm gộp phân vùng cho hàm Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for(int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for(int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// hàm gọi ra Merge Sort
void MergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Heap Sort
// tạo hàm xếp chồng cho hàm Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    } 
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
// Hàm gọi ra Heap Sort
void HeapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() 
{
    int arr[]= {8, 5, 1, 3, 6, 9, 12, 4, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout <<"Thuc hien sap xep tren mang: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

// Có thể chọn 1 trong 4 thuật toán sắp xếp để kiểm thử thay vì phải tách ra 4 file với 4 hàm int main khác nhau
    cout << "Co 3 thuat toan sap xep: " << endl;
    cout << "1. Quick Sort" << endl;
    cout << "2. Merge Sort" << endl;
    cout << "3. Heap Sort" << endl;
    cout << "Nhap vao so tu 1 toi 3 de chon 1 thuat toan sap xep muon thuc hien!" << endl;
    int number; cin >> number;

    auto start = high_resolution_clock::now();

// Kiểm tra số vừa nhập vào 
    switch(number) {
        case 1:
            QuickSort(arr, 0, n-1);
            cout << "Mang sau khi duoc sap xep la: " << endl;
            for (int k = 0; k < n; k++) {
                cout << arr[k] << " "; 
            }
            cout << endl;
            break;
        case 2:
            MergeSort(arr, 0, n-1);
            cout << "Mang sau khi duoc sap xep la: " << endl;
            for (int k = 0; k < n; k++) {
                cout << arr[k] << " "; 
            }
            cout << endl;
            break;
        case 3:
            HeapSort(arr, n);
            cout << "Mang sau khi duoc sap xep la: " << endl;
            for (int k = 0; k < n; k++) {
                cout << arr[k] << " "; 
            }
            cout << endl;
            break;
        default:
            cerr << "So khong hop le!" << endl;
            break;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"Thoi gian thuc thi: " << duration.count() << " Micro giay" << endl;

    system("pause");
    return 0;
}