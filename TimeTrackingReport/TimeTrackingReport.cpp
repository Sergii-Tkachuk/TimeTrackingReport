#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

template<class T>
struct DataTable
{
	string m_nameTable;
	vector<T> m_elements;
};

class TableCSV
{
	DataTable<string> Name;
	DataTable<string> Email;
	DataTable<string> Department;
	DataTable<string> Position;
	DataTable<string> Project;
	DataTable<string> Task;
	DataTable<string> Date;
	DataTable<int>    LoggerHours;

public:
	TableCSV(ifstream &inFile)
	{
		string buffString;
		getline(inFile, buffString);
		stringstream buffStream(buffString);

		getline(buffStream, Name.m_nameTable, ';');
		getline(buffStream, Email.m_nameTable, ';');
		getline(buffStream, Department.m_nameTable, ';');
		getline(buffStream, Position.m_nameTable, ';');
		getline(buffStream, Project.m_nameTable, ';');
		getline(buffStream, Task.m_nameTable, ';');
		getline(buffStream, Date.m_nameTable, ';');
		getline(buffStream, LoggerHours.m_nameTable, ';');
	}

	void addNewObject(ifstream& inFile)
	{
		string buffString;
		getline(inFile, buffString);
		stringstream buffStream(buffString);

		getline(buffStream, buffString, ';');
		Name.m_elements.push_back(buffString);

		getline(buffStream, buffString, ';');
		Email.m_elements.push_back(buffString);

		getline(buffStream, buffString, ';');
		Department.m_elements.push_back(buffString);

		getline(buffStream, buffString, ';');
		Position.m_elements.push_back(buffString);

		getline(buffStream, buffString, ';');
		Project.m_elements.push_back(buffString);

		getline(buffStream, buffString, ';');
		Task.m_elements.push_back(buffString);

		getline(buffStream, buffString, ';');
		Date.m_elements.push_back(buffString);

		getline(buffStream, buffString, ';');
		LoggerHours.m_elements.push_back(atoi(buffString.c_str()));
	}

	void print()
	{
		for (int i = 0; i < Name.m_elements.size(); i++)
		{
			if(Name.m_elements[i] == )
			cout << Name.m_elements[i] << '\n';
		}
	}
};




int main()
{
	ifstream inFile("data_file.txt");
	
	TableCSV csv(inFile);
	while (inFile)
	{
		csv.addNewObject(inFile);
	}
	
	csv.print();
}