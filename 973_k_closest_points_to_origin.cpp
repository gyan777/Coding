#include <iostream>
#include <vector>
#include <map>
#include <cmath>

//We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
//(Here, the distance between two points on a plane is the Euclidean distance.)
  
using namespace std;

vector<vector<int>> kClosest_1(vector<vector<int>>& points, int K) {
  
  multimap<double, vector<int>*> euclidean_map;

  // For each set of points, solve for euclidean distance and insert into a map
  for (vector<int>& point_pair : points) { //also use a reference so the paoint pairs are not copied!!
    // No need to compute sqrt()
    double euclidean_distance = pow(point_pair[0], 2) + pow(point_pair[1], 2);
    euclidean_map.emplace(euclidean_distance, &point_pair);
  }

  vector<vector<int>> ret;
  ret.reserve(K);
  auto map_iter = euclidean_map.begin();
  for (int i = 0; i < K && map_iter != euclidean_map.end(); i++, map_iter++) {
    ret.push_back(move(*map_iter->second));
  }
  return ret;
}        

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {

  vector<vector<int>> closestPoints;
  multimap<float,vector<int>> distances;
  
  for (int i = 0; i < points.size(); i++) {
    //    float dist = sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
    int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];    
    distances.insert({dist,points[i]});
  }

  int i=0;
  for (auto itr = distances.begin(); itr != distances.end(); ++itr) {
    closestPoints.push_back(itr->second);
    if (++i == K) break;
  }
  return (closestPoints);
}

int main (int argc, char **argv) {

  vector<vector<int>> points = {{0,1},
                                {1,0}};

  int K = 2;
  vector<vector<int>> sortedPoints = kClosest(points, K);

  for (int i = 0; i < K; i++) {
    cout << sortedPoints[i][0] << " " << sortedPoints[i][1] << "\n";
  }

}
