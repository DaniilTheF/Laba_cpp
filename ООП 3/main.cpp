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
		cout << endl << "\t   ����     \n" << endl
			<< " 1. ���" << endl
			<< " 2. ����" << endl;
		try {

			if (!(std::cin >> choice2) || (std::cin.peek() != '\n'))
				throw exception("����������� ������� ������");
			system("pause");
			switch (choice2) {
			case 1: {

				system("cls");
				cout << endl << "\t   ����     \n" << endl
					<< " 1.�������� " << endl
					<< " 2.�������� " << endl;
				try {

					if (!(std::cin >> choice1) || (std::cin.peek() != '\n'))
						throw exception("����������� ������� ������");
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
						cout << "������� ������� ������" << endl;
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
				cout << endl << "\t   ���� ��������      \n" << endl
					<< " 1.�������� �����" << endl
					<< " 2.�������� �����" << endl
					<< " 3.������������� �����" << endl
					<< " 4.������� �����" << endl
					<< " 5.���������� �����" << endl
					<< " 0.�����" << endl;
				try {

					if (!(std::cin >> choice) || (std::cin.peek() != '\n'))
						throw exception("����������� ������� ������");
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
						cout << "������� ������� ������" << endl;
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
				cout << "������� ������� ������" << endl;
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