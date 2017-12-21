// 4.6.2联合体
#include <string>
#include <iostream>
using namespace std;

class ExamInfo
{
	public:
		ExamInfo(string name, char g):
			name(name),mode(Grade),grade(g){}
		ExamInfo(string name, bool p):
			name(name),mode(Pass),pass(p){}
		ExamInfo(string name, int per):
			name(name),mode(Percentage),
			percentage(per){}
		~ExamInfo(){}
		void show();
	private:
		string name;
		enum { Grade,Pass,Percentage } mode;
		union{
			char grade;
			bool pass;
			int percentage;
		};
};

void ExamInfo::show(){
	cout << name << ' ' ;
	switch(mode){
		case Grade:printf("%c\n", grade);break;
		case Pass:printf("%s\n", pass?"Yes":"No");break;
		case Percentage:printf("%d\n", percentage);break;
	}
}

int main(int argc, char const *argv[])
{
	ExamInfo course1("English",'B');
	ExamInfo course2("Math",true);
	ExamInfo course3("C++",85);
	course1.show();
	course2.show();
	course3.show();

	return 0;
}
