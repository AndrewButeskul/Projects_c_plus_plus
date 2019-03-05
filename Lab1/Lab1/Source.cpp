#include<iostream>
#include<string>
#include<ctime>

struct Employee 
{
	std::string name;
	std::string lastname;
	std::string patronymic;
	std::string position;
	int salary;
	int date[3];
		
	void print()
	{
		std::cout << "|___________________________________________________________________|\n";
		std::cout << "Data:\n";
		std::cout << "Name - " << name << "\nLast Name - " << lastname << "\nPatronymic - "
			<< patronymic << "\nPosition - " << position << "\nDate - " << date[0] << "." << date[1] << "." << date[2] << "\n";
		std::cout << "\n";
	}
};

void data_input(Employee *worker, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "Enter name " << "\n";
		std::cin >> worker[i].name;

		std::cout << "Enter last name " << "\n";
		std::cin >> worker[i].lastname;

		std::cout << "Enter patronymic " << "\n";
		std::cin >> worker[i].patronymic;

		std::cout << "Enter position " << "\n";
		std::cin >> worker[i].position;

		std::cout << "Enter salary " << "\n";
		std::cin >> worker[i].salary;

		std::cout << "Enter date " << "\n";
		std::cin >> worker[i].date[0];
		std::cin >> worker[i].date[1];
		std::cin >> worker[i].date[2];
	}
}

int salary(Employee *worker, int n, int average)
{
	for (int i = 0; i < n; i++)
	{
		average += worker[i].salary;
	}
	average = average / n;
	return average;
}


int main()
{
	srand(time(NULL));
	int average = 0; // средн€€ зарплата
	int n = 0; //n - количество сотрудников

	std::cout << "Enter the number of employees" << "\n";
	std::cin >> n;

	Employee *worker = new Employee[n];

	data_input(worker, n);

	for (int i = 0; i < n; i++)
	{
		if (worker[i].salary > salary(worker, n, average) && worker[i].date[0] < 1989)
		{
			worker[i].print();
		}
	}	
	
	delete[] worker;
	system("Pause");
	return 0;
}
