#include "sud.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <ctime>

using namespace std;

int main(){
    clock_t start;
    double duration;
    start = clock();
    int numguesses=0, numtrueguesses=0, numfalseguesses=0;
    duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
    int originalSolution[9][9] = {
        {5,3,4,6,7,8,9,1,2},
        {6,7,2,1,9,5,3,4,8},
        {1,9,8,3,4,2,5,6,7},
        {8,5,9,7,6,1,4,2,3},
        {4,2,6,8,5,3,7,9,1},
        {7,1,3,9,2,4,8,5,6},
        {9,6,1,5,3,7,2,8,4},
        {2,8,7,4,1,9,6,3,5},
        {3,4,5,2,8,6,1,7,9}};

    int presetSolution[9][9] = {
        {5,3,4,6,7,8,9,1,2},
        {6,7,2,1,9,5,3,4,8},
        {1,9,8,3,4,2,5,6,7},
        {8,5,9,7,6,1,4,2,3},
        {4,2,6,8,5,3,7,9,1},
        {7,1,3,9,2,4,8,5,6},
        {9,6,1,5,3,7,2,8,4},
        {2,8,7,4,1,9,6,3,5},
        {3,4,5,2,8,6,1,7,9}};
    int solution[9][9];
    srand(time(0));

    makePuzzle(presetSolution, welcomeUser());
    while(!isfull(presetSolution)){
        if (enterandcheckanswer(originalSolution,presetSolution, numguesses, numtrueguesses, numfalseguesses)){
            cout<<"Your answer fits!"<<endl;
        }
        else{
            cout<<"Your answer does not fit"<<endl;
        }
        int numzeroes;
}
        cout << "Game over. Thanks for playing!" << endl;
    }

// Duration, output stats
