// 4.4.1类的组合
// 4.4.2类的组合程序举例
#include <iostream>
#include <cmath>
#include <stdio.h>

class Point
{
	public:
		Point(int xx=0,int yy=0){x=xx;y=yy;}
		// Point():x(0),y(0){};
		Point(Point& p);
		~Point(){}
		int getX(){ return x; }
		int getY(){ return y; }
	private:
		int x,y;
};

Point::Point(Point& p){// 复制构造函数的实现
	x = p.x;
	y =	p.y;
	printf("Calling the copy constructor of Point\n" );
}

//类的组合
class Line
{
	public:
		Line(Point xp1,Point xp2);
		Line(Line& l);
		double getLen(){return len;}
		~Line(){}
	private:
		Point p1,p2;
		double len;
};

// 组合类的构造函数
Line::Line(Point xp1,Point xp2): p1(xp1),p2(xp2) {
	printf("Calling constructor of Line\n");
	// static_cast将数据强制转换未<XXX>类型
	double x = static_cast<double>(p1.getX()-p2.getX());
	double y = static_cast<double>(p1.getY()-p2.getY());
	len = sqrt(x*x + y*y);
}

//组合类的复制构造函数
Line::Line(Line& l): p1(l.p1),p2(l.p2) {
	printf("Calling the copy constructor of Line\n");
	len = l.len;
}

int main(int argc, char const *argv[])
{
	Point myp1(1,1),myp2(4,5);
	Line line(myp1,myp2);
	Line line2(line);
	printf("length of the line:%.2f\n",line.getLen());
	printf("length of the line2:%.2f\n",line2.getLen());

	return 0;
}
