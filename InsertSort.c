#include <stdio.h>

void InsertSort1(int array[],int len){
    int i,j;
    //��һ��forѭ�� ������������
    for(i=1;i<len;i++){  //������ĵڶ���Ԫ�ؿ�ʼ���α�����������
        int tem = array[i];  //��ʱ���潫Ҫ�����Ԫ��
        //�ڶ���forѭ��������������
        for(j=i-1;tem<=array[j]&&j>=0;j--){  //��������Ԫ�����κ����������е�Ԫ�رȽ�
            //������Ԫ�� С�� ���������е�ǰԪ��ʱ ����Ԫ�غ���
            array[j+1] = array[j];
        }
        array[j+1] = tem;  //������Ԫ�� ���� �����������һ��Ԫ�� ֱ�ӽ���Ԫ�ز��뵽�����������
    }
    printf("\n�������!\n\n");
}

void Print(int* array){
    for(int i = 0;i < 10;i++){
        printf("%d ",array[i]);
    }
}

int main(){
    int i;
    int a[10] = {5,2,6,0,3,9,1,7,4,8};

    InsertSort1(a,10);

    Print(a);
}