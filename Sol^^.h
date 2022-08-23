#pragma once
#include "Lib.cpp"
void cinX(float& f, string s, char nul);//use to cin float digit || nul == + -> f > 0 || nul == - -> f = (-inf; inf);
void cinX(int& f, string s, char nul);//use to cin int digit || nul == + -> f > 0 || nul == - -> f = (-inf; inf);
void cinX(double& f, string s, char nul);//use to cin double digit
void cinX(unsigned int& f, string s, char nul);//use to cin unsigned int digit || nul == + -> f > 0 || nul == - -> f = (-inf; inf);
void cinX(char*& tmp, string s);//use to cin strings wich includeing only leters;
void cinX(char& tmp, string s);//use to cin strings wich includeing only leters;
void cinX(char**& tmp, int n, int m);//use to cin matric elements(char);
void cinX(float**& tmp, int n, int m);//use to cin matric elements(float);
void cinX(int**& tmp, int n, int m);//use to cin matric elements(int);
void cinX(double**& tmp, int n, int m);//use to cin matric elements(double);
void cinX(string& tmp, string s);//use to cin strings wich includeing only leters;
void cinX(string*& tmp, string s);//use to cin strings wich includeing only leters;
void b_sort(char mas[], int n);//use to sort char mas;
void b_sort(int mas[], int n);//use to sort int mas;
void b_sort(double mas[], int n);//use to sort double mas;
void b_sort(float mas[], int n);//use to sort float mas;
void Create2D(int**& mas, int n, int m);//use to create **int mas;
void Rand(int** mas, int n, int m);//use to randomise **int mas;
void Print(int** mas, int n, int m);//use to print **int mas;
void Create2D(double**& mas, int n, int m);//use to create **double mas;
void Rand(double** mas, int n, int m);//use to randomise **double mas;
void Print(double** mas, int n, int m);//use to print **double mas;
void Create2D(char**& mas, int n, int m);//use to create **char mas;
void Rand(char** mas, int n, int m);//use to randomise **char mas;
void Print(char** mas, int n, int m);//use to print **char mas;
void Create2D(float**& mas, int n, int m);//use to create **float mas;
void Rand(float** mas, int n, int m);//use to randomise **float mas;
void Print(float** mas, int n, int m);//use to print **float mas;
void Delete2D(int** mas, int n);//use to delete **int mas;
void Delete2D(double** mas, int n);//use to delete **double mas;
void Delete2D(char** mas, int n);//use to delete **char mas;
void Delete2D(float** mas, int n);//use to delete **float mas;
void Help();//Shows information about all functions;
