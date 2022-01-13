#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int  main(int argc,char** argv){

    int row = 200;
    int col = 198;


    double A[row][col];
    double B[row][col];
    double answer[row];

    double mul_tmp[2];



    clock_t read_st,read_end,compute_st,compute_end,output_st,output_end;
    
    for(int i=0;i<row;i++)
        answer[i] = 0.0f;

    read_st = clock();
    FILE* fp=fopen("data.txt","r"); //開啟檔案
    if(fp==NULL){
        printf("無檔案");
        return -1;
    }
    
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            fscanf(fp,"%lf",&A[i][j]); 
        }
        fscanf(fp,"\n");
    }

        for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            fscanf(fp,"%lf",&B[i][j]); 
        }
        fscanf(fp,"\n");
    }
    fclose(fp);
    
    read_end = clock();
    double read_time = (double)(read_end - read_st) / CLOCKS_PER_SEC;

    compute_st = clock();

    for (int i = 0 ; i<row ; ++i ){

        for (int j = 0 ; j<row ; ++j ){

            for(int k = 0; k<col;++k ){
                answer[i] +=(A[i][k]*B[j][k]);
            }
        }
    }

    compute_end = clock();
    double compute_time = (double)(compute_end - compute_st) / CLOCKS_PER_SEC;


    output_st = clock();

    FILE* fout=fopen("output_nosimd.txt","w+t");
    if(fout == NULL) {
        printf("Fail To Open File out.txt!!");
        return -1;
    }

    for (int i = 0 ; i<row ; ++i )
        fprintf(fout,"%lf\n",answer[i]);
    output_end = clock();
    double output_time = (double)(output_end - output_st) / CLOCKS_PER_SEC;

    fprintf(fout,"\n");
    fprintf(fout,"read_time:%lf sec\n",read_time);
    fprintf(fout,"compute_time:%lf sec\n",compute_time);
    fprintf(fout,"output_time:%lf sec\n",output_time);
    fclose(fout);


    return 0;	
}
