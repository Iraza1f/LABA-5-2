#include <fstream> 
#include <iostream> 
#include <map>
#include <algorithm>  
#include <string>
using namespace std;
bool F (const pair<int, char> &x) { return x.first > 5; };
int main()

{
	ofstream f;
	f.open("live.txt");
	map<int, char> map1;
	map<int, char> map2;
	map<int, char> map3;
	int p1 = 0;
	char p2;
	int score = 0;
	int variant = 0;
	int s = 0;
	setlocale(LC_ALL, "Russian");
	while (s == 0)
	{
		cout << "������� \n 1. ����� ������ �������� � ������ map \n 2. 2-3 \n 3. 4-8 \n 4. 9-10 \n 5. 11-12 \n 9. ����� \n" << endl;
		cin >> variant;
		switch (variant)
		{
		case 1:
			system("cls");
			cout << "������� �����" << endl;
			cin >> p1;
			cout << "������� ������" << endl;
			cin >> p2;
			map1.insert(pair<int, char>(p1,p2));
			break;

		case 2:
			system("cls");
			cout << "������ ���������" << endl;
			for (auto it = map1.rbegin(); it != map1.rend(); ++it)
			{
				cout << it->first << " : " << it->second << endl;
			}
			break;

		case 3:
			system("cls");
			copy_if(map1.begin(), map1.end(), map2.begin(), F);
			cout << "������ ��������� " << endl;
			for (auto it = map1.begin(); it != map1.end(); ++it)
			{
				cout << it->first << " : " << it->second << endl;
			}
			cout << "������ ��������� " << endl;
			for (auto it = map2.begin(); it != map2.end(); ++it)
			{
				cout << it->first << " : " << it->second << endl;
			}
			break;

		case 4:
			system("cls");
			merge(map1.begin(), map1.end(), map2.begin(), map2.end(),map3.begin());
			for (auto it = map3.begin(); it != map3.end(); ++it)
			{
				cout << it->first << " : " << it->second << endl;
			}
			break;

		case 5:
			system("cls");
			score = count_if(map3.begin(), map3.end(), F);
			if (score != 0)
			{
				cout << "������������ " << score << " ��������� ����������" << endl;
				f << "������������ " << score << " ��������� ����������" << endl;
			}
			else
			{
				cout << "� ���������� ��� �������������� ���������" << endl;
				f << "� ���������� ��� �������������� ���������" << endl;
			}
			break;

		case 9:
			system("cls");
			s = 1;

		default:
			cout << "������" << endl;
			break;
		}
	}
	f.close();
	cout << "��������� ���������. ��������� ��������" << endl;
}