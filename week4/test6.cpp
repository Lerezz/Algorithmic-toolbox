#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdlib.h>
 
using namespace std;
 
struct point{
  int x;
  int y;
};
 
int cmp(const void *i, const void *j){
  return (*(const struct point *)i).x - (*(const struct point *)j).x;
}
 
int y_cmp(const void *i, const void *j){
  point *p1 = (point *)i;
  point *p2 = (point *)j;
  return (*(const struct point *)i).y - (*(const struct point *)j).y;
}
 
double dis(point p1, point p2){
  double d = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
  return d;
}
 
 
 
double minimal_distance(point points[], int front, int back) {
  //write your code here
  if(front == back - 1) return dis(points[front],points[back]);
  if(front == back - 2) return min(min(dis(points[front],points[back]),dis(points[front],points[front+1])),dis(points[back-1],points[back])); 
  int mid = (front + back) / 2;
  double lmin = minimal_distance(points, front, mid);
  double rmin = minimal_distance(points, mid+1, back);
  double d;
  d = min(lmin,rmin);
  if(d==0) return 0;
  
  point y_sort[back];
  int n=0;
  for(int i = front; i <= back; i++) {
    if(abs(points[i].x - points[mid].x)< d) y_sort[n++]=points[i];
  }
 
  if(n == 1) return min(lmin,rmin);
 
  qsort(y_sort,n,sizeof(point),y_cmp);
  
  double mindis = dis(y_sort[0],y_sort[1]);
  for(int i = 0; i < n; i++){   
    for(int j = i+1; j < n && (y_sort[j].y-y_sort[i].y)<mindis; j++){
      if(dis(y_sort[i],y_sort[j]) < mindis) mindis = dis(y_sort[i],y_sort[j]);
    }
  }
 
  if(d > mindis) return mindis;
  else return d;
}
 
int main() {
  int n;
  std::cin >> n;
  point points[n];
  for (int i = 0; i < n; i++) {
    std::cin >> points[i].x >> points[i].y;
  }
  qsort(points,n,sizeof(point),cmp);
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(points, 0, n-1) << "\n";
}

