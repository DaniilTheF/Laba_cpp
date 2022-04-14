#pragma once
#include "Header.h"
using namespace std;
class Orkestr
{
public:
	string pionist;
	string baraban;
	string derigor;
	string skripach;
	string number;
	string konz;
public:
	Orkestr();
	Orkestr(string pionist, string baraban, string derigor, string skripach, string number, string konz);
	string getPionist();
	string getBaraban();
	string getDerigor();
	string getSkripach();
	string getNumber();
	string getKonz();
	void setPionist(string pionist);
	void setBaraban(string baraban);
	void setDerigor(string derigor);
	void setSkripach(string skripach);
	void setNumber(string number);
	void setKonz(string konz);
	void create();
	friend ostream& operator<< (ostream& out, Orkestr& k);
	friend istream& operator>> (istream& in, Orkestr& k);
};

