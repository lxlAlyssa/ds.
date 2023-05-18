#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define Max 1000
long bj[Max], yd[Max];

typedef struct {
	int key;
} Data;
long i, j, k;
void show(Data R[], long n) {
	cout << "结果为：";
	for (i = 1; i <= n; i++)
		cout << R[i].key << " ";
	cout << endl;
}

//起泡排序
void Qipao(Data R[], long n) {
	Data m[Max], temp;
	for (i = 0; i <= n; i++)
		m[i] = R[i];
	for (i = 1; i < n; i++)
		for (j = 1; j <= n - i; j++) {
			bj[1]++;	                                      //比较次数加1
			if (m[j].key > m[j + 1].key) {
				temp = m[j];
				m[j] = m[j + 1];
				m[j + 1] = temp;
				yd[1] += 3;                                   //移动次数加3
			}
		}
	cout << "起泡排序";
	show(m, n);
}
//插入排序
void charu(Data R[], long n) {
	Data r[Max];
	for (i = 0; i <= n; i++)
		r[i] = R[i];
	for (i = 2; i <= n; i++) {
		bj[2]++;                                           //比较次数加1
		if (r[i].key < r[i - 1].key) {                       //需要将r[i]插入有序字表
			r[0] = r[i];
			r[i] = r[i - 1];                               //r[i-1]后移
			for (j = i - 2; r[0].key < r[j].key; j--)
				r[j + 1] = r[j];                           //记录逐个后移，直到找到插入位置
			r[j + 1] = r[0];
			yd[2] += 3;                                    //循环一次移动次数加3
		}
	}
	cout << "插入排序";
	show(r, n);
}
//选择排序
void Choice(Data R[], long  n) {
	Data c[Max], temp;
	for (i = 0; i <= n; i++)
		c[i] = R[i];
	for (i = 1; i <= n; i++) {                            //在r中选择关键字最小的记录
		k = i;
		for (j = i + 1; j <= n; j++) {
			bj[3]++;	                                 //比较次数加1
			if (c[j].key < c[k].key)
				k = j;		                             //k指向此趟关键字最小的记录
		}
		if (k != i) {
			temp = c[k];
			c[k] = c[i];
			c[i] = temp;
			yd[3] += 3;                                  //移动次数加3
		}
	}
	cout << "选择排序";
	show(c, n);
}
//快速排序  枢纽
long Partition(Data R[], long low, long high) {
	//进行一次排序，返回枢纽位置
	R[0] = R[low];                                       //子表第一个记录做枢轴
	yd[4]++;                                             //交换次数加1
	while (low < high) {
		while (low < high && R[high].key >= R[0].key) {
			bj[4]++;	                                 //比较次数加1
			high--;
		}
		if (low < high) {
			R[low] = R[high];
			low++;
			yd[4]++;	                                //移动次数加1
		}
		while (low < high && R[low].key <= R[0].key) {
			bj[4]++;
			low++;
		}
		if (low < high) {
			R[high] = R[low];
			high--;
			yd[4]++;
		}
	}
	R[low] = R[0];                                     //枢轴记录到位
	yd[4]++;	                                       //交换次数加1
	return low;	                                       //返回枢轴位置
}
void Quick(Data R[], long low, long high) {
	long n;
	n = high - low + 1;
	//low=1; high=n;
	if (low < high) {
		i = Partition(R, low, high);
		Quick(R, low, i - 1);		              //左子表递归排序
		Quick(R, i + 1, high);			          //右子表递归排序
	}

}
void Quickzhanshi(Data R[], long n) {
	cout << "快速排序";
	show(R, n);
}
//归并排序
void Merge(Data R[], Data T[], long low, long mid, long high) {
	long i = low, j = mid + 1, k = low;
	while (i <= mid && j <= high) {
		bj[5]++;	                                      //比较次数加1
		if (R[i].key <= R[j].key) {
			T[k++] = R[i++];
			yd[5]++;                                      //移动次数加1
		}
		else {
			T[k++] = R[j++];
			yd[5]++;                                      //移动次数加1
		}
	}
	while (i <= mid) {
		T[k++] = R[i++];
		yd[5]++;                                          //移动次数加1
	}
	while (j <= high) {
		T[k++] = R[j++];
		yd[5]++;                                          //移动次数加1
	}
	for (k = low; k <= high; k++) {
		R[k] = T[k];
		yd[5]++;                                          //移动次数加1
	}
}

void MSort(Data R[], Data T[], long low, long high) {
	if (low == high)
		return;
	else {
		long mid = (low + high) / 2;
		MSort(R, T, low, mid);
		MSort(R, T, mid + 1, high);
		Merge(R, T, low, mid, high);
	}
}
void Guibing(Data R[], long n) {
	Data m[Max], temp;
	for (long i = 0; i <= n; i++)
		m[i] = R[i];
	MSort(m, R, 1, n);
	cout << "归并排序";
	show(R, n);
}

int main() {
	long n;
	Data R[Max];
	cout << "数据个数为:" << endl;
	cin >> n;
	for (i = 1; i <= n; i++)
		R[i].key = rand() % 1000;	                      //电脑产生随机数
	cout << "随机产生的数字集合为:" << endl;
	for (i = 1; i <= n; i++)
		cout << R[i].key << " ";
	cout << endl;
	Qipao(R, n);                                     //起泡排序
	charu(R, n);                                     //插入排序
	Choice(R, n);                                     //选择排序
	Quick(R, 0, n);                                   //快速排序
	Quickzhanshi(R, n);                               //归并排序
	Merge(R, R, 0, n, n);
	Guibing(R, n);
	MSort(R, R, 0, n);
	cout << "结果为：" << endl;
	cout << "排序方式" << "比较次数" << "移动次数" << endl;
	cout << "起泡排序" << bj[1] << "\t\t" << yd[1] << endl;
	cout << "插入排序" << bj[2] << "\t\t" << yd[2] << endl;
	cout << "选择排序" << bj[3] << "\t\t" << yd[3] << endl;
	cout << "快速排序" << bj[4] << "\t\t" << yd[4] << endl;
	cout << "归并排序" << bj[5] << "\t\t" << yd[5] << endl;
}
