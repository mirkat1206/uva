// 1586 Molar mass
#include <iostream>
#include <iomanip>
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

        double molar_mass = 0;
        int size = s.size();
        for (int i = 0; i < size; ++i) {
            double weight;
            if (s[i] == 'C')        weight = 12.01;
            else if (s[i] == 'H')   weight = 1.008;
            else if (s[i] == 'O')   weight = 16.00;
            else                    weight = 14.01;
            
            int number = 0;
            while ((i + 1) < size && s[i + 1] >= '0' && s[i + 1] <= '9') {
                number *= 10;
                number += (s[i + 1] - '0');
                i++;
            }            
            molar_mass += weight * (number ? number : 1);
        }        
        std::cout << std::fixed << std::setprecision(3) << molar_mass << "\n";
    }

    return 0;
}
