#include <iostream>
using namespace std;
 
class Integer{
private:
    int _num;
//getLength()函数获取_num长度
    int getLength(){
        int temp = _num;
        int k = 0;
        while(temp){ k++; temp /= 10; }
        return k;
    }
public:
//Integer类构造函数
    Integer(int num){
        _num = num;
    }
//反转_num
    int inversed(){
        int length = getLength();
        int res = 0,temp,k = _num;
        for(int i=length-1;i>=0;i--){
            temp = 1;
            for(int j=0;j<i;j++) temp *= 10;
            res += k % 10 * temp;
            k /= 10;
        }
        return res;
    }
};
 
int main() {
    int n;
    cin >> n;
    Integer integer(n);
    cout << integer.inversed() << endl;
    return 0;
}
