#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;


class Date
{
private:
	enum Months
	{
		January,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		November,
		December
	};

public:
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

	string getNameMonth() const
	{
		switch (Months)
		{
		case January: return "January";
		case February: return "February";
		case March: return "March";
		case April: return "April";
		case May: return "May";
		case June: return "June";
		case July: return "July";
		case August: return "August";
		case September: return "September";
		case October: return "October";
		case November: return "November";
		case December: return "December";
		default: return "NONE";
		}
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

bool operator == (const DataRows& d1, const DataRows& d2)
{
	return d1.Name == d2.Name && d1.Email == d2.Email && d1.date.Years == d2.date.Years && d1.date.Months == d2.date.Months;
}


void addData(istream &input, vector<DataRows> &rows, char separator)
{
	string buffString;

	while (getline(input, buffString))
	{
		stringstream buffStream(buffString);
		DataRows buffRows;

		getline(buffStream, buffRows.Name, separator);
		getline(buffStream, buffRows.Email, separator);
		getline(buffStream, buffRows.Department, separator);
		getline(buffStream, buffRows.Position, separator);
		getline(buffStream, buffRows.Project, separator);
		getline(buffStream, buffRows.Task, separator);

		getline(buffStream, buffString, separator);
		buffRows.date.getDate(buffString);

		buffStream >> buffRows.LoggedHours;

		rows.push_back(buffRows);
	}
}

void PrintData(ostream& out, vector<DataRows> arrData)
{
	for (const auto& elem : arrData)
		out << elem.Name << ';' << elem.date.getNameMonth() << ' ' << elem.date.Years << ';' << elem.LoggedHours << '\n';
}


void Report(vector<DataRows> arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
		for (int j = i + 1; j < arr.size(); ++j)
			if (arr[i] == arr[j])
			{
				arr[i].LoggedHours += arr[j].LoggedHours;
				arr.erase(arr.begin() + j);
			}
	ofstream out("Time_report.txt");

	out << "Name;Month;Total hours\n";
	PrintData(out, arr);

	out.close();
}

int main()
{
	ifstream inFile("data_file.txt"); //open csv file

	if (!inFile.is_open())
	{
		cout << "Error: File not fount!!!\n";
	}
	else
	{
		vector<DataRows> dataRows; //
		string columnName;

		getline(inFile, columnName);

		addData(inFile, dataRows, ';');
		inFile.close();

		Report(dataRows);
	}
	return 0;
}