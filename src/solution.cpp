
// #include <boost/shared_ptr.hpp>

#include <iostream>
#include <bitset>
#include <stack>

#include "solution.hpp"

namespace codility
{

using namespace std;

namespace lesson1
{
// https://app.codility.com/demo/results/trainingPDN6G4-P6S/

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)

    std::bitset<32> bits(N);

    bool shouldCount = false;
    int maxValue = 0;
    int counter = 0;
    for (size_t i = 0; i < bits.size(); ++i)
    {
        if (!shouldCount)
        {
            if (bits[i])
            {
                shouldCount = true;
            }
            continue;
        }

        if (bits[i])
        {
            maxValue = (counter > maxValue ? counter : maxValue);
            counter = 0;
        }
        else
        {
            ++counter;
        }
    }
    return maxValue;
}

} // lesson1

namespace lesson2
{
//https://app.codility.com/demo/results/training3J5P78-R8K/

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)

    if (A.size() < 2)
    {
        return A;
    }

    std::vector<int> result(A.size());
    for (int i = 0; i < A.size(); ++i)
    {
        int newPos = (i + K)%(A.size());
        result[newPos] = A[i];
    }

    return result;
}

} //lesson2

namespace lesson13
{
// https://app.codility.com/demo/results/trainingSQ5HZD-8TJ/

vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{
    // write your code in C++14 (g++ 6.2.0)
    vector<int> aSums(S.size() + 1, 0);
    vector<int> cSums(S.size() + 1, 0);
    vector<int> gSums(S.size() + 1, 0);
    for (size_t i = 0; i < S.size(); ++i)
    {
        aSums[i+1] = aSums[i];
        cSums[i+1] = cSums[i];
        gSums[i+1] = gSums[i];
        switch(S[i])
        {
            case 'A':
                aSums[i+1] += 1;
                break;
            case 'C':
                cSums[i+1] += 1;
                break;
            case 'G':
                gSums[i+1] +=1;
                break;
        }
    }

    vector<int> result;
    for (size_t i = 0; i < P.size(); ++i)
    {
        auto start = P[i];
        auto last = Q[i];

        if (aSums[last+1] - aSums[start] > 0)
        {
            result.push_back(1);
        }
        else if(cSums[last+1] - cSums[start] > 0)
        {
            result.push_back(2);
        }
        else if(gSums[last+1] - gSums[start] > 0)
        {
            result.push_back(3);
        }
        else
        {
            result.push_back(4);
        }
    }

    return result;
}

} // lesson13

namespace lesson14
{
// https://app.codility.com/demo/results/training4RCT28-RP7/

int solution(vector<int> &A) {

    std::vector<int> prefix(A.size());

    prefix[0] = A[0];
    for (size_t i = 1; i < A.size(); ++i)
    {
        prefix[i] = A[i] + prefix[i-1];
    }

    double finalMinValue, currentMinValue;
    finalMinValue = currentMinValue = (A[0] + A[1]) / 2.0;
    int currentPrevPos = -1; // -1 means not set
    int finalMinPosition = 0;
    for (size_t i = 1; i < prefix.size(); ++i)
    {
        int offset = (currentPrevPos == -1) ? 0 : currentPrevPos;
        int divider = i + 1 - offset;
        int prevValue = (currentPrevPos == -1) ? 0 : prefix[currentPrevPos - 1];
        double avgWithoutPrevValue = (double(prefix[i]) - prevValue) / divider;
        
        double avgOfTwo = (A[i-1] + A[i]) / 2.0;

        if (avgOfTwo < avgWithoutPrevValue)
        {
            currentPrevPos = i - 1;
            currentMinValue = avgOfTwo;
        }
        else
        {
            currentMinValue = avgWithoutPrevValue;
        }

        if (currentMinValue < finalMinValue)
        {
            finalMinValue = currentMinValue;
            finalMinPosition = currentPrevPos;
        }
    }

    return finalMinPosition;
}

} // lesson14

namespace brackets
{
// https://app.codility.com/demo/results/trainingTNRNXR-GB9/

enum class Bracket
{
    Round,
    Square,
    Curly
};

int solution(string &S)
{
    std::stack<Bracket> buffer;
    for (const auto& sign : S)
    {
        if (sign == '(') buffer.push(Bracket::Round);
        else if (sign == ')')
        {
            if (buffer.empty() || buffer.top() != Bracket::Round) return 0;
            buffer.pop();
        }
        else if (sign == '[') buffer.push(Bracket::Square);
        else if (sign == ']')
        {
            if (buffer.empty() || buffer.top() != Bracket::Square) return 0;
            buffer.pop(); 
        }
        else if (sign == '{') buffer.push(Bracket::Curly);
        else if (sign == '}')
        {
            if (buffer.empty() || buffer.top() != Bracket::Curly) return 0;
            buffer.pop();
        }
    }
    return buffer.empty() ? 1 : 0;
}

} // brackets

} // codility
