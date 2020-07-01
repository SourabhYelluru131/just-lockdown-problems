#include <iostream>
#include <cstring>
#include <list>
#include <vector>
using namespace std;
// addEdge(int, int)    ->  adds an edge to the graph
// printGraph()         ->  prints the entire graph in adjacency list form
// bfs(int)             ->  starts a breadth first search from the given number

class graph
{
    int size;
    list<int> *adj;
public:
    //Constructor
    graph(int size)
    {
        this->size = size;
        this->adj = new list<int>[size];
    }
    void addEdge(int src, int dest)
    {
        src--;
        dest--;   // Since indices are 0-based
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }
    void printGraph()
    {
        for(int i=0;i<this->size;i++)
        {
            cout << i+1 << " -> ";
            list<int>::iterator it;
            for(it = adj[i].begin(); it!= adj[i].end();it++)
            {
                cout << (*it)+1 << " " ; // Since indices are 0-based , we have to convert it to 1-based
            }
            cout << endl;
        }
    }
    void bfs(int search)
    {
        vector<bool> visited = vector<bool>(this->size,false);
        cout << search << " ";
        list<int> queue;
        list<int>::iterator it;
        it = adj[search-1].begin();
        visited[search-1] = true;
        for(int a:adj[search-1])
        {
            queue.push_back(a);
        }
        //cout << "ye" << endl;
        //for(int a :queue) cout << a << " ";
        //cout << endl;
        while(!queue.empty())
        {
            int s = queue.front();
            if(visited[s]==false) cout << s+1 << " "; // print only if not visited
            queue.pop_front();
            if(visited[s]==false)
            {
                for(int b:adj[s])
                {
                    if(visited[b]==false) queue.push_back(b);
                }
            }
            visited[s]=true;
        }
    }
};
int main() {
    graph g(4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(1, 4);
    g.addEdge(1, 3);
    g.printGraph();
    g.bfs(2);
    return 0;
}
