// 227 Puzzle
/* This problem has a poor problem description.
 * Here are the traps I fell into:
 * (1) If the blank is at the end of the line, it will not be given.
 *     You have to add it by yourself (line 30-31).
 * (2) There may be a puzzle with no blank in it (line 40).
 * (3) There may be a undefined move (other than "ABLR"), which is illegal (line 82-83).
 * It really wasted my time :( 
 */
#include <iostream>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t = 0;
    std::string s;
    while (getline(std::cin, s)) {
        if (s == "Z")
            break;

        std::string puzzle[5] = {s};
        for (int i = 1; i < 5; ++i)  
            getline(std::cin, puzzle[i]);        

        int x = -1, y = -1;
        for (int i = 0; i < 5; ++i) {
            if (puzzle[i].size() == 4)
                puzzle[i] += ' ';
            for (int j = 0; j < 5; ++j) {
                if (puzzle[i][j] == ' ') {
                    x = i;
                    y = j;
                }
            }
        }

        bool flag = (x == -1) ? false : true;
        char move, temp;
        while (std::cin >> move) {
            if (move == '0')
                break;
            if (flag) { 
                if (move == 'L') {
                    if (y == 0) {
                        flag = false;
                    } else {
                        temp = puzzle[x][y];
                        puzzle[x][y] = puzzle[x][y - 1];
                        puzzle[x][y - 1] = temp;
                        y--;
                    }
                } else if (move == 'R') {
                    if (y == 4) {
                        flag = false;
                    } else {
                        temp = puzzle[x][y];
                        puzzle[x][y] = puzzle[x][y + 1];
                        puzzle[x][y + 1] = temp;
                        y++;
                    }
                } else if (move == 'B') {
                    if (x == 4) {
                        flag = false;
                    } else {
                        temp = puzzle[x][y];
                        puzzle[x][y] = puzzle[x + 1][y];
                        puzzle[x + 1][y] = temp;
                        x++;
                    } 
                } else if (move == 'A'){
                    if (x == 0) {
                        flag = false;
                    } else {
                        temp = puzzle[x][y];
                        puzzle[x][y] = puzzle[x - 1][y];
                        puzzle[x - 1][y] = temp;
                        x--;
                    }
                } else {
                    flag = false;
                }
            }
        }
        
        if (t != 0)
            std::cout << "\n";
        std::cout << "Puzzle #" << ++t << ":\n";
        if (flag == true) {
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j)
                    std::cout << puzzle[i][j] << ((j < 4) ? " " : "\n");
            }
        } else {
            std::cout << "This puzzle has no final configuration.\n";
        }
        
        std::cin.ignore();
    }

    return 0;
}