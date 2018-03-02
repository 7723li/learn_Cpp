#include <stdio.h>
#include <iostream>
using namespace std;

class clock /*final*/ // 测试final
{
	public:
		clock(int h, int m, int s):
			h(h), m(m), s(s){}
		clock()
			{h = 0; m = 0; s = 0;}
		clock(const clock& c)
			{h = c.h; m = c.m; s = c.s;}
		virtual ~clock(){
			printf("del clock\n");
		}

		clock & operator ++();
		clock operator ++(int);

		virtual void show(){printf("%d:%d:%d\n", h, m, s);}
		void showthis()
			{printf("%p %d\n", this, sizeof(*this));}

	private:
		int h, m, s;
	
};

clock & clock::operator ++(){
	s++;
	return *this;
}

clock clock::operator ++(int a){
	clock old(*this);
	++(*this);
	return old;
}

class wacth : public clock
{
	public:
		wacth():
			h(23), m(59), s(59){}
		virtual ~wacth(){
			printf("del wacth\n");
		}
		virtual void show(){
			printf("%d - %d - %d\n", h, m, s);
		}
		void settime(){
			h = 12; m = 30; s = 30;
		}
		wacth operator +(wacth & w);
		friend ostream &operator <<(ostream &out, wacth &w);
	private:
		int h, m, s;
	
};

wacth wacth::operator +(wacth & w){
	wacth temp(*this);
	temp.s += w.s;
	return temp;
}

ostream &operator <<(ostream &out, wacth &w){
	out << "( w.h = " << w.h << " )" <<endl;
	return out;
}

void fun(clock & obj){ // 使用引用，即形参obj为实参的别名，通过改变obj即可改变实参，比指针略微方便
	printf("obj at %p\n", &obj);
	obj.show();
}

int main(int argc, char const *argv[])
{
	wacth *test = new wacth[10]; // 测试虚析构函数
	test[0].settime();
	test[0].show();
	delete test;
	printf("\n");

	clock c;
	printf("%p %d\n", &c, sizeof(c));
	c.showthis();
	c.show();
	(c++).show(); // 测试重载运算符
	(++c).show();
	printf("\n");

	wacth w;
	wacth w2 = w + w;
	wacth w3 = w + w2;
	w.showthis();
	printf("%p %d\n", &w, sizeof(w));
	fun(c);
	fun(w); // 测试虚函数
	fun(w2);
	fun(w3);
	w3.show();
	printf("\n");

	cout << w3;

	return 0;
}
