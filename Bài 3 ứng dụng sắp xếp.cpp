
#include<iostream>

void nhapmang(int& m, int& n, int array[100][100]) {
    std::cout << "nhap so hang m : \n";
    std::cin >> m;
    std::cout << "nhap so cot n : \n";
    std::cin >> n;
    std::cout << "nhap so phan tu mang : \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "so phan tu hang " << i + 1 << " va cot " << j + 1 << " la : \n";
            std::cin >> array[i][j];
        }
    }
}
void xuatmang(int m, int n, int array[100][100]) {
    std::cout << "mang vua nhap \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void timDongCoTongLonNhat(int m, int n, int array[100][100]) {
    int maxSum = 0, maxRow = 0;

    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += array[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxRow = i;
        }
    }

    std::cout << "Dòng có tổng lớn nhất là dòng: " << maxRow + 1 << " với tổng là: " << maxSum << std::endl;
}
void sapXepDongTheoTongGiamDan(int m, int n, int array[100][100]) {
    int rowSums[100]; // Mảng lưu tổng các dòng

    // Tính tổng từng dòng
    for (int i = 0; i < m; i++) {
        rowSums[i] = 0;
        for (int j = 0; j < n; j++) {
            rowSums[i] += array[i][j];
        }
    }

    // Sắp xếp các dòng theo tổng giảm dần
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (rowSums[i] < rowSums[j]) {
                // Hoán đổi tổng
                std::swap(rowSums[i], rowSums[j]);

                // Hoán đổi toàn bộ dòng
                for (int k = 0; k < n; k++) {
                    std::swap(array[i][k], array[j][k]);
                }
            }
        }
    }

    std::cout << "Ma trận sau khi sắp xếp dòng theo tổng giảm dần:" << std::endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


int main() {
    int m, n;
    int array[100][100];
    nhapmang(m, n, array);
    xuatmang(m, n, array);
    std::cout << "\n";
    timDongCoTongLonNhat(m, n, array);
    std:: cout << "\n";
    sapXepDongTheoTongGiamDan(m, n, array);
}