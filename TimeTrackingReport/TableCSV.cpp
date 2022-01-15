#include "TableCSV.h"

bool TableCSV::InitCSV(std::string nameFile)
{
	if (nameFile == "data_file.csv" || nameFile == "data_file.txt")
	{
		std::cout << "Initialization " << nameFile << " file\n";
		
		fileCSV = std::ifstream(nameFile);

		UpdateData();
		return true;
	}
	else
	{
		std::cout << "TableCSV not suport file: " << nameFile << '\n';
		return false;
	}
}

void TableCSV::UpdateData()
{
	workers.clear();
	fileCSV.seekg(0, std::ios::beg);

	std::string buffString;
	getline(fileCSV, nameColumns);

	while (std::getline(fileCSV, buffString))
	{
		std::stringstream buffStream(buffString);
		Worker buffRows;

		std::getline(buffStream, buffRows.Name, ';');
		std::getline(buffStream, buffRows.Email, ';');
		std::getline(buffStream, buffRows.Department, ';');
		std::getline(buffStream, buffRows.Position, ';');
		std::getline(buffStream, buffRows.Project, ';');
		std::getline(buffStream, buffRows.Task, ';');

		getline(buffStream, buffString, ';');
		buffRows.date.convertStringToDate(buffString);

		buffStream >> buffRows.LoggedHours;

		workers.push_back(buffRows);
	}
}

void TableCSV::AddWorker(Worker worker)
{
	workers.push_back(worker);
}

int TableCSV::CountWorkers()
{
	return workers.size();
}


void TableCSV::Report()
{
	std::vector<Worker> clone = workers;

	for (int i = 0; i < clone.size() - 1; i++)
		for (int j = i + 1; j < clone.size(); ++j)
			if (clone[i] == clone[j])
			{
				clone[i].LoggedHours += clone[j].LoggedHours;
				clone.erase(clone.begin() + j);
			}

	std::ofstream out("Time_report.csv");

	out << "Name;Month;Total hours\n";
	for (const auto& elem : clone)
		out << elem.Name << ';' << elem.date.getNameMonth() << ' ' << elem.date.Years << ';' << elem.LoggedHours << '\n';

	out.close();
}

std::string TableCSV::getNameColumns()
{
	return nameColumns;
}

Worker& TableCSV::operator[](const int index)
{
	assert(index >= 0 && index < workers.size());
	return workers[index];
}

bool operator==(const Worker& d1, const Worker& d2)
{
	return d1.Name == d2.Name && d1.Email == d2.Email && d1.date.Years == d2.date.Years && d1.date.Months == d2.date.Months;
}

std::ostream& operator<<(std::ostream& out, const Worker worker)
{
	out << worker.Name << ';'
		<< worker.Email << ';'
		<< worker.Department << ';'
		<< worker.Position << ';'
		<< worker.Project << ';'
		<< worker.Task << ';'
		<< worker.date.Years << '-'
		<< worker.date.Months << '-'
		<< worker.date.Days << ';'
		<< worker.LoggedHours << '\n';
	return out;
}
