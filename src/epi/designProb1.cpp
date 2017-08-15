#include<iostream>
#include<vector>
#include<cmath>

template<typename T>
class Point{
public:
  T _x, _y;
  Point()=delete;
  //Point(T &x=T(),T &y = T()):_x(x), _y(y){}
  Point( T x, T y):_x(x),_y(y){
    std::cout << "Constructed Point\n";
  }
  //virtual float distance(Point &point){
  float distance(Point &point){
    float distance = 0.0;
    if(this != &point){
      distance = sqrt(pow((_x-point._x),2)+ pow((_y-point._y),2));
      std::cout << "In distance:" << distance << std::endl;
    }
    return distance;
  }
};
template<typename T>
class Point3D:Point<T>{
  T _z;
public:
  Point3D() = default;
  //Point3D(T &z = T()):_z(z){}
  Point3D(T x, T y, T z): Point<T>(x, y), _z(z){
    std::cout << "Constructed Point3D\n";
  }
  /*virtual*/ float distance(Point3D &point){
    float distance = 0.0;
    if(this != &point){
      distance = sqrt(pow((this->_x-point._x),2)+ pow((this->_y-point._y),2) + pow((_z-point._z),2) );
    }
    return distance;
  }
};

template<typename T, template<typename> class C>
class PolyLine{
  std::vector<C<T>> polyLines;
public:
  PolyLine() = delete;
  PolyLine(C<T> point1, C<T> point2){
    this->polyLines.push_back(point1);
    this->polyLines.push_back(point2);
  }

  float distance(){
    float distance = 0.0;
    //iterators are pointers, they should access data through -> Point<int> *
    for(typename std::vector<C<T>>::iterator iter = polyLines.begin()+1; iter != polyLines.end(); ++iter){
        //distance += polyLines[iter].distance(polyLines[iter-1]);
        C<T> point = *(iter-1);
        distance += iter->distance(point);
        std::cout << iter->distance(point) << std::endl;
        //std::cout << point._x << " " << point._y << std::endl;
        //std::cout << iter->_x << " " << iter->_y << std::endl;
        //std::cout << "The distance is:" << distance << std::endl;
    }
    return distance;
  }
};

int main(){
  Point<int> point(1,1);
  Point3D<int> point3d(1,1,1); //Firs the base constructor and then the derived constructor
  //PolyLine<int, Point2D> polyLine;
  PolyLine<int, Point> polyLine(Point<int>(1, 1), Point<int>(0, 1));
  float distance = polyLine.distance();
  std::cout << "The distance is:" << distance << std::endl;

  //PolyLine<int, Point3D> polyline3d; Call to a deleted destructed, compiler error
  PolyLine<int, Point3D> polyline3D(Point3D<int>(1,1,1), Point3D<int>(0,0,1));
  distance = polyLine.distance();
  std::cout << "The distance is:" << distance << std::endl;
  return 0;
}
