#include<iostream>
#include<string>
#include<cstdlib>

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

void search(Student *student, int n)
{
	cout << "\nPlease enter 'Last name' for searching\n";
	string str;
	cin >> str;
	int count = 0;
	for (int i = 0; i < n; i++)
	{		
		if (student[i].last_name == str)
		{
			student[i].Print();
			count++;
		}
	}
	if (count == 0)
		cout << "Error! No such student\n";
}

void Main_Window(int selection, Student *student, int n, bool check_data)
{
	system("cls");
	cout << "\nPlease select a section:";
	cout << "\n1. Add data \n2. Output arrays structs \n3. Alphabetical sorting \n4. Sort date \n5. Search student \n6. Exit from programm\n";
	cin >> selection;	
	switch (selection)
	{
	case 1:
		system("cls");
		cout << "Fill in the information:\n";
		data_input(student, n);
		check_data = true;
		int selec;
		cout << "\nWhat's next?\n1. Back to main menu \n2. Add more students\n";
		cin >> selec;
		if (selec == 1)
			Main_Window(selection, student, n, check_data);
		/*else if (selec == 2)
			add_student(student, n);	*/		
		break;
	case 2:
		link_print:
		system("cls");
		if (check_data)
		{
			cout << "All students\n";
			for (int i = 0; i < n; i++)
			{
				student[i].Print();
			}
		}			
		else
			cout << "Error! Add students!)";			
			cout << "\n1. Do you want to back to main menu?(Enter 1 - Yes | 2 - Exit)\n";
			cin >> selec;
			if (selec == 1)
				Main_Window(selection, student, n, check_data);
			else if (selec == 2)
				exit(0);
			else;
			break;
		
	case 3:
		system("cls");
		if (check_data)
		{
			cout << "Sort in the name:\n";
			sort_name(student, n);
			cout << "Sort completed!";
		}
		else
			cout<< "Error! Add students!)";
		cout<< "\nWhat`s next? \n1. Back to main menu \n2. Look on the data about students\n";
		cin >> selec;
		if (selec == 1)
			Main_Window(selection, student, n, check_data);
		else if (selec == 2)
			goto link_print;
		break;
	case 4:
		system("cls");
		if (check_data)
		{
			cout << "Sort in the date:\n";
			sort_date(student, n);
			cout << "Sort completed!";
		}
		else
			cout << "Error! Add students!)";
		cout << "\nWhat`s next? \n1. Back to main menu \n2. Look on the data about students\n";
		cin >> selec;
		if (selec == 1)
			Main_Window(selection, student, n, check_data);
		else if (selec == 2)
			goto link_print;
		break;
	case 5:
		system("cls");
		if (check_data)
			search(student, n);
		else
			cout << "Error! Add students)";
		cout << "\nWhat`s next? \n1. Exit \n2. Back to main menu\n";
		cin >> selec;
		if (selec == 1)
			exit(0);
		else if (selec == 2)
			Main_Window(selection, student, n, check_data);
		break;
	case 6:
		exit(0);
	default:
		cout << "\nERROR! RETURN INPUT";
		cout << "\nWhat`s next? \n1. Exit \n2. Back to main menu\n";
		cin >> selec;
		if (selec == 1)
			exit(0);
		else if(selec == 2)
			Main_Window(selection, student, n, check_data);
		else;
		break;
	}
}

int main()
{
	int n = 0, selection = 0;
	bool check_data = false;
	cout << "Please enter quality students!\n";
	cin >> n;
	Student *student = new Student[n];	
	Main_Window(selection, student, n, check_data);
	
	delete[] student;
	system("pause");
	return 0;
}