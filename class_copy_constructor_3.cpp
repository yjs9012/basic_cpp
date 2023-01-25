#include <string.h>
#include <iostream>

class string
{
    char *str;
    int len;

public:
    string(char c, int n); // 문자 c 가 n 개 있는 문자열로 정의
    string(const char *s);
    string(const string &s);
    ~string();

    void add_string(const string &s);  // str 뒤에 s 를 붙인다.
    void copy_string(const string &s); // str 에 s 를 복사한다.
    int strlen();                      // 문자열 길이 리턴
};

string::string(char c, int n)
{
    str = new char[n + 1];
    for (int i = 0; i < n; ++i)
    {
        str[i] = c;
    }
    str[n] = '\0';
    len = n;
}
string::string(const char *s)
{
    len = 0;
    while (*s != NULL)
    {
        len++;
        s++;
    }
    s -= len;
    str = new char[len + 1];

    strcpy(str, s);
}
string::string(const string &s)
{
    len = s.len;
    str = new char[len];
    strcpy(str, s.str);
}
string::~string()
{
    if (str)
    {
        delete[] str;
        std::cout << "소멸자 호출" << std::endl;
    }
}
/******************************************************/
void string::add_string(const string &s) // str 뒤에 s 를 붙인다.
{
    int new_len = len + s.len + 1;
    char *new_str = new char[new_len];
    char *original = str;
    char *add = s.str;

    int i = 0;
    while (*original)
    {
        new_str[i++] = *original;
        original++;
    }
    while (*add)
    {
        new_str[i++] = *add;
        add++;
    }
    new_str[i] = '\0';
    delete[] str;
}
void string::copy_string(const string &s) // str 에 s 를 복사한다.
{
    delete[] str;
    len = s.len;
    str = new char[len + 1];
    strcpy(str, s.str);
}
int string::strlen() // 문자열 길이 리턴
{
    return len;
}
/******************************************************/
int main()
{
    string s1('o', 4);
    string s2("abcde");
    string s3(s1);
    string s4(s2);

    std::cout << "길이" << s1.strlen() << std::endl;
    std::cout << "길이" << s2.strlen() << std::endl;
    std::cout << "길이" << s3.strlen() << std::endl;
    std::cout << "길이" << s4.strlen() << std::endl;

    s1.add_string(s2);
    std::cout << "길이" << s1.strlen() << std::endl;

    s3.copy_string(s4);
    std::cout << "길이" << s1.strlen() << std::endl;

    return 0;
}