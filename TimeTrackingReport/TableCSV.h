#ifndef TABLE_CSV_H
#define TABLE_CSV_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <cassert>
#include "Date.h"

struct Worker
{
	std::string Name;
	std::string Email;
	std::string Department;
	std::string Position;
	std::string Project;
	std::string Task;
	Date date = { 0, 0, 0 };
	int LoggedHours = 0;
};


class TableCSV
{
	std::vector<Worker> workers;
	std::ifstream FileCSV;
	std::string nameColumns;

public:
	bool initCSV(std::string nameFile);  //≥н≥ц≥ал≥зуЇ таблицю csv
	void updateData();                   //€кщо файл.csv був зм≥нений, то оновлюЇмо наш≥ дан≥
	void addWorker(Worker worker);       //додаЇ новий елемент типу Worker
	int countWorkers();                  //повертаЇ к≥льк≥сть елемент≥в массиву workers
	void Report();                       //генерац≥€ щом≥с€чного зв≥ту
	std::string getNameColumns();        //повертаЇ ≥мена колонок
	Worker& operator[] (const int index);
};

std::ostream& operator<< (std::ostream& out, const Worker worker);
bool operator == (const Worker& d1, const Worker& d2);


#endif