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
