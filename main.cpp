#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

int result(int numOne, char action, int numTwo){

    int result = 0;

    switch (action) {
        case '+':
            result = numOne + numTwo;
            break;
        case '-':
            result = numOne - numTwo;
            break;
        case '*':
            result = numOne * numTwo;
            break;
        case '/':
            result = numOne / numTwo;
            break;
        case '%':
            result = numOne % numTwo;
            break;
        defaut:
            break;
    }

    return result;
}

int cmp(std::pair<std::string, int> & a, std::pair<std::string, int> & b){
    return a.second > b.second;
}

void printStream(std::stringstream & istr){

    std::string current;
    while(istr >> current){
        std::cout << current << std::endl;
    }
}

int main() {
    int counter = 0;
    std::cin >> counter;
    std::cin.ignore();

    std::stringstream istr;

    std::vector<std::pair<std::string, int>> totalResults;
    std::string data;

    char action;
    int numOne = 0;
    int numTwo = 0;
    int endResult = 0;
    std::string stringempty = " ";

    for (int i = 0; i < counter; ++i) {
        std::cin >> numOne >> action >> numTwo;
        endResult = result(numOne, action, numTwo);
        istr << numOne;
        istr << stringempty;
        istr << action;
        istr << stringempty;
        istr << numTwo;
        data = istr.str();
        istr.str("");
        totalResults.emplace_back(data, endResult);
        data = "";
    }

    std::sort(totalResults.begin(), totalResults.end(), cmp);

    for(auto & result : totalResults){
        std::cout << result.first << std::endl;
    }


    return 0;
}

/*
3
1 / 2
1 + 2
1 * 2
 */