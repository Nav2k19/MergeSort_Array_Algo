
#include <iostream>
#include <fstream>
#include <iomanip>
#include "ArgumentManager.h"
#include <string>
#include <vector>
#include <queue>
using namespace std;
/*
* Selection Criteria
* 
* 1. Design a path from one vertex to EVERY OTHER vertex. point A to point b, point c, to Point D. A complete path
* 2. Traverse the entire graph in just one walk. Example. Walking into IKEA
* 3. Minimum length of cable- Use Min Span Tree Algorithm 
* 4. Make a vertex with most adjacent verticies. 
* ////////////////////////////////////////////////////////
    How to implement each requirement
    use a boolean statement
    count how many boolean statements
    count++


    void Design_Inspection(ofstream& Outfile)
    {

        if(1 && 2 && 4 objectives are met)
        { Outfile<<"Good"<<endl;}

        else if(!1) { Outfile<<"Bad"<<endl;}
}
        else if(1 && (2 || 4))
        {Outfile<<"Fair"<<endl;}
    }

*/
class Graph {
  public:
  int maxsize;
  int num_verticies;
  vector<int> *Graph;//create adjacency list using Array
  void D4L(int v, bool visited[]);//check to see if fisrt vertex of graph has been visited to start actual DFS
  bool IsEmpty();
  void AdjListGraph();//graph creation
  void ClearGraph();
  void printGraph();
  void DFS();
  void DFS_ATVertex(int Vertex);
  void BFT();
  Graph(int size = 0);
  ~Graph();
};

bool Graph::IsEmpty()
{ return (num_verticies == 0);}

// add contents of the graph
void Graph::AdjListGraph()//function to use in GA3 
{

  ifstream Input;
  char FileName[69];

  int Vertex;
  int Adj_Vertex;

  if(num_verticies!=0) {ClearGraph();}

  Input.open(FileName);
  Input>>num_verticies;//input number of num_verticies

  for(int i = 0; i<num_verticies; i++)
  {
    Input>>Vertex;
    Input>>Adj_Vertex;

    while(Adj_Vertex!=-999)
    {
      Graph[Vertex].insertLast(Adj_Vertex);
      Input>>Adj_Vertex;
    }
  }
}
//delete contents of Graph
void Graph::ClearGraph()
{
  for(int i = 0; i<num_verticies; i++)
  {
    Graph[i].destroyList();
    num_verticies = 0;
  }
}
void Graph::printGraph()
{
   for(int i = 0; i<num_verticies; i++)
  {
    cout<<i <<" ";
    Graph[i].print();
    cout<<endl;
  }
  cout<<endl;
}
//initializes the Graph
Graph::Graph(int Size)
{
  maxsize = Size;
  num_verticies = 0;
  Graph = new UnorderedLinkList<int> [Size];
}
//destructor deletes the Graph
Graph::~Graph()
{ClearGraph();}

void Graph::D4L(int v, bool visited[])
{
  visited[v] = true;//set visited array to true
  //once vertex has passed
  cout<<v<<" "<<endl;//print Vertex

  vector<int> GraphIt;

  for(GraphIt = Graph[v].begin(); GraphIt != Graph[v.end(); GraphIt++])
  {
    int W = *GraphIt;
    if(!visited[W])
    {D4L(int W, visited);}
  }
}
void Graph::DFS()
{
  bool *visited;
  visited = new bool[num_verticies];

  for(int j = 0; j<num_verticies; j++)
  {visited[j] = false;}

  for(int i = 0; i<num_verticies; i++)
  {
    if(!visited[i])
    { D4L(i,visited);}
  }
  delete [] visited;
}

void Graph::DFS_ATVertex(int Vertex)
{
  bool *visited;
  visited = new bool[num_verticies];

  for(int k = 0; k<num_verticies; k++)
  {visited[k] = false; }

  D4L(Vertex, visited);

  delete [] visited;
}

void Graph::BFT()// for number 1 of the Requirements
{
  //declare a queue
  priority_queue<int> Q;

  bool *visited;

  visited = new bool[num_verticies];

  for(int i =0; i<num_verticies i++)
  {
    //in For loop initialize all Vertices to fals
    visited[i] = false;
  }
  vector<int> GraphIt;// have to make this LList

  for(int h = 0; h<num_verticies; h++)
  {
    if(!visited[h])
    {
      Q.push(h);//add vertex into queue
      visited[h] = true;//change to true since Vertex has been visited
      cout<<h<<endl;
      //while queue isnt Empty
      while(!Q.isempty())
      {
        int d = Q.top();
        Q.pop();

        for(GraphIt = Graph[d].begin(); GraphIt!=Graph[d].end(); ++GraphIt)
        {
          int o = *GraphIt;
          if(!visited[o])
          {
            Q.push(o);
            visited[o] = true;
          }
        }
      }
    }
  }
  delete [] visited;
}
class WeightedGraph: public Graph {
  public:
  int **weight;
  int *smallWeight;

  void CreateWeightedGraph();

  void shortestPath(int Vertex);///Lab6

  void PrintShortestDistance(int Vertex);//lab6

  WeightedGraph(int size = 0);

  ~WeightedGraph();
};
void WeightedGraph::shortestPath(int Vertex)//algo for shortest path through entire graph starting from Vertex
{
  for(int j = 0; j<num_verticies; j++)
  {
    smallWeight[j] = weight[Vertex][j];
  }
    bool *WeightFound;
    WeightFound = new bool[num_verticies];

    //initialize all verticies to false until vertex Weight is found
    for(int i = 0; i<num_verticies; i++)
    {WeightFound[i] = false;}

    WeightFound[Vertex] = true;
    smallWeight[Vertex] = 0;

    //set verticies to true Once the weight is found
    for(int k = 0; k<num_verticies-1; k++)
    {
      double Miniumum_Weight = DBL_MAX;
      int v;

      for(int j = 0; j<num_verticies; j++)
      {
        if(!WeightFound[j])
        {
          if(smallWeight[j]<Miniumum_Weight)
          {
            v = j;
            Miniumum_Weight = smallWeight[v];
          }
        }
      }
      WeightFound[v] = true;
      for(int o = 0; o<num_verticies; o++)
      {
        if(!WeightFound[o])
        {
          if(Miniumum_Weight + weight[v][o]< smallWeight[o])
          {smallWeight[o] = Miniumum_Weight + weight[v][o];}
        }
      }
    }
  }

  //This Algo only produces the wieght of each vertex when Given the values of the edge
  void WeightedGraph::PrintShortestDistance(int Vertex)//print Function
  {
      cout<<"Main vertex: "<<Vertex<<endl;
      for(int j = 0; j<num_verticies; j++)
      {cout<<smallWeight[j]<<endl;}
  }
  //Minimum Spanning Tree
  class MinSpanTree: public Graph {
      public:
      int source_vertex;//starting of the graph
      int *Edges;// each edge after vertex is traversed
      double **Weights;
      double Edge_Weights; //total wieght of the edge

      void CreateSpanningGraph();

      void MinSpanning(int SpanVertex);

      void Print_Tree_And_Weight();

      MinSpanTree(int Size = 0);

      ~MinSpanTree();
  };
  void MinSpanTree::CreateSpanningGraph(ifstream &Input)
  {
      int Vertex;
      int adjVertex;

     /* if(num_verticies!=0)//initialize Graph
      { ClearGraph();}

      Input.open(fileName);

      if(!infile)
      {
          cout<<"Unable to open file"<<endl;
      }*/
      infile>>num_verticies;
      if(num_verticies>maxSize)
      { cout<<" "<<endl;}

      for(int i =0; i<num_verticies; i++)
      {
          infile>>Vertex;//0
          infile>>adjVertex;
          while(adjacent!=-999)
          {
              infile>>Edge_Weights;//last part
              Graph[vertex].InsertLast(adjVertex);
              Weights[vertex][adjVertex] = Edge_Weights;
          }
      }
  }

  void MinSpanTree::MinSpanning(int SpanVertex,ofstream &OutFile)//miniumum Tree is created
  {
      int startV, endV;

      double MinWeight;

      source_vertex = SpanVertex;

      bool *mstv;
      mstv = new bool[num_verticies];

      for(int j = 0; j<num_verticies; j++)
      {
          mstv[j] = false;
          edges[j] = source_vertex;
          Edge_Weights[j] =  Weights[source_vertex][j];
      }
      mstv[source_vertex] = true;///initialize first vertex
      Edge_Weights[source_vertex] = 0;// initialize first vertex

      for(int i = 0; i<num_verticies -1; i++)
      {
          MinWeight = DBL_MAX;// highest value
          for(int j = 0; j<num_verticies; j++)//find all verticies with their edges
          {
              if(mstv[j])//if true
              {
                  for(int k = 0; k<num_verticies; k++)
                  {
                      if(!mstv[k] && weights[j][k]<MinWeight)
                      {
                          endV = k;
                          startV = j;
                          MinWeight = weights[j][k];
                      }
                  }
              }
          }
      }
  }

  void MinSpanTree::Print_Tree_And_Weight(ofstream &Outfile)//prints cost. I think??
  {
      double TreeWeight = 0;

      cout<<"Source Vertex: "<<source_vertex<<endl;
      cout<<"Edges Weight. "<<endl;

      for(int j = 0; j<num_verticies; j++)
      {
        if(Edges[j]!=j)
        {
          TreeWeight = TreeWeight + Edges[j];
         // Outfile<<Edges[j]<<","<<j<<endl;
        }
      }   

      Outfile<<TreeWeight<<endl;//print function to show cost
  }


  class TopologicalOrder: public Graph
  { void BFTopOrder();}



void TopologicalOrder::BFTopOrder
{
    linkQueueType<int> Q;

    int *Topological_Order;

    int TopIndex = 0;

    vector <int> GraphIt;

    int *PredCount;

    PredCount = new int[num_verticies];
    for(int i = 0; i<num_verticies; i++)
    {}

}

int main(int argc, char* argv[])
{
    ArgumentManager am;
    string input = am.get("input");
    string output = am.get("output");
    Graph DoubleG;


    MinSpanTree mst;



    vector <int> *Graph;
    int num_verticies;
    int verticies;
    int adjVertex;
    double Edge_Weight;
    int edges;

    ifstream InFile(input);
    ofstream OutFile(output);


    InFile.open(input);



    if(!InFile)
    { cout<<"Error. Unable to open file."<<endl;}


    mst.CreatSpanningGraph(InFile);







    InFile>>num_verticies;



    for(int k = 0; k<num_verticies; k++)
    {
      InFile>>verticies;
      InFile>>adjVertex;


      while(adjVertex!= -999)
      {

        InFile>> Edge_Weight;



      }








    }






    InFile.close();
    OutFile.close();

    return 0;
}
