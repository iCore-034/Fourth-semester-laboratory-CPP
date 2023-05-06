//// Программа реализует парсинг данных файла формата csv в массив структур Node
//// 
//#include<iostream>
//#include<vector>
//#include <fstream>
//#include<algorithm>
//#include <string>
//#include <time.h>
//using namespace std;
//
//struct Node // Сохранить график как структуру данных
//{
//	int start;
//	int end;
//	int length;
//};
////############################################ TRANSLATION ############################################
//int Node_translation(vector<Node>& arr) {
//	//srand(time(NULL));
//	ifstream csv("CSV.csv");
//	if (!csv.is_open())
//	{
//		cerr << "\nError!\n";
//	}
//	string sLine;
//	int i = 0;
//	try
//	{
//		while (getline(csv, sLine))
//		{
//			Node temp;
//			for (size_t j = 0; j < sLine.size(); j += 2)
//			{
//				if (j != i) // ---------------------------------------- Ограничение: Если вершина приходит в саму себя - игнорируем (упрощение)
//				{
//					temp.start = i;
//					temp.end = sLine[j] - '0';
//					temp.length = rand() % 8 + 1;
//					arr.push_back(temp);
//				}
//			}
//			i++;
//		}
//	}
//	catch (const std::exception&) {}
//
//	csv.close();
//	return i;
//}
////############################################ KRUSKAL ############################################### 
//bool compare(Node a, Node b)
//{
//	return a.length < b.length;
//}
//void Kruskal(vector<Node>& arr, vector<bool>& visited)
//{
//	int M, N;
//	visited.resize(arr.size());
//	sort(arr.begin(), arr.end(), compare);
//	for (int i = 0; i < arr.size(); i++)
//	{
//		cout << i << " ------- ";
//		cout << arr[i].start << ": " << arr[i].length << "(length)" << ", " << arr[i].end << "(end)" << endl;
//	}
//	int weight = 0;
//	for (int i = 0; i < arr.size(); i++)
//	{
//		if (!visited[arr[i].start] || !visited[arr[i].end])
//		{
//			weight += arr[i].length;
//			visited[arr[i].start] = true;
//			visited[arr[i].end] = true;
//		}
//	}
//	cout << "Minimal weight of connected tree:";
//	cout << weight << endl;
//}
////############################################ MAIN ################################################# 
//int main()
//{
//	vector<Node> arr;
//	int count_lines = Node_translation(arr);
//	vector<bool> visited;
//	Kruskal(arr, visited);
//}