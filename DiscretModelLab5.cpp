#include <conio.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <string.h>
#include <Windows.h>
using namespace std;

const int N = 5;

int graph1[N][N];
int graph2[N][N];

int K[N] = { 0,1,2,3,4 };

bool graph_isomorph() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (graph1[i][j] != graph2[K[i]][K[j]])
				return false;
	return true;
}

int read_graph1(int graph1[N][N]) {
	char line[2];
	ifstream in("l5-1.txt");
	if (in.is_open())
	{
		in.getline(line, 2);
		printf("Матриця графа 1: \n");
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				in >> graph1[i][j];

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
				cout << graph1[i][j] << "\t";
			cout << "\n";
		}

		in.close();
		printf("\n");
		return **graph1;
	}
	else
	{
		cout << "!Помилка читання файла!";
		return 0;
	}
}

int read_graph2(int graph2[N][N]) {
	char line[2];
	ifstream in("l5-2.txt");
	if (in.is_open())
	{
		in.getline(line, 2);
		printf("Матриця графа 2: \n");
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				in >> graph2[i][j];

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
				cout << graph2[i][j] << "\t";
			cout << "\n";
		}

		in.close();
		printf("\n");
		return **graph2;
	}
	else
	{
		cout << "!Помилка читання файла!";
		return 0;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	read_graph1(graph1);
	read_graph2(graph2);
	do {
		if (graph_isomorph()) {
			printf("Задані графи ізоморфні\n");
			printf("Відповідні вершини графів:\n");
			for (int i = 0; i < N; i++)
				printf("%d - %d\n", i + 1, K[i] + 1);
			return 0;
		}		
	} while (next_permutation(K, K + N));

}
