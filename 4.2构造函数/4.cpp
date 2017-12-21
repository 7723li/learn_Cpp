// 复制构造函数
#include <iostream>

class Point
{
	public:
		Point(int x=0,int y=0){x=x;y=y;}// 构造函数
		Point(const Point& p);// 复制构造函数
		~Point();// 析构函数
	private:
		int x,y;
};


Point::Point(const Point &p){// 复制构造函数的实现
			
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
