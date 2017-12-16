// 析构函数
#include <iostream>
using namespace std;

class Point
{
	public:
		Point(int x,int y);
		~Point();// 析构函数
		inline void print(){cout<<xx<<','<<yy<<endl;}

	private:
		int xx,yy;
};

Point::Point(int x,int y):
	xx(x),yy(y){

	}

Point::~Point(){}// 资源消亡时自动调用,不带返回值，参数表

int main(int argc, char const *argv[])
{
	Point p(1,1);
	p.print();
	return 0;
}
