#include <iostream>
#include <vector>
using namespace std;

vector<string> nums = {"Zero", "One", "Two", "Three", "Four", 
                       "Five", "Six", "Seven", "Eight", "Nine", 
                       "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", 
                       "Fifteen", "Sixteen", "Seventeen", "Eighteen","Nineteen"};

vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Fourty", "Fifty",
                       "Sixty", "Seventy", "Eighty", "Ninety"};

vector<string> thousands = {"", "Thousand", "Million", "Billion"};

string convert_to_english(int number){
    string result;
    if(number >= 100){
        result += nums[number/100];
        result += " Hundred ";
        number %= 100;
    }
    if(number >= 20){
        result += tens[number/10];
        result += " ";
        number %= 10;
    }
    if(number >= 1 && number <= 19){
        result += nums[number];
    }

    return result;
}

string convert_number_to_english(int number){
    string result;
    int count = 0;
    while(number > 0){
        if(number%1000 != 0){
            string res =  convert_to_english(number%1000) + " " + thousands[count];
            result = res + " " + result;
        }
        number /= 1000;
        count++;
    }
    return result;
}

void test_case_one(){
    int number = 672;
    auto res = convert_to_english(number);
    cout << "123 in english = " << res << endl;
}

void test_case_two(){
    int number = 6723;
    auto res = convert_number_to_english(number);
    cout << "6723 in english = " << res << endl;
}

void test_case_three(){
    int number = 23456;
    auto res = convert_number_to_english(number);
    cout << "23456 in english = " << res << endl;
}

int main(){
    test_case_one();
    test_case_two();
    test_case_three();
    return 0;
}
