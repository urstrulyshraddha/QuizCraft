#include <iostream>
#include <string>

using namespace std;

// Include module implementations directly
#include "QuestionData.cpp"
#include "QuizEngine.cpp"

// Global seed state for pseudo-random number generation
unsigned int seedValue = 12345;

// Linear Congruential Generator: next = (seed * a + c) % m
int getSimpleRandom(int maxLimit) {
    seedValue = (seedValue * 1103515245 + 12345) % 2147483648;
    return seedValue % maxLimit;
}

// Fisher-Yates shuffle algorithm to randomize question indices
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

    // 1. Domain Selection
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

    switch (domainChoice) {
        case 1:
            loadCppQuestions(bankItems);
            domainName = "C++ Programming";
            break;
        case 2:
            loadEvsQuestions(bankItems);
            domainName = "Environmental Sciences";
            break;
        case 3:
            loadGkQuestions(bankItems);
            domainName = "General Knowledge";
            break;
        case 4:
            loadHistoryQuestions(bankItems);
            domainName = "History";
            break;
        default:
            loadCppQuestions(bankItems);
            domainName = "C++ Programming";
            break;
    }

    // 2. Session Configuration
    int numStudents;
    cout << "\nEnter number of participating students: ";
    cin >> numStudents;
    if (numStudents < 1) numStudents = 1;
    if (numStudents > 50) numStudents = 50;

    int qPerQuiz;
    cout << "Enter number of questions per quiz (10 to 15): ";
    cin >> qPerQuiz;
    if (qPerQuiz < 5) qPerQuiz = 5;
    if (qPerQuiz > 15) qPerQuiz = 15;

    // Seed input for reproducible randomness across rounds
    cout << "Enter any random 2-4 digit number (seed): ";
    cin >> seedValue;

    // Array of Objects: maintains session state for each participant
    StudentSession students[50];

    // 3. Execution of Quiz per Student
    for (int s = 0; s < numStudents; s++) {
        string r, n;
        cout << "\n--------------------------------------------\n";
        cout << "Enter details for Student #" << (s + 1) << "\n";
        cout << "Registration Number: ";
        cin >> r;
        cout << "Student Name: ";
        cin.ignore();
        getline(cin, n);

        // Populate index pool [0 ... 14] and shuffle
        int indices[TOTAL_IN_BANK];
        for (int i = 0; i < TOTAL_IN_BANK; i++) {
            indices[i] = i;
        }
        shuffleIndices(indices, TOTAL_IN_BANK);

        // Select the first qPerQuiz shuffled questions
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

        // Initialize and conduct quiz attempt
        students[s].setStudentDetails(r, n, qPerQuiz);
        students[s].conductQuiz(selectedQuestions);
    }

    // 4. Final Scoreboard Display
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
