#include <iostream>
#include <string>
#include <map>

class Question {
private:
    std::string questionText;
    std::string options[4];
    char correctOption;

public:
    Question(std::string text, std::string optA, std::string optB, std::string optC, std::string optD, char correct)
        : questionText(text), correctOption(correct) {
        options[0] = optA;
        options[1] = optB;
        options[2] = optC;
        options[3] = optD;
    }

    void displayQuestion() const {
        std::cout << questionText << std::endl;
        for (int i = 0; i < 4; ++i) {
            std::cout << char('A' + i) << ". " << options[i] << std::endl;
        }
    }

    bool checkAnswer(char answer) const {
        return std::toupper(answer) == correctOption;
    }

    char getCorrectOption() const {
        return correctOption;
    }
};

struct Player {
    std::string name;
    int score = 0;
};

int main() {
    int numPlayers;
    std::cout << "Enter the number of players: ";
    std::cin >> numPlayers;
    std::cin.ignore();  // Ignore the newline character left in the input buffer

    Player players[numPlayers];

    for (int i = 0; i < numPlayers; ++i) {
        std::cout << "Enter name for Player " << i + 1 << ": ";
        std::getline(std::cin, players[i].name);
    }

    Question questions[] = {
        {"What is the capital of France?", "Berlin", "Paris", "London", "Madrid", 'B'},
        {"Which planet is known as the Red Planet?", "Jupiter", "Venus", "Mars", "Saturn", 'C'},
        {"Who wrote 'Romeo and Juliet'?", "Charles Dickens", "William Shakespeare", "Jane Austen", "Mark Twain", 'B'}
    };

    for (int i = 0; i < numPlayers; ++i) {
        std::cout << std::endl;
        std::cout << "Player: " << players[i].name << std::endl;
        std::cout << "--------------------------" << std::endl;

        for (const auto& question : questions) {
            question.displayQuestion();

            std::cout << "Enter your answer (A, B, C, or D): ";
            char userAnswer;
            std::cin >> userAnswer;

            if (question.checkAnswer(userAnswer)) {
                std::cout << "Correct!" << std::endl;
                players[i].score++;
            } else {
                std::cout << "Wrong! The correct answer is " << question.getCorrectOption() << "." << std::endl;
            }

            std::cin.ignore();  // Ignore the newline character left in the input buffer
        }
    }

    std::cout << "--------------------------" << std::endl;
    std::cout << "Leaderboard" << std::endl;
    std::cout << "--------------------------" << std::endl;

    std::map<int, std::string, std::greater<int>> leaderboard;  // Use map to store scores and sort by score
    for (const auto& player : players) {
        leaderboard[player.score] = player.name;
    }

    int rank = 1;
    for (const auto& entry : leaderboard) {
        std::cout << rank++ << ". " << entry.second << " - " << entry.first << " points" << std::endl;
    }

    return 0;
}
