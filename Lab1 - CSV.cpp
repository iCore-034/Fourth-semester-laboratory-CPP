///*
//����������� ��������� �� ����� �������� ������, ����������� ��������� ��������� ������ � ������ ����������.
//��������� ������ ������������ ������������� ����� � ���� ������� ��������� � ���������� ���� ������� � ������� CSV
//*/
//
//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <time.h>
//#include <math.h>
//using namespace std;
//class Con {
//public:
//	vector<int> hookups;
//};
////##################################################################################### ��������� ������ ����� ���� � ������
//void set_connections(vector<Con> &countNodes, int net) {
//
//	for (size_t i = 0; i < net; i++)
//	{
//		for (size_t j = 0; j < net; j++)
//		{
//			int randbool = rand() % 25;
//			if (randbool == 0)
//			{
//				countNodes[i].hookups.push_back(j);
//			}
//		}
//	}
//}
// //#########################################################################################################################
//
// //################################################################################################# ����������������� �����
//void output_matrix(vector<Con> countNodes, int net) {
//	for (size_t i = 0; i < net; i++)
//	{
//		cout << i << ": ";
//		for (size_t j = 0; j < countNodes[i].hookups.size(); j++)
//		{
//			cout << countNodes[i].hookups[j] << " ";
//		}
//		cout << endl;
//	}
//}
//// #########################################################################################################################
//
//// ################################################################################################ ����� � ���� ������� CVS
//void file_output(vector<Con> countNodes, int net) {
//
//	ofstream csv;
//	csv.open("CSV_7lab.csv");
//	for (size_t i = 0; i < net; i++)
//	{
//		for (size_t j = 0; j < countNodes[i].hookups.size(); j++)
//		{
//			csv << countNodes[i].hookups[j] << ";";
//		}
//		csv << endl;
//	}
//	csv.close();
//}
// //#########################################################################################################################
//void main() {
//	srand(time(NULL));
//	
//	int net = 50;//rand() % 5 + 3; // ----------------------------------------------------------------------------- ���������� �����
//	Con Node;
//	vector<Con> countNodes(net); //__________________________________ ������ ����� � ������� ������ � ����� � ������� ������
//	
//	set_connections(countNodes, net);
//	cout << "###################### Adjacency matrix ######################" << endl;
//	output_matrix(countNodes, net);
//	file_output(countNodes, net);
//	cout << "###### File with .cvs-format was successfully created! ######" << endl;
//}