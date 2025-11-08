int priority(char x) {
	if (x == '/' || x == '*'||x=='%')return 2;
	if (x == '+' || x == '-')return 1;
	if (x == '^')return 3;
	return 0;
}
string toPreFix(string ss) {
	reverse(ss.begin(), ss.end());
	stack<char>s;
	string output = "";
	for (int i = 0; i < ss.size(); i++) {
		if (ss[i] == ' ')continue;
		if (isdigit(ss[i])||isalpha(ss[i])) {
			output += ss[i];
		}
		else if (ss[i] == '(') {
			s.push(ss[i]);
		}
		else if (ss[i] == ')') {
			while (!s.empty()&&s.top() != '(') { output += s.top(); s.pop(); }
			s.pop();
		}
		else {
			while (!s.empty() && (priority(ss[i]) < priority(s.top()) ||
				ss[i] == s.top() && ss[i] == '^')) {
				output += s.top();
				s.pop();
			}
			s.push(ss[i]);
		}
	}
	while (!s.empty()) {
		output += s.top();
		s.pop();
	}
	reverse(output.begin(), output.end());
	return output;
}

void ans(int& ret, int one, int two, char x) {
	if (x == '+'){
		ret= one + two;
		return;
	}
	if (x == '-') {
		ret = one - two;
		return;
	}
	if (x == '/') {
		ret = one / two;
		return;
	}
	if (x == '*') {
		ret = one * two;
		return;
	}
	if (x == '^') {
		ret = pow(one, two);
		return;
	}
}
int evaluate(string ss) {
	stack <int>s;
	for (int i = ss.size()-1; i >=0; i--) {
		if (isdigit(ss[i]) || isalpha(ss[i])) {
			s.push(ss[i] - '0');
			
		}
		else {
			int operand1 = s.top();
			s.pop();
			int operand2 = s.top();
			s.pop();
			int ret;
			ans(ret, operand1, operand2, ss[i]);
			s.push(ret);
		}
	}
	return s.top();

}
void handle(string &s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ')') {
			s[i] = '(';
		}
		else if (s[i] == '(') {
			s[i] = ')';
		}
	}
}
int main()
{
	int t = 1;
//	cin >> t;
	while (t--) {
		/*                     // infix normal for humane
		                      // prefix or postfix for machine


         3 + 2 * 5 => 3 + 2 5 *
         3 2 + 5 *
		 ((a+b)*c-d)*e
		 a b + c * d - e * //postfix 
		 * - * + a b c d e //prefix

		 while priority top of stack less or equal priority op (pop)
		*/
		string s;
		getline(cin, s);
		handle(s);

		cout << toPreFix(s); el;
		// Evlauate;(2+3)*4
		cout << evaluate(toPreFix(s));
		el;
	}
}
