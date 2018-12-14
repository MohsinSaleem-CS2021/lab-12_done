#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<sstream>

using namespace std;

class Shape{
public:
float virtual get_area()=0;

float virtual get_perimeter()=0;


};

class Circle : public Shape {
private:
  float radius;

public:
  Circle(float r)
  {
    radius = r;
  }
float get_area()
{
  return (3.1416 * (radius * radius));
}

float get_perimeter()
{
  return (2 * 3.1416 * radius);
}
};

class Rectangle : public Shape {
private:
  float width;
  float height;

public:
  Rectangle(float w ,float h)
  {
    width = w;
    height = h;
  }
float get_area()
{
  return (width * height);
}

float get_perimeter()
{
  return (2 * (width + height));
}
};


class Triangle : public Shape {
private:
  float base;
  float height;
public:
  Triangle(float b , float h)
  {
    base = b;
    height = h;
  }
float get_area()
{
  return (0.5 * base * height);
}

float get_perimeter()
{
  return (base+height + (sqrt((base*base) + (height*height))));
}

};


int main() {

  int i = 0;
  string line;

  vector < string > v;

  ifstream in;

  in.open ("data.txt");

  if ( in.is_open ( ))
  {
    while ( getline ( in, line ))
    {
      stringstream ss ( line );

      while ( getline (ss ,line, ','))
      {
        v.push_back(line);
      }
    }
  }

  i=0;

  float temp1 , temp2;

  while ( true )
    {
      if (i==v.size())
      {
        break;
      }

      if(v[i]=="c")
      {
      stringstream ss(v[i+1]);
      ss>>temp1;
      Circle c(temp1);
      cout << "area of circle : " << c.get_area() << '\n';
      cout << "perimeter of circle : " << c.get_perimeter() << '\n';

      cout << "/*********************/" << '\n';
      cout << '\n';
      cout << '\n';
      }

      if(v[i]=="t")
      {
      stringstream ss1(v[i+1]);
      stringstream ss2(v[i+2]);
      ss1>>temp1;
      ss2>>temp2;
      Triangle t(temp1 , temp2);
      cout << "area of triangle : " << t.get_area() << '\n';
      cout << "perimeter of triangle : " << t.get_perimeter() << '\n';

      cout << "/*********************/" << '\n';
      cout << '\n';
      cout << '\n';
      }

      if(v[i]=="r")
      {
      stringstream ss1(v[i+1]);
      stringstream ss2(v[i+2]);
      ss1>>temp1;
      ss2>>temp2;
      Rectangle r(temp1 , temp2);
      cout << "area of rectangle : " << r.get_area() << '\n';
      cout << "perimeter of rectangle : " << r.get_perimeter() << '\n';

      cout << "/*********************/" << '\n';
      cout << '\n';
      cout << '\n';
      }
      i++;
    }
    return 0;
}
