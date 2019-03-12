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

	void print()
	{
		std::cout << "\n|-----------------------------------------------------------------|\n";
		std::cout << "| ���: " << Name << " " << inithial[0] << ". " << inithial[1] << "." << "\n";
		std::cout << "������: " << G.name_group << "\n";
		std::cout << "���������: " << G.facultet << "\n";
		std::cout << "����: " << G.cours << "\n";
		std::cout << "����� ������: " << G.number_group << "\n";
		float a = 0;
		for (int i = 0; i < 4; i++)
		{
			a += ses[i];			
		}
		a = a / 4;
		std::cout << "������� ������: " << a << "\n";
	 }
};


//void input(Stud *student, short n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		std::cout << "������� �������\n";
//		std::cin >> student[i].Name;
//
//		std::cout << "������� ���� ��������\n";
//		for (int j  = 0; i < 2; i++)
//		{
//			std::cin >> student[i].inithial[j];
//		}		
//
//		std::cout << "������� ��� ���������\n";
//		std::cin >> student[i].G.facultet;
//
//		std::cout << "������� ����� ������ �����\n";
//		std::cin >> student[i].G.cours;
//		if (student[i].G.cours > 5 || student[i].G.cours < 0)
//		{
//			std::cout << "���������� ��������� ����! �� ����� ����������� ��������\n";
//			break;
//		}
//
//		std::cout << "������� �������� ����� ������\n";
//		std::cin >> student[i].G.name_group;
//
//		std::cout << "������� ����� ����� ������\n";
//		std::cin >> student[i].G.number_group;
//
//		for (int j = 0; j < 4; j++)
//		{
//			std::cout << "������� ���� ������ �� " << j + 1 << "��������\n";
//			std::cin >> student[i].ses[j];
//			if (student[i].ses[j] > 5 || student[i].ses[j] < 0)
//			{
//				std::cout << "���������� ��������� ����! �� ����� ����������� ��������\n";
//				break;
//			}			
//		}		
//	}
//}

//------------------------
//void Print(Stud *student, short n, float average)
//{
//	for (int i = 0; i < n; i++)
//	{
//		std::cout << "\n|-----------------------------------------------------------------|\n";
//		std::cout << "| ���: " << student[i].Name << " " << student[i].inithial[0] << ". " << student[i].inithial[1] << "." << "\n";
//		std::cout << "������: " << student[i].G.name_group << "\n";
//		std::cout << "���������: " << student[i].G.facultet << "\n";
//		std::cout << "����: " << student[i].G.cours << "\n";
//		std::cout << "����� ������: " << student[i].G.number_group << "\n";
//		std::cout << "������� ������: " << Ses(student, n, average) << "\n";
//	}	
//}
//--------------------------


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

		for (int j = 0; j < 4; j++)
		{
			student[i].ses[j] = 5;
		}		
	}

}

float Ses(Stud *student, short n, float average)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			average += student[i].ses[j];			
		}
		return (average / 4);
	}	
}

void sort(Stud *student, short n)
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(student[i].Name.c_str(), student[i+1].Name.c_str()) > 0)
		{
			std::swap(student[i], student[i + 1]);
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

	for (int i = 0; i < n; i++)
	{
		if (Ses(student, n, average) > 4.2)
		{
			sort(student, n);
			student[i].print();
		}
		else
		{
			std::cout << "��������� �� ������� ������� � 4,2 � ����, ����!\n";
			break;
		}
	}

	delete[] student;
	system("Pause");
	return 0;
}