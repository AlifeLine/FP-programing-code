#include<stdio.h>
#define MAXN 26

int main()
{
    //ÿһ�ֳ��������� 
    int N;
    //����������װ�����ֵ�˫������
    int A[MAXN], B[MAXN];
    //��¼������
    while (scanf("%d", &N) && N)
    {
        int i;
        //�ֱ��ȡ���A��B����
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < N; i++)
        {
            scanf("%d",&B[i]);
        }
        //��¼ÿһ����ҵ��Ƶ��                        
        int pointsA = 0;
        int pointsB = 0;
        for (int i = 0; i < N; i++)
        {
            if (A[i] > B[i])
            {
                if (A[i] == 2 && B[i] == 1)
                    pointsB += 6;
                else if (A[i] - B[i] == 1)
                    pointsB += (A[i] + B[i]);
                else
                    pointsA += A[i];
            }
            else if (A[i] < B[i])
            {
                if (A[i] == 1 && B[i] == 2)
                    pointsA += 6;
                else if (B[i] - A[i] == 1)
                    pointsA += (A[i] + B[i]);
                else
                    pointsB += B[i];
            }
        }
        printf("A has %d points. B has %d points.\n", pointsA, pointsB);
    }
    return 0;
}