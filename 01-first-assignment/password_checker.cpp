/*
 * 1. 原错误分析：
 *    - 长度判断错误：原代码为 <= 10，应为 >= 10（至少10个字符）。
 *    - 范围边界错误：原代码为 < 和 >，漏掉了 A, Z, a, z, 0, 9 等边界字符，应改为 <= 和 >=。
 *    - 数字判断类型错误：原代码传入的是整数 0 和 9，应传入字符 '0' 和 '9'。
 * 2. 自己设计的测试用例：
 *    - 输入：Zhang San Xy12345678 预期输出：VALID
 *    - 输入：Zhang San Zhang1234567 预期输出：INVALID
 */
#include <iostream>
#include <string>

bool contains_between(const std::string& text, char lower, char upper) {
    for (char ch : text) {
        if (lower <= ch && ch <= upper) {
            return true;
        }
    }
    return false;
}

bool check_password(const std::string& first_name,
                    const std::string& last_name,
                    const std::string& password) {
    bool length_ok = password.size() >= 10;
    bool upper_ok = contains_between(password, 'A', 'Z');
    bool lower_ok = contains_between(password, 'a', 'z');
    bool digit_ok = contains_between(password, '0', '9');
    
    bool name_ok = password.find(first_name) == std::string::npos &&
                   password.find(last_name) == std::string::npos;
                   
    return length_ok && upper_ok && lower_ok && digit_ok && name_ok;
}

int main() {
    std::string first_name, last_name, password;
    if (!(std::cin >> first_name >> last_name >> password)) {
        std::cerr << "请输入：名 姓 密码\n";
        return 1;
    }
    std::cout << (check_password(first_name, last_name, password)
                      ? "VALID" : "INVALID") << '\n';
    return 0;
}
