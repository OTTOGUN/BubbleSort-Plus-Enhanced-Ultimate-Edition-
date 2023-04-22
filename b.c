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
    printf("�ܹ�������%d�αȽ�,������%d���ƶ�\n",count1,count2);
}

//ð�����������:������ ���1,2,3,5,4 ����ֻ��Ҫ��һ�ε����ݣ������ٴαȽ�
void BubbleSort_Optimize_1(int* a,int size)
{
    int count1 = 0,count2 = 0;
    assert(a);
    if(size==1)
        return;

    bool flag=0;//�����־λ����Ѿ����������
    for(int i=0;i<size-1;i++)
    {
        flag=1;//��ʼ��Ϊ1
        for(int j=0;j<size-1-i;j++)
        {
            count1++;
            if(a[j]>a[j+1])
            {
                int tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
                flag=0;//�������flag��0����ʾ�Ѿ�����
                count2++;
            }
        }
        if(flag)
            break;//���flagΪ1��˵������ǰ�Ѿ�����
    }
    printf("�ܹ�������%d�αȽ�,������%d���ƶ�\n",count1,count2);
}

//ð������ƽ��:������
void BubbleSort3(int* array,int n){
    assert(array);
    if(n == 1){
        return;
    }

    bool flag = 0;      //�����־λ����Ѿ����������
    int index = n - 1;
    int max_index = 0;  //ÿһ���ҵ����������Ͻ�
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
    printf("�ܹ�������%d�αȽ�,������%d���ƶ�\n",count1,count2);
}
//ð�������ռ���:������
void BubbleSort4(int* a,int size) {
    assert(a);
    if (size == 1)
        return;

    int max_index = 0;//ÿһ���������ǵõ����������Ͻ�
    int min_index = 0;//ÿһ���������ǵõ����������½�
    int index = size - 1;
    bool flag = 0;//�����־λ����Ѿ����������
    int count1 = 0,count2 = 0;

    for (int i = 0; i < size - 1; i++) {
        flag = 1;//��ʼ��Ϊ1
        min_index = 0;//����Ҳ���Բ�д
        for (int j = 0; j < index; j++) {
            count1++;
            //����ɨ���ҵ����ֵ
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                flag = 0;//�������flag��0����ʾ�Ѿ�����
                max_index = j;//ע�ⲻҪ������ֱ�ӽ�max_index��Ϊj
                count2++;
            }
        }
        if (flag)
            break;//���flagΪ1��˵������ǰ�Ѿ�����
        index = max_index;//���������index��Ϊ���һ�ν��������꣬��û�����ʾ�Ѿ�����

        for (int j = index; j > min_index; j--) {
            //����ɨ���ҵ���Сֵ
            if (a[j] < a[j - 1]) {
                int tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
                flag = 0;//�������flag��0����ʾ�Ѿ�����
            }
        }
        min_index++;
        if (flag)
            break;//���flagΪ1��˵������ǰ�Ѿ�����
    }
    printf("�ܹ�������%d�αȽ�,������%d���ƶ�\n",count1,count2);
}

int main(){
    int i = 0;
    int a[10] = {4,3,2,1,0,5,6,7,8,9};
    int b[10] = {4,3,2,1,0,5,6,7,8,9};
    int c[10] = {4,3,2,1,0,5,6,7,8,9};
    int d[10] = {4,3,2,1,0,5,6,7,8,9};

    BubbleSort1(a,10);

    printf("�����Ľ��: ");
    for(i = 0;i < 10;i++){
        printf("%d ",a[i]);
    }
    printf("\n\n");

    BubbleSort_Optimize_1(b,10);

    printf("�����Ľ��: ");
    for(i = 0;i < 10;i++){
        printf("%d ",b[i]);
    }
    printf("\n\n");

    BubbleSort3(c,10);

    printf("�����Ľ��: ");
    for(i = 0;i < 10;i++){
        printf("%d ",c[i]);
    }
    printf("\n\n");

    BubbleSort4(d,10);

    printf("�����Ľ��: ");
    for(i = 0;i < 10;i++){
        printf("%d ",d[i]);
    }
    printf("\n\n");
    return 0;
}