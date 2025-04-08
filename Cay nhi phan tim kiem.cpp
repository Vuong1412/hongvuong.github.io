// cây nhị phân tìm kiếm 
#include<iostream>
using namespace std;
// bài số 98 - Validate Binary Search Tree trên LeetCode:
struct node {
	int p;
	node* Pleft;
	node* pRight;
	//Constructor khởi tạo một nút mới
	node(int value) {
		p = value;
		Pleft = pRight = nullptr;
	}
};
//in order traversal
void inordertraversal(node* root) {
	if (root != nullptr) {
		inordertraversal(root -> Pleft);  // Duyệt cây con trái
		cout << root->p << " ";      // In giá trị của nút
		inordertraversal(root->pRight); // Duyệt cây con phải
	}
}
bool isvalidBST(node* root, long long minval, long long maxval) {
	if (root == nullptr)
		return true;
	if (root->p <= minval || root->p >= maxval)
		return false;
	return isvalidBST(root->Pleft, minval, maxval) && isvalidBST(root->pRight, root->Pleft, maxval);
}




//#include <iostream>
//using namespace std;
//
//// Định nghĩa một nút trong cây BST
//struct Node {
//    int data;        // Giá trị của nút
//    Node* left;      // Con trỏ đến nút con trái
//    Node* right;     // Con trỏ đến nút con phải
//
//    // Constructor khởi tạo một nút mới
//    Node(int value) {
//        data = value;
//        left = right = nullptr;
//    }
//};
//// Hàm chèn một giá trị vào cây BST
//Node* insert(Node* root, int value) {
//    if (root == nullptr) {
//        return new Node(value); // Nếu cây rỗng, tạo nút mới
//    }
//    if (value < root->data) {
//        root->left = insert(root->left, value); // Chèn vào cây con bên trái
//    }
//    else {
//        root->right = insert(root->right, value); // Chèn vào cây con bên phải
//    }
//    return root;
//}
//// Hàm tìm kiếm một giá trị trong BST
//bool search(Node* root, int key) {
//    if (root == nullptr) {
//        return false; // Không tìm thấy
//    }
//    if (root->data == key) {
//        return true; // Tìm thấy giá trị
//    }
//    if (key < root->data) {
//        return search(root->left, key); // Tìm bên trái
//    }
//    return search(root->right, key); // Tìm bên phải
//}
//// Duyệt cây theo thứ tự trung tố (Inorder - LNR)
//void inorderTraversal(Node* root) {
//    if (root != nullptr) {
//        inorderTraversal(root->left);  // Duyệt cây con trái
//        cout << root->data << " ";      // In giá trị của nút
//        inorderTraversal(root->right); // Duyệt cây con phải
//    }
//}
//// Duyệt cây theo thứ tự tiền tố (Preorder - NLR)
//void preorderTraversal(Node* root) {
//    if (root != nullptr) {
//        cout << root->data << " ";       // In giá trị của nút
//        preorderTraversal(root->left);  // Duyệt cây con trái
//        preorderTraversal(root->right); // Duyệt cây con phải
//    }
//}
//// Duyệt cây theo thứ tự hậu tố (Postorder - LRN)
//void postorderTraversal(Node* root) {
//    if (root != nullptr) {
//        postorderTraversal(root->left);  // Duyệt cây con trái
//        postorderTraversal(root->right); // Duyệt cây con phải
//        cout << root->data << " ";        // In giá trị của nút
//    }
//}
//// Hàm main để chạy chương trình
//int main() {
//    Node* root = nullptr;
//    // Thêm các phần tử vào BST
//    root = insert(root, 50);
//    insert(root, 30);
//    insert(root, 70);
//    insert(root, 20);
//    insert(root, 40);
//    insert(root, 60);
//    insert(root, 80);
//    insert(root, 100);
//    cout << "Duyệt cây theo thứ tự trung tố (Inorder):";
//    inorderTraversal(root);
//    cout << endl;
//    cout << "Duyệt cây theo thứ tự tiền tố (Preorder): ";
//    preorderTraversal(root);
//    cout << endl;
//    cout << "Duyệt cây theo thứ tự hậu tố (Postorder): ";
//    postorderTraversal(root);
//    cout << endl;
//    // Kiểm tra tìm kiếm
//    int key = 40;
//    if (search(root, key)) {
//        cout << key << " có trong cây BST.\n";
//    }
//    else {
//        cout << key << " không có trong cây BST.\n";
//    }
//    return 0;
//}
