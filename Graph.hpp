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
        std::string printGraph();
        int getVertices();
        int getEdges();
        std::vector<std::vector<int>> getGraph();

        friend Graph operator+(Graph& g1,Graph& g2);//graph addition
        friend void operator+=(Graph& g1,Graph& g2);//graph addition and store it in g1  
        friend void operator++(Graph& g1);//prefix
        friend void operator--(Graph& g1);//prefix
        friend void operator++(Graph& g1,int);//postfix
        friend void operator--(Graph& g1,int);//postfix
        friend void operator*=(Graph &g1,int num);//graph multiplication by number
        friend void operator/=(Graph &g1,int num); //graph division by number
        friend void operator-=(Graph& g1,Graph& g2); //graph subtraction and store it in g1
        friend Graph operator-(Graph& g1,Graph& g2);//graph subtraction
        friend Graph operator*(Graph& g1,Graph& g2);//graph multiplication
        friend Graph operator+(Graph& g1);//plus unary
        friend Graph operator-(Graph& g1);//minus unary

        friend bool operator>(Graph& g1,Graph& g2);//check if g1 is bigger than g2
        friend bool operator<(Graph& g1,Graph& g2);//check if g1 is smaller than g2
        friend bool operator==(Graph& g1,Graph& g2);//check if g1 is equal to g2
        friend bool operator!=(Graph& g1,Graph& g2);//check if g1 is not equal to g2
        friend bool operator>=(Graph& g1,Graph& g2);//check if g1 is bigger or equal to g2
        friend bool operator<=(Graph& g1,Graph& g2);//check if g1 is smaller or equal to g2
        
        friend std::ostream& operator<<(std::ostream& os,Graph& g);//print the graph
    };
}
#endif 
