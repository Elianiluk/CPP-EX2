#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

/*id-214787483
   name- elian iluk
   email- elian10119@gmail.com
*/
namespace ariel {
    class Graph {
    private:
        int numOfEdges;
        std::vector<std::vector<int>> vec;
        int numOfVertices;

    public:
        Graph();
        void loadGraph(std::vector<std::vector<int>> vec1);
        void printGraph();
        int getVertices();
        int getEdges();
        std::vector<std::vector<int>> getGraph();

        friend Graph operator+(Graph& g1,Graph& g2);
        friend void operator+=(Graph& g1,Graph& g2);  
        friend void operator++(Graph& g1);
        friend void operator--(Graph& g1);
        friend void operator*=(Graph &g1,int num);
        friend void operator-=(Graph& g1,Graph& g2); 
        friend Graph operator-(Graph& g1,Graph& g2);
        friend Graph operator*(Graph& g1,Graph& g2);
        friend std::ostream& operator<<(std::ostream& os,Graph& g);
    };
}
#endif 
