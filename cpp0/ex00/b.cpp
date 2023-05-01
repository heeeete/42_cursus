#include <cstring>
#include <string>
#include <iostream>

class string {
  char *str;
  int len;

 public:
  string(char c, int n);  // 문자 c 가 n 개 있는 문자열로 정의
  string(const char *s);
  string(const string &s);
  ~string();

  void add_string(const string &s);   // str 뒤에 s 를 붙인다.
  void copy_string(const string &s);  // str 에 s 를 복사한다.
  void print_string();
  int strlen();                       // 문자열 길이 리턴
};

string::string(char c, int n) {
	str = new char[n];
	while (n--) {
		str[n] = c;
	}
}

string::string(const char *s){
	str = new char[std::strlen(s) + 1];
	strcpy(str, s);
}

string::string(const string &s){
	str = new char[std::strlen(s.str) + 1];
	strcpy(str, s.str);
}

string::~string() {
	delete []str;
}

void string::print_string(){
	std::cout << str << std::endl;
}

void string::add_string(const string &s){
	strcat(str, s.str);
}

void string::copy_string(const string &s){
	delete []str;
	str = new char[std::strlen(s.str) + 1];
	strcpy(str, s.str);
}

int string::strlen(){
	return std::strlen(str);
}

int main() {
	string str('a', 10);
	string str2("asd");
	string str3(str2);
	str.print_string();
	str2.print_string();
	str3.print_string();
	str3.add_string(" hello");
	str3.print_string();
	str3.copy_string("huipark");
	str3.print_string();
}
