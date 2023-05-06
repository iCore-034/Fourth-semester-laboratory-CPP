//#include <iostream>
//#include <string.h>
//#include <vector>
//#include <time.h>
//using namespace std;
//
//bool bpm(vector<vector<bool>> Graph, int u,
//    bool seen[], int matchR[])
//{
//    for (int v = 0; v < Graph.size(); v++)
//    {
//        if (Graph[u][v] && !seen[v])
//        {
//            seen[v] = true;
//            if (matchR[v] < 0 || bpm(Graph, matchR[v],
//                seen, matchR))
//            {
//                matchR[v] = u;
//                return true;
//            }
//        }
//    }
//    return false;
//}
//int maxBPM(vector<vector<bool>> Graph)
//{
//    int *matchR = new int[Graph.size()];
//    memset(matchR, -1, sizeof(matchR));
//
//    int result = 0;
//    for (int u = 0; u < Graph.size(); u++)
//    {
//        bool *seen = new bool[Graph.size()];
//        memset(seen, 0, sizeof(seen));
//        if (bpm(Graph, u, seen, matchR))
//            result++;
//    }
//    return result;
//}
//void GraphGeneratop(vector<vector<bool>> &Graph, int numVertex) {
//    srand(time(NULL));
//    for (size_t i = 0; i < Graph.size(); i++)
//    {
//        for (size_t j = 0; j < Graph[i].size(); j++)
//        {
//            if (i == 0 || i%2 == 0)
//            {
//                if (j % 2 != 0)
//                {
//                    int rd = rand() % 4;
//                    if (rd == 0)
//                    {
//                        Graph[i][j] = 1;
//                    }
//                }
//            }
//            else if (i%2 != 0 && j%2 == 0)
//            {
//                int rd = rand() % 4;
//                if (rd == 0)
//                {
//                    Graph[i][j] = 1;
//                }
//            }
//        }
//    }
//}
//void OutputGpaph(vector<vector<bool>> Graph) {
//    for (size_t i = 0; i < Graph.size(); i++)
//    {
//        cout << i << ": ";
//        for (size_t j = 0; j < Graph[i].size(); j++)
//        {
//            if (Graph[i][j] != 0)
//                cout << j << " ";
//        }
//        cout << endl;
//    }
//}
//void main()
//{
//    int numVertex = 0;
//    cout << "Input count of vertex: ";
//    cin >> numVertex;
//    cout << endl;
//    vector<vector<bool>> Graph(numVertex, vector<bool>(numVertex, 0));
//    GraphGeneratop(Graph, numVertex);
//    OutputGpaph(Graph);
//    cout << "Maximum number of applicants that can get job is "
//        << maxBPM(Graph);
//}