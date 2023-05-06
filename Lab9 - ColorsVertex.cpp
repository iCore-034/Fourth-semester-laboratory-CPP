//#include <iostream>
//#include <vector>
//#include <string>
//#include <fstream>
//#include <time.h>
//#include <math.h>
//#include <algorithm>
//using namespace std;
//
//enum Colors
//{
//	NONE_COLOR,
//	RED,
//	BLUE,
//	GREEN,
//	YELLO,
//	BLACK,
//	PURPLE,
//	ORANGE,
//	WHITE,
//	GREY,
//	PINK,
//	VIOLET,
//	LIGHT_BLUE,
//	BROWN,
//	DARK_BLUE,
//	LIGHT_GREEN,
//	DARK_GREEN,
//	GOLD,
//	SILVER,
//	NAVY_BLUE,
//	SKY_BLUE,
//	LIME_GREEN,
//	INDIGO,
//	TEAL,
//	MAGENTA,
//	KHAKI,
//	SALMON,
//	CRIMSON,
//	PLUM,
//	BLUE_VIOLET,
//	OLIVE,
//	CYAN,
//	MAROON,
//	BEIGE
//};
//
//vector<Colors> cl = { Colors::BLACK, Colors::BLUE,Colors::GREEN,Colors::GREY, Colors::ORANGE, Colors::PURPLE, Colors::RED,
//Colors::WHITE, Colors::YELLO, Colors::PINK, Colors::VIOLET,Colors::BEIGE,Colors::BLUE_VIOLET,Colors::BROWN,Colors::CRIMSON,Colors::CYAN,
//Colors:: DARK_BLUE,Colors:: DARK_GREEN,Colors:: GOLD,Colors:: INDIGO,Colors:: KHAKI,Colors:: LIGHT_BLUE,Colors:: LIGHT_GREEN,Colors:: LIME_GREEN,
//Colors:: MAGENTA,Colors:: MAROON,Colors:: NAVY_BLUE,Colors:: OLIVE,Colors:: PLUM,Colors:: SALMON,Colors:: TEAL,Colors:: SKY_BLUE,Colors:: SILVER};
//
//
//// ########################################### Class with node, color and blocked color ######################################
//class nodes {
//public:
//	pair<int, int> from_to;
//	vector<Colors> blocked;
//
//private:
//	Colors color = NONE_COLOR;
//public:
//	void setColor(Colors t);
//	Colors getColor();
//
//};
//void nodes::setColor(Colors t) {
//	this->color = t;
//}
//Colors nodes::getColor() {
//	return color;
//}
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
//				nd.push_back(temp);
//			}
//		}
//		i++;
//	}
//	csv.close();
//	return i;
//
//}
//// ########################################## Cheking forbidden Colors #######################################################
//bool block_list_cheking(vector<nodes> nd, Colors c, int pos) {
//	for (size_t i = 0; i < nd[pos].blocked.size(); i++)
//	{
//		if (c == nd[pos].blocked[i])
//		{
//			return true;
//		}
//	}
//	return false;
//}
//bool massive_block(vector<nodes> nd, Colors c, int pos) {
//	for (size_t i = 0; i < nd.size(); i++)
//	{
//
//		if ((nd[i].from_to.first == pos) && (block_list_cheking(nd, c, i) && nd[i].getColor() == Colors::NONE_COLOR))
//		{
//			return false;
//		}
//	}
//	return true;
//}
//void set_blocked_Colors_first(vector<nodes>& nd, Colors c, int pos) {
//	for (size_t i = 0; i < nd.size(); i++)
//	{
//		if (nd[i].from_to.first == pos)
//		{
//			nd[i].blocked.push_back(c);
//		}
//	}
//}
//void set_blocked_Colors_second(vector<nodes>& nd, Colors c, int pos) {
//	for (size_t i = 0; i < nd.size(); i++)
//	{
//		if (nd[i].from_to.second == pos)
//		{
//			if (nd[i].getColor() == Colors::NONE_COLOR)
//			{
//				nd[i].blocked.push_back(c);
//			}
//		}
//	}
//}
//// ########################################## DFS ###########################################################################
//void dfs(vector<nodes>& nd, int vertex) {
//	for (size_t i = 0; i < cl.size(); i++)
//	{
//		if (massive_block(nd, cl[i], nd[vertex].from_to.first) && massive_block(nd, cl[i], nd[vertex].from_to.second)) {
//			nd[vertex].setColor(cl[i]);
//			set_blocked_Colors_first(nd, cl[i], nd[vertex].from_to.first);
//			set_blocked_Colors_second(nd, cl[i], nd[vertex].from_to.first);
//			set_blocked_Colors_first(nd, cl[i], nd[vertex].from_to.second);
//			set_blocked_Colors_second(nd, cl[i], nd[vertex].from_to.second);
//
//			return;
//		}
//	}
//}
//// ########################################## Cleaning Graph from useless parts ##############################################
//void orientation(vector<nodes>& nd) {
//	for (size_t i = 0; i < nd.size(); i++)
//	{
//		for (size_t j = 0; j < nd.size(); j++)
//		{
//			if (nd[j].from_to.second == nd[i].from_to.first && nd[j].from_to.first == nd[i].from_to.second)
//			{
//				nd.erase(nd.begin() + j);
//			}
//		}
//	}
//}
//// ########################################## OUTPUT END RESULT ##############################################################
//void output_end_result(vector<nodes> nd) {
//	for (size_t i = 0; i < nd.size(); i++)
//	{
//		cout << i << ": " << "Color: [" << nd[i].getColor() << "]  " << nd[i].from_to.first << " --> " << nd[i].from_to.second << endl;
//
//	}
//}
//// ########################################## MAIN ###########################################################################
//void main() {
//	vector<nodes> nd;
//	int countv = outr(nd);
//	orientation(nd);
//	cout << "###################################################################" << endl;
//
//	for (size_t i = 0; i < nd.size(); i++)
//	{
//		dfs(nd, i);
//	}
//	output_end_result(nd);
//
//	cout << "SOMETHING" << endl;
//}