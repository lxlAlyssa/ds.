#pragma once
#include"Graph.h"
#include"vector.h"

template < typename Tv, typename Te> //�����������DFS�㷨��ȫͼ��
void Graph<Tv, Te>::dfs(Rank s) { // s < n
	reset(); Rank clock = 0; //ȫͼ��λ
	for (Rank v = s; v < s + n; v++) //��s��˳�μ�����ж���
		if (UNDISCOVERED == status(v % n)) //һ��������δ������
			DFS(v % n, clock); //��������������һ��DFS

} //��˿���������ȫͼ�������帴�Ӷ���Ȼ����ΪO(n+e)

template < typename Tv, typename Te> //�����������DFS�㷨��������ͨ��
void Graph<Tv, Te>::DFS(Rank v, Rank& clock) { // v < n
	dTime(v) = clock++; status(v) = DISCOVERED; //���ֵ�ǰ����v
	for (Rank u = firstNbr(v); -1 != u; u = nextNbr(v, u)) //����v��ÿһ���ھ�u
		switch (status(u)) { //������״̬�ֱ���
		case UNDISCOVERED: // u��δ���֣���ζ��֧�������ڴ���չ
			type(v, u) = TREE; parent(u) = v; DFS(u, clock); break;
		case DISCOVERED: // u�ѱ����ֵ���δ������ϣ�Ӧ�������ָ�������
			type(v, u) = BACKWARD; break;
		default: // u�ѷ�����ϣ�VISITED������ͼ�������ӳ�Ϯ��ϵ��Ϊǰ��߻���
			type(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS; break;

		}
	status(v) = VISITED; fTime(v) = clock++; //���ˣ���ǰ����v����������

}