#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct Date
{
	int Years;
	int Months;
	int Days;

	void getDate(string str)
	{
		char separator;
		stringstream stream(str);
		stream >> Years >> separator;
		stream >> Months >> separator;
		stream >> Days;
	}
};

struct DataRows
{
	string Name;
	string Email;
	string Department;
	string Position;
	string Project;
	string Task;
	Date date = {0, 0, 0};
	int LoggedHours = 0;
};


bool operator > (const DataRows& d1, const DataRows& d2)
{
	return d1.Name > d2.Name || d1.date.Years > d2.date.Years || d1.date.Months > d2.date.Months;
}

bool operator < (const DataRows& d1, const DataRows& d2)
{
	return d1.Name < d2.Name || d1.date.Years < d2.date.Years || d1.date.Months < d2.date.Months;
}

bool operator == (const DataRows& d1, const DataRows& d2)
{
	return d1.Name == d2.Name && d1.date.Years == d2.date.Years && d1.date.Months == d2.date.Months;
}


void addData(istream &input, vector<DataRows> &rows)
{
	string buffString;

	while (getline(input, buffString))
	{
		stringstream buffStream(buffString);
		DataRows buffRows;

		getline(buffStream, buffRows.Name, ';');
		getline(buffStream, buffRows.Email, ';');
		getline(buffStream, buffRows.Department, ';');
		getline(buffStream, buffRows.Position, ';');
		getline(buffStream, buffRows.Project, ';');
		getline(buffStream, buffRows.Task, ';');

		getline(buffStream, buffString, ';');
		buffRows.date.getDate(buffString);

		buffStream >> buffRows.LoggedHours;

		rows.push_back(buffRows);
	}
}

void PrintData(ostream& out, vector<DataRows> arrData)
{
	for (const auto& elem : arrData)
		out << elem.Name << ';' << elem.date.Years << '-' << elem.date.Months << ';' << elem.LoggedHours << '\n';
}

void Report(vector<DataRows> arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = i + 1; j < arr.size(); ++j)
		{
			if (arr[i] == arr[j])
			{
				arr[i].LoggedHours += arr[j].LoggedHours;
				arr.erase(arr.begin() + j);
			}
		}
	}
	PrintData(cout, arr);
}

int main()
{
	ifstream inFile("data_file.txt");
	
	vector<DataRows> dataRows;
	string columnName;
	getline(inFile, columnName);

	while(inFile)
		addData(inFile, dataRows);
	inFile.close();

	Report(dataRows);
}