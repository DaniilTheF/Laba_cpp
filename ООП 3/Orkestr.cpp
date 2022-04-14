#include "Orkestr.h"
        Orkestr::Orkestr() { pionist = "unknown"; baraban = "unknown"; derigor = "unknown"; skripach = "unknown"; number = "unknown"; konz = "unknown"; }
        Orkestr::Orkestr(string pionist, std::string baraban, std::string derigor, std::string skripach, string number, string konz) {
		this->pionist = pionist;
		this->baraban = baraban;
		this->derigor = derigor;
		this->skripach = skripach;
		this->number = number;
		this->konz = konz;
	}
	string Orkestr::getPionist() {
		string pionist;
		pionist = this->pionist;
		return pionist;
	}
	string Orkestr::getBaraban() {
		string baraban;
		baraban = this->baraban;
		return baraban;
	}
	string Orkestr::getDerigor() {
		string derigor;
		derigor = this->derigor;
		return derigor;
	}
	string Orkestr::getSkripach() {
		string skripach;
		skripach = this->skripach;
		return skripach;
	}
	string Orkestr::getNumber() {
		string number;
		number = this->number;
		return number;
	}
	string Orkestr::getKonz() {
		string konz;
		konz = this->konz;
		return konz;
	}
	void Orkestr::setPionist(string pionist) {
		this->pionist = pionist;
	}
	void Orkestr::setBaraban(string baraban) {
		this->baraban = baraban;
	}
	void Orkestr::setDerigor(string derigor) {
		this->derigor = derigor;
	}
	void Orkestr::setSkripach(string skripach) {
		this->skripach = skripach;
	}
	void Orkestr::setNumber(string number) {
		this->number = number;
	}
	void Orkestr::setKonz(string konz) {
		this->konz = konz;
	}
	void Orkestr::create() {
		std::cout << "Введите имя Книги: " << std::endl;
		std::cin.ignore(32767, '\n');
		std::getline(std::cin, baraban);

		std::cout << "Введите имя Автора: " << std::endl;
		std::getline(std::cin, pionist);

		std::cout << "Введите тип обложки: " << std::endl;
		std::getline(std::cin, derigor);

		std::cout << "Введите тип шрифта: " << std::endl;
		std::getline(std::cin, skripach);

		std::cout << "Введите размер шрифта: " << std::endl;
		cin >> number;

		std::cout << "Введите количество страниц: " << std::endl;
		cin >> konz;
	}
	ostream& operator<< (ostream& out, Orkestr& k) {
		out << k.baraban << endl;
		out << k.derigor << endl;
		out << k.pionist << endl;
		out << k.skripach << endl;
		out << k.number << endl;
		out << k.konz << endl;
		return out;
	}
	istream& operator>> (istream& in, Orkestr& k) {
		getline(in, k.baraban);
		getline(in, k.derigor);
		getline(in, k.pionist);
		getline(in, k.skripach);
		getline(in, k.number);
		getline(in, k.konz);
		return in;
	}