// 4.4.3前向引用声明

class a;//前向引用声明

class b{
	public:
			void f(a A);
};

class a
{
	public:
		a();
		~a();
		void g(b B);
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
