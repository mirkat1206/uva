// 1225 Digit Counting 
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        
        int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for(int i = 1; i <= n; ++i) {
            int temp = i;
            do {
                count[temp % 10]++;
                temp /= 10;
            }while (temp);
        }
        std::cout << count[0];
        for (int i = 1; i <= 9; ++i)
            std::cout << " " << count[i];
        std::cout << "\n";
    }

    return 0;
}
