#include <iostream>
#include<windows.h>
#include <chrono>
#include <thread>
using namespace std;

//Functions Names 

int** create_integer_Array(int x, int y);
void giving_values_to_array(int** count, int x, int y);
bool room_limit_check(int x, int y, int i, int j);
bool my_12_IQ(int** count, int x, int y);
void final_density(int** count, int x, int y, int moves);

// Possible moves array
const int IMOVE[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
const int JMOVE[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };

int main() {
    int N, M, startX, startY;
   
    cout << "Enter the number of rows: ";
    cin >> N;
    cout << "Enter the number of columns: ";
    cin >> M;
    cout << "Enter the starting point (ROW-BY-COLUMN): ";
    cin >> startX >> startY;
    system("cls");
    if (2 < N && N <= 40 && 2 <= M && M <= 20 && startX <= N && startY <= M) {
        int** int_array = create_integer_Array(N, M);
        giving_values_to_array(int_array, N, M);

        int xi = startX - 1;
        int yi = startY - 2;
        int moves = 0;

        //Loop for Show animation and process the main work 
        while (my_12_IQ(int_array, N, M) && moves < 100000000000) {
            int k = rand() % 8;
            int nextX = xi + IMOVE[k];
            int nextY = yi + JMOVE[k];

            if (room_limit_check(N, M, nextX, nextY)) {
                xi = nextX;
                yi = nextY;
                int_array[xi][yi]++;
                moves++;

                this_thread::sleep_for(chrono::milliseconds(300));
                system("cls");


                cout << "                    Created by M.Muaaz Ali  \n\n                       Rectangular room             \n\n                   Cockroach is represent by \"*\"" << endl;
                cout << endl << endl << endl << endl;
                cout << "\t\t";
                for (int o = 0; o < (M * 3); o++) {
                    cout << "-";
                }
                cout << endl;
                for (int i = 0; i < N; i++) {
                    cout << "\t\t";
                    for (int j = 0; j < M; j++) {

                        if (i == xi && j == yi) {
                            cout << "|*|";     //Represent bug position 
                        }
                        else {
                            cout << "| |";
                        }
                    }
                    cout << endl;
                    cout << "\t\t";
                    for (int o = 0; o < (M * 3); o++) {
                        cout << "-";
                    }
                    cout << "\t\t";
                    for (int j = 0; j < M; j++) {
                        cout << int_array[i][j] << "    ";
                    }
                    cout << endl;
                }

            }
        }

        final_density(int_array, N, M, moves);

        // freeing space or array and make it ready for further work 

        for (int i = 0; i < N; i++) {
            delete[] int_array[i];
        }
        delete[] int_array;

    }
    else {
        cout << "Please check the input limits:\n2 < row && row <= 40 && 2 <= col && col <= 20 && iBug <= row && jBug <= col";
    }
    return 0;
}

//Functions Code

// declearing 2d Dynamic array 
int** create_integer_Array(int x, int y) {
    int** dy = new int* [x];
    for (int i = 0; i < x; i++) {
        dy[i] = new int[y];
    }
    return dy;
}

//Assigning values to array
void giving_values_to_array(int** count, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            count[i][j] = 0;
        }
    }
}

// Checking the room limits 
bool room_limit_check(int x, int y, int i, int j) {
    return (i >= 0 && i < x && j >= 0 && j < y);
}

// Making a point for break the loop
bool my_12_IQ(int** count, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (count[i][j] == 0) {
                return true;
            }
        }
    }
    return false;
}

//Showing the final density of values given to array elements in all process
void final_density(int** count, int x, int y, int moves) {
    cout << endl << endl;
    cout << "Total legal moves made by the cockroach: " << moves << endl << endl;
    cout << "      Density of array:" << endl;
    cout << "\n\n\n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << count[i][j] << "   ";
        }
        cout << endl;
    }
}