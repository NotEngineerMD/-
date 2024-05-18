#include <iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;

int main() {
    srand( time(NULL) );
    int tests = 30000; // 測試樣本數
    int coincnt;
    cout << "你想問連續幾連反面？\n";
    cin >> coincnt;
    int games[4]; // 玩了幾場(4種情況)
    games[0] = 1000;
    games[1] = 2000;
    games[2] = 5000;
    games[3] = 10000;
    int pass[4]; // 達標連續10場反面(4種情況)
    pass[0] = 0;
    pass[1] = 0;
    pass[2] = 0;
    pass[3] = 0;
    cout << "測試樣本數：" << tests << endl;
    for (int a = 0; a < 4; a++) {
        int var[20000]; // 硬幣正反容器
        for (int i = 0; i < tests; i++) {
            int cnt = 0; // 連續反面計數器
            for (int j = 0; j < games[a]; j++) var[j] = rand() % 2;
            for (int j = 0; j < games[a]; j++) {
                if (var[j] == 0) cnt = 0;
                else cnt++;
                if (cnt >= coincnt) {pass[a]++; break;}
            }
        }
        cout << "-----\n" << "場次：" << games[a] << endl;
        cout << "丟過" << coincnt << "連反面硬幣的機率：" << 100 * static_cast<float>(pass[a]) / static_cast<float>(tests) << "%\n";
    }
    return 0;
}
