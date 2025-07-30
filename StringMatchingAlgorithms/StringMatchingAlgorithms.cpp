#include <iostream>
#include <vector>
std::string reverseString(std::string word)
{
    std::string reversed = "";
    for (int i{};i < word.length();i++)
    {
        reversed = word[i] + reversed;
    }
    return reversed;
}
void naiveStringMatching(std::string input, std::string pattern)
{
    int inputPointer = 0;
    int patternPointer = 0;
    int tempForInput;

    for (inputPointer=0;inputPointer < input.length(); inputPointer++)
    {
        tempForInput = inputPointer;
        for (patternPointer=0;patternPointer < pattern.length(); patternPointer++)
        {
            if (pattern[patternPointer]==input[inputPointer])
            {
                inputPointer++;
            }
            else
            {
                inputPointer = tempForInput;
                break;
            }
            if (patternPointer==pattern.length()-1)
            {
                std::cout << "Pattern found at position " << inputPointer - pattern.length() << std::endl;
                return;
            }
        }

    }
        std::cout << "Pattern not found." << std::endl;
}
std::vector<int> BuildLPSArray(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> lps(m, 0);

    int len = 0; // length of the previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}
void KMPSearch(const std::string& inputString, const std::string& pattern) {
    int n = inputString.length();
    int m = pattern.length();

    std::vector<int> lps = BuildLPSArray(pattern);

    int i = 0; 
    int j = 0; 

    while (i < n) {
        if (inputString[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            std::cout << "Pattern found at position " << (i - j) << std::endl;
            j = lps[j - 1]; 
        }
        else if (i < n && inputString[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}
int main()
{
    std::string inputString = "CAKECAKECAKEYCAKES";
    std::string pattern = "CAKES";
    //std::cout<<reverseString("raed");
    naiveStringMatching(inputString, pattern);
    std::cin.get();
}