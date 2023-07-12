#include<bits/stdc++.h>
using namespace std;

bool is_operator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '>' || ch == '<' || ch == '=' || ch == '|' || ch == '&')
    {
       return true;
    }
    return false;
}

bool bracket(char ch)
{
	if (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']')
		return true;
	return false;
}

bool keyword(string s)
{
    if (s == "if"  || s == "else" || s ==  "while" || s ==  "do" || s == "break" || s ==  "continue"
       || s ==  "int"|| s ==  "double"|| s == "float" || s ==  "return"|| s ==  "char"|| s == "case"
        || s ==  "long"|| s ==  "short"|| s ==  "typedef"|| s == "switch"
       || s == "unsigned"|| s == "void"|| s == "static"|| s ==  "struct"|| s ==  "sizeof"|| s == "long"
        || s ==  "volatile"|| s ==  "typedef"|| s == "enum"|| s == "const"
        || s ==  "union"|| s ==  "extern"|| s == "bool") {
			return true;
        }
    else
    {
       return false;
    }
}

bool ws_semi(char ch)
{
	if (ch == ' ' || ch == '\n' || ch == ';' || ch ==',')
		return true;
	return false;
}

bool literal_comment(char ch)
{
	if (ch == '\"')  return true;
	if (ch == '\'' ) return true;
	if (ch == '/') return true;

	return false;
}



bool letter_(char ch)
{
	if (ch >= 'A' && ch <= 'Z') return true;
	if (ch >= 'a' && ch <= 'z') return true;
	if (ch == '_') return true;
	return false;
}

bool digit(char ch)
{
	if (ch >= '0' && ch <= '9') return true;
	return false;
}

bool identifier(string  s)
{
	int i = 0;
	if (!letter_(s[0])) return false; i++;

	while (i < s.size() && (letter_(s[i]) || digit(s[i]))) {
		i++;
	}

	if (i == s.size()) return true;

	return false;
 }

 bool number(string s)
 {
 	int i = 0;
 	bool point = 0, e = 0;

 	while (i < s.size() && digit(s[i])) i++;

	if (i == s.size()) return true;

	if (s[i] == '.') point = true, i++;
	while (i < s.size() && digit(s[i])) i++;
	if (i == s.size()) return true;

	if (s[i] == 'E') e = true, i++;
	if (i == s.size()) return false;
	if (s[i] == '+' || s[i] == '-') i++;
	if (i == s.size()) return false;
	while (i < s.size() && digit(s[i])) i++;

	if (i == s.size()) return true;

	return false;
 }

void find_error(string &s)
{
	int left = 0, right = 0, len = s.size();
	string now = "";

	while (left < len) {

		while (right < len && !is_operator(s[right]) && !ws_semi(s[right]) && !bracket(s[right]) && !literal_comment(s[right]) ){
			now += s[right];
			right++;
		}

		//cout << now << " " << right << endl;

		if (right < len && literal_comment(s[right])) {
				char ch = s[right++];
				while ((right < len && !(ch == s[right])) || (right+1 < len && !s[right] == '*' && !s[right+1] == '/'))
					right++;
				if (s[right] == '/') right++;
		}

		while (right < len && (ws_semi(s[right]) || bracket(s[right])))
			right++;

		cout << now << endl;
		if (identifier(now) || keyword(now) || number(now));
		else {
			cout << "Lexical Error!" << endl;
			return ;
		}

		left = right;
		now = "";
	}
}

int main()
{
	string s, temp;
	while (getline(cin, temp))
		s += temp;
	find_error(s);

}

/*
int main()
{
	printf("hi");$
	return 0;
}

*/
