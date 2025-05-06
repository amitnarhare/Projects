#include <iostream>
#include <vector>
using namespace std;

int calculateScore(const vector<int>& rolls) {
    int score = 0;
    int frame = 0;
    int i = 0;

    while (frame < 10) 
    {
        if (frame < 9) 
        {
            
            if (rolls[i] == 10) { 
                score += 10 + rolls[i + 1] + rolls[i + 2];
                i += 1;
            } else if (rolls[i] + rolls[i + 1] == 10) { 
                score += 10 + rolls[i + 2];
                i += 2;
            } else { 
                score += rolls[i] + rolls[i + 1];
                i += 2;
            }
        } else 
        {
            
            score += rolls[i] + rolls[i + 1];
            if (rolls[i] == 10 || rolls[i] + rolls[i + 1] == 10) {
                score += rolls[i + 2]; 
            }
            break;
        }
        frame++;
    }

    return score;
}

int main() {
    vector<int> rolls;
    int Try;

    cout << " Enter the rolls"<<endl;
    while (cin >> Try) {
        rolls.push_back(Try);
        if (rolls.size() >= 21) 
            break;
    }

    int totalScore = calculateScore(rolls);
    cout << "Final Bowling Score: " << totalScore << endl;

    return 0;
}
