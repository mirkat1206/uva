// 455 Prediodic Strings
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        
        int size = s.size();
        for (int length = 1; length <= size; ++length) {
            if (size % length == 0) {
                int num_subs = size / length;
                bool flag = true;
                for (int i = 1; i < num_subs && flag; ++i) {
                    for (int j = 0; j < length && flag; ++j) {
                        if (s[j] != s[j + i * length])
                            flag = false;
                    }
                }
                if (flag) {
                    std::cout << length << "\n"; 
                    if (t)
                        std::cout << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}
