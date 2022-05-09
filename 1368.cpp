// 1368 DNA Consensus String
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t;
    while (t--) {
        int m, n;
        std::string s;
        std::vector<std::string> dna;
        std::cin >> m >> n;
        for (int i = 0; i < m; ++i) {
            std::cin >> s;
            dna.push_back(s);
        }

        std::string str = "";
        int err = 0;
        for (int i = 0; i < n; ++i) {
            int cnt[4] = {0, 0, 0, 0};
            for (int j = 0; j < m; ++j) {
                if (dna[j][i] == 'A')    cnt[0]++;
                else if (dna[j][i] == 'C')    cnt[1]++;
                else if (dna[j][i] == 'G')    cnt[2]++;
                else if (dna[j][i] == 'T')    cnt[3]++;
            }

            if (cnt[0] >= cnt[1] && cnt[0] >= cnt[2] && cnt[0] >= cnt[3]) {
                str += "A";
                err += (cnt[1] + cnt[2] + cnt[3]);
            } else if (cnt[1] >= cnt[2] && cnt[1] >= cnt[3]) {
                str += "C";
                err += (cnt[0] + cnt[2] + cnt[3]);
            } else if (cnt[2] >= cnt[3]) {
                str += "G";
                err += (cnt[0] + cnt[1] + cnt[3]);
            } else {
                str += "T";
                err += (cnt[0] + cnt[1] + cnt[2]);
            }
        }

        std::cout << str << "\n" << err << "\n";
    }
    
    return 0;
}
