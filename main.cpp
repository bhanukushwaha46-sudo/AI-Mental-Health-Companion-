#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include "ChatSession.h"
#include "SupportStrategy.h"

using namespace std;

int analyzeKeywords(const string& text) {
    string lowerText = text;
    transform(lowerText.begin(), lowerText.end(), lowerText.begin(), ::tolower);

    if (lowerText.find("suicide") != string::npos || 
        lowerText.find("kill") != string::npos || 
        lowerText.find("die") != string::npos || 
        lowerText.find("hopeless") != string::npos || 
        lowerText.find("emergency") != string::npos ||
        lowerText.find("end it") != string::npos ||
        lowerText.find("hurt myself") != string::npos ||
        lowerText.find("want to die") != string::npos ||
        lowerText.find("cant take it anymore") != string::npos) {
        return 9;
    }
    
    if (lowerText.find("stress") != string::npos || 
        lowerText.find("overwhelmed") != string::npos || 
        lowerText.find("anxious") != string::npos || 
        lowerText.find("pressure") != string::npos || 
        lowerText.find("worried") != string::npos ||
        lowerText.find("panic") != string::npos ||
        lowerText.find("depressed") != string::npos ||
        lowerText.find("exhausted") != string::npos) {
        return 6;
    }

    return 2;
}

int main() {
    cout << "=====================================================" << endl;
    cout << " AI-POWERED MENTAL HEALTH COMPANION & SOS SYSTEM" << endl;
    cout << " Team: Spartans | ID: DSCPP-III-2026-T336" << endl;
    cout << " Backend Developer: Bhanu Pratap (Team Lead)" << endl;
    cout << "=====================================================\n" << endl;

    vector<ChatSession> sessionHistory;
    queue<string> taskMessageQueue;
    BaseSupportStrategy* strategy = new AdvancedCrisisManager();

    int choice;
    do {
        cout << "\n--- C++ MODULAR BACKEND MENU ---\n";
        cout << "1. Enter Chat Message (Automated Sentiment Analysis)\n";
        cout << "2. View Vector Session History Logs\n";
        cout << "3. Exit Application\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string message;
            cout << "Enter user message text: ";
            getline(cin, message);
            
            if (message.empty()) {
                cout << "[Error]: Input cannot be empty!" << endl;
                continue;
            }

            int score = analyzeKeywords(message);
            cout << "[C++ Analyzer Engine]: Assessed score -> " << score << "/10" << endl;

            taskMessageQueue.push(message);
            sessionHistory.emplace_back(message, score);
            strategy->processResponse(score);
            taskMessageQueue.pop();

        } 
        else if (choice == 2) {
            cout << "\n--- VECTOR SESSION LOGS & METRICS ARCHIVE ---" << endl;
            if (sessionHistory.empty()) {
                cout << "No records logged during this session yet." << endl;
            } else {
                for (size_t i = 0; i < sessionHistory.size(); ++i) {
                    cout << i + 1 << ". ";
                    sessionHistory[i].displayLog();
                }
            }
        }
    } while (choice != 3);

    delete strategy;
    cout << "\n[System]: Modular C++ backend session closed safely." << endl;
    return 0;
}
