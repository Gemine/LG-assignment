//in one brand
#include<iostream>
#include<cassert>
#include<vector>
#include <functional>
using namespace std;

class Shape
{
	protected:
        double area, perimeter;
    public:
		Shape(){};
		virtual double cal_area(){return area;};
		virtual double cal_perimeter(){return perimeter;};
		~Shape(){};
		
};

class Triangle : public Shape
{
	protected:
		double a{},b{},c{};
	public:
		Triangle(double a1,double b1,double c1):Shape()
		{
			a = a1; //first line lenght
			b = b1; //second line lenght
			c = c1; //third line lenght
		};
		~Triangle(){};
		double cal_area();
		double cal_perimeter();

};

double Triangle::cal_area(){
    return 1.0;
};
double Triangle::cal_perimeter(){
    cout << "In Triangle" <<'\n';
    return (a+b+c);
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
        cout << "In RightTriangle" <<'\n';
		return (a+b+c);
	};
};

class ShapeManager
{
	private:
		int m_lenght{0};
		vector<reference_wrapper<Shape>> m_data{}; 
	public:
		ShapeManager() = default;
		ShapeManager(int lenght):
			m_lenght{lenght}
			{
				assert(lenght>=0);
				if(lenght>0){
					vector<Shape> m_data(lenght);
				}
			};
		~ShapeManager(){
			delete[] &m_data;
		}
		Shape operator[](int index){
			assert(index >=0 && index <=m_lenght);
			return m_data[index];
		};
		void addShape(Shape &shape){
			//cout << shape.cal_perimeter()<<'\n';
			m_data.push_back(shape);
			//cout << shape.cal_perimeter()<<'\n';
		};
		void printShape(){
            //cout<<"check"<<'\n';
			for(vector<reference_wrapper<Shape>>::iterator ptr = m_data.begin();ptr!=m_data.end();++ptr){
				cout << ptr->get().cal_perimeter() << '\n';
				//cout << "10 ";
			}
		};
};
int main(){
    Shape *ptr;
	Triangle one_triangle(1,2,3);
    RightTriangle one_right_trianngle(3,1,10);
	RightTriangle two_right_trianngle(3,1,60);
    // ptr=&one_triangle;
    // cout << ptr->cal_perimeter() << '\n';
    // ptr = &one_right_trianngle;
    // cout << ptr->cal_perimeter() << '\n';
    
    ShapeManager ShapeManager1;
    ShapeManager1.addShape(one_triangle);
    ShapeManager1.addShape(one_right_trianngle);
	ShapeManager1.addShape(two_right_trianngle);
    ShapeManager1.printShape();
	return 0;
};
