#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string getCurrentTime()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char timeStr[9];
    strftime(timeStr, sizeof(timeStr), "%H:%M:%S", ltm);
    return string(timeStr);
}

string getCurrentDay()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char dayStr[10];
    strftime(dayStr, sizeof(dayStr), "%A", ltm);
    return string(dayStr);
}

string getWeather()
{
    return "It's sunny and 25 degrees Celsius.";
}

int main()
{
    string UserInput;
    string ChatBot = "ChatBot";
    string UserName;

    cout << "Hello! I'm " << ChatBot << ". What's your name?" << endl;
    getline(cin, UserName);

    cout << "Nice to meet you, " << UserName << "!" << endl;;

    while(true)
    {
        cout << "You : ";
        getline(cin, UserInput);

        for(char &c : UserInput)
        {
            c = tolower(c);
        }

        if(UserInput == "hi" || UserInput == "hello" || UserInput == "hey")
        {
            cout << ChatBot << " : Hello, " << UserName << "! How can I help you today?" << endl;
        }
        else if (UserInput == "how are you?" || UserInput == "how are you")
        {
            cout << ChatBot << " : I'm just a ChatBot, I don't have feelings. How about you?" << endl;
        }
        else if (UserInput == "I am fine" || UserInput == "I'm fine" || UserInput == "fine")
        {
            cout << ChatBot << " : That sounds good." << endl;
        }
        else if (UserInput == "what's the time?" || UserInput == "what time is it?" || UserInput == "time")
        {
            cout << ChatBot << " : The current time is " << getCurrentTime() << "." << endl;
        }
        else if (UserInput == "what's the day?" || UserInput == "what day is it?" || UserInput == "day")
        {
            cout << ChatBot << " : Today is " << getCurrentDay() << "." << endl;
        }
        else if (UserInput == "how's the weather?" || UserInput == "weather")
        {
            cout << ChatBot << " : " << getWeather() << "." << endl;
        }
        else if (UserInput == "bye" || UserInput == "exit")
        {
            cout << ChatBot << " : Goodbye, " << UserName << "! Have a great day!" << endl;
            break;
        }
        else
        {
            cout << ChatBot << " : I'm sorry, I didn't understand that." << endl;
        }
    }

    return 0;
}
