//                          CE39204	WATER RESOURCES AND GEOTECHNICAL ENGINEERING SESSIONAL
//           Name : DHANRAJ KUMAR     ||      Roll no: 20CE10021      || Assignment - 1

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n_loops = 4;      // Total number of loops
    int n_branches = 13;  // Total number of branches

    vector<double> R = {96.8, 96.8, 306, 306, 306, 3098, 3098, 3098, 306, 612, 306, 9295, 3098};    // Stores coefficient of resistance of each branch
    double discharge[13] = {217 , 300, 100, 50, 150, 50, 50, 50, 30, 30, 70, 20, 30};  // Initial assumed discharge in each branch such as discharge[0] store discharge of branch 1 and respectively

    double connection[4][13] = {{-1, 1, 0, 0, 1, 0, 0, 1, 0,-1, 0, 0, 0},              // 2D array that shows anticlockwise and clockwise branches of each loop
                                {0, 0, 1, 1, -1,-1, 0, 0, 0, 0, 0, 0, 0},        // 1 shows clockwise and -1 shows anticlockwise
                                {0, 0, 0, 0, 0, 1, 1, -1,-1, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 1, 1,-1, -1, 1}};


    double delta_Q = 1;     // To store maximum correction in discharge of whole network
    
    while( delta_Q > 0.001){ // Condition to break out of loop
        // cout << "delta_Q = " << delta_Q << endl;
        double delta_q[n_branches] = {0};   // Array to store discharge correction in each branch

        for(int i = 0; i < n_loops; i++){   // Loop to calculate discharge correction of each loop

            double num = 0, den = 0;

            for(int j = 0; j < n_branches; j++){  // /_\ Q = sum(R * Q^2) / sum (2 * R * Q)
                if(connection[i][j] != 0){
                    num += (connection[i][j] * (R[j] * (discharge[j] * discharge[j])));
                    den += (2 * (R[j] * discharge[j]));
                }
            }

            delta_q[i] = (num / den);  // Corrected discharge of loop i

           
        }
        for(int i = 0; i < n_loops; i++){
            for(int j = 0; j < n_branches; j++){  // To correct discharge of each branch
                if(connection[i][j] > 0){                   // If water flow in branch is clockwise direction
                    double x = discharge[j] - delta_q[i];   // Subtracting correction if flow is in clockwise direction

                    if((discharge[j] * x) < 0 ){
                        connection[i][j] *= -1;         // Altring the direction of flow if correction makes changs to flow direction
                        discharge[j] = -x;
                    }
                    else
                        discharge[j] = x;
                }
                else if(connection[i][j] < 0){          // If water flow in branch is clockwise direction
                    double x = discharge[j] + delta_q[i];// Adding correction if flow is in clockwise direction

                    if((discharge[j] * x) < 0 ){
                        connection[i][j] *= -1;         // Altring the direction of flow if correction makes changs to flow direction
                        discharge[j] = -x;
                    }
                    else
                        discharge[j] = x;
                }
            }
        }
        
        delta_Q = delta_q[0];
        for(int i = 0; i < n_branches; i++){    // To store maximum value of corrected discharge in delta_Q
            if(delta_Q < delta_q[i])
                delta_Q = delta_q[i];
        }
    

    }
    cout << "delta_Q = " << delta_Q << endl;    // TO print final value of delta_Q
    cout << "Discharge: ";
    for(int i = 0; i < n_branches; i++)                 // To print final discharge value of each branch
        cout << discharge[i] << "   ";

    return 0;
}
