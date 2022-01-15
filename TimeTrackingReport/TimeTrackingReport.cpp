/*
Data is supplied in text file in CSV format. First line of the file is columns names. Separator is semicolon (;). It is assumed that the file is not malformed. 
Date is in YYYY-MM-DD format.
Input data example:
Name;email;department;position;project;task;date;logged hours
John Doe;john.doe@company.com;Delivery;Software Engineer;Mars;MRS-2240;2021-10-19;5
John Doe;john.doe@company.com;Delivery;Software Engineer;Mars;MRS-2241;2021-10-20;8
Jane Doe;jane.doe@company.com;Delivery;Manager;Venus;VNS-1111;2021-10-20;4
......
It is expected to receive output in CSV format, containing person name, month and total hours logged
Output data example:
Name;Month;Total hours
John Doe;October 2021;13
Jane Doe;October 2021;4
*/
#include "TableCSV.h"

int main()
{
	TableCSV csv;
	
	if (csv.InitCSV("data_file.csv"))
	{
		std::cout << csv.getNameColumns() << '\n';
		for (int i = 0; i < csv.CountWorkers(); ++i)
			std::cout << csv[i];

		csv.Report();
	}
	return 0;
}