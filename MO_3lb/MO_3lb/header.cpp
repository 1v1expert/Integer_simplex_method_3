#include "description.h"
#include "stdio.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
//#include "main.cpp"

using std::cout;


void Print(char *file_name){
	cout.precision(2);
	//-----------
	
	//-------
		FILE *pF;
		char simv, simvPr[2];
		
		int n;
		int m;
		//-----------
		Ntree *tree = NULL;
		tree = new Ntree;
		//-----------
		pF = fopen(file_name, "r");
		simv = fgetc(pF);
			while (simv != '\n') // Считываем размерность матрицы
			{
				int k = 0;
				if ((simv != ' ') && (simv != '.') && (k==0)){simvPr[0] = simv; n = atoi(simvPr); ++k;};
				if ((simv != ' ') && (simv != '.') && (k==1)){simvPr[0] = simv; m = atoi(simvPr); ++k;};
			 simv = fgetc(pF);
			 }; 
		simv = fgetc(pF);
	

	tree->data = new double*[m + 1]; /*Создаем массив (m+1) x (n+1), т.к. кроме самих
	значений нужен столбец свободных членов и строка целевой функции*/
	
	for (int i = 0; i < m + 1; i++) {
		tree->data[i] = new double[n + 1];
	}

	//Считыаем вектор значений целевой функции из файла
		int j = 0;
		while ((simv != '\n') || (j < n)){
		if ((simv != ' ') && (simv != '.')) {
			simvPr[0] = simv; 
			tree->data[m][j + 1] = atoi(simvPr);
			++j;
		}
		simv = fgetc(pF);
		}
		j = 0;
		simv = fgetc(pF);

	//Считываем матрицу значений из файла
	
	int i = 0;
	while (i < m){
		while (simv != '\n'){
		if ((simv != ' ') && (simv != '.')) {
			simvPr[0] = simv; 
			tree->data[i][j + 1] = atoi(simvPr);
			++j;
		}
		simv = fgetc(pF);
		}
		++i;
		j = 0;
		simv = fgetc(pF);}
		tree->data[2][2] = 0.5;
		tree->data[2][3] = 2;
		
		
	//Считыаем вектор значений свободных членов

	i = 0;
	while ((simv != '\n') && (i < m)) {
		if ((simv != ' ') && (simv != '.')) 
		{
			simvPr[0] = simv; 
			tree->data[i][0] = atoi(simvPr);
			++i;
		};
		simv = fgetc(pF);
	};
	tree->data[m][0] = 0;
	
	
	
	fclose(pF);

	tree->free = new int[n]; //Свободные переменные
	for (int i = 0; i < n; i++) {
		tree->free[i] = i + 1;
	}

	tree->depended = new int[m]; //Базисные переменные
	for (int i = 0; i < m; i++) {
		tree->depended[i] = n + i + 1;
	};

	Solve(m, n, &(*tree));
	};
	//-----------------------------------------------------------------
	void atree(int m, int n, Ntree *tree)
	{
		system("pause");
		Ntree *ntree = NULL;
		ntree = new Ntree;
		Ntree *rtree = NULL;
		rtree = new Ntree;
			 int nm;
	for (int i = 0; i < 3; i++) 
	{
		int k ;
		double temp = 0;
		cout << "X" << i+1 << " = ";
		for (int j = 0; j < n; j++)
		{
				if (tree->free[j] == i + 1)
					cout << temp;
				if (tree->depended[j] == i + 1) 
				{
					temp = tree->data[j][0];
					k = j;
					cout << temp;
				}
		}
		if (temp != floor(temp))
		{
			 cout << " - дробное\n ";
			 
			 //nn = n + 1;
			 nm = m + 1;
			 
			 ntree->data = new double*[nm + 1];
			 rtree->data = new double*[nm + 1];/*Создаем массив (m+1) x (n+1), т.к. кроме самих
	значений нужен столбец свободных членов и строка целевой функции*/
	int l = 0;
	for (int i = 0; i < nm + 1; ++i){
		ntree->data[i] = new double[n + 1];
		rtree->data[i] = new double[n + 1];
	}
	//-------------
		
		for (int i = 0; i < m + 1; ++i)
		{
			l = i;
		for (int j = 0; j < n + 1; ++j)
		{
			if (l == m)
				l = i + 1;
			ntree->data[l][j] = tree->data[i][j];
			rtree->data[l][j] = tree->data[i][j];
		}
		}
		//--------------------------------
		ntree->data[nm-1][0] = floor(temp)-tree->data[k][0];
		for (int j = 1; j < n + 1; ++j)
			ntree->data[nm-1][j] = -tree->data[k][j];
		//--------------------------------
		
		ntree->depended = new int[nm];
		rtree->depended = new int[nm];//
	for (int i = 0; i < nm ; i++) 
		if (i < nm-1){
			ntree->depended[i] = tree->depended[i];
			rtree->depended[i] = tree->depended[i];
		}
		else
		{
			ntree->depended[i] = n+m+1;
			rtree->depended[i] = n+m+1;
		}
		ntree->free = new int[n]; 
		rtree->free = new int[n];
		for (int y = 0; y < n; y ++)
		{
			ntree->free[y] = tree->free[y];
			rtree->free[y] = tree->free[y];
		//	cout << "X" << ntree->free[y] << ' ';
		}
		
		cout << "\n--------left trees-------\n";
	Solve(nm, n, ntree);
	//--------------------------------
	system("pause");
	rtree->data[nm-1][0] = tree->data[k][0]-(floor(temp)+1);
		for (int j = 1; j < n + 1; ++j)
			rtree->data[nm-1][j] = tree->data[k][j];
		//--------------------------------
		cout << "\n---------right trees----------\n";
		Solve(nm, n, rtree);
		}
		else
		{
			cout << " - целое\n";
		}
//		
	}
		
	}
	//-----------------------------------------------------------------
void Solve(int m, int n, Ntree *tree) {
	//печать - проверка
		cout << "\n";
		cout << "     ";
		for (int y = 0; y < n; y ++)
			cout << "X" << tree->free[y] << ' ';
		cout << "\n" ;

	for (int q=0; q < m+1; ++q)
	{ 
		if (q < m)  
			cout << "X" << tree->depended[q] << ' ' ;

			for (int p=0; p < n+1; ++p)
				cout << tree->data[q][p] << ' ';
			cout << ' ' <<  "\n";
	}

	cout << "\n";
	int itr = 1;
	bool is_solve = true;
	//Поиск опорного решения
	int iter = 1;
	bool loop = true;
	cout << "Поиск опорного решения\n";
	while (loop) {
		loop = false;

		// Поиск i0 строки, с отрицательным значением (недопустимое решение)
		for (int i0 = 0; i0 < m; i0++) {
			if (tree->data[i0][0] < 0) {
				int k = 0;
				// Поиск k столбца, с первым отрицательным элементом (разрешающий столбец)
				for (int j = 1; j < n + 1 && !k; j++) { 
					if (tree->data[i0][j] < 0) {
						k = j;
					}
				}
				if (k) {
					loop = true;
					float min = FLT_MAX;
					int r = 0;
					// Поиск r строки, 
					for (int i = 0; i < m; i++) { 
						if (tree->data[i][0] / tree->data[i][k] < min && tree->data[i][0] / tree->data[i][k] > 0) {
							r = i;
							min = tree->data[i][0] / tree->data[i][k];
						}
					}
					swap(r, k, m, n, &(*tree));
					break;
				}
				else {
					std::cout << "Нет решения\n";
					is_solve = false;
				}
			}
		}
		if (!loop) break;
		cout << "\n" << iter++ << " Итерация\n" << "\n";

		//печать - проверка
		cout << "     ";
		for (int y = 0; y < n; y ++)
			cout << "X" << tree->free[y] << ' ';
		cout << "\n" ;

	for (int q=0; q < m+1; ++q)
	{ 
		if (q < m)  
			cout << "X" << tree->depended[q] << ' ' ;

			for (int p=0; p < n+1; ++p)
				cout << tree->data[q][p] << ' ';
			cout << ' ' <<  "\n";
	}
	}

	//Поиск оптимального решения
	loop = true;
	iter = 1;
	cout << "Поиск оптимального решения\n";
	while (loop) {
		loop = false;
		int r = 0, k = 0;
		for (int j = 1; j < n + 1; j++) { //поиск k столбца
			if (tree->data[m][j] > 0)  {
				k = j;
				float minimum = FLT_MAX;
				for (int i = 0; i < 3; i++) { //поиск r строки
					if (tree->data[i][j] > 0 && tree->data[i][0] / tree->data[i][k] < minimum) {
						r = i;
						minimum = tree->data[i][0] / tree->data[i][k];
					}
				}

				if (minimum < FLT_MAX) {
					loop = true;
					swap(r, k, m, n, &(*tree));
					break;
				}
				else {
					is_solve = false;
					break;
				}
			}
		}
		if (!loop) break;
		cout << "\n" << iter++ << " Итерация\n" << "\n";
		//печать - проверка
		cout << "     ";
		for (int y = 0; y < n; y ++)
			cout << "X" << tree->free[y] << ' ';
		cout << "\n" ;

	for (int q=0; q < m+1; ++q)
	{ 
		if (q < m)  
			cout << "X" << tree->depended[q] << ' ' ;

			for (int p=0; p < n+1; ++p)
				cout << tree->data[q][p] << ' ';
			cout << ' ' <<  "\n";
	}
	cout << "\n";
	}

	//Вывод результата
	if (!is_solve) cout << "Нет решения\n";
	else {
		for (int i = 0; i < 3; i++) 
		{
			cout << "X" << i + 1 << " = ";
			for (int j = 0; j < n; j++) {
				if (tree->free[j] == i + 1) {
					cout << "0\n";
				}
				if (tree->depended[j] == i + 1) {
					cout << tree->data[j][0] << "\n";
				}
			}
		}
		std::cout << "F  = " << -tree->data[m][0] << "\n";
		std::cout << " --------------------- " << "\n";
		atree(m, n, tree);
	}

};

void swap(int r, int k, int m, int n, Ntree *tree) {

	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (i != r && j != k) {
				tree->data[i][j] = tree->data[i][j] - tree->data[i][k] * tree->data[r][j] / tree->data[r][k];
			}
		}
	}

	for (int i = 0; i < m + 1; i++) {
		if (i != r) {
			tree->data[i][k] = -tree->data[i][k] / tree->data[r][k];
		}
	}

	for (int j = 0; j < n + 1; j++) {
		if (j != k) {
			tree->data[r][j] = tree->data[r][j] / tree->data[r][k];
		}
	}

	tree->data[r][k] = 1.0 / tree->data[r][k];

	int i = tree->free[k - 1];
	tree->free[k - 1] = tree->depended[r];
	tree->depended[r] = i;
};