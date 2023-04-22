#include <stdio.h>

//参数说明：
//a -- 待排序的数组
//n -- 数组的长度

void Shell_Sort(int* array,int size){
    int i,j,gap;
    // gap为步长，每次减为原来的一半
    for( gap = size / 2;gap > 0;gap /= 2){
        //共gap个数组，对每一组都执行直接插入程序
        for(i = 0;i < gap;i++){
            for(j = i + gap;j < size;j += gap){
                //如果 array[j] < array[j - gap],则寻找a[j]的位置，并将后面的位置都后移
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