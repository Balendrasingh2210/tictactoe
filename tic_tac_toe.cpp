#include <bits/stdc++.h>
using namespace std;

int mark(vector<vector<int>> &matrix, char c, int k)
{
    int i = (k - 1) / 3;
    int j = (k - 1) % 3;
    if (c == 'a')
    {
        matrix[i][j] = 1;
    }
    else
    {
        matrix[i][j] = 0;
    }
}

char check(vector<vector<int>> &matrix)
{
    char a = 'a', b = 'b';
    char x = 'x';
    if (matrix[0][0] == matrix[0][1] && matrix[0][0] == matrix[0][2])
    {
        if (matrix[0][0] == 1)
        {
            return a;
        }
        else if (matrix[0][0] == 0)
        {
            return b;
        }
    }
    else if (matrix[1][0] == matrix[1][1] && matrix[1][0] == matrix[0][2])
    {
        if (matrix[1][0] == 1)
        {
            return a;
        }
        else if (matrix[1][0] == 0)
        {
            return b;
        }
    }
    else if (matrix[2][0] == matrix[2][1] && matrix[2][0] == matrix[2][2])
    {
        if (matrix[2][0] == 1)
        {
            return a;
        }
        else if (matrix[2][0] == 0)
        {
            return b;
        }
    }
    else if (matrix[0][0] == matrix[1][0] && matrix[0][0] == matrix[2][0])
    {
        if (matrix[0][0] == 1)
        {
            return a;
        }
        else if (matrix[0][0] == 0)
        {
            return b;
        }
    }
    else if (matrix[0][1] == matrix[1][1] && matrix[0][1] == matrix[2][1])
    {
        if (matrix[0][1] == 1)
        {
            return a;
        }
        else if (matrix[0][1] == 0)
        {
            return b;
        }
    }
    else if (matrix[0][2] == matrix[1][2] && matrix[0][2] == matrix[2][2])
    {
        if (matrix[0][2] == 1)
        {
            return a;
        }
        else if (matrix[0][2] == 0)
        {
            return b;
        }
    }
    else if (matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2])
    {
        if (matrix[0][0] == 1)
        {
            return a;
        }
        else if (matrix[0][0] == 0)
        {
            return b;
        }
    }
    else if (matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0])
    {
        if (matrix[0][2] == 1)
        {
            return a;
        }
        else if (matrix[0][2] == 0)
        {
            return b;
        }
    }
    return x;
}

void printMatrix(vector<vector<int>> &matrix)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == 1)
            {
                cout << 'X' << '\t';
            }
            else if (matrix[i][j] == 0)
            {
                cout << 'O' << '\t';
            }
            else
            {
                cout << " " << '\t';
            }
        }
        cout << endl
             << endl;
    }
}

int main()
{
    // start your code here
    vector<vector<int>> matrix(3, vector<int>(3, -1));
    int count = 9;
    char a = 'a', b = 'b';
    bool chance = true;
    while (count--)
    {
        char c = chance ? a : b;

        cout << "Chance of"
             << " " << c << endl;
        int k;
        cin >> k;
        cout << endl;

        int i = (k - 1) / 3;
        int j = (k - 1) % 3;
        if (k > 9 && k < 1)
        {
            cout << "Enter valid position between 1 to 9" << endl;
            count++;
            continue;
        }
        else if (matrix[i][j] != -1)
        {
            cout << "This position is already filled" << endl;
            count++;
            continue;
        }
        else
        {
            chance = !chance;
        }
        mark(matrix, c, k);
        printMatrix(matrix);
        char r = check(matrix);
        if (r == 'x')
            continue;
        else if (r == 'a')
        {
            cout << r << " is the winner" << endl;
            break;
        }
        else
        {
            cout << r << " is the winner" << endl;
            break;
        }

        if (count == 0 && r == 'x')
        {
            cout << "This match is drawn" << endl;
            break;
        }
    }

    return 0;
}
