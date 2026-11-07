#include <iostream>
#include <string>

using namespace std;

// Class 1: Encapsulation of Question details
class Question {
private:
    int id;
    string text;
    string options[4];
    int correctIndex;

public:
    // Default constructor
    Question() {
        id = 0;
        text = "";
        correctIndex = 0;
    }

    // Parameterized constructor
    Question(int qId, string qText, string opts[], int cIdx) {
        id = qId;
        text = qText;
        for (int i = 0; i < 4; i++) {
            options[i] = opts[i];
        }
        correctIndex = cIdx;
    }

    // Member function to display question and options
    void displayQuestion(int qNumber) {
        cout << "\nQuestion " << qNumber << ": " << text << "\n";
        for (int i = 0; i < 4; i++) {
            cout << "  " << (i + 1) << ". " << options[i] << "\n";
        }
        cout << "  0. Skip this question\n";
    }

    int getCorrectIndex() {
        return correctIndex;
    }
};

// Class 2: Manages individual student quiz attempt
class StudentSession {
private:
    string regNo;
    string name;
    int totalQuestions;
    int correctCount;
    int wrongCount;
    int skippedCount;
    int score;

public:
    StudentSession() {
        regNo = "";
        name = "";
        totalQuestions = 0;
        correctCount = 0;
        wrongCount = 0;
        skippedCount = 0;
        score = 0;
    }

    void setStudentDetails(string r, string n, int qCount) {
        regNo = r;
        name = n;
        totalQuestions = qCount;
        correctCount = 0;
        wrongCount = 0;
        skippedCount = 0;
        score = 0;
    }

    void conductQuiz(Question quizQuestions[]) {
        cout << "\n============================================\n";
        cout << " Starting Quiz for: " << name << " (" << regNo << ")\n";
        cout << " Enter 1 to 4 to answer, or 0 to Skip.\n";
        cout << "============================================\n";

        for (int i = 0; i < totalQuestions; i++) {
            quizQuestions[i].displayQuestion(i + 1);

            int choice = -1;
            cout << "Your Choice: ";
            cin >> choice;

            // Simple validation
            while (choice < 0 || choice > 4) {
                cout << "Invalid choice! Enter 0 to Skip, or 1-4: ";
                cin >> choice;
            }

            if (choice == 0) {
                skippedCount++;
            } else if ((choice - 1) == quizQuestions[i].getCorrectIndex()) {
                correctCount++;
                score += 1; // 1 mark per correct answer, 0 for wrong/skip
            } else {
                wrongCount++;
            }
        }
        cout << "\nQuiz completed for " << name << "!\n";
    }

    // Formatted row for final scoreboard
    void printScoreCard() {
        cout << regNo << "\t\t"
             << name << "\t\t"
             << correctCount << "\t\t"
             << wrongCount << "\t\t"
             << skippedCount << "\t\t"
             << score << "\n";
    }
};
