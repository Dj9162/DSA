#include <stdio.h>

int main(){
    double Q[13] = {217 , 300, 100, 50, 150, 50, 50, 50, 30, 30, 70, 20, 30}; 
    double R[13] = {96.8, 96.8, 306, 306, 306, 3098, 3098, 3098, 306, 612, 306, 9295, 3098};

    double C[4][13] = {{-1, 1, 0, 0, 1, 0, 0, 1, 0,-1, 0, 0, 0},
                    {0, 0, 1, 1, -1,-1, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 1, 1, -1,-1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 1, 1,-1, -1, 1}};


    double DQ = 1;
    
    while( DQ > 0.001){
        double dq[13] = {0};

        for(int i = 0; i < 4; i++){

            double temp1 = 0, temp2 = 0;

            for(int j = 0; j < 13; j++){
                if(C[i][j] != 0){
                    temp1 = temp1 + (C[i][j] * (R[j] * (Q[j] * Q[j])));
                    temp2 = temp2 + (2 * (R[j] * Q[j]));
                }
            }

            dq[i] = (temp1 / temp2);
           
        }
        int a = 4;
        while(a > 0){
            for(int j = 0; j < 13; j++){ 
                if(C[4-a][j] > 0){              

                    if((Q[j] * (Q[j] - dq[4-a])) < 0 ){
                        C[4-a][j] = -1 * C[4-a][j];  
                        Q[j] = -1 * (Q[j] - dq[4-a]);
                    }
                    else
                        Q[j] = (Q[j] - dq[4-a]);
                }
                else if(C[4-a][j] < 0){       

                    if((Q[j] * (Q[j] + dq[4-a])) < 0 ){
                        C[4-a][j] *= -1; 
                        Q[j] = -(Q[j] + dq[4-a]);
                    }
                    else
                        Q[j] = (Q[j] + dq[4-a]);
                }
            }
        a--;
        }
        DQ = dq[0];
        for(int i = 1; i < 13; i++){ 
            if(dq[i] > DQ)
                DQ = dq[i];
        }
    }
    for(int i = 0; i < 13; i++)
        printf("%f ", Q[i]);

    return 0;
}
