#include <stdio.h>

//����˵����
//a -- �����������
//n -- ����ĳ���

void Shell_Sort(int* array,int size){
    int i,j,gap;
    // gapΪ������ÿ�μ�Ϊԭ����һ��
    for( gap = size / 2;gap > 0;gap /= 2){
        //��gap�����飬��ÿһ�鶼ִ��ֱ�Ӳ������
        for(i = 0;i < gap;i++){
            for(j = i + gap;j < size;j += gap){
                //��� array[j] < array[j - gap],��Ѱ��a[j]��λ�ã����������λ�ö�����
                if( array[j] < array[j - gap] ){
                    int temp = array[j];
                    int k = j - gap;
                    while( k >= 0 && array[k] > temp){
                        array[k + gap] = array[k];
                        k -= gap;
                    }
                    array[k + gap] = temp;
                }
            }
        }
    }
}

void Print(int* array,int size){
    for(int i = 0;i < size;i++){
        printf("%d ",array[i]);
    }
}

int main(){
    int a[10] = {7,2,6,5,4,1,3,9,8,10};

    Shell_Sort(a,10);

    Print(a,10);

    return 0;
}