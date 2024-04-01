#include <iostream>;
#include <ctime>
#include <cstdlib>

int NUM; //Принято выделять большими буквами, что она глобальная.
const double PI = 3.1416; //глобальная константа.
int ARR[3]; //глобальный массив.
//Со статической переменной:
void func() {
	static int a = 0; //делает переменную статической.
	a++;
	std::cout << a << std::endl;
}
int power(int left, int right = 2) { //значение по умолчанию = 2.
	int result = 1;
	for (int i = 1; i <= right; i++)
		result *= left;
	return result;
}
//Встраеваемая функция:
inline int sum(int num1, int num2) { //inline видимых изменений нет;
	return (num1 + num2); //обязательно круглые скобри;
}
//перегруженные функции:
int max(int num1, int num2) {
	std::cout << "TWO INTS\n";
	return num1 > num2 ? num1 : num2;// Перегруженная функция;
}
double max(double num1, double num2) {
	std::cout << "TWO DOUBLE\n";
	return num1 > num2 ? num1 : num2; // Перегруженная функция;
}
char max(char sym1, char sym2) {
	std::cout << "TWO CHARS\n";
	return sym1 > sym2 ? sym1 : sym2; //Перешруженная функция;
}
int max(int num1, int num2, int num3) {
	std::cout << "THREE INTS\n";
	return max(max(num1, num2), num3); //Перегруженная функция 
 }
//Шаблонная фугкция:
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}



int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	//Области видимости данных
	NUM = 7;
	std::cout << "NUM = " << NUM << std::endl;
	std::cout << "PI = " << PI << std::endl;

	func();
	func();
	func();

	//Параметры по умолчанию
	std::cout << "7^2 = " << power(7) << std::endl;
	std::cout << "4^3 = " << power(4, 3) << std::endl;
	std::cout << "5^2 = " << power(5) << std::endl;
	std::cout << "10^5 = " << power(10, 5) << std::endl;

	//Встраиваемая функция 
	std::cout << "Введите два числа -> ";
	std::cin >> n >> m;
	std::cout << n << " + " << m << " = " << sum(n, m) << std::endl;

	//Перегруженные функции
	std::cout << max(7, 15) << std::endl; //15
	std::cout << max(5.4, 5.04) << std::endl; //5.4
	std::cout << max('k', '0') << std::endl; //k
	std::cout << max(7, 42, 15) << std::endl;//42

	//Шаблонная функция
	const int size = 5;
	int arr[size]{ 7, 15, 42, 105, -77 };

	std::cout << "Массив:\n";
	print_arr(arr, size);

	return 0;
}