#include <fstream> 
#include <iostream> 
#include <map>
#include <algorithm>  
#include <string>
using namespace std;
int main()
{
	ofstream f;
	f.open("live.txt");
	map<int, char> map1;
	map<int, char> map2;
	map<int, char> map3;
	int p1 = 0;
	char p2;
	int variant = 0;
	int x = 0;
	int s = 0;
	setlocale(LC_ALL, "Russian");
	while (s == 0)
	{
		cout << "Нажмите \n 1. чтобы внести элементы в первый map \n 2. 2-3 \n 3. 4-6 \n 4. 7-8 \n 5. 9-10 \n 6. 11 \n 7. 12 \n 8. выход \n 9. для вывода очередей " << endl;
		cin >> variant;
		switch (variant)
		{
		case 1:
			system("cls");
			cout << "Введите число" << endl;
			cin >> p1;
			cout << "Введите символ" << endl;
			cin >> p2;
			map1.insert(pair<int, char>(p1,p2));
			break;

		case 2:
			system("cls");
			cout << "Первый контейнер" << endl;
			for (auto it = map1.rbegin(); it != map1.rend(); ++it)
			{
				cout << it->first << " : " << it->second << endl;
			}
			break;

		case 3:
			system("cls");
			copy_if(map1.begin(), map1.end(), map2.begin(), [](const pair<int, char> &x) { return x.first > 5; });
			cout << "Первый контейнер " << endl;
			for (auto it = map1.begin(); it != map1.end(); ++it)
			{
				cout << it->first << " : " << it->second << endl;
			}
			cout << "Второй контейнер " << endl;
			for (auto it = map2.begin(); it != map2.end(); ++it)
			{
				cout << it->first << " : " << it->second << endl;
			}
			break;

		default:
			cout << "Ошибка" << endl;
			break;
		}
	}
	f.close();
	cout << "Программа завершена. Результат сохранен" << endl;
}