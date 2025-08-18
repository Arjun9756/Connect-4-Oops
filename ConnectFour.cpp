#include <bits/stdc++.h>
using namespace std;

int ii , jj; // Global Variables

pair<int,int>canFilledOnCol(vector<vector<string>>&matrix , int &colNumber , bool &isPlayerOne)
{
    for(int i=matrix.size()-1 ; i>=0 ; i--)
    {
        if(matrix[i][colNumber] == ".")   // if it is an empty Cells
        {
            matrix[i][colNumber] = (isPlayerOne == true ? "X" : "O");
            return make_pair(i , colNumber);
        }
    }
    return make_pair(-1 , -1);
}

void printBoard(vector<vector<string>>&matrix) {
    cout << "\nCurrent Board:\n";
    for(int i=0; i<ii; i++) {
        for(int j=0; j<jj; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "0 1 2 3 4 5 6\n"; // columns index for help
    cout << "-----------------\n";
}

inline bool isValid(int i , int j)
{return (i >= 0 and j >= 0 and i < ii and j < jj);}

bool canUpwardPossible(vector<vector<string>>&matrix , int i , int j)
{
    string prev = matrix[i][j];
    int count = 0;

    for(int k=i ; k>=0 ; k--)
    {
        if(!isValid(k , j) or matrix[k][j] != prev) 
            return false;
        if(isValid(k , j) and matrix[k][j] == prev)
            count++;
        if(count >= 4)
            return true;
    }
    return (count >= 4 ? true : false);
}

bool canDownwardPossible(vector<vector<string>>&matrix , int i , int j)
{
    string prev = matrix[i][j];
    int count = 0;

    for(int k=i ; k<matrix.size() ; k++)
    {
        if(!isValid(k , j) or matrix[k][j] != prev)
            return false;
        if(isValid(k , j) and matrix[k][j] == prev)
            count++;
        if(count >= 4)
            return true;
    }
    return (count >= 4 ? true : false);
}

bool canRightwardPossible(vector<vector<string>>&matrix , int i , int j)
{
    string prev = matrix[i][j];
    int count = 0;

    for(int k=j ; k<matrix[0].size() ; k++)
    {
        if(!isValid(i , k) or matrix[i][k] != prev)
            return false;
        if(isValid(i , k) and matrix[i][k] == prev)
            count++;
        if(count >= 4)
            return true;
    }

    return (count >= 4 ? true : false);
}

bool canLeftWardPossible(vector<vector<string>>&matrix , int i , int j)
{
    string prev = matrix[i][j];
    int count = 0;

    for(int k=j ; k>=0 ; k--)
    {
        if(!isValid(i , k) or matrix[i][k] != prev)
            return false;
        if(isValid(i , k) and matrix[i][k] == prev)
            count++;
        if(count >= 4)
            return true;
    }

    return (count >= 4 ? true : false);
}

// Code to Be Cange Two Functions
bool canLeftDigoPossible(vector<vector<string>>&matrix , int i , int j) {
    string prev = matrix[i][j];
    int count = 0;

    // upar-left taraf
    for(int k=0 ; i-k>=0 && j-k>=0 ; k++) {
        if(matrix[i-k][j-k] != prev) break;
        count++;
    }

    // neeche-right taraf
    for(int k=1 ; i+k<ii && j+k<jj ; k++) {
        if(matrix[i+k][j+k] != prev) break;
        count++;
    }

    return count >= 4;
}

bool canRightDigoPossible(vector<vector<string>>&matrix , int i , int j) {
    string prev = matrix[i][j];
    int count = 0;

    // upar-right taraf
    for(int k=0 ; i-k>=0 && j+k<jj ; k++) {
        if(matrix[i-k][j+k] != prev) break;
        count++;
    }

    // neeche-left taraf
    for(int k=1 ; i+k<ii && j-k>=0 ; k++) {
        if(matrix[i+k][j-k] != prev) break;
        count++;
    }

    return count >= 4;
}


pair<bool,bool>canThePlayerWins(vector<vector<string>>&matrix , pair<int,int>&nodes , bool &isPlayerOne)
{
    // Check for UpWard 
    bool answerFromUpward = canUpwardPossible(matrix , nodes.first , nodes.second);
    bool answerFromDownward = canDownwardPossible(matrix , nodes.first , nodes.second);
    bool answerFromRight = canRightwardPossible(matrix , nodes.first , nodes.second);
    bool answerFromLeft = canLeftWardPossible(matrix , nodes.first , nodes.second);
    bool answerFromLeftDigonal = canLeftDigoPossible(matrix , nodes.first , nodes.second);
    bool answerFromRightDigonal = canRightDigoPossible(matrix , nodes.first , nodes.second);

    bool finalAnswer = (answerFromUpward or answerFromDownward or answerFromRight or answerFromLeft or answerFromLeftDigonal or answerFromRightDigonal);
    if(isPlayerOne)
        return {finalAnswer , false};

    return {false , finalAnswer};
}

bool whoWons(vector<vector<string>>&matrix)
{
    int moves = 0;
    bool isPlayerOne = true;

    while(moves < matrix.size() * matrix[0].size())
    {
        // Take Input from Player
        pair<int,int>nodes;         // Stores row & col of filled cell
        int colNumber = -1;

        if(isPlayerOne == true){
            while(colNumber == -1){
                cout<<"Player 1 Chance Enter the Column Number You Want to Drop the Disc Between 0--6 \n";
                cin>>colNumber;
                
                if(colNumber < 0 or colNumber >= 7){
                    colNumber = -1;
                }

                nodes = canFilledOnCol(matrix , colNumber , isPlayerOne);
                if(nodes.first == -1 or nodes.second == -1){
                    cout<<"Please Choose a Distinct Column this Column gets Full \n";
                    colNumber = -1;
                }
            }
        }
        else{
            while(colNumber == -1){
                cout<<"Player 2 Chance Enter the Column Number You Want To Drop the Disc Between 0--6\n";
                cin>>colNumber;

                if(colNumber < 0 or colNumber >= 7){
                    colNumber = -1;
                }

                nodes = canFilledOnCol(matrix , colNumber , isPlayerOne);
                if(nodes.first == -1 or nodes.second == -1){
                    cout<<"Please Choose a Distinct Column this Column gets Full \n";
                    colNumber = -1;
                }
            }
        }
        
        printBoard(matrix);
    
        pair<bool,bool>winsNodes = canThePlayerWins(matrix , nodes , isPlayerOne);
        if(winsNodes.first == true){
            return 1; // 1st Player wins
        }
        else if(winsNodes.second == true){
            return 2; // 2nd Player Wins
        }  

        if(winsNodes.first) { printBoard(matrix); return 1; }
        if(winsNodes.second) { printBoard(matrix); return 2; }
        
        isPlayerOne = !isPlayerOne;
        moves++;
    }

    return -1; // Match Draw;
}

int main()
{
    vector<vector<string>>matrix(6 , vector<string>(7 , "."));
    ii = matrix.size();
    jj = matrix[0].size();

    int result = whoWons(matrix);
    if(result == 1) cout<<"Player 1 wins!\n";
    else if(result == 2) cout<<"Player 2 wins!\n";
    else cout<<"Match draw!\n";
}