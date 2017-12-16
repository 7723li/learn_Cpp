// 4.2.2构造函数例题（1）
// 4.2.2构造函数例题（2）

#include <stdio.h>
#include <iostream>

class Clock{
	public:
		Clock(int newH,int newM,int newS);// 构造函数
		Clock();// 默认构造函数
		void setTime(int newH=0,int newM=0,int newS=0);
		void showTime();
		inline void test(){printf("test\n");};// 内联函数
	private:// 默认
		int hour,minute,second;// 类内初始值
};

// 构造函数的实现
Clock::Clock(int newH,int newM,int newS):
	// 数值初始化
	hour(newH),minute(newM),second(newS){ showTime(); }

// 默认构造函数的实现
Clock::Clock():
	// 数值初始化
	hour(0),minute(0),second(0){}

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
	Clock myClock(9,30,0);// 初始化自动调用构造函数
	// myClock.showTime();
	myClock.setTime(8,20);
	myClock.showTime();

	Clock myClock2;// 初始化自动调用默认构造函数
	myClock2.showTime();
	myClock2.setTime(12,12,12);
	myClock2.showTime();
	return 0;
}
