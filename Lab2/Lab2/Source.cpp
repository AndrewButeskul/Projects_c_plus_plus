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
	int number_phone;
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
};

void data_input(Student *student, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "Enter name " << "\n";
		std::cin >> student[i].name;

		std::cout << "Enter last name " << "\n";
		std::cin >> student[i].last_name;

		std::cout << "Enter middle name " << "\n";
		std::cin >> student[i].middle_name;

		std::cout << "Enter national " << "\n";
		std::cin >> student[i].national;

		std::cout << "Enter height " << "\n";
		std::cin >> student[i].height;

		std::cout << "Enter weight " << "\n";
		std::cin >> student[i].weight;

		std::cout << "Enter your number phone " << "\n";
		std::cin >> student[i].number_phone;

		std::cout << "Enter date " << "\n";
		do
		{
			std::cout << "Day  " << "\n";
			std::cin >> student[i].date[0];
		} while (student[i].date[0] > 30);
		do
		{
			std::cout << "Mouth " << "\n";
			std::cin >> student[i].date[1];
		} while (student[i].date[1] > 12);

		do
		{
			std::cout << "Year " << "\n";
			std::cin >> student[i].date[2];
		} while (student[i].date[2] > 2019);

		std::cout << "Enter your post index " << "\n";
		std::cin >> student[i].adress.post_index;

		std::cout << "Enter your country " << "\n";
		std::cin >> student[i].adress.country;

		std::cout << "Enter your oblast " << "\n";
		std::cin >> student[i].adress.oblast;

		std::cout << "Enter your district " << "\n";
		std::cin >> student[i].adress.district;

		std::cout << "Enter your city " << "\n";
		std::cin >> student[i].adress.city;

		std::cout << "Enter your street " << "\n";
		std::cin >> student[i].adress.street;

		std::cout << "Enter your number house " << "\n";
		std::cin >> student[i].adress.house;

		std::cout << "Enter your number flat " << "\n";
		std::cin >> student[i].adress.flat;

		std::cout << "Enter name your university " << "\n";
		std::cin >> student[i].university;

		std::cout << "Enter name your group " << "\n";
		std::cin >> student[i].group;

		std::cout << "Enter your cours " << "\n";
		std::cin >> student[i].cours;

		std::cout << "Enter name your specialty " << "\n";
		std::cin >> student[i].specialty;

		do
		{
			std::cout << "Enter average mark " << "\n";
			std::cin >> student[i].average_mark;
		} while (student[i].average_mark > 6 && student[i].average_mark < 0);
		
	}
}

int main()
{
	int n = 0;

	cout << "Please enter quality students!\n";
	cin >> n;

	Student *student = new Student[n];

	data_input(student, n);

	delete[] student;
	system("pause");
	return 0;
}