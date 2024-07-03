/*Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according
to the following rules:
Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note: A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.*/




#include<stdio.h>       //Usual header file inclusion.
#include<stdbool.h>     //Included due to the usage of bool datatype inside a code.


//Here, I have to check either the value is correct(true) or not(false).
//So, I declared a function with bool data type.
//It also returns a value like a int data type.

bool sudoku(int grid[9][9]) 
{
    //This loop is to check row wise correctness of a value.
    //Here.I am using an 1D array "used" to store and check.
    //It's first element is initialised with false value.

    int i,j,k,l;
    for (i=0;i<9;i++) 
    {
        bool used[9]={false};
        for (j=0;j<9;j++) 
        {
            if (grid[i][j]==0) 
            {
                return false;       //exits the function by giving return value as "false".
            }
            if (used[grid[i][j]-1]) 
            {
                return false;       //exits the function by giving return value as "false".
            }
            used[grid[i][j]-1]=true;
        }
    }

    //This loop is to check column wise correctness of a value.
    //Here.I am agian initialising an 1D array "used" to store and check.
    //It's first element is initialised with false value.

    for (i=0;i<9;i++) 
    {
        bool used[9]={false};
        for (j=0;j<9;j++) 
        {
            if (grid[j][i]==0) 
            {
                return false;       //exits the function by giving return value as "false".
            }
            if (used[grid[j][i]-1]) 
            {
                return false;       //exits the function by giving return value as "false".
            }
            used[grid[j][i]-1] = true;
        }
    }

    /*This loop checks the correctness of a value in each grid(3x3).
    So,I am incrementing i and j values by 3.
    Here also, I am using an 1D array "used" to store and check.
    It's first element is initialised with false value.*/

    // i and j are used for grid accessing.
    // k and l are used for accessing elements in a grid.

    for (i=0;i<9;i+=3) 
    {
        for (j=0;j<9;j+=3) 
        {
            bool used[9]={false};
            for (k=0;k<3;k++) 
            {
                for (l=0;l<3;l++) 
                {
                    if (grid[i+k][j+l]==0) 
                    {
                        return false;       //exits the function by giving return value as "false".
                    } 
                    if(used[grid[i+k][j+l]-1]) 
                    {
                        return false;       //exits the function by giving return value as "false".
                    }
                    used[grid[i+k][j+l]-1]=true;
                }
            }
        }
    }

    /*From this, we infer that if all the given conditions have failed, i.e., if the value 
    never passed on to a loop, it finally comes to the last executable code of this function and gives 
    return value as "true".*/

    return true;
}

void main() 
{
    /*In main function we get the values and just show the result by calling the function.
    We can either get a data from the user or input a data on code itself.
    I input in 2nd way for my convenience.*/

    int value[9][9] = 
    {
        {5,3,4,6,7,8,9,1,2},
        {6,7,2,1,9,5,3,4,8},
        {1,9,8,3,4,2,5,6,7},
        {8,5,9,7,6,1,4,2,3},
        {4,2,6,8,5,3,7,9,1},
        {7,1,3,9,2,4,8,5,6},
        {9,6,1,5,3,7,2,8,4},
        {2,8,7,4,1,9,6,3,5},
        {3,4,5,2,8,6,1,7,9}
    };
    
    //This is a conditional operator.
    //If the return value of the function is true, it prints VALID.
    //If the return value of the function is false, it prints NOT VALID.

    printf("%s",sudoku(value)?"VALID":"NOT VALID");

    //Code terminates.
}