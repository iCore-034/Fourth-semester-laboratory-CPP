#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Adjacency_list {
public:
	vector<int> hookups;
};
bool check_ex(vector<int>blocked, int position) {
	for (size_t i = 0; i < blocked.size(); i++)
	{
		if (position == blocked[i])
		{
			return false;
		}
	}
	return true;
}
//######################################### ĞÅÊÓĞÑÈÂÍÛÉ ÀËÃÎĞÈÒÌ ÏÎÈÑÊÀ (DFS) ###########################################  
bool DFS_end = false;
bool DFS(vector<Adjacency_list> matrix, vector<int> blocked, int entry, int end, vector<int>& st) {
	blocked.push_back(entry);
	for (size_t i = 0; i < matrix[entry].hookups.size(); i++)
	{
		if (matrix[entry].hookups[i] != end)
		{
			if (check_ex(blocked, matrix[entry].hookups[i]))
			{
				st.push_back(matrix[entry].hookups[i]);
				DFS(matrix, blocked, matrix[entry].hookups[i], end, st);
				if (DFS_end)
				{
					return true;
				}
			}
		}
		else
		{
			DFS_end = true;
			return true;
		}
	}
	return false;
}
//######################################### ĞÅÊÓĞÑÈÂÍÛÉ ÀËÃÎĞÈÒÌ ÏÎÈÑÊÀ (BFS) ###########################################  

bool BFS(vector<Adjacency_list> matrix, int entry, int end, vector<int>& st, vector<int> blocked) {
	blocked.push_back(entry);
	if (count(matrix[entry].hookups.begin(), matrix[entry].hookups.end(), end))
	{
		DFS_end = true;
		return true;
	}
	else
	{
		for (size_t i = 0; i < matrix[entry].hookups.size(); i++)
		{
			if (check_ex(blocked, matrix[entry].hookups[i]))
			{
				st.push_back(matrix[entry].hookups[i]);
				BFS(matrix, matrix[entry].hookups[i], end, st, blocked);
				if (DFS_end)
				{
					return true;
				}
			}
		}
	}
	return false;
}
//######################################## ÏÅĞÅÂÎÄ ÒÅÊÑÒÎÂÎÃÎ ÔÎĞÌÀÒÀ ÔÀÉËÀ Â ÈÍÒÎÂÛÉ ####################################
int translate_into_class(vector<Adjacency_list>& Connections) {
	ifstream csv("CSV_7lab.csv");
	if (!csv.is_open())
	{
		cerr << "\nError!\n";
	}
	string sLine;
	int i = 0;
	try
	{
		while (getline(csv, sLine))
		{
			Adjacency_list line;
			int g = sLine.size();
			for (size_t j = 0; j < g; j += 2)
			{
				int tr = (sLine[j] - '0');
				line.hookups.push_back(tr);
			}
			Connections.push_back(line);
			i++;
		}
	}
	catch (const std::exception&) {}

	csv.close();
	return i;
}
//######################################## ÂÛÂÎÄ ÈÑÕÎÄÍÎÃÎ ÑÏÈÑÊÀ ÑÌÅÆÍÎÑÒÈ ##############################################
void output_matrix(vector<Adjacency_list> countNodes, int count) {
	for (size_t i = 0; i < count; i++)
	{
		cout << i << ": ";
		for (size_t j = 0; j < countNodes[i].hookups.size(); j++)
		{
			cout << countNodes[i].hookups[j] << " ";
		}
		cout << endl;
	}
}
//######################################## MAIN ###########################################################################
void output(vector<int> st, int entry, int end) {
	cout << "Subsequence: ";
	for (size_t i = 0; i < st.size(); i++)
	{
		cout << st[i] << " ";
	}
	cout << "-> " << end << endl;

}
void main() {
	vector<Adjacency_list> Connections;
	int entry, end;

	int count_connection = translate_into_class(Connections);
	output_matrix(Connections, count_connection);
	//__________________________________________________ Äàííûå äëÿ ïîëüçîâàòåëÿ
again:
	cout << "\nInput entry point: ";
	cin >> entry;
	cout << "\nInput end point: ";
	cin >> end;
	if (entry >= count_connection || end >= count_connection || entry < 0 || end < 0)
	{
		cerr << "\nError data!\n";
		goto again;
	}
	cout << " \n";
	//__________________________________________________ Ïîèñê DFS
	vector<int> blocked;
	vector<int> st;
	cout << "########################## DFS-algorithm ##########################" << endl;
	st.push_back(entry);
	if (DFS(Connections, blocked, entry, end, st)) {
		cout << "The way from " << entry << " to " << end << " exists" << endl;
		cout << "Subsequence: ";
		output(st, entry, end);
	}
	else
	{
		cout << "There is no way" << endl;
	}
	cout << "########################## BFS-algorithm ##########################" << endl;
	st.clear();
	st.push_back(entry);
	DFS_end = false;
	if (BFS(Connections, entry, end, st, blocked)) {
		cout << "The way exists" << endl;
		output(st, entry, end);
	}
	else
	{
		cout << "The way isn't exist" << endl;
	}
	cout << "###################################################################" << endl;
}