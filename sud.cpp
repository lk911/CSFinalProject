#include <sud.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>

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

//Prof Shea's Code
void generateBoard(int solution[9][9], int startX, int startY) {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(int i = 0; i < 9; i++) {
        int randNum = rand() % nums.size(), valX = i % 3, valY = i / 3;

        solution[startX + valX][startY + valY] = nums.at(randNum);
        nums.erase(nums.begin() + randNum);
    }
}

void makeBoard(int solution[9][9]) {
    long count = 0;
    do {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                generateBoard(solution, i * 3, j * 3);
            }
        }
        count++;

        // Prints every millionth board 
        if(count % 1000000 == 0) {
            cout << "Board " << count << ":" << endl;
            printBoard(solution);
        }
        
    } while(!validBoard(solution));
    cout << "Took " << count << " tries" << endl;
}

bool validBoard(int solution[9][9]) {
    vector<int> nums;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if (find(nums.begin(), nums.end(), solution[i][j]) != nums.end()) {
                return false;
            }
            nums.push_back(solution[i][j]);
        }
        nums.clear();
        for(int j = 0; j < 9; j++) {
            if (find(nums.begin(), nums.end(), solution[j][i]) != nums.end()) {
                return false;
            }
            nums.push_back(solution[j][i]);
        }
        nums.clear();
    }
    return true;
}

void printBoard(int solution[9][9]) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//end of prof sheas code


//Checking
void initSudoku();   
bool checkAnswer();
int mySudoku[9][9];
void initSudoku(){    
    for(int i=0;i<9;i++)        
        for(int j=0;j<9;j++)            
            cin>>mySudoku[i][j];}
bool review(int* p) 
{    
    int i=1;    
    while(i<10)    
    {        
        if(!*(++p))        
        {            
            return false;        
        }        
        ++i;    
    }    
    return true;
}

void zero_tag(int* p)   
{    
    int i=1;    
    while(i<10)    
    {        
        *(++p)=0;        
        ++i;    
    }
}
bool checkAnswer()
{    
    int tag[10]={0};  
    int curValue=0;
    int curValue=0;
    for(int i=0; i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            curValue = mySudoku[i][j];
            tag[curValue]=1; 
        }
    }
    if(!review(tag))
        return false; 

    zero_tag(tag);

    for(int i=0; i<9;i++)
    {
        for(int j=0;j<9;j++){
            curValue = mySudoku[i][j];
            tag[curValue]=1; 
        }
    }
    if(!review(tag)){
        return false; 

    zero_tag(tag);

    }
    
    return true;

}
//test
