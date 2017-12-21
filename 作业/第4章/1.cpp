// C4-1 最大公约数  
#include <iostream>
using namespace std;
class Integer {
	private:
	    int _num;
	public:
	//构造函数
	    Integer(int num) {
	    	_num = num;
	    }
	//计算当前Integer 和 b之间的最大公约数
    int gcd(Integer b) {
    	int c,mid,d;
    	if(_num == b._num) return _num;
    	if(_num > b._num) { c = _num;d = b._num; }
    	if(_num < b._num) { c = b._num;d = _num; }
    	while(d){
    		mid = d;
    		d = c-c/d*d;
    		c = mid;
    	}
    	return c;
    }
};
int main(){
    int a, b;
    cin >> a >> b;
    Integer A(a);
    Integer B(b);
    cout << A.gcd(B) << endl;
    return 0;
}
