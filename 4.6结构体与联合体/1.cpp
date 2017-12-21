// 4.6.1结构体
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct stu{// 学生信息结构体
	int num; // 学号
	string name;
	char sex;
	int age;
};

int main(int argc, char const *argv[])
{
	struct stu Li;
	Li.num = 10;
	printf("%d\n", Li.num);
	
	return 0;
}
