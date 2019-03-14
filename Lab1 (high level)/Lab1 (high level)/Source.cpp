#include<iostream>
#include<string>

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
		std::cout << "\n���: " << Name << " " << inithial[0] << ". " << inithial[1] << "." << "\n";
		std::cout << "������: " << G.name_group << "\n";
		std::cout << "���������: " << G.facultet << "\n";
		std::cout << "����: " << G.cours << "\n";
		std::cout << "����� ������: " << G.number_group << "\n";
		std::cout << "������� ������: " << aver << "\n";
	}
};

void fill(Stud *student, short n)
{
	student[0].Name = "������";
	student[1].Name = "������";
	student[2].Name = "��������";
	student[3].Name = "�������";
	student[4].Name = "������";
	student[5].Name = "������";
	student[6].Name = "�����";
	student[7].Name = "������";
	student[8].Name = "������";
	student[9].Name = "������";

	for (int i = 0; i < n; i++)
	{
		student[i].inithial[0] = '�';
		student[i].inithial[1] = '�';

		student[i].G.facultet = "���";

		student[i].G.cours = 1;

		student[i].G.name_group = "��";

		student[i].G.number_group = 182;
	}	
	for (int j = 0; j < 4; j++)
	{
		student[0].ses[j] = 2;
	}
	for (int j = 0; j < 4; j++)
	{
		student[1].ses[j] = 5;
	}
	for (int j = 0; j < 4; j++)
	{
		student[2].ses[j] = 3;
	}
	for (int j = 0; j < 4; j++)
	{
		student[3].ses[j] = 4.6;
	}
	for (int j = 0; j < 4; j++)
	{
		student[4].ses[j] = 4.5;
	}
	for (int j = 0; j < 4; j++)
	{
		student[5].ses[j] = 1.5;
	}	
	for (int j = 0; j < 4; j++)
	{
		student[6].ses[j] = 4;
	}
	for (int j = 0; j < 4; j++)
	{
		student[7].ses[j] = 2;
	}
	for (int j = 0; j < 4; j++)
	{
		student[8].ses[j] = 1;
	}
	for (int j = 0; j < 4; j++)
	{
		student[9].ses[j] = 4;
	}
}

/*void input(Stud *student, short n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "������� �������\n";
		std::cin >> student[i].Name;

		std::cout << "������� ���� ��������\n";
		for (int j  = 0; j < 2; j++)
		{
			std::cin >> student[i].inithial[j];
		}		

		std::cout << "������� ��� ���������\n";
		std::cin >> student[i].G.facultet;

		std::cout << "������� ����� ������ �����\n";
		std::cin >> student[i].G.cours;
		if (student[i].G.cours > 5 || student[i].G.cours < 0)
		{
			std::cout << "���������� ��������� ����! �� ����� ����������� ��������\n";
			break;
		}
		std::cout << "������� �������� ����� ������\n";
		std::cin >> student[i].G.name_group;

		std::cout << "������� ����� ����� ������\n";
		std::cin >> student[i].G.number_group;

		for (int j = 0; j < 4; j++)
		{
			std::cout << "������� ���� ������ �� " << j + 1 << " ��������\n";
			std::cin >> student[i].ses[j];
			if (student[i].ses[j] > 5 || student[i].ses[j] < 0)
			{
				std::cout << "���������� ��������� ����! �� ����� ����������� ��������\n";
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
	float average = 0;
	short n = 10;
	Stud *student = new Stud[10];
	
	//input(student, n);
	fill(student, n);

	sort_name(student, n);
	std::cout << "������ ���� ��������� (� ���������� �������)\n";
	for (int i = 0; i < n; i++)
	{
		student[i].print();
	}
	std::cout << "\n�������� � �� ������, ������� ��� ������� ���� 4,2 (������������ �� ����������� ����)";
	sort_mark(student, n);
	for (int i = 0; i < n; i++)
	{
		if (student[i].Ses() > (float)4.2)
		{
			student[i].print();
		}
	}			
		/*else
		{
			std::cout << "��������� �� ������� ������� � 4,2 � ����, ����!\n";
			return 0;
		}*/
	
	delete[] student;
	system("Pause");
	return 0;
}