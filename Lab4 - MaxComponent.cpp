//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//class Adjacency_list { // ----------------------------------- нрнапюфемхе хяундмнцн яохяйю ялефмнярх
//public:
//	vector<int> hookups;
//};
//struct ST { //----------------------------------------------- ярпсйрспю люяяхбнб ян яохяйнл йнлонмемрнб
//	vector<int> components;
//};
//bool BFS_end = false;
//bool Cheking(ST cp, int item) {
//	for (size_t i = 0; i < cp.components.size(); i++)
//	{
//		if (item == cp.components[i])
//		{
//			return false;
//		}
//	}
//	return true;
//}
//ST push_ST;
//void BFS(vector<Adjacency_list> matrix, int high, vector<ST>& comp) {
//
//	if (!count(push_ST.components.begin(), push_ST.components.end(), high))
//	{
//		push_ST.components.push_back(high);
//	}
//	for (size_t i = 0; i < matrix[high].hookups.size(); i++)
//	{
//		if (Cheking(push_ST, matrix[high].hookups[i]) && !count(push_ST.components.begin(), push_ST.components.end(), matrix[high].hookups[i]))
//		{
//			push_ST.components.push_back(matrix[high].hookups[i]);
//			BFS(matrix, matrix[high].hookups[i], comp);
//
//		}
//	}
//}
////######################################## оепебнд рейярнбнцн тнплюрю тюикю б хмрнбши ####################################
//int translate_into_class(vector<Adjacency_list>& Connections) {
//	ifstream csv("CSV_7lab.csv");
//	if (!csv.is_open())
//		cerr << "\nError!\n";
//
//	string sLine;
//	int i = 0;
//	while (getline(csv, sLine)) {
//		Adjacency_list line;
//		int g = sLine.size();
//		for (size_t j = 0; j < g; j += 2) {
//			int tr = (sLine[j] - '0');
//			line.hookups.push_back(tr);
//		}
//		Connections.push_back(line);
//		i++;
//	}
//	csv.close();
//	return i;
//}
////######################################## бшбнд хяундмнцн яохяйю ялефмнярх ##############################################
//void output_matrix(vector<Adjacency_list> countNodes, int count) {
//	for (size_t i = 0; i < count; i++)
//	{
//		cout << i << ": ";
//		for (size_t j = 0; j < countNodes[i].hookups.size(); j++)
//		{
//			cout << countNodes[i].hookups[j] << " ";
//		}
//		cout << endl;
//	}
//}
////######################################## MAIN ###########################################################################
//bool compare(ST a, ST b) {
//	return a.components.size() > b.components.size();
//}
//void delsort(vector<ST>& Connections) {
//	for (size_t i = 0; i < Connections.size(); i++)
//	{
//		sort(Connections[i].components.begin(), Connections[i].components.end());
//	}
//	sort(Connections.begin(), Connections.end(), compare);
//
//}
//bool HighCheking(vector<ST> comp, int high) {
//	for (size_t i = 0; i < comp.size(); i++)
//	{
//		if (count(comp[i].components.begin(), comp[i].components.end(), high))
//		{
//			return false;
//		}
//	}
//	return true;
//}
//void main() {
//	vector<Adjacency_list> Connections;
//	int count_connection = translate_into_class(Connections);
//	output_matrix(Connections, count_connection);
//	vector<ST> comp;
//	for (size_t i = 0; i < count_connection; i++)
//	{
//		if (HighCheking(comp, i))
//		{
//			BFS(Connections, i, comp);
//			comp.push_back(push_ST);
//			push_ST.components.clear();
//		}
//	}
//	cout << "################## OUTPUT ##################" << endl;
//	delsort(comp);
//	cout << "All connected components (largest is on top)" << endl;
//	for (size_t i = 0; i < comp.size(); i++)
//	{
//		for (size_t j = 0; j < comp[i].components.size(); j++)
//		{
//			cout << comp[i].components[j] << " ";
//		}
//		cout << endl;
//	}
//}