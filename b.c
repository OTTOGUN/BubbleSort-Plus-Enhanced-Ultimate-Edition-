#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

void BubbleSort1(int* array,int n){
    int i,j,temp,count1 = 0,count2 = 0;

    for(i = 0;i < n - 1;i++){
        for(j = i + 1;j < n;j++){
            count1++;
            if(array[i] > array[j]){
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
                count2++;
            }
        }
    }
    printf("总共进行了%d次比较,进行了%d次移动\n",count1,count2);
}

//冒泡排序白银版:》》》 针对1,2,3,5,4 这种只需要排一次的数据，无需再次比较
void BubbleSort_Optimize_1(int* a,int size)
{
    int count1 = 0,count2 = 0;
    assert(a);
    if(size==1)
        return;

    bool flag=0;//定义标志位标记已经有序或无序
    for(int i=0;i<size-1;i++)
    {
        flag=1;//开始置为1
        for(int j=0;j<size-1-i;j++)
        {
            count1++;
            if(a[j]>a[j+1])
            {
                int tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
                flag=0;//交换后对flag置0，表示已经有序
                count2++;
            }
        }
        if(flag)
            break;//如果flag为1则说明排序前已经有序
    }
    printf("总共进行了%d次比较,进行了%d次移动\n",count1,count2);
}

//冒泡排序黄金版:》》》
void BubbleSort3(int* array,int n){
    assert(array);
    if(n == 1){
        return;
    }

    bool flag = 0;      //定义标志位标记已经有序或无序
    int index = n - 1;
    int max_index = 0;  //每一次找到无序区的上界
    int count1 = 0, count2 = 0;

    for(int i = 0;i < n - 1;i++){
        flag = 1;
        for(int j = 0;j < index;j++){
            count1++;
            if(array[j] > array[j + 1]){
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                flag = 0;
                max_index = j;
                count2++;
            }
        }
        if(flag)
            break;
        index = max_index;
    }
    printf("总共进行了%d次比较,进行了%d次移动\n",count1,count2);
}
//冒泡排序终极版:》》》
void BubbleSort4(int* a,int size) {
    assert(a);
    if (size == 1)
        return;

    int max_index = 0;//每一次排序我们得到无序区的上界
    int min_index = 0;//每一次排序我们得到无序区的下界
    int index = size - 1;
    bool flag = 0;//定义标志位标记已经有序或无序
    int count1 = 0,count2 = 0;

    for (int i = 0; i < size - 1; i++) {
        flag = 1;//开始置为1
        min_index = 0;//这里也可以不写
        for (int j = 0; j < index; j++) {
            count1++;
            //正序扫描找到最大值
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                flag = 0;//交换后对flag置0，表示已经有序
                max_index = j;//注意不要在这里直接将max_index置为j
                count2++;
            }
        }
        if (flag)
            break;//如果flag为1则说明排序前已经有序
        index = max_index;//若排序过则将index置为最后一次交换的坐标，若没有则表示已经有序

        for (int j = index; j > min_index; j--) {
            //逆序扫描找到最小值
            if (a[j] < a[j - 1]) {
                int tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
                flag = 0;//交换后对flag置0，表示已经有序
            }
        }
        min_index++;
        if (flag)
            break;//如果flag为1则说明排序前已经有序
    }
    printf("总共进行了%d次比较,进行了%d次移动\n",count1,count2);
}

int main(){
    int i = 0;
    int a[10] = {4,3,2,1,0,5,6,7,8,9};
    int b[10] = {4,3,2,1,0,5,6,7,8,9};
    int c[10] = {4,3,2,1,0,5,6,7,8,9};
    int d[10] = {4,3,2,1,0,5,6,7,8,9};

    BubbleSort1(a,10);

    printf("排序后的结果: ");
    for(i = 0;i < 10;i++){
        printf("%d ",a[i]);
    }
    printf("\n\n");

    BubbleSort_Optimize_1(b,10);

    printf("排序后的结果: ");
    for(i = 0;i < 10;i++){
        printf("%d ",b[i]);
    }
    printf("\n\n");

    BubbleSort3(c,10);

    printf("排序后的结果: ");
    for(i = 0;i < 10;i++){
        printf("%d ",c[i]);
    }
    printf("\n\n");

    BubbleSort4(d,10);

    printf("排序后的结果: ");
    for(i = 0;i < 10;i++){
        printf("%d ",d[i]);
    }
    printf("\n\n");
    return 0;
}