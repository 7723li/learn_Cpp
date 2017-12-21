// 4.2.6复制构造函数调用举例
// 会调用复制构造函数的三种情况
#include <stdio.h>
#include <iostream>

class Point
{
	public:
		Point(int xx=0,int yy=0){x=xx;y=yy;}
		Point(const Point& p);
		~Point(){};
		void setPoint(int xx,int yy){x=xx;y=yy;}
		void showPoint();
	private:
		int x,y;
};

Point::Point(const Point& p){
	x = p.x;
	y = p.y;
	printf("A copy constructor is being invoked\n");
}

void Point::showPoint(){
	printf("%d,%d\n", x,y);
}

void func1(Point p){
	p.setPoint(20,20);
	p.showPoint();
	return;
}

// 返回值为Point类对象的函数
Point func2(){
	Point p;
	return p;// 构造一个临时无名对象
}

int main(int argc, char const *argv[])
{
	Point a(10,10);
	// 情况1:用a初始化b,第一次调用复制构造函数
	Point b(a);

	printf("1~");a.showPoint();
	printf("2~");b.showPoint();

	// 情况2:对象b作为func1的实参
	printf("3~");func1(b);

	// 情况3:函数的返回值是类对象,函数返回时调用复制构造
	b = func2();
	printf("4~");;b.showPoint();

	// system("pause");
}
