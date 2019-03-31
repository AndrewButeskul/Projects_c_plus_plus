#include<iostream>
#include<string>
#include<ctime>

struct Stud 
{
	std::string Name;
	char inithial[2];
	struct Group
	{
		std::string facultet;
		std::string name_group;
		short cours;
		short number_group;
	}G;
	float ses[4];	
	float aver = 0;

	float Ses()
	{
		aver = 0;
		for (int i = 0; i < 4; i++)
		{
			aver = aver + ses[i];
		}
		aver = aver / 4;
		return aver;
	}
	void print()
	{
		std::cout << "\n|-----------------------------------------------------------------|\n";
		std::cout << "\nИмя: " << Name << " " << inithial[0] << ". " << inithial[1] << "." << "\n";
		std::cout << "Группа: " << G.name_group << "\n";
		std::cout << "Факультет: " << G.facultet << "\n";
		std::cout << "Курс: " << G.cours << "\n";
		std::cout << "Номер группы: " << G.number_group << "\n";
		std::cout << "Средняя оценка: " << aver << "\n";
	}
};

void fill(Stud *student, short n)
{
	student[0].Name = "Иванов";
	student[1].Name = "Спатар";
	student[2].Name = "Яновский";
	student[3].Name = "Тютенко";
	student[4].Name = "Будяну";
	student[5].Name = "Курпол";
	student[6].Name = "Шумин";
	student[7].Name = "Пенчев";
	student[8].Name = "Баблюк";
	student[9].Name = "Мясников";	

	for (int i = 0; i < n; i++)
	{
		student[i].inithial[0] = 'Б';
		student[i].inithial[1] = 'Ю';

		student[i].G.facultet = "ИКС";

		student[i].G.cours = 1;

		student[i].G.name_group = "АТ";

		student[i].G.number_group = 182;
	}	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			student[i].ses[j] = rand() % 5; 
		}
	}	
}

/*void input(Stud *student, short n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "Введите фамилию\n";
		std::cin >> student[i].Name;

		std::cout << "Введите ваши инициалы\n";
		for (int j  = 0; j < 2; j++)
		{
			std::cin >> student[i].inithial[j];
		}		

		std::cout << "Введите ваш факультет\n";
		std::cin >> student[i].G.facultet;

		std::cout << "Введите номер вашего курса\n";
		std::cin >> student[i].G.cours;
		if (student[i].G.cours > 5 || student[i].G.cours < 0)
		{
			std::cout << "Пожалуйста повторите ввод! Вы ввели некоректное значение\n";
			break;
		}
		std::cout << "Введите название вашей группы\n";
		std::cin >> student[i].G.name_group;

		std::cout << "Введите номер вашей группы\n";
		std::cin >> student[i].G.number_group;

		for (int j = 0; j < 4; j++)
		{
			std::cout << "Введите вашу оценку по " << j + 1 << " предмету\n";
			std::cin >> student[i].ses[j];
			if (student[i].ses[j] > 5 || student[i].ses[j] < 0)
			{
				std::cout << "Пожалуйста повторите ввод! Вы ввели некоректное значение\n";
				break;
			}			
		}		
	}
}*/
void sort_name(Stud *student, short n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(student[i].Name.c_str(), student[j].Name.c_str()) > 0)
			{
				std::swap(student[i], student[j]);
			}
		}
	}
}

void sort_mark(Stud *student, short n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (student[i].Ses() > student[j].Ses())
			{
				std::swap(student[i], student[j]);
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	float average = 0;
	short n = 10;
	Stud *student = new Stud[10];
	
	//input(student, n);
	fill(student, n); //автоматическое заполнение информации

	sort_name(student, n);
	std::cout << "Список всех студентов (в алфавитном порядке)\n";
	for (int i = 0; i < n; i++)
	{
		student[i].Ses();
		student[i].print();
	}
	std::cout << "\nСтуденты, средний бал которых выше 4,2 (отсортирован по возростанию бала)\n";
	sort_mark(student, n);
	for (int i = 0; i < n; i++)
	{
		if (student[i].Ses() > (float)4.2)
		{
			student[i].print();
		}		
	}	
	for (int i = 0; i < n; i++)
	{
		if (student[i].Ses() < (float)4.2)
		{
			int count = i + 1;
			if (count == 10)
			{
				std::cout << "Студентов со средней оценкой в 4,2 и выше, нету!\n";
			}
		}	
	}		
	
	delete[] student;
	system("Pause");
	return 0;
}