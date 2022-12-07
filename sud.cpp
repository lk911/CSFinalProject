#include <sud.h>
#include <iostream>
#include <cstdlib>
#include <string>

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