#include <iostream>
#include <string>
using namespace std;

#include "QuestionData.cpp"
#include "QuizEngine.cpp"

// A simple custom random generator using standard math (Linear Congruential Generator)
// Formula: next = (previous * A + C) % M
unsigned int seedValue = 12345;

int getSimpleRandom(int maxLimit) {
    seedValue = (seedValue * 1103515245 + 12345) % 2147483648;
    return seedValue % maxLimit;
}

// Simple shuffle function using our custom random generator
void shuffleIndices(int indices[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = getSimpleRandom(i + 1);
        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }
}

int main() {
    cout << "====================================================\n";
    cout << "       MINI QUIZ GAME WITH SCORES (OOP C++)\n";
    cout << "====================================================\n";

    cout << "Choose Domain:\n";
    cout << "  1. C++ Programming\n";
    cout << "  2. Environmental Sciences\n";
    cout << "  3. General Knowledge\n";
    cout << "  4. History\n";
    cout << "Enter Choice (1-4): ";

    int domainChoice;
    cin >> domainChoice;

    const int TOTAL_IN_BANK = 15;
    QuestionItem bankItems[TOTAL_IN_BANK];
    string domainName = "";

    if (domainChoice == 1) {
        loadCppQuestions(bankItems);
        domainName = "C++ Programming";
    } else if (domainChoice == 2) {
        loadEvsQuestions(bankItems);
        domainName = "Environmental Sciences";
    } else if (domainChoice == 3) {
        loadGkQuestions(bankItems);
        domainName = "General Knowledge";
    } else if (domainChoice == 4) {
        loadHistoryQuestions(bankItems);
        domainName = "History";
    } else {
        loadCppQuestions(bankItems);
        domainName = "C++ Programming";
    }

    int numStudents;
    cout << "\nEnter number of participating students: ";
    cin >> numStudents;

    int qPerQuiz;
    cout << "Enter number of questions per quiz (< 15): ";
    cin >> qPerQuiz;
    if (qPerQuiz < 1) qPerQuiz = 5;
    if (qPerQuiz > 15) qPerQuiz = 15;

    // Ask for a simple seed number to randomize questions differently each session
    cout << "Enter any random 2-4 digit number (seed): ";
    cin >> seedValue;

    StudentSession students[50];

    for (int s = 0; s < numStudents; s++) {
        string r, n;
        cout << "\n--------------------------------------------\n";
        cout << "Enter details for Student #" << (s + 1) << "\n";
        cout << "Registration Number: ";
        cin >> r;
        cout << "Student Name: ";
        cin.ignore();
        getline(cin, n);

        // 1. Prepare indices [0, 1, ..., 14]
        int indices[TOTAL_IN_BANK];
        for (int i = 0; i < TOTAL_IN_BANK; i++) {
            indices[i] = i;
        }

        // 2. Shuffle indices using our own function
        shuffleIndices(indices, TOTAL_IN_BANK);

        // 3. Pick the first qPerQuiz questions
        Question selectedQuestions[15];
        for (int i = 0; i < qPerQuiz; i++) {
            int pickedIdx = indices[i];
            selectedQuestions[i] = Question(
                bankItems[pickedIdx].id,
                bankItems[pickedIdx].text,
                bankItems[pickedIdx].options,
                bankItems[pickedIdx].correctIndex
            );
        }

        // 4. Run the quiz
        students[s].setStudentDetails(r, n, qPerQuiz);
        students[s].conductQuiz(selectedQuestions);
    }

    // --- End-of-Quiz Final Scoreboard ---
    cout << "\n\n========================================================================\n";
    cout << "            FINAL SCOREBOARD - DOMAIN: " << domainName << "\n";
    cout << "========================================================================\n";
    cout << "Reg No\t\tName\t\tCorrect\t\tWrong\t\tSkipped\t\tScore\n";
    cout << "------------------------------------------------------------------------\n";

    for (int s = 0; s < numStudents; s++) {
        students[s].printScoreCard();
    }

    cout << "========================================================================\n";
    cout << "Grading Policy: 1 Mark per correct answer | 0 for wrong/skipped\n\n";

    return 0;
}
