#pragma once
#include "Header.h"
#include "ABS.h"
#include "Orkestr.h"
#include "Gournal.h"
class Outp : public ABS 
{
public:
	list<Orkestr> readOrkestr();
	map<int, Gournal> readKrkestr();
	void View();
	void add();
	void redact();
	void deleteO();
	void sort();
	void Viewm();
	void addm();
	void redactm();
	void deleteG();
	void sortm();
};

	