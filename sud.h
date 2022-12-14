#ifndef SUD_H
#define SUD_H
char welcomeUser();
void createSolution(int solution[9][9]);
void createPuzzle();
void generateBoard(int solution[9][9], int startX, int startY);
void makeBoard(int solution[9][9]);
bool validBoard(int solution[9][9]);
void printBoard(int solution[9][9]);
void makePuzzle(int presetSolution[9][9],char choice);
void initSudoku();   
bool enterandcheckanswer(int solution[9][9],int presetSolution[9][9], int &numguesses, int &numtrueguesses,int &numfalseguesses);
bool isfull(int presetSolution[9][9]);
void outputStats(int numguesses, int numtrueguesses, int numfalseguesses);
#endif
