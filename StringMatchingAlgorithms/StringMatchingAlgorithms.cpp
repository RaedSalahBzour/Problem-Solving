#include <iostream>
std::string reverseString(std::string word)
{
    std::string reversed = "";
    for (int i{};i < word.length();i++)
    {
        reversed = word[i] + reversed;
    }
    return reversed;
}
int main()
{
    std::cout<<reverseString("raed");
    std::cin.get();
}