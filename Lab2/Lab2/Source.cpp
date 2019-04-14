#include<iostream>
#include<string>

using namespace std;

struct Student
{
	string name;
	string last_name;
	string middle_name;
	string national;
	float height;
	float weight;
	int phone_number;
	int date[3];
	struct Adress
	{
		int post_index;
		string country;
		string oblast;
		string district;
		string city;
		string street;
		int house;
		int flat;
	}adress;
	string university;
	string group;
	int cours;
	float average_mark;
	string specialty;

	void Print()
	{
		cout << endl << endl << "Name: " << name << "\nLast name: " << last_name << "\nMiddle name: " << middle_name << "\nNational: " << national <<
			"\nHeight: " << height << "\nWeight: " << weight << "\nPhone number: " << phone_number << "\nDate of Birth: "
			<< date[0] << "." << date[1] << "." << date[2] << "\nRESIDENCE DATA: " << "\nPost index: " << adress.post_index << "\nCountry: " << adress.country <<
			"\nOblast: " << adress.oblast << "\nDistrict: " << adress.district << "\nCity: " << adress.city << "\nStreet: " << adress.street
			<< "\nNumber house: " << adress.house << "\nNumber flat: " << adress.flat << "\nName university: " << university << "\nName group: " <<
			group << "\nNumber cours: " << cours << "\nAverage mark: " << average_mark << "\nSpecialty: " << specialty << endl;
	}
};

void data_input(Student *student, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << endl << "Enter name " << "\n";
		cin >> student[i].name;

		cout << "Enter last name " << "\n";
		cin >> student[i].last_name;

		cout << "Enter middle name " << "\n";
		cin >> student[i].middle_name;

		cout << "Enter national " << "\n";
		cin >> student[i].national;

		cout << "Enter height " << "\n";
		cin >> student[i].height;

		cout << "Enter weight " << "\n";
		cin >> student[i].weight;

		cout << "Enter your number phone " << "\n";
		cin >> student[i].phone_number;

		cout << "Enter date " << "\n";
		do
		{
			cout << "Day  " << "\n";
			cin >> student[i].date[0];
		} while (student[i].date[0] > 30);
		do
		{
			cout << "Mouth " << "\n";
			cin >> student[i].date[1];
		} while (student[i].date[1] > 12);

		do
		{
			cout << "Year " << "\n";
			cin >> student[i].date[2];
		} while (student[i].date[2] > 2019);

		cout << "Enter your post index " << "\n";
		cin >> student[i].adress.post_index;

		cout << "Enter your country " << "\n";
		cin >> student[i].adress.country;

		cout << "Enter your oblast " << "\n";
		cin >> student[i].adress.oblast;

		cout << "Enter your district " << "\n";
		cin >> student[i].adress.district;

		cout << "Enter your city " << "\n";
		cin >> student[i].adress.city;

		cout << "Enter your street " << "\n";
		cin >> student[i].adress.street;

		cout << "Enter your number house " << "\n";
		cin >> student[i].adress.house;

		cout << "Enter your number flat " << "\n";
		cin >> student[i].adress.flat;

		cout << "Enter name your university " << "\n";
		cin >> student[i].university;

		cout << "Enter name your group " << "\n";
		cin >> student[i].group;

		cout << "Enter your cours " << "\n";
		cin >> student[i].cours;

		cout << "Enter name your specialty " << "\n";
		cin >> student[i].specialty;

		do
		{
			cout << "Enter average mark " << "\n";
			cin >> student[i].average_mark;
		} while (student[i].average_mark > 6 && student[i].average_mark < 0);
		
	}
}

void sort_name(Student *student, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(student[i].last_name.c_str(), student[j].last_name.c_str()) > 0)
			{
				swap(student[i], student[j]);
			}
		}
	}
}

void sort_date(Student *student, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			int temp1 = student[i].date[0] + (student[i].date[1] * 30) + (student[i].date[2] * 365);
			int temp2 = student[j].date[0] + (student[j].date[1] * 30) + (student[j].date[2] * 365);
			if (temp1 < temp2)
			{
				swap(student[i], student[j]);
			}
		}
	}
}

int main()
{
	int n = 0, selection = 0;
	cout << "Please enter quality students!\n";
	cin >> n;

	Student *student = new Student[n];
	data_input(student, n);

	cout << "\n1. Alphabetical sorting\n2. Sort date\n";
	cin >> selection;
	switch (selection)
	{
	case 1:
		sort_name(student, n);
		break;
	case 2:
		sort_date(student, n);
		break;
	default:
		break;
	}
	

	for (int i = 0; i < n; i++)
	{
		student[i].Print();
	}

	delete[] student;
	system("pause");
	return 0;
}