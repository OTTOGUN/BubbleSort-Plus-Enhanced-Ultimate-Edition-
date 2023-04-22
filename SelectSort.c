#include <stdio.h>

void SelectSort(int* array,int size){
    int i,j,min,temp,count1 = 0,count2 = 0;

    for(i = 0;i < size - 1;i++){        //�������滻��Ԫ��
        min = i;
        count1++;
        for(j = i + 1;j < size;j++){    //ѡ����Сֵ
            if(array[j] < array[min]){
                min = j;
            }
        }
        if( min != i){                  //����Ԫ���滻
            temp = array[min];
            array[min] = array[i];
            array[i] = temp;
            count2++;
        }
    }
    printf("�ܹ�������%d�αȽ�,������%d��λ��\n",count1,count2);
}

int main(){
    int a[10] = {5,2,6,0,3,9,1,7,4,8};

    SelectSort(a,10);

    for(int i = 0;i < 10;i++){
        printf("%d ",a[i]);
    }
}