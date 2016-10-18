//Bibhash Singh - Edmonds karp algorithm

#include<bits/stdc++.h>
using namespace std; 

 

int capacities[100][100];

int flowPassed[100][100];

vector<int> graph[100];

int parentsList[100];       

int currentPathCapacity[100];  

 

int bfs(int startNode, int endNode)

{
    parentsList[100]={-1};
    

    currentPathCapacity[100]= {0};

 

    queue<int> q;

    q.push(startNode);

 

    parentsList[startNode] = -2;

    currentPathCapacity[startNode] = 999;

 

    while(!q.empty())

    {

        int currentNode = q.front();

        q.pop();

 

        for(int i=0; i<graph[currentNode].size(); i++)

        {

            int to = graph[currentNode][i];

            if(parentsList[to] == -1)

            {

                if(capacities[currentNode][to] - flowPassed[currentNode][to] > 0)

                {

                    parentsList[to] = currentNode;

                    currentPathCapacity[to] = min(currentPathCapacity[currentNode], 

                    capacities[currentNode][to] - flowPassed[currentNode][to]);

                    if(to == endNode)

                    {

                        return currentPathCapacity[endNode];

                    }

                    q.push(to);

                }

            }

        }

    }

    return 0;

}

 

int edmondsKarp(int startNode, int endNode)

{

    int maxFlow = 0;

      while(true)

    {

        int flow = bfs(startNode, endNode);

        if (flow == 0) 

        {

            break;

        }

        maxFlow += flow;

        int currentNode = endNode;

        while(currentNode != startNode)

        {

            int previousNode = parentsList[currentNode];

            flowPassed[previousNode][currentNode] += flow;

            flowPassed[currentNode][previousNode] -= flow;

            currentNode = previousNode;

        }

    }

    return maxFlow;

}

int main()

{

    int nodesCount, edgesCount;
    cout<<"enter the number of nodes and edges\n";
    cin>>nodesCount>>edgesCount;
    int source, sink;
    cout<<"enter the source and sink\n";
    cin>>source>>sink;
    for(int edge = 0; edge < edgesCount; edge++)

    {
        cout<<"enter the start and end vertex alongwith capacity\n";
        int from, to, capacity;
        cin>>from>>to>>capacity;
        capacities[from][to] = capacity;
        graph[from].push_back(to);
        graph[to].push_back(from);

    }
    int maxFlow = edmondsKarp(source, sink);
    cout<<endl<<endl<<"Max Flow is:"<<maxFlow<<endl;

}
