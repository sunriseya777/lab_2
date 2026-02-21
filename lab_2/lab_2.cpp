// lab_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <clocale>
using namespace std;
// Функция для изменения двух значений:
// первый аргумент - по ссылке
// второй аргумент - по указателю

void fun(int& arg1, int* arg2){
	arg1 = arg1 * 2;
	*arg2 = (*arg2) + 1;

}
void stat_ind() {
	cout << "Статический массив, индексная адресация. ";
	const int SIZE = 10;
	int mass[SIZE];
	for (int i = 0; i < SIZE; i++) {
		mass[i] = i * i;
	}
	cout << "Элементы массива: ";
	for (int i = 0; i < SIZE; i++) {
		cout << mass[i] << " ";
	}
	cout << endl;
}
void stat_ykaz() {
	cout << "Статический массив, адресация с помощью указателя. ";
	const int SIZE = 10;
	int mass[SIZE];
	int* ykaz = mass;
	for (int i = 0; i < SIZE; i++) {
		*(ykaz + i) = i * i;
	}
	cout << "Элементы массива: ";
	for (int i = 0; i < SIZE; i++) {
		cout << *(ykaz + i) << " ";
	}
	cout << endl;
}
void dinam_ind() {
	cout << "Динамический массив, индексная адресация. ";
	const int SIZE = 10;
	int* mass = new int[SIZE];
	for (int i = 0; i < SIZE; i++) {
		mass[i] = i * i;
	}
	cout << "Элементы массива: ";
	for (int i= 0; i < SIZE; i++) {
		cout << mass[i] << " ";
	}
	cout << endl;
}
void dinam_ykaz() {
	cout << "Динамический массив, адресация с помощью указателя. ";
	const int SIZE = 10;
	int* mass = new int[SIZE];
	int* ykaz = mass;
	for (int i = 0; i < SIZE; i++) {
		*(ykaz + i) = i * i;
	}
	cout << "Элементы массива: ";
	for (int i = 0; i < SIZE; i++) {
		cout << *(ykaz + i) << " ";
	}
	cout << endl;

}
int* merge_mass(int arr1[], int size1, int arr2[], int size2) {
	int size3 = size1 + size2;
	int* result = new int[size3];

	int i = 0;          // индекс для первого массива (индексная адресация)
	int* ptr2 = arr2;   // указатель на начало второго массива
	int j = 0;          // смещение для второго массива
	int k = 0;          // индекс для конечного массива

	while (i < size1 && j < size2) {
		// Сравниваем элементы:
		if (arr1[i] < *(ptr2 + j)) {
			result[k] = arr1[i];
			i++;
		}
		else {
			result[k] = *(ptr2 + j);
			j++;
		}
		k++;
	}
	//копируем из 1 массива
	while (i < size1) {
		result[k] = arr1[i];
		i++;
		k++;
	}

	//копируем из 2 массива
	while (j < size2) {
		result[k] = *(ptr2 + j);
		j++;
		k++;
	}

	return result;
}

void printArray(int arr[], int size, const char* name) {
	cout << name << ": ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
struct Node {
	int data;
	Node* pred;
	Node* next;
	Node(int value) : data(value), pred(nullptr), next(nullptr); {}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Упражднение 2" << endl;
	int a = 5;
	int b = 10;
	cout << "До изменений:" << endl;
	cout << "a = " << a << ",b = " << b << endl;
	fun(a,&b);
	cout << "После изменений:" << endl;
	cout << "a = " << a << ",b = " << b << endl;
	cout << endl;

	cout << "Упражднение 3_1" << endl;
	stat_ind();
	stat_ykaz();
	dinam_ind();
	dinam_ykaz();
	const int size1 = 4;
	const int size2 = 5;
 
	int* arr1 = new int[size1] {1, 3, 5, 7};       
	int* arr2 = new int[size2] {2, 4, 6, 8, 10};   

	cout << "Исходные упорядоченные массивы:" << endl;
	printArray(arr1, size1, "массив 1");
	printArray(arr2, size2, "массив 2");

	int* arr3 = merge_mass(arr1, size1, arr2, size2);
	int size3 = size1 + size2;

	cout << "Результат после слияния:" << endl;
	printArray(arr3, size3, "массив 3 ");

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	//4 упражнение
	Node* head = nullptr;
	Node* tail = nullptr;
	//создадим 10 узлов и свяжем их
	for (int i = 1; i <= 10; i++) {
		Node* newNode = new Node(i);
		if (head == nullptr) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			newNode->pred = tail;
			tail = newNode;
		}
	}
	cout << "Прямой порядок: ";
	for (Node* cur = head; cur != nullptr; cur = cur->next) {
		cout << cur->data << " ";

	}
	cout << endl;
	cout << "Обратный порядок";
	for (Node* cur = tail; cur != nullptr; cur = cur->pred) {
		cout << cur->data << " ";

	}
	cout << endl;
	//освобождение памяти
	Node* cur = head;
	while (cur != nullptr) {
		Node* next = cur->next;
		delete cur;
		cur = next;
	}

	





	return 0;

}
 
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
