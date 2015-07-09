#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void QSort(int x[ ], int left, int right);
void Swap(int x[ ], int i, int j);

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


int main(int argc, char** argv){
    int *array;
    array = (int*)malloc(1000*1000*1000);
      int count;
    
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
    //1GB分のデータを整列し、ファイルに書き込む(1/10)
    count = 0;
    while(count!=250*1000*1000){
        fread(&(array[count]), sizeof(int), 1, fp);
        count++;
        printf("%d\n",array[count]);
    }
    
    QSort(array, 0, 250*1000*1000-1);

    FILE* fp2 = fopen("sort1", "wb");
    int i, j;
    int* buffer = (int*)malloc(100*1000);
    for (i = 0; i < size; i++) {
        int num =  100*1000/ sizeof(int);
        for (j = 0; j < num; j++) {
            buffer[j] = array[j];
        }
        size_t ret = fwrite(buffer, sizeof(int), num, fp2);
        if (ret != num) {
            printf("error: Failed in writing bytes to the file sort1\n");
            return -1;
        }
    }
    fclose(fp2);

    //1GB分のデータを整列し、ファイルに書き込む(2/10)
    count = 0;
    while(count!=250*1000*1000){
        fread(&(array[count]), sizeof(int), 1, fp);
        count++;
        printf("%d\n",array[count]);
    }
    
    QSort(array, 0, 250*1000*1000-1);
    
    FILE* fp3 = fopen("sort2", "wb");
    for (i = 0; i < size; i++) {
        int num =  100*1000/ sizeof(int);
        for (j = 0; j < num; j++) {
            buffer[j] = array[j];
        }
        size_t ret = fwrite(buffer, sizeof(int), num, fp3);
        if (ret != num) {
            printf("error: Failed in writing bytes to the file sort2\n");
            return -1;
        }
    }
    fclose(fp3);
    
    //1GB分のデータを整列し、ファイルに書き込む(3/10)
    count = 0;
    while(count!=250*1000*1000){
        fread(&(array[count]), sizeof(int), 1, fp);
        count++;
        printf("%d\n",array[count]);
    }
    
    QSort(array, 0, 250*1000*1000-1);
    
    FILE* fp4 = fopen("sort3", "wb");
    for (i = 0; i < size; i++) {
        int num =  100*1000/ sizeof(int);
        for (j = 0; j < num; j++) {
            buffer[j] = array[j];
        }
        size_t ret = fwrite(buffer, sizeof(int), num, fp4);
        if (ret != num) {
            printf("error: Failed in writing bytes to the file sort3\n");
            return -1;
        }
    }
    fclose(fp4);
    //1GB分のデータを整列し、ファイルに書き込む(4/10)
    count = 0;
    while(count!=250*1000*1000){
        fread(&(array[count]), sizeof(int), 1, fp);
        count++;
        printf("%d\n",array[count]);
    }
    
    QSort(array, 0, 250*1000*1000-1);
    
    FILE* fp5 = fopen("sort4", "wb");
    for (i = 0; i < size; i++) {
        int num =  100*1000/ sizeof(int);
        for (j = 0; j < num; j++) {
            buffer[j] = array[j];
        }
        size_t ret = fwrite(buffer, sizeof(int), num, fp5);
        if (ret != num) {
            printf("error: Failed in writing bytes to the file sort4\n");
            return -1;
        }
    }
    fclose(fp5);
    //1GB分のデータを整列し、ファイルに書き込む(5/10)
    count = 0;
    while(count!=250*1000*1000){
        fread(&(array[count]), sizeof(int), 1, fp);
        count++;
        printf("%d\n",array[count]);
    }
    
    QSort(array, 0, 250*1000*1000-1);
    
    FILE* fp6 = fopen("sort5", "wb");
    for (i = 0; i < size; i++) {
        int num =  100*1000/ sizeof(int);
        for (j = 0; j < num; j++) {
            buffer[j] = array[j];
        }
        size_t ret = fwrite(buffer, sizeof(int), num, fp6);
        if (ret != num) {
            printf("error: Failed in writing bytes to the file sort5\n");
            return -1;
        }
    }
    fclose(fp6);
    //1GB分のデータを整列し、ファイルに書き込む(6/10)
    count = 0;
    while(count!=250*1000*1000){
        fread(&(array[count]), sizeof(int), 1, fp);
        count++;
        printf("%d\n",array[count]);
    }
    
    QSort(array, 0, 250*1000*1000-1);
    
    FILE* fp7 = fopen("sort6", "wb");
    for (i = 0; i < size; i++) {
        int num =  100*1000/ sizeof(int);
        for (j = 0; j < num; j++) {
            buffer[j] = array[j];
        }
        size_t ret = fwrite(buffer, sizeof(int), num, fp7);
        if (ret != num) {
            printf("error: Failed in writing bytes to the file sort6\n");
            return -1;
        }
    }
    fclose(fp7);
    //1GB分のデータを整列し、ファイルに書き込む(7/10)
    count = 0;
    while(count!=250*1000*1000){
        fread(&(array[count]), sizeof(int), 1, fp);
        count++;
        printf("%d\n",array[count]);
    }
    
    QSort(array, 0, 250*1000*1000-1);
    
    FILE* fp8 = fopen("sort7", "wb");
    for (i = 0; i < size; i++) {
        int num =  100*1000/ sizeof(int);
        for (j = 0; j < num; j++) {
            buffer[j] = array[j];
        }
        size_t ret = fwrite(buffer, sizeof(int), num, fp8);
        if (ret != num) {
            printf("error: Failed in writing bytes to the file sort7\n");
            return -1;
        }
    }
    fclose(fp8);
    //1GB分のデータを整列し、ファイルに書き込む(8/10)
    count = 0;
    while(count!=250*1000*1000){
        fread(&(array[count]), sizeof(int), 1, fp);
        count++;
        printf("%d\n",array[count]);
    }
    
    QSort(array, 0, 250*1000*1000-1);
    
    FILE* fp9 = fopen("sort8", "wb");
    for (i = 0; i < size; i++) {
        int num =  100*1000/ sizeof(int);
        for (j = 0; j < num; j++) {
            buffer[j] = array[j];
        }
        size_t ret = fwrite(buffer, sizeof(int), num, fp9);
        if (ret != num) {
            printf("error: Failed in writing bytes to the file sort8\n");
            return -1;
        }
    }
    fclose(fp9);
    //1GB分のデータを整列し、ファイルに書き込む(9/10)
    count = 0;
    while(count!=250*1000*1000){
        fread(&(array[count]), sizeof(int), 1, fp);
        count++;
        printf("%d\n",array[count]);
    }
    
    QSort(array, 0, 250*1000*1000-1);
    
    FILE* fp10 = fopen("sort9", "wb");
    for (i = 0; i < size; i++) {
        int num =  100*1000/ sizeof(int);
        for (j = 0; j < num; j++) {
            buffer[j] = array[j];
        }
        size_t ret = fwrite(buffer, sizeof(int), num, fp10);
        if (ret != num) {
            printf("error: Failed in writing bytes to the file sort9\n");
            return -1;
        }
    }
    fclose(fp10);
    //1GB分のデータを整列し、ファイルに書き込む(10/10)
    count = 0;
    while(count!=250*1000*1000){
        fread(&(array[count]), sizeof(int), 1, fp);
        count++;
        printf("%d\n",array[count]);
    }
    
    QSort(array, 0, 250*1000*1000-1);
    
    FILE* fp11 = fopen("sort10", "wb");
    for (i = 0; i < size; i++) {
        int num =  100*1000/ sizeof(int);
        for (j = 0; j < num; j++) {
            buffer[j] = array[j];
        }
        size_t ret = fwrite(buffer, sizeof(int), num, fp11);
        if (ret != num) {
            printf("error: Failed in writing bytes to the file sort10\n");
            return -1;
        }
    }
    fclose(fp11);
    fclose(fp);
    free(array);
    free(buffer);
    
    //１０個にわかれたデータを２個ずつマージする
    int a, b;
    FILE* fpr2 = fopen("sort1", "rb");
    FILE* fpr3 = fopen("sort2", "rb");
    FILE* fpmerge1 = fopen("merge1", "wb");//マージしたデータを入れるファイル
    
    fread(&a, sizeof(int), 1, fpr2);
    fread(&b, sizeof(int), 1, fpr3);
    while(a!=0&&b!=0){
    if (a<=b) {
        fwrite(&a, sizeof(int), 1, fpmerge1);
        fread(&a, sizeof(int), 1, fpr2);
    }
    else{
        fwrite(&b, sizeof(int), 1, fpmerge1);
        fread(&b, sizeof(int), 1, fpr3);
    }
    }
    if(a==0){
        while(b!=0){
        fwrite(&b, sizeof(int), 1, fpmerge1);
        fread(&b, sizeof(int), 1, fpr3);
        }
    }
    else{
        while(b!=0){
        fwrite(&a, sizeof(int), 1, fpmerge1);
        fread(&a, sizeof(int), 1, fpr2);
        }
    }
    fclose(fpr2);
    fclose(fpr3);
    fclose(fpmerge1);
    
    FILE* fpr4 = fopen("sort3", "rb");
    FILE* fpr5 = fopen("sort4", "rb");
    FILE* fpmerge2 = fopen("merge2", "wb");//マージしたデータを入れるファイル
    
    fread(&a, sizeof(int), 1, fpr4);
    fread(&b, sizeof(int), 1, fpr5);
    while(a!=0&&b!=0){
        if (a<=b) {
            fwrite(&a, sizeof(int), 1, fpmerge2);
            fread(&a, sizeof(int), 1, fpr4);
        }
        else{
            fwrite(&b, sizeof(int), 1, fpmerge2);
            fread(&b, sizeof(int), 1, fpr5);
        }
    }
    if(a==0){
        while(b!=0){
            fwrite(&b, sizeof(int), 1, fpmerge2);
            fread(&b, sizeof(int), 1, fpr5);
        }
    }
    else{
        while(b!=0){
            fwrite(&a, sizeof(int), 1, fpmerge2);
            fread(&a, sizeof(int), 1, fpr4);
        }
    }
    fclose(fpr4);
    fclose(fpr5);
    fclose(fpmerge2);
    
    FILE* fpr6 = fopen("sort5", "rb");
    FILE* fpr7 = fopen("sort6", "rb");
    FILE* fpmerge3 = fopen("merge3", "wb");//マージしたデータを入れるファイル

    fread(&a, sizeof(int), 1, fpr6);
    fread(&b, sizeof(int), 1, fpr7);
    while(a!=0&&b!=0){
        if (a<=b) {
            fwrite(&a, sizeof(int), 1, fpmerge3);
            fread(&a, sizeof(int), 1, fpr6);
        }
        else{
            fwrite(&b, sizeof(int), 1, fpmerge3);
            fread(&b, sizeof(int), 1, fpr7);
        }
    }
    if(a==0){
        while(b!=0){
            fwrite(&b, sizeof(int), 1, fpmerge3);
            fread(&b, sizeof(int), 1, fpr7);
        }
    }
    else{
        while(b!=0){
            fwrite(&a, sizeof(int), 1, fpmerge3);
            fread(&a, sizeof(int), 1, fpr6);
        }
    }
    fclose(fpr6);
    fclose(fpr7);
    fclose(fpmerge3);
    
    FILE* fpr8 = fopen("sort7", "rb");
    FILE* fpr9 = fopen("sort8", "rb");
    FILE* fpmerge4 = fopen("merge4", "wb");//マージしたデータを入れるファイル
    
    fread(&a, sizeof(int), 1, fpr8);
    fread(&b, sizeof(int), 1, fpr9);
    while(a!=0&&b!=0){
        if (a<=b) {
            fwrite(&a, sizeof(int), 1, fpmerge4);
            fread(&a, sizeof(int), 1, fpr8);
        }
        else{
            fwrite(&b, sizeof(int), 1, fpmerge4);
            fread(&b, sizeof(int), 1, fpr9);
        }
    }
    if(a==0){
        while(b!=0){
            fwrite(&b, sizeof(int), 1, fpmerge4);
            fread(&b, sizeof(int), 1, fpr9);
        }
    }
    else{
        while(b!=0){
            fwrite(&a, sizeof(int), 1, fpmerge4);
            fread(&a, sizeof(int), 1, fpr8);
        }
    }
    fclose(fpr8);
    fclose(fpr9);
    fclose(fpmerge4);

    FILE* fpr10 = fopen("sort9", "rb");
    FILE* fpr11 = fopen("sort10", "rb");
    FILE* fpmerge5 = fopen("merge5", "wb");//マージしたデータを入れるファイル
    
    fread(&a, sizeof(int), 1, fpr10);
    fread(&b, sizeof(int), 1, fpr11);
    while(a!=0&&b!=0){
        if (a<=b) {
            fwrite(&a, sizeof(int), 1, fpmerge5);
            fread(&a, sizeof(int), 1, fpr10);
        }
        else{
            fwrite(&b, sizeof(int), 1, fpmerge5);
            fread(&b, sizeof(int), 1, fpr11);
        }
    }
    if(a==0){
        while(b!=0){
            fwrite(&b, sizeof(int), 1, fpmerge5);
            fread(&b, sizeof(int), 1, fpr10);
        }
    }
    else{
        while(b!=0){
            fwrite(&a, sizeof(int), 1, fpmerge5);
            fread(&a, sizeof(int), 1, fpr11);
        }
    }
    fclose(fpr10);
    fclose(fpr11);
    fclose(fpmerge5);
    
     //５個にわかれたデータをマージする
    FILE* fpr12 = fopen("merge1", "rb");
    FILE* fpr13 = fopen("merge2", "rb");
    FILE* fpmerge6 = fopen("merge6", "wb");//マージしたデータを入れるファイル
    
    fread(&a, sizeof(int), 1, fpr12);
    fread(&b, sizeof(int), 1, fpr13);
    while(a!=0&&b!=0){
        if (a<=b) {
            fwrite(&a, sizeof(int), 1, fpmerge6);
            fread(&a, sizeof(int), 1, fpr12);
        }
        else{
            fwrite(&b, sizeof(int), 1, fpmerge6);
            fread(&b, sizeof(int), 1, fpr13);
        }
    }
    if(a==0){
        while(b!=0){
            fwrite(&b, sizeof(int), 1, fpmerge6);
            fread(&b, sizeof(int), 1, fpr13);
        }
    }
    else{
        while(b!=0){
            fwrite(&a, sizeof(int), 1, fpmerge6);
            fread(&a, sizeof(int), 1, fpr12);
        }
    }
    fclose(fpr12);
    fclose(fpr13);
    fclose(fpmerge6);
    
    FILE* fpr14 = fopen("merge3", "rb");
    FILE* fpr15 = fopen("merge4", "rb");
    FILE* fpmerge7 = fopen("merge7", "wb");//マージしたデータを入れるファイル
    
    fread(&a, sizeof(int), 1, fpr14);
    fread(&b, sizeof(int), 1, fpr15);
    while(a!=0&&b!=0){
        if (a<=b) {
            fwrite(&a, sizeof(int), 1, fpmerge7);
            fread(&a, sizeof(int), 1, fpr14);
        }
        else{
            fwrite(&b, sizeof(int), 1, fpmerge7);
            fread(&b, sizeof(int), 1, fpr15);
        }
    }
    if(a==0){
        while(b!=0){
            fwrite(&b, sizeof(int), 1, fpmerge7);
            fread(&b, sizeof(int), 1, fpr15);
        }
    }
    else{
        while(b!=0){
            fwrite(&a, sizeof(int), 1, fpmerge7);
            fread(&a, sizeof(int), 1, fpr14);
        }
    }
    fclose(fpr14);
    fclose(fpr15);
    fclose(fpmerge7);
    
    FILE* fpr16 = fopen("merge5", "rb");
    FILE* fpr17 = fopen("merge6", "rb");
    FILE* fpmerge8 = fopen("merge8", "wb");//マージしたデータを入れるファイル
    
    fread(&a, sizeof(int), 1, fpr16);
    fread(&b, sizeof(int), 1, fpr17);
    while(a!=0&&b!=0){
        if (a<=b) {
            fwrite(&a, sizeof(int), 1, fpmerge8);
            fread(&a, sizeof(int), 1, fpr16);
        }
        else{
            fwrite(&b, sizeof(int), 1, fpmerge8);
            fread(&b, sizeof(int), 1, fpr17);
        }
    }
    if(a==0){
        while(b!=0){
            fwrite(&b, sizeof(int), 1, fpmerge8);
            fread(&b, sizeof(int), 1, fpr17);
        }
    }
    else{
        while(b!=0){
            fwrite(&a, sizeof(int), 1, fpmerge8);
            fread(&a, sizeof(int), 1, fpr16);
        }
    }
    fclose(fpr16);
    fclose(fpr17);
    fclose(fpmerge8);
    
    FILE* fpr18 = fopen("merge7", "rb");
    FILE* fpr19 = fopen("merge8", "rb");
    FILE* fpmerge9 = fopen("result10000", "wb");//マージしたデータを入れるファイル
    
    fread(&a, sizeof(int), 1, fpr18);
    fread(&b, sizeof(int), 1, fpr19);
    while(a!=0&&b!=0){
        if (a<=b) {
            fwrite(&a, sizeof(int), 1, fpmerge9);
            fread(&a, sizeof(int), 1, fpr18);
        }
        else{
            fwrite(&b, sizeof(int), 1, fpmerge9);
            fread(&b, sizeof(int), 1, fpr19);
        }
    }
    if(a==0){
        while(b!=0){
            fwrite(&b, sizeof(int), 1, fpmerge9);
            fread(&b, sizeof(int), 1, fpr19);
        }
    }
    else{
        while(b!=0){
            fwrite(&a, sizeof(int), 1, fpmerge9);
            fread(&a, sizeof(int), 1, fpr18);
        }
    }
    fclose(fpr16);
    fclose(fpr17);
    fclose(fpmerge8);

    return 0;
    
}