#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

struct TitanicRecord
{
	int passengerID = 0;
	bool survived = 0;
	int passengerClass = 0;
	string lastName = "";
	char sex = ' ';
	int age = 0;
	double fareCost = 0;
};

void printTitanicRecords(std::vector <TitanicRecord> records)
{

	for (auto& record : records)
	{
		cout << setw(15) << left << record.passengerID
			<< setw(11) << left << record.survived
			<< setw(18) << left << record.passengerClass
			<< setw(15) << left << record.lastName
			<< setw(6) << left << record.sex
			<< setw(6) << left << record.age
			<< setw(6) << left << record.fareCost
			<< endl;
	}
}

void calculateAverageFareAndSurvivalCount(const vector<TitanicRecord>& records)
{
	double avgFareCost = 0;
	int peopleSurvived = 0;
	double totalFareCost = 0;

	for (auto& record : records) //tried using auto and it works
	{
		totalFareCost += record.fareCost;
		peopleSurvived += record.survived;
	}

	avgFareCost = totalFareCost / records.size();

	cout << "Average Fare Cost: " << avgFareCost << endl;
	cout << "Number of People who survived: " << peopleSurvived << endl;
}

int main()
{
	string titanicText;

	ifstream readTitanicText("titanic.txt");

	vector<TitanicRecord> records;

	double avgFareCost = 0;

	int peopleSurvived = 0;

	cout << "Passenger ID:  " << "Survived?  " << "Passenger Class:  " << "Last Name:     " << "Sex:  " << "Age:  " << "Fare Cost:  " << endl;

	while (!readTitanicText.eof())
	{
		TitanicRecord tr;

		readTitanicText >> tr.passengerID >> tr.survived >> tr.passengerClass >> tr.lastName >> tr.sex
						>> tr.age >> tr.fareCost;

		records.push_back(tr);
	}

	printTitanicRecords(records);
	calculateAverageFareAndSurvivalCount(records);
}