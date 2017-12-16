// 时钟类
// 4.1.1类和对象的定义
// 4.1.2类和对象的程序举例
#include <stdio.h>
#include <iostream>

class Clock{
	public:
		void setTime(int newH=0,int newM=0,int newS=0);
		void showTime();
		inline void test(){printf("test\n");};// 内联函数
	private:// 默认
		int hour,minute,second;// 类内初始值
};

void Clock::setTime(int newH,int newM,int newS){
	hour = newH;
	minute = newM;
	second = newS;
}

void Clock::showTime(){
	printf("%d:%d:%d\n", hour,minute,second);
}

int main(int argc, char const *argv[])
{
	Clock myClock;
	myClock.test();
	myClock.setTime(8,30);
	myClock.showTime();
	return 0;
}
