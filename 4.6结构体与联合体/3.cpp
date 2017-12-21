// 4.7.1枚举类
#include <stdio.h>

// enum class Type{ General, Light, Medium, Heavy};
enum Type{ General, Light, Medium, Heavy};

int main(int argc, char const *argv[])
{
	int a = Type(Light);
	printf("%d\n", a);
	return 0;
}
