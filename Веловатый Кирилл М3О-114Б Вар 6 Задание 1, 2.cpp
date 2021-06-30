/* Веловатый Кирилл М3О-114Б-20
Вариант 6*/
#include <iostream>
using namespace std;
//Задание 1
void lShiftMas(int* source, int n, const int size) {
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < size; i++) {
			if (size == i + 1) {
				break;
			}
			source[i] = source[i + 1];
		}
		source[size - 1] = 0;
	}
}
bool CompareMas(int* a, int* b, int size)
{
    for (int i = 0; i < size; i++)
        if (a[i] != b[i]) return false;

    return true;
}
//Задание 2
bool test(int n, int size){
	int mass1[5] = {1, 2, 3, 4, 5};
	int mass2[5] = {3, 4, 5, 0, 0};
	lShiftMas(mass1, 2, 5);
	bool f1 = CompareMas(mass1, mass2, 5);
	return(f1);
}

void runTest(int (*test)(),const std::string& testName)
{
  if(test()==1)
    cout << "Test "<< testName << " - OK" << std::endl;
  else 
    cout << "Test "<< testName << " - FAIL" << std::endl;
}

int main()
{
	const int size = 5;
	int s, k;
	cout<<"Введите размер массива"<<endl;
	cin >> s;
	cout<<"Введите элементы массива"<<endl;
	int mass[s];
	for (int i = 0; i < s; i++)
	{
		cin >> mass[i];
	}
	cout <<"Введите количество сдвигов"<<endl;
	cin >> k;
	test(k, s);
	lShiftMas(mass, k, s);
	for (int i = 0; i < size; i++)
	{
		cout << mass[i];
	}
	return 0;
	
}