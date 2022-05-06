// 1585 Score
#include <iostream>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t;
    while (t--) {        
        std::string s;
        std::cin >> s;
    
        int score = 0, combo = 0;
        int size = s.size();
        for (int i = 0; i < size; ++i) {
            if (s[i] == 'O')
                score += ++combo;
            else
                combo = 0;
        }
        std::cout << score << "\n";
    }

    return 0;
}
