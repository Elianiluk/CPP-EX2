#include <iostream>
#include <vector>
#include "Graph.hpp"

/*id-214787483
   name- elian iluk
   email- elian10119@gmail.com
*/

namespace ariel {

    Graph::Graph() : numOfEdges(0), numOfVertices(0), vec() {}

    void Graph::loadGraph(std::vector<std::vector<int>> vec1) {
        if(vec1.size() != vec1[0].size()) {
            std::cout << "Invalid graph: The graph is not a square matrix." << std::endl;
            exit(1);
        }

        numOfVertices = vec1.size();
        vec = vec1;
        int countEdges = 0;
        for(unsigned long i = 0; i < vec1.size(); i++) {
            for(unsigned long j = 0;  j < vec1.size(); j++) {
                if(vec[i][j]!=0)
                    countEdges++;
            }
        }
        numOfEdges = countEdges;   
    }

    int Graph::getVertices(){
        return numOfVertices;
    }

    int Graph::getEdges(){
        return numOfEdges;
    }

    std::vector<std::vector<int>> Graph::getGraph() {
        return vec;
    }
    
    void Graph::printGraph() {
        std::cout << "Graph with " << numOfVertices << " vertices and " << numOfEdges << " edges" << std::endl;
    }

    //asiignment 2

    Graph operator+(Graph& g1,Graph& g2) {
        std::vector<std::vector<int>> vec1 = g1.getGraph();
        std::vector<std::vector<int>> thisVec = g2.getGraph();
        std::vector<std::vector<int>> vecNew(vec1.size(), std::vector<int>(vec1[0].size()));
        if(vec1.size() != thisVec.size()) {
            std::cout << "Invalid graph: The graphs are not the same size." << std::endl;
            exit(1);
        }
        for(unsigned long i = 0; i < vec1.size(); i++) {
            for(unsigned long j = 0; j < vec1.size(); j++) {
                vecNew[i][j] = vec1[i][j] + thisVec[i][j];
            }
        }
        Graph g3;
        g3.loadGraph(vecNew);
        return g3;
    }


    void operator+=(Graph& g1,Graph& g2) {
        std::vector<std::vector<int>> vec1 = g1.getGraph();
        std::vector<std::vector<int>> vec2 = g2.getGraph();
        //std::vector<std::vector<int>> vecNew;
        if(vec1.size() != vec2.size()) {
            std::cout << "Invalid graph: The graphs are not the same size." << std::endl;
            exit(1);
        }
        for(unsigned long i = 0; i < vec1.size(); i++) {
            for(unsigned long j = 0; j < vec1.size(); j++) {
                vec1[i][j] = vec2[i][j] + vec1[i][j];
            }
        }
        g1.loadGraph(vec1);
    }

    void operator++(Graph& g1) {
        std::vector<std::vector<int>> thisVec = g1.getGraph();
        for(unsigned long i = 0; i < thisVec.size(); i++) {
            for(unsigned long j = 0; j < thisVec.size(); j++) {
                thisVec[i][j]++;
            }
        }
        g1.loadGraph(thisVec);
    }
    

    void operator--(Graph& g1) {
        std::vector<std::vector<int>> thisVec = g1.getGraph();
        for(unsigned long i = 0; i < thisVec.size(); i++) {
            for(unsigned long j = 0; j < thisVec.size(); j++) {
                thisVec[i][j]--;
            }
        }
        g1.loadGraph(thisVec);
    }


    void operator*=(Graph &g1,int num) {
        std::vector<std::vector<int>> thisVec = g1.getGraph();
        for(unsigned long i = 0; i < thisVec.size(); i++) {
            for(unsigned long j = 0; j < thisVec.size(); j++) {
                thisVec[i][j] *= num;
            }
        }
        g1.loadGraph(thisVec);
    }

    Graph operator-(Graph& g1,Graph& g2) {
        std::vector<std::vector<int>> vec1 = g1.getGraph();
        std::vector<std::vector<int>> thisVec = g2.getGraph();
        std::vector<std::vector<int>> vecNew(vec1.size(), std::vector<int>(vec1[0].size()));
        if(vec1.size() != thisVec.size()) {
            std::cout << "Invalid graph: The graphs are not the same size." << std::endl;
            exit(1);
        }
        for(unsigned long i = 0; i < vec1.size(); i++) {
            for(unsigned long j = 0; j < vec1.size(); j++) {
                vecNew[i][j] = vec1[i][j] - thisVec[i][j];
            }
        }
        Graph g3;
        g3.loadGraph(vecNew);
        return g3;
    }

    void operator-=(Graph& g1,Graph& g2) {
        std::vector<std::vector<int>> vec1 = g1.getGraph();
        std::vector<std::vector<int>> vec2 = g2.getGraph();
        //std::vector<std::vector<int>> vecNew;
        if(vec1.size() != vec2.size()) {
            std::cout << "Invalid graph: The graphs are not the same size." << std::endl;
            exit(1);
        }
        for(unsigned long i = 0; i < vec1.size(); i++) {
            for(unsigned long j = 0; j < vec1.size(); j++) {
                vec1[i][j] = vec1[i][j] - vec2[i][j];
            }
        }
        g1.loadGraph(vec1);
    }

    Graph operator*(Graph& g1,Graph& g2) {
        std::vector<std::vector<int>> vec1 = g1.getGraph();
        std::vector<std::vector<int>> thisVec = g2.getGraph();
        std::vector<std::vector<int>> vecNew(vec1.size(), std::vector<int>(thisVec[0].size()));
        if(vec1.size() != thisVec[0].size()) {
            std::cout << "Invalid graph: The number of columns in the first matrix must be equal to the number of rows in the second matrix." << std::endl;
            exit(1);
        }
        for(unsigned long i = 0; i < vec1.size(); i++) {
            for(unsigned long j = 0; j < thisVec[0].size(); j++) {
                for(unsigned long k = 0; k < thisVec.size(); k++) {
                    vecNew[i][j] += vec1[i][k] * thisVec[k][j];
                }
            }
        }
        Graph g3;
        g3.loadGraph(vecNew);
        return g3;
    }

    std::ostream& operator<<(std::ostream& os,Graph& g) {
        std::vector<std::vector<int>> vec = g.getGraph();
        for(unsigned long i = 0; i < vec.size(); i++) {
            for(unsigned long j = 0; j < vec.size(); j++) {
                os << vec[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }
}
