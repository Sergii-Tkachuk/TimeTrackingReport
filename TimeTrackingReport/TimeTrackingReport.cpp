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
	
	if (csv.initCSV("data_file.csv")) //зчитуванн€ data_file.csv в об'Їкт csv
	{
		std::cout << csv.getNameColumns() << '\n';       //виводито ≥мена колонок
		for (int i = 0; i < csv.countWorkers(); ++i)//виводимо дан≥ прац≥вник≥в
			std::cout << csv[i];

		csv.Report();                               //генеруЇмо зв≥т прац≥вник≥в за м≥с€ць в Time_report.csv
	}
	return 0;
}