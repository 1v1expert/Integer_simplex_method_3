#pragma once
#include <iostream>
#include <string>
struct Ntree //Звено дерева
	{
		Ntree *left,*right; //Указатели на новые звенья
		//int x; //Ключ звена
		double **data;
		int *free;
		int *depended;
		int n, m;
	};
void Print(char *file_name);
void swap(int r, int k,int m, int n, Ntree *tree);
void Solve(int m, int n, Ntree *tree);
void atree(int m, int n, Ntree *tree);
