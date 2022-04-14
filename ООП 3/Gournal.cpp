#include "Gournal.h"
#include "Header.h"
Gournal::Gournal() {
	name = "";
	str = "";
}
Gournal::Gournal(string name, string str) {
	this->name = name;
	this->str = str;
}
string Gournal::getName() {
	return name;
}
string Gournal::getStr() {
	return str;
}
void Gournal::setName(string name) {
	this->name = name;
}
void Gournal::setStr(string str) {
	this->str = str;
}
void Gournal::createG() {
	std::cout << "¬ведите им€ : " << std::endl;
	std::cin.ignore(32767, '\n');
	std::getline(std::cin, name);

	std::cout << "¬ведите номер ученика: " << std::endl;
	cin >> str;

}
 ostream& operator <<(ostream& out, Gournal& t) {
	out << t.name << endl;
	out << t.str << endl;
	return out;
}
 istream& operator >>(istream& in, Gournal& t) {
	 getline(in, t.name);
	 getline(in, t.str);
	 return in;
}

