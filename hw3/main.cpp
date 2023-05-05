
#include<iostream>
#include<cstring>
using namespace std;

#define  N_CHAR (0x80 - 0x20) //���Կɴ�ӡ�ַ�Ϊ��
struct HuffChar { //Huffman�������ַ�
    char ch; unsigned int weight; //�ַ���Ƶ��
    HuffChar(char c = '^', unsigned int w = 0) : ch(c), weight(w) {};
    // �Ƚ������е�����������һ���������в��䣩
    bool operator< (HuffChar const& hc) { return weight > hc.weight; } //�˴������С�ߵ�
    bool operator== (HuffChar const& hc) { return weight == hc.weight; }

};


int main()
{
    char s[10000] = "But one hundred years later, the Negro still is not free.One hundred years later, the life of the Negro is still sadly crippled by the manacles of segregationand the chains of discrimination.One hundred years later, the Negro lives on a lonely island of poverty in the midst of a vast ocean of material prosperity.One hundred years later, the Negro is still languished in the corners of American societyand finds himself an exile in his own land.";
    int a[26] = { 0 };
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            a[s[i] - 'a']++;
        }
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            a[s[i] - 'A']++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != 0)
        {
            cout << (char)(i + 'a') << ":" << a[i] << endl;
        }
    }
    return 0;
}





