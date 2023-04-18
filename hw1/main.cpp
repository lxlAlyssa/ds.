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

// ������Ķ���
class Complex {
private:
double real; // ʵ��
double imag; // �鲿
public:
Complex(double r = 0, double i = 0) : real(r), imag(i) {}
double getReal() const { return real; }
double getImag() const { return imag; }
double getMod() const { return sqrt(real * real + imag * imag); } // ģ
bool operator<(const Complex& c) const { // ����С�ںŲ���������ģΪ��׼����
if (getMod() != c.getMod()) return getMod() < c.getMod();
return real < c.real;
}
};

// �����������������
vector<Complex> generateRandomComplexVector(int size) {
vector<Complex> vec;
for (int i = 0; i < size; i++) {
vec.push_back(Complex(rand() % 1000, rand() % 1000));
}
// ����ظ���
vec.push_back(vec[rand() % size]);
vec.push_back(vec[rand() % size]);
return vec;
}

// ���������ʵ��
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

// �鲢�����ʵ��
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

// ��¼ʱ��ĺ���
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
// ˳������
cout << "˳������:" << endl;
cout << "��������ʱ��: " << timeIt(bubbleSort, vec) << "s" << endl;
cout << "�鲢����ʱ��: " << timeIt(mergeSort, vec) << "s" << endl;
// ��������
reverse(vec2.begin(), vec2.end());
cout << "��������:" << endl;
cout << "��������ʱ��: " << timeIt(bubbleSort, vec2) << "s" << endl;
cout << "�鲢����ʱ��: " << timeIt(mergeSort, vec2) << "s" << endl;
// ��������
random_shuffle(vec3.begin(), vec3.end());
cout << "��������:" << endl;
cout << "��������ʱ��: " << timeIt(bubbleSort, vec3) << "s" << endl;
cout << "�鲢����ʱ��: " << timeIt(mergeSort, vec3) << "s" << endl;
return 0;
}

