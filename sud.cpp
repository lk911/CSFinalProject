#include "sud.h"
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

//modified here for aesthetic purposes and to fit our code
void printBoard(int presetSolution[9][9]){
   for (int i = 0; i < 9; i++){
      for (int j = 0; j < 9; j++){
         if(j == 3 || j == 6)
            cout << " | ";
         cout << presetSolution[i][j] <<" ";
      }
      if(i == 2 || i == 5){
         cout << endl;
         for(int k = 0; k<9; k++)
            cout << "---";
      }
      cout << endl;
   }
}

//end of prof sheas code

//creates and outputs puzzles varying in difficulty
void makePuzzle(int presetSolution[9][9], char choice){
    int randx, randy;
    if(choice == 'a'){
    for(int i=0; i < 45; i++){
    randx = rand() % 9 + 0;
    randy = rand() % 9 + 0;
    presetSolution[randy][randx] = 0;
    }
    }
    else if(choice == 'b'){
    for(int i=0; i < 50; i++){
    randx = rand() % 9 + 0;
    randy = rand() % 9 + 0;
    presetSolution[randy][randx] = 0;
    }
    }
    else if(choice == 'c'){
    for(int i=0; i < 60; i++){
    randx = rand() % 9 + 0;
    randy = rand() % 9 + 0;
    presetSolution[randy][randx] = 0;
    }
    }

    printBoard(presetSolution);
    cout << "Fill in all '0' values:" << endl;
}





//Checking
bool enterandcheckanswer(int originalSolution[9][9],int presetSolution[9][9], int &numguesses, int &numtrueguesses, int &numfalseguesses){
    int i,j,guess;
    cout <<"Please enter the number of the row and column:"<< endl;
    cin >> i >> j;
    cout<<"Enter your guess:"<<endl;
    cin>> guess;
    if(guess == originalSolution[i-1][j-1]){
        presetSolution[i-1][j-1]=guess;
        printBoard(presetSolution);
        numguesses++;
        numtrueguesses++;
        return true;
    }
    printBoard(presetSolution);
    numguesses;
    numfalseguesses++;
    return false;
    
}
bool isfull(int presetSolution[9][9]){
    int numzeroes = 0;
    for(int i = 1; i < 9; i++){
        for(int j = 1; j < 9; j++){
            if(presetSolution[i][j] == 0){
                numzeroes++;
            }
        }
    }
    if(numzeroes > 0){
        cout << "Game not complete yet, keep playing!" << endl;
        return false;
    }
    else if (numzeroes == 0){
        cout << "Game complete. Great job!" << endl;
        return true;
    }
    return false;
}

void outputStats(int numguesses, int numtrueguesses, int numfalseguesses){
    cout << "You completeted the game in" << numguesses << " tries." << endl << "Of these, " << numfalseguesses << " were false, and " << numtrueguesses << " were correcrt." << endl;
    cout << "This give you a ratio of" << numtrueguesses/numguesses << "percent correct answers." << endl;
}
