#include <iostream>
#include <string>

using namespace std;

// Base class representing a person
class Person {
protected:
    string name;

public:
    Person() {
        name = "";
    }
    Person(string n) {
        name = n;
    }
    string getName() {
        return name;
    }
};

// Single inheritance: Student extends Person
class Student : public Person {
protected:
    string regNo;

public:
    Student() : Person() {
        regNo = "";
    }
    Student(string r, string n) : Person(n) {
        regNo = r;
    }
    string getRegNo() {
        return regNo;
    }
};

// Base scoring interface for runtime polymorphism
class ScoringRule {
public:
    virtual int calculateScore(int correct) {
        return correct;
    }
};

// Derived scoring implementation
class StandardScoring : public ScoringRule {
public:
    int calculateScore(int correct) override {
        return correct * 1;
    }
};

// Encapsulates individual question state and display
class Question {
private:
    int id;
    string text;
    string options[4];
    int correctIndex;

public:
    Question() {
        id = 0;
        text = "";
        correctIndex = 0;
    }

    Question(int qId, string qText, string opts[], int cIdx) {
        id = qId;
        text = qText;
        for (int i = 0; i < 4; i++) {
            options[i] = opts[i];
        }
        correctIndex = cIdx;
    }

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

// Multilevel inheritance: Person -> Student -> StudentSession
class StudentSession : public Student {
private:
    int totalQuestions;
    int correctCount;
    int wrongCount;
    int skippedCount;
    int finalScore;
    ScoringRule* rule;

public:
    StudentSession() : Student() {
        totalQuestions = 0;
        correctCount = 0;
        wrongCount = 0;
        skippedCount = 0;
        finalScore = 0;
        rule = NULL;
    }

    void setSessionDetails(string r, string n, int qCount, ScoringRule* rPtr) {
        regNo = r;
        name = n;
        totalQuestions = qCount;
        correctCount = 0;
        wrongCount = 0;
        skippedCount = 0;
        finalScore = 0;
        rule = rPtr;
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

            while (choice < 0 || choice > 4) {
                cout << "Invalid choice! Enter 0 to Skip, or 1-4: ";
                cin >> choice;
            }

            if (choice == 0) {
                skippedCount++;
            } else if ((choice - 1) == quizQuestions[i].getCorrectIndex()) {
                correctCount++;
            } else {
                wrongCount++;
            }
        }

        // Dynamic dispatch via base pointer
        if (rule != NULL) {
            finalScore = rule->calculateScore(correctCount);
        } else {
            finalScore = correctCount;
        }

        cout << "\nQuiz completed for " << name << "!\n";
    }

    void printScoreCard() {
        cout << regNo << "\t\t"
             << name << "\t\t"
             << correctCount << "\t\t"
             << wrongCount << "\t\t"
             << skippedCount << "\t\t"
             << finalScore << "\n";
    }
};
