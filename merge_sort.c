#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void QSort(int x[ ], int left, int right);
void Swap(int x[ ], int i, int j);
void sort_and_array(FILE* fp, int size, char* file);
void merge_file(char* file1, char* file2, char* file3);  // file1とfile2をマージしてfile3を作る

int* array = (int*)malloc(1000*1000*1000);
int* buffer = (int*)malloc(1000 * 1000);


void QSort(int x[ ], int left, int right)
{
    int i, j;
    int pivot;
    
    i = left;                      /* ソートする配列の一番小さい要素の添字 */
    j = right;                     /* ソートする配列の一番大きい要素の添字 */
    
    pivot = x[(left + right) / 2]; /* 基準値を配列の中央付近にとる */
    
    while (1) {                    /* 無限ループ */
        
        while (x[i] < pivot)       /* pivot より大きい値が */
            i++;                   /* 出るまで i を増加させる */
        
        while (pivot < x[j])       /* pivot より小さい値が */
            j--;                   /*  出るまで j を減少させる */
        if (i >= j)                /* i >= j なら */
            break;                 /* 無限ループから抜ける */
        
        Swap(x, i, j);             /* x[i] と x[j]を交換 */
        i++;                       /* 次のデータ */
        j--;
    }
    
    if (left < i - 1)              /* 基準値の左に 2 以上要素があれば */
        QSort(x, left, i - 1);     /* 左の配列を Q ソートする */
    if (j + 1 <  right)            /* 基準値の右に 2 以上要素があれば */
        QSort(x, j + 1, right);    /* 右の配列を Q ソートする */
}

/* 配列の要素を交換する */
void Swap(int x[ ], int i, int j)
{
    int temp;
    
    temp = x[i];
    x[i] = x[j];
    x[j] = temp;
}

void sort_and_array(FILE* fp, int size, char* file, int* array, int* buffer){
    int i,j;
    int count=0;
    FILE* fp2 = fopen(file, "wb");
    
    while(count!=250*1000*1000){
        fread(&(array[count]), sizeof(int), 1, fp);
        count++;
        printf("%d\n",array[count]);
    }
    
    QSort(array, 0, 250*1000*1000-1);//内部整列する
    
    for (i = 0; i < size; i++) {
        int num =  100*1000/ sizeof(int);
        for (j = 0; j < num; j++) {
            buffer[j] = array[j];
        }
        size_t ret = fwrite(buffer, sizeof(int), num, fp2);
        if (ret != num) {
            printf("error: Failed in writing bytes to the file sort6\n");
            exit(1);
        }
    }
    
    fclose(fp2);
    
    
}
void merge_file(char* file1, char* file2, char* file3){
    int a, b;
    FILE* fp1 = fopen(file1, "rb");
    FILE* fp2 = fopen(file2, "rb");
    FILE* fpmerge1 = fopen(file3, "wb");//マージしたデータを入れるファイル
    
    fread(&a, sizeof(int), 1, fp1);
    fread(&b, sizeof(int), 1, fp2);
    while(a!=0&&b!=0){
        if (a<=b) {
            fwrite(&a, sizeof(int), 1, fpmerge1);
            fread(&a, sizeof(int), 1, fp1);
        }
        else{
            fwrite(&b, sizeof(int), 1, fpmerge1);
            fread(&b, sizeof(int), 1, fp2);
        }
    }
    if(a==0){
        while(b!=0){
            fwrite(&b, sizeof(int), 1, fpmerge1);
            fread(&b, sizeof(int), 1, fp2);
        }
    }
    else{
        while(b!=0){
            fwrite(&a, sizeof(int), 1, fpmerge1);
            fread(&a, sizeof(int), 1, fp1);
        }
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fpmerge1);
    }

int main(int argc, char** argv){
 

    if(array == 0) {
        fprintf(stderr, "メモリ確保エラー\n");
        exit(1);
    }
    
    if (argc != 3) {
        printf("usage: %s <filename> <size (MB)>\n", argv[0]);
        return -1;
    }
    
    char* filename = argv[1];
    int size = atoi(argv[2]);
    FILE* fp = fopen(filename, "rb");
    
    if (fp == NULL) {
        printf("error: Cannot open file %s\n", filename);
        return -1;
    }
    
     //1GB分のデータずつ整列し、１０個のファイルに書き込む
    sort_and_array(fp, size, "sort1");
    sort_and_array(fp, size, "sort2");
    sort_and_array(fp, size, "sort3");
    sort_and_array(fp, size, "sort4");
    sort_and_array(fp, size, "sort5");
    sort_and_array(fp, size, "sort6");
    sort_and_array(fp, size, "sort7");
    sort_and_array(fp, size, "sort8");
    sort_and_array(fp, size, "sort9");
    sort_and_array(fp, size, "sort10");
    fclose(fp);
    free(array);
    free(buffer);
    
    //10個にわかれた1KBのデータをマージする
    merge_file("sort1", "sort2", "merge1_1");
    merge_file("sort3", "sort4", "merge1_2");
    merge_file("sort5", "sort6", "merge1_3");
    merge_file("sort7", "sort8", "merge1_4");
    merge_file("sort9", "sort10", "merge1_5");
    
    //5個にわかれた２KBのデータをマージする
    merge_file("merge1_1", "merge1_2", "merge2_1");
    merge_file("merge1_3", "merge1_4", "merge2_2");
    merge_file("merge2_1", "merge1_5", "merge2_3");
    
    //２個にわかれた４KBと6KBのデータをマージする
    merge_file("merge2_2", "merge2_3", "result10000");

    return 0;
    
}