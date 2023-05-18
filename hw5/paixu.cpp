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
	cout << "���Ϊ��";
	for (i = 1; i <= n; i++)
		cout << R[i].key << " ";
	cout << endl;
}

//��������
void Qipao(Data R[], long n) {
	Data m[Max], temp;
	for (i = 0; i <= n; i++)
		m[i] = R[i];
	for (i = 1; i < n; i++)
		for (j = 1; j <= n - i; j++) {
			bj[1]++;	                                      //�Ƚϴ�����1
			if (m[j].key > m[j + 1].key) {
				temp = m[j];
				m[j] = m[j + 1];
				m[j + 1] = temp;
				yd[1] += 3;                                   //�ƶ�������3
			}
		}
	cout << "��������";
	show(m, n);
}
//��������
void charu(Data R[], long n) {
	Data r[Max];
	for (i = 0; i <= n; i++)
		r[i] = R[i];
	for (i = 2; i <= n; i++) {
		bj[2]++;                                           //�Ƚϴ�����1
		if (r[i].key < r[i - 1].key) {                       //��Ҫ��r[i]���������ֱ�
			r[0] = r[i];
			r[i] = r[i - 1];                               //r[i-1]����
			for (j = i - 2; r[0].key < r[j].key; j--)
				r[j + 1] = r[j];                           //��¼������ƣ�ֱ���ҵ�����λ��
			r[j + 1] = r[0];
			yd[2] += 3;                                    //ѭ��һ���ƶ�������3
		}
	}
	cout << "��������";
	show(r, n);
}
//ѡ������
void Choice(Data R[], long  n) {
	Data c[Max], temp;
	for (i = 0; i <= n; i++)
		c[i] = R[i];
	for (i = 1; i <= n; i++) {                            //��r��ѡ��ؼ�����С�ļ�¼
		k = i;
		for (j = i + 1; j <= n; j++) {
			bj[3]++;	                                 //�Ƚϴ�����1
			if (c[j].key < c[k].key)
				k = j;		                             //kָ����˹ؼ�����С�ļ�¼
		}
		if (k != i) {
			temp = c[k];
			c[k] = c[i];
			c[i] = temp;
			yd[3] += 3;                                  //�ƶ�������3
		}
	}
	cout << "ѡ������";
	show(c, n);
}
//��������  ��Ŧ
long Partition(Data R[], long low, long high) {
	//����һ�����򣬷�����Ŧλ��
	R[0] = R[low];                                       //�ӱ��һ����¼������
	yd[4]++;                                             //����������1
	while (low < high) {
		while (low < high && R[high].key >= R[0].key) {
			bj[4]++;	                                 //�Ƚϴ�����1
			high--;
		}
		if (low < high) {
			R[low] = R[high];
			low++;
			yd[4]++;	                                //�ƶ�������1
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
	R[low] = R[0];                                     //�����¼��λ
	yd[4]++;	                                       //����������1
	return low;	                                       //��������λ��
}
void Quick(Data R[], long low, long high) {
	long n;
	n = high - low + 1;
	//low=1; high=n;
	if (low < high) {
		i = Partition(R, low, high);
		Quick(R, low, i - 1);		              //���ӱ�ݹ�����
		Quick(R, i + 1, high);			          //���ӱ�ݹ�����
	}

}
void Quickzhanshi(Data R[], long n) {
	cout << "��������";
	show(R, n);
}
//�鲢����
void Merge(Data R[], Data T[], long low, long mid, long high) {
	long i = low, j = mid + 1, k = low;
	while (i <= mid && j <= high) {
		bj[5]++;	                                      //�Ƚϴ�����1
		if (R[i].key <= R[j].key) {
			T[k++] = R[i++];
			yd[5]++;                                      //�ƶ�������1
		}
		else {
			T[k++] = R[j++];
			yd[5]++;                                      //�ƶ�������1
		}
	}
	while (i <= mid) {
		T[k++] = R[i++];
		yd[5]++;                                          //�ƶ�������1
	}
	while (j <= high) {
		T[k++] = R[j++];
		yd[5]++;                                          //�ƶ�������1
	}
	for (k = low; k <= high; k++) {
		R[k] = T[k];
		yd[5]++;                                          //�ƶ�������1
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
	cout << "�鲢����";
	show(R, n);
}

int main() {
	long n;
	Data R[Max];
	cout << "���ݸ���Ϊ:" << endl;
	cin >> n;
	for (i = 1; i <= n; i++)
		R[i].key = rand() % 1000;	                      //���Բ��������
	cout << "������������ּ���Ϊ:" << endl;
	for (i = 1; i <= n; i++)
		cout << R[i].key << " ";
	cout << endl;
	Qipao(R, n);                                     //��������
	charu(R, n);                                     //��������
	Choice(R, n);                                     //ѡ������
	Quick(R, 0, n);                                   //��������
	Quickzhanshi(R, n);                               //�鲢����
	Merge(R, R, 0, n, n);
	Guibing(R, n);
	MSort(R, R, 0, n);
	cout << "���Ϊ��" << endl;
	cout << "����ʽ" << "�Ƚϴ���" << "�ƶ�����" << endl;
	cout << "��������" << bj[1] << "\t\t" << yd[1] << endl;
	cout << "��������" << bj[2] << "\t\t" << yd[2] << endl;
	cout << "ѡ������" << bj[3] << "\t\t" << yd[3] << endl;
	cout << "��������" << bj[4] << "\t\t" << yd[4] << endl;
	cout << "�鲢����" << bj[5] << "\t\t" << yd[5] << endl;
}
