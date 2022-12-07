#include <sud.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <random>
using namespace std;

char welcomeUser(){
    char choice;
    cout<<"Welcome to Sudoku!"<<endl;
    cout<<"Sudoku is played on a grid of 9 x 9 spaces. Within the rows and columns are 9 “squares” (made up of 3 x 3 spaces). Each row, column and square (9 spaces each) needs to be filled out with the numbers 1-9, without repeating any numbers within the row, column or square."<<endl;
    cout<<"Please select a difficulty:\na)easy\nb)medium\nc)hard"<<endl;
    cout<<"enter letter of desired difficulty:";
    cin>>choice;
    return choice;
}
void createSolution(int solution[9][9]){
    vector<vector<int>> square = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> randsquare = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> randomsolution = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> final;
    random_device rd;
    mt19937 g(rd());

    for(int i = 0; i < 3; i++){
        for(int j = 0 ; j < 3; j++){
            cout << square[i][j] << "|";
        }
        cout << endl << "------" << endl;
    }

    //randomizing randsquare vectors
   cout << endl;
   shuffle(randsquare.begin(), randsquare.end(), g); 

    //applying randsquare vector to square vector
        int numrandsquare = -1;
    for(int i = 0; i < 3; i++){
        for(int j = 0 ; j < 3; j++){
            square[i][j] = randsquare[numrandsquare+1];
            numrandsquare++;
        }
    }

    //mapping square vector onto randomsolution
        final = square;
        final.insert(final.end(), randomsolution.begin(), randomsolution.end());





        //how the heck are you supposed to do this
    for(int i=0;i<9;i++){
    int numrandsquare =-1;
    vector<int> randsquare = {1,2,3,4,5,6,7,8,9};
    shuffle(randsquare.begin(), randsquare.end(), g); //shuffles random 1d array
    for(int j = 0; j < 3; j++){// maps 1d array onto 2d
        for(int k = 0 ; k < 3; k++){
            square[j][k] = randsquare[numrandsquare+1];
            numrandsquare++;
        }
    }

    final = square;                          //maps random 2d array onto master puzzle array
    final.insert(final.end(), randomsolution.begin(), randomsolution.end());
    

}

//testing
    cout << "Randomized vector:" << endl;

    for(int i = 0; i < 3; i++){
        for(int j = 0 ; j < 3; j++){
            cout << square[i][j] << "|";
        }
        cout << endl << "------" << endl;
    }


for(int i = 0; i < 6; i++){
        for(int j = 0 ; j < 3; j++){
            cout << final[i][j] << "|";
        }
        cout << endl << "------" << endl;
    }     


}    
