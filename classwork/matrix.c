#include<stdio.h>
int main(){

    int matrix[3][4]= { {10,22,35,41},{50,65,73,80},{91,10,11,12}};
    int i,j,max;
    int sum,total = 0;
    max = matrix[0][0];
    for(i = 0;i <= 2;i++){
        for(j = 0;j <= 3;j++){
            if(matrix[i][j] > max){
                max = matrix[i][j];
                sum += matrix[i][j];
            }
        }
        printf(" matrix[%d][%d] your sum is %d\n",i,j,sum);
        total += sum;
    }
        printf("MAX IS %d\n",max);
        printf("Total sum : %d",total);

}
