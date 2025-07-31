#include <iostream>
#include <vector>
#include <unordered_set>
#include <list>

using namespace std;

// Maze
/*
 *   |----------|
 *     0   1   2|
 *   |   |------|
 *   | 3   4   5|
 *   |       |--|
 *   | 6 | 7   8
 *   |---|------|
 *
 *   Start = 0;
 *   Finish = 8;
 *   Shortest path = 0 3 4 7 8
 *   DFS = 0 1 2 3 4 5 7 8
*/

vector<int> findPath(vector<vector<int>>& maze, int start, int finish) {
  vector<int> currentPath;
  unordered_set<int> visited;

  currentPath.push_back(start);
  visited.insert(start);
  int curr = start;
  cout << curr << endl;

  while(!currentPath.empty() && currentPath.back() != finish) {
    bool foundUnvisited = false;  // iterator is better here
    int unvisited = -1;
    for(int neighbor : maze[curr]) {
      if(visited.find(neighbor) == visited.end()) { // if not yet visited
        foundUnvisited = true;
        unvisited = neighbor;
        break;
      }
    }

    if(foundUnvisited) {
      visited.insert(unvisited);
      currentPath.push_back(unvisited);
      cout << unvisited << endl;
    } else {
      currentPath.pop_back(); // backtracking
    }

    if (!currentPath.empty()) {
      curr = currentPath.back();
    }
  }
  return currentPath;
}

bool findPath_r_helper(vector<vector<int>>& maze, int start, int finish, list<int>& path, unordered_set<int>& visited) {
  if(start == finish) {
    path.push_front(start);
    return true;
  }

  visited.insert(start);
  vector<int>::iterator it = maze[start].begin();
  while(it != maze[start].end()) {
    if(visited.count(*it) == 0) { // if not yet visited
      if(findPath_r_helper(maze, *it, finish, path, visited)) {
        path.push_front(start);
        return true;
      }
    }
    it++;
  }
  return false;
}

list<int> findPath_r(vector<vector<int>>& maze, int start, int finish) {
  list<int> path;
  unordered_set<int> visited;
  bool solutionExists = findPath_r_helper(maze, start, finish, path, visited);
  return path;
}

int main(void) {
  vector<vector<int>> maze(9);
  maze[0].push_back(1);
  maze[0].push_back(3);

  maze[1].push_back(2);

  maze[3].push_back(4);
  maze[3].push_back(6);

  maze[4].push_back(5);
  maze[4].push_back(7);

  maze[7].push_back(8);

  const vector<int> pat = findPath(maze, 0, 8);
  const list<int> path = findPath_r(maze, 0, 8);

    cout << "Path: ";
  for(const int& x : path) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
