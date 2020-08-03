//Assignment 4
//-	Implement base class, derived class for shape, triangle, right triangle, 
//rectangle and square with methods to calculate area and perimeter.
//-	Create a class of shape manager which is a container to store these shapes. 
//This class has a method for user to add shapes and print all of their area and perimeter.
#include<iostream>
#include <cassert>
#include<vector>
using namespace std;
class Shape
{
	public:
		Shape() = default;
		virtual double cal_area();
		virtual double cal_perimeter();
		~Shape(){
		};
};

class Triangle : public Shape
{
	protected:
		double a,b,c;
	public:
		Triangle(double a1,double b1,double c1):Shape()
		{
			a = a1; //first line lenght
			b = b1; //second line lenght
			c = c1; //third line lenght
		};
		~Triangle(){
		};
		double cal_area(){return 0;};
		double cal_perimeter(){
			return (a+b+c);
		};

};

class Rectangle : public Shape
{
	protected:
		double a, b;
	public:
		Rectangle(double a1, double b1):Shape(){
			a = a1;
			b= b1;
		};
		~Rectangle(){
		};
		double cal_area(){return 0;};
		double cal_perimeter(){return 2*(a+b);};	
};

class RightTriangle : public Triangle
{
	public:
	RightTriangle(double a1,double b1,double c1):
		Triangle(a1,b1,c1)
		{

		}
	double cal_area(){return 0;};
	double cal_perimeter(){
		return (a+b+c);
	};
};

class Square : public Rectangle
{
	public:
	Square(double a1,double b1):
		Rectangle(a1,b1)
		{
			
		}	
	double cal_area(){return 0;};
	double cal_perimeter(){return 2*(a+b);};	
};

class ShapeManager
{
	private:
		int m_lenght{0};
		vector<Shape> m_data; 
	public:
		ShapeManager() = default;
//		ShapeManager(int lenght):
//			m_lenght{lenght}
//			{
//				assert(lenght>=0);
//				if(lenght>0){
//					vector<Shape> m_data(lenght);
//				}
//			};
		~ShapeManager(){
			delete[] &m_data;
		}
		Shape operator[](int index){
			assert(index >=0 && index <=m_lenght);
			return m_data[index];
		};
		void addShape(Shape &shape){
			m_data.push_back(shape);
		};
		void printShape(){
			for(vector<Shape>::iterator ptr = m_data.begin();ptr!=m_data.end();++ptr){
				//cout << ptr->cal_perimeter() << " ";
				cout << "10 ";
			}
		};
};
int main(){
	//RightTriangle firstTriangle(1.0,1.0,1.0);
	
	//std::cout << firstTriangle.cal_perimeter();
	ShapeManager ShapeManager1;
//	
	Triangle one_triangle(1,2,3);
//
//	ShapeManager1.addShape(one_triangle);
//	ShapeManager1.printShape();
//	

	return 0;
};


