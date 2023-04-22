#include <stdio.h>

void InsertSort1(int array[],int len){
    int i,j;
    //第一个for循环 遍历无序序列
    for(i=1;i<len;i++){  //从数组的第二个元素开始依次遍历无序序列
        int tem = array[i];  //临时保存将要排序的元素
        //第二个for循环遍历有序序列
        for(j=i-1;tem<=array[j]&&j>=0;j--){  //将待排序元素依次和有序序列中的元素比较
            //待排序元素 小于 有序序列中当前元素时 将该元素后移
            array[j+1] = array[j];
        }
        array[j+1] = tem;  //待排序元素 大于 有序序列最后一个元素 直接将该元素插入到有序序列最后
    }
    printf("\n排序完成!\n\n");
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