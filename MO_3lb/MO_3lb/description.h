#pragma once
#include <iostream>
#include <string>
struct Ntree //����� ������
	{
		Ntree *left,*right; //��������� �� ����� ������
		//int x; //���� �����
		double **data;
		int *free;
		int *depended;
		int n, m;
	};
void Print(char *file_name);
void swap(int r, int k,int m, int n, Ntree *tree);
void Solve(int m, int n, Ntree *tree);
void atree(int m, int n, Ntree *tree);
