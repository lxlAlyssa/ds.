#include <iostream>
#include<fstream> 
#include <vector>
#include <cstdlib>
#include <ctime>
#include<cstring>
#include<math.h>
#include <algorithm>
//#include "../../vector1/vector1_fun.h"

using namespace std;

// 复数类的定义
class Complex {
private:
double real; // 实部
double imag; // 虚部
public:
Complex(double r = 0, double i = 0) : real(r), imag(i) {}
double getReal() const { return real; }
double getImag() const { return imag; }
double getMod() const { return sqrt(real * real + imag * imag); } // 模
bool operator<(const Complex& c) const { // 定义小于号操作符，以模为基准排序
if (getMod() != c.getMod()) return getMod() < c.getMod();
return real < c.real;
}
};

// 随机生成无序复数向量
vector<Complex> generateRandomComplexVector(int size) {
vector<Complex> vec;
for (int i = 0; i < size; i++) {
vec.push_back(Complex(rand() % 1000, rand() % 1000));
}
// 添加重复项
vec.push_back(vec[rand() % size]);
vec.push_back(vec[rand() % size]);
return vec;
}

// 起泡排序的实现
void bubbleSort(vector<Complex>& vec) {
int n = vec.size();
for (int i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
if (vec[j] < vec[j + 1]) {
swap(vec[j], vec[j + 1]);
}
}
}
}

// 归并排序的实现
void mergeSort(vector<Complex>& vec) {
if (vec.size() <= 1) return;
int mid = vec.size() / 2;
vector<Complex> left(vec.begin(), vec.begin() + mid);
vector<Complex> right(vec.begin() + mid, vec.end());
mergeSort(left);
mergeSort(right);
vec.clear();
merge(left.begin(), left.end(), right.begin(), right.end(), back_inserter(vec));
}

// 记录时间的函数
double timeIt(void (*sortFunc)(vector<Complex>&), vector<Complex>& vec) {
clock_t start = clock();
sortFunc(vec);
clock_t end = clock();
return (double)(end - start) / CLOCKS_PER_SEC;
}

int main() {
srand(time(0));
vector<Complex> vec = generateRandomComplexVector(10000);
vector<Complex> vec2 = vec;
vector<Complex> vec3 = vec;
// 顺序排序
cout << "顺序排序:" << endl;
cout << "起泡排序时间: " << timeIt(bubbleSort, vec) << "s" << endl;
cout << "归并排序时间: " << timeIt(mergeSort, vec) << "s" << endl;
// 逆序排序
reverse(vec2.begin(), vec2.end());
cout << "逆序排序:" << endl;
cout << "起泡排序时间: " << timeIt(bubbleSort, vec2) << "s" << endl;
cout << "归并排序时间: " << timeIt(mergeSort, vec2) << "s" << endl;
// 乱序排序
random_shuffle(vec3.begin(), vec3.end());
cout << "乱序排序:" << endl;
cout << "起泡排序时间: " << timeIt(bubbleSort, vec3) << "s" << endl;
cout << "归并排序时间: " << timeIt(mergeSort, vec3) << "s" << endl;
return 0;
}

