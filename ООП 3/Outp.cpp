#include "Outp.h"
const char* OrkestrFile = "Matbe.txt";
const char* GournalFile = "GG";
ostream& xo(ostream& stream) {
	stream.setf(ios::right);
	stream << setw(5) << '|';
	return stream;
}
map<int, Gournal> Outp::readKrkestr() {
	Gournal read_G;
	map<int, Gournal> redact;
	int i = 1;
	ifstream in(GournalFile);
	while (!in.fail()) {
		if (in.is_open()) {
			while (!in.eof()) {
				in >> read_G;
				if (!in.eof()) {
					redact.insert(pair<int, Gournal>(i,read_G));
					i++;
				}
			}
		}
	}
	in.close();
	return redact;
}
list<Orkestr> Outp::readOrkestr() {
	Orkestr read_redact;
	list<Orkestr> redact;
	ifstream in(OrkestrFile);
	while (!in.fail()) {
		if (in.is_open()) {
			while (!in.eof()) {	
				in >> read_redact;
				if (!in.eof()) {
					redact.push_back(read_redact);
				}
			}
		}
	}
	in.close();
	return redact;
}
void Outp::View() {
	list<Orkestr> redact;
	redact = readOrkestr();
	list<Orkestr>::iterator l;
	l = redact.begin();
	system("cls");
	while (l != redact.end())
	{
		std::cout << "\t" << *l;
		++l;
	}
	if (redact.empty()) {
		std::cout << endl << "Записей не существует\n" << endl;
	}
	system("pause");
}
void Outp::add() {
	Orkestr redact;
	system("cls");
	redact.create();
	ofstream out(OrkestrFile, ios::app);
	if (out.good()) {
			out <<setw(15)<< redact;
			system("cls");
			std::cout
				<< setw(35) << redact.getBaraban()
				<< "|" << setw(21) << redact.getPionist()
				<< "|" << setw(15) << redact.getDerigor()
				<< " |" << setw(14) << redact.getSkripach()
				<< "| " << setw(10) << redact.getNumber()
				<< " |" << setw(6) << redact.getKonz()
				<< " |" << std::endl;
	}
	out.close();
	system("pause");
	return;
}
void Outp::redact() {
	int choiceRedact = 0, p = 1;
	list<Orkestr> redact;
	redact = readOrkestr();
	list<Orkestr>::iterator l;
	l = redact.begin();
	system("cls");
	if (redact.empty()) {
		cout << endl << "Записей не существует\n" << endl;
		system("pause");
		return;
	}
	while (l != redact.end())
	{
		cout << "\t"<< *l;
		++l;
	}
	cout << "Введите номер записи: ";
	while (!(std::cin >> choiceRedact) || (std::cin.peek() != '\n')) {
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Неправильно введены данные.\n Повторите ввод: ";
	}
	if (choiceRedact > redact.size() || choiceRedact <= 0) {
		cout << endl << "Запись под таким номером отсутствует";
		return;
	}
	system("cls");
	l = redact.begin();
	while (l != redact.end() && p != choiceRedact)
	{
		++l; p++;
	}
	l->create();
	ofstream out(OrkestrFile);
	l = redact.begin();
	while (l != redact.end()) {
		if (out.good()) {
			out << l->getBaraban() << "\t";
			out << l->getPionist() << "\t";
			out << l->getDerigor() << "\t";
			out << l->getSkripach() << "\t";
			out << l->getNumber() << "\t";
			out << l->getKonz() << "\t";
			system("cls");
		}
		l++;
	}
	out.close();
	system("pause");
}
void Outp::deleteO(){
	int choice, p = 1, gg;
	list<Orkestr> redact;
	list<Orkestr>::iterator l;
	ofstream out;
	system("cls");
	cout << endl << "Выберите действие :"
		<< endl << "1.удалить одну запись"
		<< endl << "2.удалить все записи" << endl;
	while (!(std::cin >> choice) || (std::cin.peek() != '\n') || choice < 1 || choice > 2) {
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Неправильно введены данные.\n Повторите ввод: ";
	}
	switch (choice) {
	case 1:
		system("cls");
		redact = readOrkestr();
		if (redact.empty()) {
			cout << endl << "Записей нет";
			return;
		}
		l = redact.begin();
		while (l != redact.end()) {
			cout << *l << endl;
			l++;
		}
		cout << "Введите номер записи ";
		cin >> gg;
		l = redact.begin();
		out.open(OrkestrFile);
		while (l != redact.end()) {
			if (p != gg) {
				out << l->getBaraban() << " ";
				out << l->getPionist() << " ";
				out << l->getDerigor() << " ";
				out << l->getSkripach() << " ";
				out << l->getNumber() << " ";
				out << l->getKonz() << " ";
			}
			l++; p++;
		}
		out.close();
		break;
	case 2:
		system("cls");
		out.open(OrkestrFile, ios::trunc);
		out.close();
		cout << endl << "Все записи удалены";
		break;
	default: cout << endl << "Такого действия не существует";
		return;
		break;
	}
	system("pause");
}
//void Outp::search() {
//	vector<Orkestr> redact;
//	std::regex dregex("\\d{2}.\\d{2}.\\d{4}");
//	std::regex tregex("\\d{2}.\\d{2}");
//	redact = readOrkestr();
//	if (redact.size() == 0) {
//		cout << endl << "Записей не существует";
//		return;
//	}
//	vector<Orkestr> find_redact;
//	int i, p;
//	string searchingData, currentData, newData;
//	char c;
//	string(Orkestr:: * getanyD)() = NULL;
//	system("cls");
//	cout << endl << " По какому полю необходимо произвести поиск?"
//		<< endl << " 1) Имя барабанщика"
//		<< endl << " 2) Имя пиониста"
//		<< endl << " 3) Имя дерижера"
//		<< endl << " 4) Имя скрипача"
//		<< endl << " 5) Номер зала "
//		<< endl << " 6) Количество концертов\n  ";
//	c = _getch();
//	if (c == '1' || c == '7' || c == '3' || c == '4'|| c == '5'|| c == '6') {
//		cout << endl << " Введите данные для поиска: ";
//		std::cin.ignore(32767, '\n');
//		getline(std::cin, newData);
//	}
//	searchingData = newData;
//	regex searchRegex("([\\w- ])*(^|-|\\b|_)(" + searchingData + ")($|-|\\b|_)([\\w- ])*");
//	switch (c) {
//	case '1':
//		getanyD = &Orkestr::getBaraban;
//		break;
//	case '2':
//		getanyD = &Orkestr::getPionist;
//		break;
//	case '3':
//		getanyD = &Orkestr::getDerigor;
//		break;
//	case '4':
//		getanyD = &Orkestr::getSkripach;
//		break;
//	case '5':
//		getanyD = &Orkestr::getNumber;
//		break;
//	case '6':
//		getanyD = &Orkestr::getKonz;
//		break;
//	default: cout << endl << "Такого поля не существует";
//		return;
//		break;
//	}
//	for (i = 0; i < redact.size(); i++) {
//		currentData = (&redact[i]->*getanyD)();
//		if (regex_match(currentData.begin(), currentData.end(), searchRegex))
//			find_redact.push_back(redact[i]);
//	}
//	cout << endl << " Количество объектов - " << find_redact.size() << endl;
//	for (i = 0; i < find_redact.size(); i++) {
//		std::cout << "|" << setw(3) << i + 1
//			<< "|" << setw(35) << find_redact[i].getBaraban()
//			<< "|" << setw(21) << find_redact[i].getPionist()
//			<< "|" << setw(15) << find_redact[i].getDerigor()
//			<< " |" << setw(14) << find_redact[i].getSkripach()
//			<< "| " << setw(10) << find_redact[i].getNumber()
//			<< " |" << setw(6) << find_redact[i].getKonz()
//			<< " |" << std::endl;
//	}
//	system("pause");
//}
void Outp::sort() {
	system("cls");
	list<Orkestr> redact;
	redact = readOrkestr();
if (redact.empty()) {
	cout << "Список пуст" << endl;
	system("pause");
	return;
}
int ff;
do {
	system("cls");
	cout << "\t--- сортировка по параметрам ---" << endl;
	cout << " 1) По названию книги" << endl;
	cout << " 2) По автору" << endl;
	cout << " 3) По кол-ву страниц" << endl;
	cout << " --> ";
	cin >> ff;
} while (ff <= 0 || ff > 3);
switch (ff) {
case 1: {
	auto compare = [](const Orkestr& a, const Orkestr& b) { return a.baraban < b.baraban; };
	redact.sort(compare);
	break;
}
case 2: {
	auto compare = [](const Orkestr& a, const Orkestr& b) { return a.pionist < b.pionist; };
	redact.sort(compare);
	break;
}
case 3: {
	auto compare = [](const Orkestr& a, const Orkestr& b) { return a.konz < b.konz; };
	redact.sort(compare);
	break;
}
}
list<Orkestr>::iterator l;
l = redact.begin();
cout << setw(18) << "Название | " << setw(18) << "Автор | " << "Кол-во | " << endl;
cout << "--------------------------------------------" << endl;
while (l != redact .end()) {
	std::cout<<"\t" << *l ;
	l++;
}
cout << endl;
system("pause");
return;
}
void Outp::Viewm() {
	map<int, Gournal> redact;
	redact = readKrkestr();
	map<int, Gournal>::iterator m;
	m = redact.begin();
	system("cls");
	while (m != redact.end())
	{
		std::cout << "\t" << m->second;
		m++;
	}
	if (redact.empty()) {
		std::cout << endl << "Записей не существует\n" << endl;
	}
	system("pause");
}
void Outp::addm() {
	Gournal g;	
	g.createG();
	
	ofstream out(GournalFile, ios::app);
	if (out.good()) {
		out << setw(15) << g;
		system("cls");
		std::cout
			<< setw(35) << g.getName()
			<< "|" << setw(21) << g.getStr() << endl;
	}
	out.close();
	system("pause");
	return;
}
