
# Assignment 2- operators overloading using Graph class

 # Elian iluk
 # id- 214787483
 # email- elian10119@gmail.com

## Overview

This `Graph` class having a variety of operations(overloads them) that can be performed on graphs(the operators are used on the adjacenct matrix which represent the graph itself). The graph is represented as an adjacency matrix, which is a square matrix used to represent a graph. The elements of the matrix indicate whether pairs of vertices have an edge between them and if so what is the weight of the edge, if the edge is '0' it means the vertices dont have an edge.

## Class and Function Descriptions

### Class: `Graph`

#### Constructors
- **`Graph()`**
  - Default constructor that initializes an empty graph with zero vertices and zero edges.

#### Member Functions
- **`void loadGraph(std::vector<std::vector<int>> vec1)`**
  - Loads a graph from a given adjacency matrix `vec1`.
  - Checks if the input matrix is a square matrix, if not throw an error and end the program.
  - Sets the number of vertices and edges based on the input matrix.

- **`int getVertices()`**
  - Returns the number of vertices in the graph.

- **`int getEdges()`**
  - Returns the number of edges in the graph.

- **`std::vector<std::vector<int>> getGraph()`**
  - Returns the adjacency matrix of the graph.

- **`std::string printGraph()`**
  - Returns a string representation of the graph's adjacency matrix.

#### Overloaded Operators
- **`Graph operator+(Graph& g1, Graph& g2)`**
  - Adds two graphs by summing their adjacency matrixes.
  - Returns a new graph with the new adjacency matrix.

- **`Graph operator+(Graph& g1)`**
  - Unary plus operator that returns the graph itself(there is nothing to be done, just put + on each edge).

- **`Graph operator-(Graph& g1)`**
  - Unary minus operator that negates the adjacency matrix of the graph.

- **`void operator+=(Graph& g1, Graph& g2)`**
  - Adds the adjacency matrix of `g2` to `g1` and store the result in `g1`.

- **`void operator++(Graph& g1)`**
  - Prefix increment operator that increments all non-zero elements(all edges in the matrix, a slot which equals 0 means there is no edge so we dont need to change it) of the adjacency matrix of `g1` by 1.

- **`void operator++(Graph& g1, int)`**
  - Postfix increment operator that increments all non-zero elements(all edges in the matrix, a slot which equals 0 means there is no edge so we dont need to change it) of the adjacency matrix of `g1` by 1.

- **`void operator--(Graph& g1)`**
  - Prefix decrement operator that decrements all non-zero elements(all edges in the matrix, a slot which equals 0 means there is no edge so we dont need to change it) of the adjacency matrix of `g1` by 1.

- **`void operator--(Graph& g1, int)`**
  - Postfix decrement operator that decrements all non-zero elements(all edges in the matrix, a slot which equals 0 means there is no edge so we dont need to change it) of the adjacency matrix of `g1` by 1.

- **`void operator*=(Graph& g1, int num)`**
  - Multiplies all elements of the adjacency matrix of `g1` by `num`.

- **`void operator/=(Graph& g1, int num)`**
  - Divides all elements of the adjacency matrix of `g1` by `num`. Checks for division by zero and throw an error if num==0.

- **`Graph operator-(Graph& g1, Graph& g2)`**
  - Subtracts the adjacency matrix of `g2` from `g1`.
  - Returns a new graph with the new adjacency matrix.

- **`void operator-=(Graph& g1, Graph& g2)`**
  - Subtracts the adjacency matrix of `g2` from `g1` and store it in `g1`.

- **`Graph operator*(Graph& g1, Graph& g2)`**
  - Multiplies the adjacency matrix of `g1` with `g2` (matrix multiplication).
  - Returns a new graph with the resultant adjacency matrix.

- **`bool operator>(Graph& right, Graph& left)`**
  - Compares two graphs. Returns true if `right` is "bigger" than `left` based on:
    - the `left` graph is contained in full in the `right` graph.
    - Number of edges in `right` being greater than `left`.
    - The size of the adjacency matrix of `right` being larger than `left`.

- **`bool operator==(Graph& g1, Graph& g2)`**
  - Checks if two graphs are equal by comparing their adjacency matrices.

- **`bool operator!=(Graph& g1, Graph& g2)`**
  - Checks if two graphs are different by comparing their adjacency matrices.

- **`bool operator<(Graph& left, Graph& right)`**
  - Compares two graphs. Returns true if `left` is less than `right` based on:
    - the `right` graph is contained in full in the `left` graph.
    - Number of edges in `left` being less than `right`.
    - The size of the adjacency matrix of `left` being smaller than `right`.

- **`bool operator>=(Graph& g1, Graph& g2)`**
  - Checks if `g1` is greater than or equal to `g2`.

- **`bool operator<=(Graph& g1, Graph& g2)`**
  - Checks if `g1` is less than or equal to `g2`.

- **`std::ostream& operator<<(std::ostream& os, Graph& g)`**
  - Overloads the output stream operator to print the adjacency matrix of the graph.
