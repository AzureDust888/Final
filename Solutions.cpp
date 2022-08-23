#pragma once
#include "Library.cpp"
void cinX(char**& tmp, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
		point:cout << "Enter matric element[" << i << "][" << j << "] ";
			tmp[i][j] = _getch();
			if (tmp[i][j] == 13)
			{
				cout << "Error, try again" << endl;
				goto point;
			}
			cout << tmp[i][j];
			cout << "\n";
		}
	}
}
void cinX(float &f, string s, char nul) {

	char mas[40];
	int k = 0;
	int m = 0;
	int p = 0;
ret3:cout << s;
	gets_s(mas);
	k = 0;
	m = 0;
	p = 0;
	for (int i = 0; i < strlen(mas); i++)
	{
		if (nul == '+')
		{
			if (isdigit(mas[i]) || mas[i] == '.')
			{
				k++;
				if (mas[i] == '.')
				{
					p++;
				}
			}
		}
		else if(nul == '-')
		{
			if (isdigit(mas[i]) || mas[i] == '.' || mas[i] == '-')
			{
				if (mas[i] == '-')
				{
					m++;
				}
				if (mas[i] == '.')
				{
					p++;
				}
				k++;
			}
		}
		else if(nul == 'o')
		{
			if (isdigit(mas[i]) || mas[i] == '.')
			{
				k++;
				if (mas[i] == '.')
				{
					p++;
				}
			}
		}
	}
	if (k != strlen(mas) || k == 0 || m > 1 || p > 1)
	{
		cout << "Error, try again." << endl;
		system("pause");
		system("cls");
		goto ret3;
	}
	else
	{
		f = atof(mas);
		if (nul == '+')
		{
			if (f == 0 || mas[0] == '.')
			{
				cout << "Error, try again." << endl;
				system("pause");
				system("cls");
				goto ret3;
			}
		}
		else if(nul == '-')
		{
			if (strlen(mas) == 1)
			{
				if (mas[0] == '.' || mas[0] == '-')
				{
					cout << "Error, try again." << endl;
					system("pause");
					system("cls");
					goto ret3;
				}
			}
		}
		else if (nul == 'o')
		{
			if (mas[0] == '.')
			{
				cout << "Error, try again." << endl;
				system("pause");
				system("cls");
				goto ret3;
			}
		}
	}
}
void cinX(unsigned int& f, string s, char nul) {

	char mas[40];
	int k = 0;
	int m = 0;
	int p = 0;
ret3:cout << s;
	gets_s(mas);
	k = 0;
	m = 0;
	p = 0;
	for (int i = 0; i < strlen(mas); i++)
	{
		if (nul == '+')
		{
			if (isdigit(mas[i]) || mas[i] == '.')
			{
				k++;
				if (mas[i] == '.')
				{
					p++;
				}
			}
		}
		else if (nul == '-')
		{
			if (isdigit(mas[i]) || mas[i] == '.' || mas[i] == '-')
			{
				if (mas[i] == '-')
				{
					m++;
				}
				if (mas[i] == '.')
				{
					p++;
				}
				k++;
			}
		}
		else if (nul == 'o')
		{
			if (isdigit(mas[i]) || mas[i] == '.')
			{
				k++;
				if (mas[i] == '.')
				{
					p++;
				}
			}
		}
	}
	if (k != strlen(mas) || k == 0 || m > 1 || p > 1)
	{
		cout << "Error, try again." << endl;
		system("pause");
		system("cls");
		goto ret3;
	}
	else
	{
		f = atoi(mas);
		if (nul == '+')
		{
			if (f == 0 || mas[0] == '.')
			{
				cout << "Error, try again." << endl;
				system("pause");
				system("cls");
				goto ret3;
			}
		}
		else if (nul == '-')
		{
			if (strlen(mas) == 1)
			{
				if (mas[0] == '.' || mas[0] == '-')
				{
					cout << "Error, try again." << endl;
					system("pause");
					system("cls");
					goto ret3;
				}
			}
		}
		else if (nul == 'o')
		{
			if (mas[0] == '.')
			{
				cout << "Error, try again." << endl;
				system("pause");
				system("cls");
				goto ret3;
			}
		}
	}
}
void cinX(double &f, string s, char nul) {

	char mas[40];
	int k = 0;
	int m = 0;
	int p = 0;
ret3:cout << s;
	gets_s(mas);
	k = 0;
	m = 0;
	p = 0;
	for (int i = 0; i < strlen(mas); i++)
	{
		if (nul == '+')
		{
			if (isdigit(mas[i]) || mas[i] == '.')
			{
				k++;
				if (mas[i] == '.')
				{
					p++;
				}
			}
		}
		else if (nul == '-')
		{
			if (isdigit(mas[i]) || mas[i] == '.' || mas[i] == '-')
			{
				if (mas[i] == '-')
				{
					m++;
				}
				if (mas[i] == '.')
				{
					p++;
				}
				k++;
			}
		}
		else if (nul == 'o')
		{
			if (isdigit(mas[i]) || mas[i] == '.')
			{
				k++;
				if (mas[i] == '.')
				{
					p++;
				}
			}
		}
	}
	if (k != strlen(mas) || k == 0 || m > 1 || p > 1)
	{
		cout << "Error, try again." << endl;
		system("pause");
		system("cls");
		goto ret3;
	}
	else
	{
		f = atof(mas);
		if (nul == '+')
		{
			if (f == 0 || mas[0] == '.')
			{
				cout << "Error, try again." << endl;
				system("pause");
				system("cls");
				goto ret3;
			}
		}
		else if (nul == '-')
		{
			if (strlen(mas) == 1)
			{
				if (mas[0] == '.' || mas[0] == '-')
				{
					cout << "Error, try again." << endl;
					system("pause");
					system("cls");
					goto ret3;
				}
			}
		}
		else if (nul == 'o')
		{
			if (mas[0] == '.')
			{
				cout << "Error, try again." << endl;
				system("pause");
				system("cls");
				goto ret3;
			}
		}
	}
}
void cinX(int& f, string s, char nul) {

	char mas[40];
	int k = 0;
	int m = 0;
ret3:cout << s;
	gets_s(mas);
	k = 0;
	m = 0;
	for (int i = 0; i < strlen(mas); i++)
	{
		if (nul == '+')
		{
			if (isdigit(mas[i]))
			{
				k++;
			}
		}
		else if (nul == '-')
		{
			if (isdigit(mas[i]) || mas[i] == '-')
			{
				if (mas[i] == '-')
				{
					m++;
				}
				k++;
			}
		}
		else if (nul == 'o')
		{
			if (isdigit(mas[i]))
			{
				k++;
			}
		}
	}
	if (k != strlen(mas) || k == 0 || m > 1)
	{
		cout << "Error, try again." << endl;
		system("pause");
		system("cls");
		goto ret3;
	}
	else
	{
		f = atoi(mas);
		if (nul == '+')
		{
			if (f == 0)
			{
				cout << "Error, try again." << endl;
				system("pause");
				system("cls");
				goto ret3;
			}
		}
		else if(nul == '-')
		{
			if (strlen(mas) == 1)
			{
				if (mas[0] == '-')
				{
					cout << "Error, try again." << endl;
					system("pause");
					system("cls");
					goto ret3;
				}
			}
		}
		else if (nul == 'o')
		{
		}
	}
}
void cinX(char& tmp, string s)
{
	WER:cout << s;
	tmp = _getch();
	if (tmp == 13)
	{
		system("cls");
		cout << "Error! Try again" << endl;
		system("pause");
		system("cls");
		goto WER;
	}
		
	cout << tmp << endl;
}
void cinX(char*& tmp, string s)
{
	int k = 0;
	char mas[50];
ret2:cout << s;
	gets_s(mas);
	k = 0;
	for (int i = 0; i < strlen(mas); i++)
	{
		if (isalpha(mas[i]) || mas[i] == ' ')
		{
			k++;
		}
	}
	if (k != strlen(mas) || k == 0)
	{
		cout << "Error, try again." << endl;
		system("pause");
		system("cls");
		goto ret2;
	}
	else
	{
		tmp = new char[strlen(mas)];
		strcpy(tmp, mas);
	}
}
void cinX(string& tmp, string s)
{
	int k = 0;
ret2:cout << s;
	getline(cin, tmp);
	k = 0;
	for (int i = 0; i < tmp.length(); i++)
	{
		if (isalpha(tmp[i]) || tmp[i] == ' ')
		{
			k++;
		}
	}
	if (k != tmp.length() || k == 0)
	{
		cout << "Error, try again." << endl;
		system("pause");
		system("cls");
		goto ret2;
	}
}
void cinX(string*& tmp, string s)
{
	int k = 0;
	string mas;
ret2:cout << s;
	getline(cin, mas);
	k = 0;
	for (int i = 0; i < mas.length(); i++)
	{
		if (isalpha(mas[i]) || mas[i] == ' ')
		{
			k++;
		}
	}
	if (k != mas.length() || k == 0)
	{
		cout << "Error, try again." << endl;
		system("pause");
		system("cls");
		goto ret2;
	}
	else
	{
		tmp = new string[mas.length()];
		*tmp = mas;
	}
}
void b_sort(char mas[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= i; j--)
		{
			if (mas[j - 1] > mas[j])
			{
				char t = mas[j - 1];
				mas[j - 1] = mas[j];
				mas[j] = t;
			}
		}
	}
}
void b_sort(int mas[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= i; j--)
		{
			if (mas[j - 1] > mas[j])
			{
				char t = mas[j - 1];
				mas[j - 1] = mas[j];
				mas[j] = t;
			}
		}
	}
}
void b_sort(double mas[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= i; j--)
		{
			if (mas[j - 1] > mas[j])
			{
				char t = mas[j - 1];
				mas[j - 1] = mas[j];
				mas[j] = t;
			}
		}
	}
}
void b_sort(float mas[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= i; j--)
		{
			if (mas[j - 1] > mas[j])
			{
				char t = mas[j - 1];
				mas[j - 1] = mas[j];
				mas[j] = t;
			}
		}
	}
}
void Create2D(int**& mas, int n, int m)
{
	mas = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		mas[i] = (int*)malloc(m * sizeof(int));
	}
}
void Rand(int** mas, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mas[i][j] = rand() % 25;
		}
	}
}
void Print(int** mas, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << mas[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
}
void Create2D(double**& mas, int n, int m)
{
	mas = (double**)malloc(n * sizeof(double*));
	for (int i = 0; i < n; i++)
	{
		mas[i] = (double*)malloc(m * sizeof(double));
	}
}
void Rand(double** mas, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mas[i][j] = rand() % 25 * 0.01;
		}
	}
}
void Print(double** mas, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << mas[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
}
void Create2D(char**& mas, int n, int m)
{
	mas = (char**)malloc(n * sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		mas[i] = (char*)malloc(m * sizeof(char));
	}
}
void Rand(char** mas, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mas[i][j] = 65 + rand() % 26;
		}
	}
}
void Print(char** mas, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << mas[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
}
void Create2D(float**& mas, int n, int m)
{
	mas = (float**)malloc(n * sizeof(float*));
	for (int i = 0; i < n; i++)
	{
		mas[i] = (float*)malloc(m * sizeof(float));
	}
}
void Rand(float** mas, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mas[i][j] = rand() % 25 * 0.1;
		}
	}
}
void Print(float** mas, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << mas[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
}
void Delete2D(int** mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		free(mas[i]);
	}
	free(mas);
}
void Delete2D(double** mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		free(mas[i]);
	}
	free(mas);
}
void Delete2D(char** mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		free(mas[i]);
	}
	free(mas);
}
void Delete2D(float** mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		free(mas[i]);
	}
	free(mas);
}
void cinX(int**& tmp, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cinX(tmp[i][j], "Enter matric element -> ", '-');
		}
	}
}
void cinX(double**& tmp, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cinX(tmp[i][j], "Enter matric element -> ", '-');
		}
	}
}
void cinX(float**& tmp, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cinX(tmp[i][j], "Enter matric element -> ", '-');
		}
	}
}
void Help()
{
	cout << "void cinX(float& f, string s, char nul);//use to cin float digit || nul == + -> f > 0 || nul == - -> f <= 0;\n\nvoid cinX(int& f, string s, char nul);//use to cin int digit || nul == + -> f > 0 || nul == - -> f <= 0;\n\nvoid cinX(char tmp[], string s);//use to cin strings wich includeing only leters;\n\nvoid b_sort(char mas[], int n);//use to sort char mas;\n\nvoid b_sort(int mas[], int n);//use to sort int mas;\n\nvoid b_sort(double mas[], int n);//use to sort double mas;\n\nvoid b_sort(float mas[], int n);//use to sort float mas;\n\nvoid Create2D(int**& mas, int n, int m);//use to create **int mas;\n\nvoid Rand(int** mas, int n, int m);//use to randomise **int mas;\n\nvoid Print(int** mas, int n, int m);//use to print **int mas;\n\nvoid Create2D(double**& mas, int n, int m);//use to create **double mas;\n\nvoid Rand(double** mas, int n, int m);//use to randomise **double mas;\n\nvoid Print(double** mas, int n, int m);//use to print **double mas;\n\nvoid Create2D(char**& mas, int n, int m);//use to create **char mas;\n\nvoid Rand(char** mas, int n, int m);//use to randomise **char mas;\n\nvoid Print(char** mas, int n, int m);//use to print **char mas;\n\nvoid Create2D(float**& mas, int n, int m);//use to create **float mas;\n\nvoid Rand(float** mas, int n, int m);//use to randomise **float mas;\n\nvoid Print(float** mas, int n, int m);//use to print **float mas;\n\nvoid Delete2D(int** mas, int n);//use to delete **int mas;\n\nvoid Delete2D(double** mas, int n);//use to delete **double mas;\n\nvoid Delete2D(char** mas, int n);//use to delete **char mas;\n\nvoid Delete2D(float** mas, int n);//use to delete **float mas;\n\nvoid Help();//Shows information about all functions;" << endl;
}