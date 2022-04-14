#include "Header.h"
#include "Orkestr.h"
#include "Outp.h"	
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice,choice1,choice2;
	Outp o;

	while (true) {
		system("cls");
		cout << endl << "\t   Меню     \n" << endl
			<< " 1. Мап" << endl
			<< " 2. Лист" << endl;
		try {

			if (!(std::cin >> choice2) || (std::cin.peek() != '\n'))
				throw exception("неправильно введены данные");
			system("pause");
			switch (choice2) {
			case 1: {

				system("cls");
				cout << endl << "\t   Меню     \n" << endl
					<< " 1.Просмотр " << endl
					<< " 2.Добавить " << endl;
				try {

					if (!(std::cin >> choice1) || (std::cin.peek() != '\n'))
						throw exception("неправильно введены данные");
					system("pause");
					switch (choice1) {
					case 1: {

						o.Viewm();
						break;
					}
					case 2: {
						o.addm();
						break;
					}
					case 0:
						return 0;
						break;
					default:
						cout << "неверно введены данные" << endl;
						system("pause");
						break;
					}

				}

				catch (exception error) {
					cin.clear();
					cin.ignore(32767, '\n');
					cout << error.what() << endl;

				}
				break;
			}
			case 2: {
				system("cls");
				cout << endl << "\t   Меню Оркестра      \n" << endl
					<< " 1.Просмотр книги" << endl
					<< " 2.Добавить книгу" << endl
					<< " 3.Редактировать книгу" << endl
					<< " 4.Удалить книгу" << endl
					<< " 5.Сортировка книги" << endl
					<< " 0.Выход" << endl;
				try {

					if (!(std::cin >> choice) || (std::cin.peek() != '\n'))
						throw exception("неправильно введены данные");
					system("pause");
					switch (choice) {
					case 1: {

						o.View();
						break;
					}
					case 2: {
						o.add();
						break;
					}
					case 3: {
						o.redact();
						break;
					}
					case 4: {
						o.deleteO();
						break;
					}
					case 5: {
						o.sort();
						break;
					}
					case 6: {
						o.Viewm();
						break;
					}
					case 0:
						return 0;
						break;
					default:
						cout << "неверно введены данные" << endl;
						system("pause");
						break;
					}

				}

				catch (exception error) {
					cin.clear();
					cin.ignore(32767, '\n');
					cout << error.what() << endl;

				}

				break;
			}
			case 0:
				return 0;
				break;
			default:
				cout << "неверно введены данные" << endl;
				system("pause");
				break;
			}

		}

		catch (exception error) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << error.what() << endl;

		}
		
		
	}
	return 0;
}