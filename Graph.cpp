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
    
    std::string Graph::printGraph(){
        std::string str;
        for(unsigned long i = 0; i < vec.size(); i++) {
            str+="[";
            for(unsigned long j = 0; j < vec.size(); j++) {
                str += std::to_string(vec[i][j]);
                str += " ";
            }
            str.pop_back();
            str+="]";
            str += "\n";
        }
        return str;
    }

    //asiignment 2

    Graph operator+(Graph& g1,Graph& g2) {
        std::vector<std::vector<int>> vec1 = g1.getGraph();
        std::vector<std::vector<int>> vec2 = g2.getGraph();
        std::vector<std::vector<int>> vecNew(vec1.size(), std::vector<int>(vec1[0].size()));
        if(vec1.size() != vec2.size() || vec1[0].size() != vec2[0].size()) {
            std::cout << "Invalid graph: The graphs are not the same size." << std::endl;
            exit(1);
        }
        unsigned long smallX=0,smallY=0;
        if(vec1.size()>=vec2.size())
            smallY=vec2.size();
        else
            smallY=vec1.size();
        if(vec1[0].size()>=vec2[0].size())
            smallX=vec2[0].size();
        else
            smallX=vec1[0].size();
        for(unsigned long i = 0; i < smallX; i++) {
            for(unsigned long j = 0; j < smallY; j++) {
                vecNew[i][j] = vec1[i][j] + vec2[i][j];
            }
        }
        Graph g3;
        g3.loadGraph(vecNew);
        return g3;
    }

    Graph operator+(Graph& g1){//plus unary
        return g1;
    }

    Graph operator-(Graph& g1){//minus unary
        std::vector<std::vector<int>> vec1 = g1.getGraph();
        for(unsigned long i = 0; i < vec1.size(); i++) {
            for(unsigned long j = 0; j < vec1.size(); j++) {
                vec1[i][j] = -vec1[i][j];
            }
        }
        Graph g3;
        g3.loadGraph(vec1);
        return g3;
    }


    void operator+=(Graph& g1,Graph& g2) {
        std::vector<std::vector<int>> vec1 = g1.getGraph();
        std::vector<std::vector<int>> vec2 = g2.getGraph();
        std::vector<std::vector<int>> vecNew;
        if(vec1.size() != vec2.size() || vec1[0].size() != vec2[0].size()) {
            std::cout << "Invalid graph: The graphs are not the same size." << std::endl;
            exit(1);
        }
        unsigned long smallX=0,smallY=0;
        if(vec1.size()>=vec2.size())
            smallY=vec2.size();
        else
            smallY=vec1.size();
        if(vec1[0].size()>=vec2[0].size())
            smallX=vec2[0].size();
        else
            smallX=vec1[0].size();
        for(unsigned long i = 0; i < smallX; i++) {
            for(unsigned long j = 0; j < smallY; j++) {
                vec1[i][j] = vec2[i][j] + vec1[i][j];
            }
        }
        g1.loadGraph(vec1);
    }

    void operator++(Graph& g1) {
        std::vector<std::vector<int>> thisVec = g1.getGraph();
        for(unsigned long i = 0; i < thisVec.size(); i++) {
            for(unsigned long j = 0; j < thisVec.size(); j++) {
                if(thisVec[i][j]!=0)
                    thisVec[i][j]++;
            }
        }
        g1.loadGraph(thisVec);
    }

    void operator++(Graph& g1,int) {
        std::vector<std::vector<int>> thisVec = g1.getGraph();
        for(unsigned long i = 0; i < thisVec.size(); i++) {
            for(unsigned long j = 0; j < thisVec.size(); j++) {
                if(thisVec[i][j]!=0)
                    ++thisVec[i][j];
            }
        }
        g1.loadGraph(thisVec);
    }
    

    void operator--(Graph& g1) {
        std::vector<std::vector<int>> thisVec = g1.getGraph();
        for(unsigned long i = 0; i < thisVec.size(); i++) {
            for(unsigned long j = 0; j < thisVec.size(); j++) {
                if(thisVec[i][j]!=0)
                    thisVec[i][j]--;
            }
        }
        g1.loadGraph(thisVec);
    }

    void operator--(Graph& g1,int) {
        std::vector<std::vector<int>> thisVec = g1.getGraph();
        for(unsigned long i = 0; i < thisVec.size(); i++) {
            for(unsigned long j = 0; j < thisVec.size(); j++) {
                if(thisVec[i][j]!=0)
                    --thisVec[i][j];
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

    void operator/=(Graph &g1,int num) {
        if(num == 0) {
            std::cout << "Invalid operation: Division by zero." << std::endl;
            exit(1);
        }
        std::vector<std::vector<int>> thisVec = g1.getGraph();
        for(unsigned long i = 0; i < thisVec.size(); i++) {
            for(unsigned long j = 0; j < thisVec.size(); j++) {
                thisVec[i][j] /= num;
            }
        }
        g1.loadGraph(thisVec);
    }

    Graph operator-(Graph& g1,Graph& g2) {
        std::vector<std::vector<int>> vec1 = g1.getGraph();
        std::vector<std::vector<int>> vec2 = g2.getGraph();
        std::vector<std::vector<int>> vecNew=vec1;
        // unsigned long big=0;
        // if(vec1.size()>=vec2.size())
        // {
        //     big=vec1.size();
        //     std::vector<std::vector<int>> vecNew=vec1;
        //     for (unsigned long i = 0; i < vec1.size(); i++)
        //     {
        //         for (unsigned long j = 0; j < vec1[0].size(); j++)
        //         {
        //                 vecNew[i][j]=0;
        //         }
        //     }
        // }
        // else
        // {
        //     big=vec2.size();
        //     std::vector<std::vector<int>> vecNew=vec2;
        //     for (unsigned long i = 0; i < vec2.size(); i++)
        //     {
        //         for (unsigned long j = 0; j < vec2[0].size(); j++)
        //         {
        //                 vecNew[i][j]=0;
        //         }
        //     }
        // }

        if(vec1.size() != vec2.size() || vec1[0].size() != vec2[0].size()){
            std::cout << "Invalid graph: The graphs are not the same size." << std::endl;
            exit(1);
        }
        unsigned long smallX=0,smallY=0;
        if(vec1.size()>=vec2.size())
            smallY=vec2.size();
        else
            smallY=vec1.size();
        if(vec1[0].size()>=vec2[0].size())
            smallX=vec2[0].size();
        else
            smallX=vec1[0].size();
        for(unsigned long i = 0; i < smallX; i++) {
            for(unsigned long j = 0; j < smallY; j++) {
                vecNew[i][j] = vec1[i][j] - vec2[i][j];
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
        if(vec1.size() != vec2.size() || vec1[0].size() != vec2[0].size()) {
            std::cout << "Invalid graph: The graphs are not the same size." << std::endl;
            exit(1);
        }
        unsigned long smallX=0,smallY=0;
        if(vec1.size()>=vec2.size())
            smallY=vec2.size();
        else
            smallY=vec1.size();
        if(vec1[0].size()>=vec2[0].size())
            smallX=vec2[0].size();
        else
            smallX=vec1[0].size();
        for(unsigned long i = 0; i < smallX; i++) {
            for(unsigned long j = 0; j < smallY; j++) {
                vec1[i][j] = vec1[i][j] - vec2[i][j];
            }
        }
        g1.loadGraph(vec1);
    }

    Graph operator*(Graph& g1,Graph& g2) {
        std::vector<std::vector<int>> vec1 = g1.getGraph();
        std::vector<std::vector<int>> thisVec = g2.getGraph();
        std::vector<std::vector<int>> vecNew(vec1.size(), std::vector<int>(thisVec[0].size()));
        if(vec1.size() != thisVec[0].size() || vec1[0].size() != thisVec[0].size()) {
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
        for(unsigned long i=0;i<vecNew.size();i++)
            vecNew[i][i]=0;
        Graph g3;
        g3.loadGraph(vecNew);
        return g3;
    }

    bool operator>(Graph& right,Graph& left) {
        std::vector<std::vector<int>> vec1 = right.getGraph();
        std::vector<std::vector<int>> vec2 = left.getGraph();
        unsigned long smallX=0,smallY=0;
        if(vec1.size()>=vec2.size())
            smallY=vec2.size();
        else
            smallY=vec1.size();
        if(vec1[0].size()>=vec2[0].size())
            smallX=vec2[0].size();
        else
            smallX=vec1[0].size();

        if(vec1.size()<vec2.size() || vec1[0].size()<vec2[0].size())
            return false;
        int count=0;
        bool flag=true;
        for(unsigned long i=0;i<smallY;i++)
            for(unsigned long j=0;j<smallX;j++)
            {
                if(vec1[i][j]!=0 && vec2[i][j]==0)
                    continue;
                else if(vec2[i][j]==vec1[i][j])
                    count++;
                else if(vec2[i][j]!=vec1[i][j])
                {
                    flag=false;
                    break;
                }
                
            }
        if(count!=vec1.size()*vec1.size() && flag)
            return true;

        if(right.getEdges() > left.getEdges())//if the number of edges in the right graph is bigger than the left graph,option 2
            return true;

        if(vec1.size()*vec1[0].size()>vec2.size()*vec2[0].size())//if the representing matrix of right graph is bigger than the left graph,option 3
            return true;

        return false;
    }

    bool operator==(Graph& g1,Graph& g2)
    {
        std::vector<std::vector<int>> vec1 = g1.getGraph();
        std::vector<std::vector<int>> vec2 = g2.getGraph();
        if(vec1.size()!=vec2.size() || vec1[0].size()!=vec2[0].size())
            return false;
        
        int count=0;
        for(unsigned long i=0;i<vec1.size();i++)
            for(unsigned long j=0;j<vec1[0].size();j++){
                if(vec1[i][j]!=vec2[i][j])
                    return false;
                if(vec1[i][j]==vec2[i][j])
                    count++;
            }
        if(count==vec1.size()*vec1[0].size())
            return true;

        if(!(g1>g2) && !(g2>g1))//if g1 isnt bigger than g2 and g2 isnt bigger than g1, option 2
            return true;
        
        return false;
    }

    bool operator!=(Graph& g1,Graph& g2)
    {
        return !(g1==g2);
    }

    bool operator<(Graph& left, Graph& right) {
        std::vector<std::vector<int>> vec1 = left.getGraph();
        std::vector<std::vector<int>> vec2 = right.getGraph();
        unsigned long smallX=0,smallY=0;
        
        if(vec1.size() >= vec2.size())
            smallY = vec2.size();
        else
            smallY = vec1.size();
        
        if(vec1[0].size() >= vec2[0].size())
            smallX = vec2[0].size();
        else
            smallX = vec1[0].size();

        if(vec1.size()>vec2.size() || vec1[0].size()>vec2[0].size())
            return false;

        int count = 0;
        bool flag = true;
        for(unsigned long i = 0; i < smallY; i++) {
            for(unsigned long j = 0; j < smallX; j++) {
                if(vec2[i][j] != 0 && vec1[i][j] == 0)
                    continue;
                else if(vec1[i][j] == vec2[i][j])
                    count++;
                else if(vec1[i][j] != vec2[i][j])
                {
                    flag = false;
                    break;
                }
            }
        }
        if(count != smallX*smallY && flag)
            return true;

        if(left.getEdges() < right.getEdges())  // Number of edges in left graph is less than right graph
            return true;

        if(vec1.size() * vec1[0].size() < vec2.size() * vec2[0].size())  // Size of representing matrix of left graph is less than right graph
            return true;

        return false;
    }

    bool operator>=(Graph& g1,Graph& g2)
    {
        return (g1>g2 || g1==g2);
    }

    bool operator<=(Graph& g1,Graph& g2)
    {
        return (g1<g2 || g1==g2);
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
