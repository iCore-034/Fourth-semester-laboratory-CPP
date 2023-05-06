//#include <iostream>
//#include <vector>
//#include <string>
//#include <fstream>
//#include <time.h>
//#include <math.h>
//using namespace std;
//
//
//class nodes {
//public:
//	pair<int, int> from_to;
//	int s;
//};
//// ########################################## output adj list + add a weingh of way ########################################## 
//int outr(vector<nodes>& nd) {
//	srand(time(NULL));
//	ifstream csv("csv_7lab.csv");
//	if (!csv.is_open())
//	{
//		cerr << "\nerror!\n";
//		exit(0);
//	}
//	string sline;
//	int i = 0;
//
//	while (getline(csv, sline))
//	{
//		cout << i << ": " << sline << endl;
//		nodes temp;
//		for (size_t j = 0; j < sline.size(); j++)
//		{
//			if (sline[j] != ';')
//			{
//				temp.from_to.first = i;
//				//-------------------------
//				int k = 0;
//				bool bl = false;
//				temp.from_to.second = 0;
//				while (sline[j + k] != ';')
//				{
//					temp.from_to.second *= 10 * bl;
//					temp.from_to.second += int(sline[j + k] - '0');
//					bl = true;
//					k++;
//				}
//				j += k;
//				//-------------------------
//				temp.s = rand() % 10;
//				nd.push_back(temp);
//			}
//		}
//		i++;
//	}
//	csv.close();
//	return i;
//
//}
//vector<int> blocked; // --------------- visited vertex
//bool check_blocked(int pos) {
//	for (size_t i = 0; i < blocked.size(); i++)
//	{
//		if (pos == blocked[i])
//		{
//			return false;
//		}
//	}
//	return true;
//}
//// ########################################## dfs ############################################################################ 
//int weight = 0;
//void dfs(vector<nodes> nd, int start, int end) {
//	blocked.push_back(start);
//	for (size_t i = 0; i < nd.size(); i++)
//	{
//		if (nd[i].from_to.first == start)
//		{
//			if (check_blocked(nd[i].from_to.second))
//			{
//
//				if (nd[i].from_to.second != end)
//				{
//					weight += nd[i].s;
//					dfs(nd, nd[i].from_to.second, end);
//					weight -= nd[i].s;
//				}
//				else
//				{
//					cout << "        weight = " << weight + nd[i].s << "       " << blocked[0] << "--->";
//					for (size_t m = 1; m < blocked.size(); m++)
//					{
//						cout << "-" << blocked[m];
//					}
//					cout << "-->" << end << endl;
//				}
//			}
//		}
//	}
//	blocked.pop_back();
//}
//// ########################################## MAIN #########################################################################
//void main() {
//	vector<nodes> nd;
//	int countv = outr(nd);
//here:
//	cout << "###################################################################" << endl;
//	cout << "input start position: ";
//	int start = 0;
//	cin >> start;
//	cout << "input end position: ";
//	int end = 0;
//	cin >> end;
//	if ((start > countv || end > countv) || (start < 0 || end < 0))
//	{
//		cerr << "\nerror!\n";
//		exit(0);
//	}
//	dfs(nd, start, end);
//	cout << "###### Do you want to try again with another vertexes?(y/n) ######" << endl;
//	char t;
//	cin >> t;
//	if (t == 'y')
//	{
//		goto here;
//	}
//}