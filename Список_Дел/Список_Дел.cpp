#include <iostream>
#include <list>
#include <iterator>
#include <string.h>
#include <windows.h>
#include <string>

using namespace std;

enum Chooce_Watch
{
	Watch_Prioritet = 1,
	Watch_Date,
	Watch_All,
	Watch_Exit
};

enum Chooce_Found
{
	Found_Name = 1,
	Found_Prioritet,
	Found_Opisanie,
	Found_Date,
	EXIT_Found
};

enum Chooce
{
	CREATE = 1,
	DELET,
	REDACT,
	FOUND,
	ALL_WATCH,
	EXIT
};

struct Delo
{
	string name_delo;
	double prioritet;
	string opisanie;
	int day;
	int month;
	int year;
	int hour;
	int minutes;
	int seconds;
};

void ADD(list <Delo>* dela, Delo* delo)
{
	cout << "Введите название дела: ";
	getline(cin, delo->name_delo);
	cout << "Укажите приоритет дела, где 1 самое важное дело: ";
	(cin >> delo->prioritet).get();
	cout << "Введите описание дела: ";
	getline(cin, delo->opisanie);
	cout << "Введите дедлайн: \nДень - ";
	cin >> delo->day;
	cout << "Месяц - ";
	cin >> delo->month;
	cout << "Год(XX.XX.XX) - ";
	cin >> delo->year;
	cout << "Час - ";
	cin >> delo->hour;
	cout << "Минуты - ";
	cin >> delo->minutes;
	cout << "Секунды - ";
	(cin >> delo->seconds).get();
	system("cls");
	dela->push_back(*delo);
}

void DELETT(list <Delo>* dela, Delo* delo, int nomer_delete_delo)
{
	list <Delo> ::iterator it;
	int i = 1;
	for (it = dela->begin(); it != dela->end(); i++)
	{
		if (i == nomer_delete_delo)
		{
			it = dela->erase(it);
		}
		else it++;
	}
}

void Redact_Delo(list <Delo>* dela, Delo* delo, int nomer_delete_redact)
{
	list <Delo> ::iterator it;
	int i = 1;
	for (it = dela->begin(); it != dela->end(); it++, i++)
	{
		if (i == nomer_delete_redact)
		{
			cin.get();
			cout << "Введите название дела: ";
			getline(cin, it->name_delo);
			cout << "Укажите приоритет дела, где 1 самое важное дело: ";
			(cin >> it->prioritet).get();
			cout << "Введите описание дела: ";
			getline(cin, it->opisanie);
			cout << "Введите дедлайн: \nДень - ";
			cin >> it->day;
			cout << "Месяц - ";
			cin >> it->month;
			cout << "Год(XX.XX.XX) - ";
			cin >> it->year;
			cout << "Час - ";
			cin >> it->hour;
			cout << "Минуты - ";
			cin >> it->minutes;
			cout << "Секунды - ";
			(cin >> it->seconds).get();
			system("cls");
		}
	}
}

void Found_Name_Delo(list <Delo>* dela, Delo* delo, string found_name_delo)
{
	list <Delo>::iterator it;
	cout << "Дела с названием " << found_name_delo << " найдены: \n\n";
	for (it = dela->begin(); it != dela->end(); it++)
	{
		if (it->name_delo == found_name_delo)
		{
			cout << "Название Дела: " << it->name_delo << "\n";
			cout << "Приоритет: " << it->prioritet << "\n";
			cout << "Описание Дела: " << it->opisanie << "\n";
			cout << "Дата выполнения Дела: " << it->day << "." << it->month << "." << it->year << "\n";
			cout << "Время, до которого нужно успеть выполнить Дело: " << it->hour << ":" << it->minutes << ":" << it->seconds << "\n";
			cout << "\n";
		}
	}
}

void Found_Prioritet_Delo(list <Delo>* dela, Delo* delo, int found_prioritet_delo)
{
	list <Delo>::iterator it;
	cout << "Дела с приоритетом " << found_prioritet_delo << " найдены:\n\n";
	for (it = dela->begin(); it != dela->end(); it++)
	{
		if (it->prioritet == found_prioritet_delo)
		{
			cout << "Название Дела: " << it->name_delo << "\n";
			cout << "Приоритет: " << it->prioritet << "\n";
			cout << "Описание Дела: " << it->opisanie << "\n";
			cout << "Дата выполнения Дела: " << it->day << "." << it->month << "." << it->year << "\n";
			cout << "Время, до которого нужно успеть выполнить Дело: " << it->hour << ":" << it->minutes << ":" << it->seconds << "\n";
			cout << "\n";
		}
	}
}

void Found_Opisanie_Delo(list <Delo>* dela, Delo* delo, string found_opisanie_delo)
{
	list <Delo>::iterator it;
	cout << "Дела с введённым описанием - " << found_opisanie_delo << " найдены: \n\n";
	for (it = dela->begin(); it != dela->end(); it++)
	{
		if (it->opisanie == found_opisanie_delo)
		{
			cout << "Название Дела: " << it->name_delo << "\n";
			cout << "Приоритет: " << it->prioritet << "\n";
			cout << "Описание Дела: " << it->opisanie << "\n";
			cout << "Дата выполнения Дела: " << it->day << "." << it->month << "." << it->year << "\n";
			cout << "Время, до которого нужно успеть выполнить Дело: " << it->hour << ":" << it->minutes << ":" << it->seconds << "\n";
			cout << "\n";
		}
	}
}

void Found_Date_Delo(list <Delo>* dela, Delo* delo, int day, int month,int year,int hour,int minutes,int seconds)
{
	list <Delo>::iterator it;
	cout << "Дела с датой: " << day<<'.'<<month<<'.'<<year << "\n И временем: "<<hour<<':'<<minutes<<':'<<seconds<<"\n найдены: \n\n";
	for (it = dela->begin(); it != dela->end(); it++)
	{
		if (it->day == day
			and it->month == month
			and it->year == year
			and it->hour == hour
			and it->minutes == minutes
			and it->seconds == seconds)
		{
			cout << "Название Дела: " << it->name_delo << "\n";
			cout << "Приоритет: " << it->prioritet << "\n";
			cout << "Описание Дела: " << it->opisanie << "\n";
			cout << "Дата выполнения Дела: " << it->day << "." << it->month << "." << it->year << "\n";
			cout << "Время, до которого нужно успеть выполнить Дело: " << it->hour << ":" << it->minutes << ":" << it->seconds << "\n";
			cout << "\n";
		}
	}
}

void Watch_Prioritet_Delo(list <Delo>* dela, Delo* delo)
{
	list<Delo>::iterator it;
		int i = 1;
		for (it = dela->begin(); it != dela->end(); it++)
		{
			for (it = dela->begin(); it != dela->end();it++)
			{
				if (it->prioritet == i)
				{
					cout << "Название Дела: " << it->name_delo << "\n";
					cout << "Приоритет: " << it->prioritet << "\n";
					cout << "Описание Дела: " << it->opisanie << "\n";
					cout << "Дата выполнения Дела: " << it->day << "." << it->month << "." << it->year << "\n";
					cout << "Время, до которого нужно успеть выполнить Дело: " << it->hour << ":" << it->minutes << ":" << it->seconds << "\n";
					cout << "\n";
				}
			}
			if (i < 11)
				i++;
			else i = 10;
		}
}

void Watch_Date_Delo(list <Delo>* dela, Delo* delo, int menu_sort_date)
{
	list<Delo>::iterator it;
	if (menu_sort_date == 1)
	{
		int i = 1, j = 1, k = 0;
		for (it = dela->begin(); it != dela->end(); it++)
		{
			while (i <= 31 or j <= 12 or k <= 99)
			{
				for (it = dela->begin(); it != dela->end(); it++)
				{
					if (it->day == i
						and it->month == j
						and it->year == k)
					{
						cout << "Название Дела: " << it->name_delo << "\n";
						cout << "Приоритет: " << it->prioritet << "\n";
						cout << "Описание Дела: " << it->opisanie << "\n";
						cout << "Дата выполнения Дела: " << it->day << "." << it->month << "." << it->year << "\n";
						cout << "Время, до которого нужно успеть выполнить Дело: " << it->hour << ":" << it->minutes << ":" << it->seconds << "\n";
						cout << "\n";
					}
				}
				if (i <= 31)
					i++;
				if (j <= 12)
					j++;
				if (k <= 99)
					k++;
			}
		}
	}
}

int main()
{
	setlocale(NULL, "RUSSIAN");
	Delo* delo = new Delo[1];
	list <Delo> dela;
	list <Delo> ::iterator it;
	int chooce, chooce_found;
	do
	{
		cout << "\t\t\t\t\t__Меню__\n";
		cout << "\t\t\t\t[1] Добавление дел\n";
		cout << "\t\t\t\t[2] Удаление дел\n";
		cout << "\t\t\t\t[3] Редактирование дел\n";
		cout << "\t\t\t\t[4] Поиск дел по\n";
		cout << "\t\t\t\t[5] Отображение списка дел\n";
		cout << "\t\t\t\t[6] Выход из списка дел\n";
		(cin >> chooce).get();
		system("cls");
		switch (chooce)
		{
		case CREATE: //1
		{
			ADD(&dela, delo);
			break;
		}
		case ALL_WATCH: //5
		{
			int chooce_watch;
			system("cls");
			cout << "\t\t\t\t\t__Меню__\n";
			cout << "\t\t\t\t[1] Отсортировать по приоритету\n";
			cout << "\t\t\t\t[2] Отсортировать по дате и времени\n";
			cout << "\t\t\t\t[3] Вывести весь текущий список\n";
			cout << "\t\t\t\t[4] Вернуться в начальное меню\n";
			cin >> chooce_watch;
			switch (chooce_watch)
			{
			case Watch_Prioritet:
			{
				Watch_Prioritet_Delo(&dela, delo);
				break;
			}
			case Watch_Date:
			{
			}
			}
		}
		case DELET: //2
		{
			int nomer_delete_delo;
			cout << "Введите номер дела, которое хотите удалить - ";
			cin >> nomer_delete_delo;
			DELETT(&dela, delo, nomer_delete_delo);
			break;
		}
		case REDACT: //3
		{
			int nomer_delete_redact;
			cout << "Введите номер дела, которое хотите изменить - ";
			cin >> nomer_delete_redact;
			Redact_Delo(&dela, delo, nomer_delete_redact);
			break;
		}
		case FOUND: //4
		{
			system("cls");
			cout << "\t\t\t\t\t__Меню__\n";
			cout << "\t\t\t\t[1] Названию\n";
			cout << "\t\t\t\t[2] Приоритету\n";
			cout << "\t\t\t\t[3] Описанию\n";
			cout << "\t\t\t\t[4] Дате и времени исполнения\n";
			cout << "\t\t\t\t[5] Выход из поиска\n";
			cin >> chooce_found;
			switch (chooce_found)
			{
			case Found_Name:
			{
				string found_name_delo;
				cout << "Введите название дела, которое хотите найти: ";
				cin >> found_name_delo;
				Found_Name_Delo(&dela, delo, found_name_delo);
				break;
			}
			case Found_Prioritet:
			{
				int found_prioritet_delo;
				cout << "Введите приоритет дела, которое хотите найти, где 1 самый важный: ";
				cin >> found_prioritet_delo;
				Found_Prioritet_Delo(&dela, delo, found_prioritet_delo);
				break;
			}
			case Found_Opisanie:
			{
				string found_opisanie_delo;
				cout << "Введите описание дела, которое хотите найти: ";
				cin >> found_opisanie_delo;
				Found_Opisanie_Delo(&dela, delo, found_opisanie_delo);
				break;
			}
			case Found_Date:
			{
				int day, month, year, hour, minutes, seconds;
				cout << "Введите дату и время дела, которое хотите найти: \nДень - ";
				cin >> day;
				cout << "Месяц - ";
				cin >> month;
				cout << "Год(XX.XX.XX) - ";
				cin >> year;
				cout << "Часы - ";
				cin >> hour;
				cout << "Минуты - ";
				cin >> minutes;
				cout << "Секунды - ";
				cin >> seconds;
				Found_Date_Delo(&dela, delo, day, month, year, hour, minutes, seconds);
				break;
			}
			case EXIT_Found:
			{
				system("cls");
				break;
			}
			}
		}
		}
	} while (chooce != 6);
}