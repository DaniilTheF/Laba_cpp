#pragma once
#include "Header.h"
using namespace std;
class Gournal
{ 
public: string name;
public: string str;
public:
	Gournal();
	Gournal(string name, string str);
	void setName(string name);
	void setStr(string str);
	void createG();
	string getName();
	string getStr();
	friend ostream& operator <<(ostream& out, Gournal& t);
	friend istream& operator >>(istream& in, Gournal& t);
};

