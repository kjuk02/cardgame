/***************************************************************
*  시이저암호문복호기법                                                                                                  *
***************************************************************/
/***************************************************************
* 국민대학교 소프트웨어융합대학 소프트웨어학부 20163281황수진                                *
***************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

//#define __MY_DEBUG__
void hw_32(std::ifstream& ifs);

int main()
{
	std::ifstream ifs;

	ifs.open("input.txt");
	if (ifs.fail())
	{
		std::cerr << "Cannot open file: input.txt" << std::endl;
		exit(1);
	}
	int num_cases;
	ifs >> num_cases;
#ifdef __MY_DEBUG__
	std::cout << "num_cases : " << num_cases << '\n';
#endif

	for (int i = 0; i < num_cases; ++i)
	{
		hw_32(ifs);
	}
	ifs.close();

	return 0;
}

void hw_32(std::ifstream& ifs)
{
	//문제에 주어진 알파벳의 백분율을 a부터 z까지 순서대로 저장
	double fe[26] = { 8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 6.996, 0.153, 0.772, 4.025, 2.406, 6.749, 7.507, 1.929, 0.095, 5.987, 6.327, 9.056, 2.758, 0.978, 2.360, 0.150, 1.974, 0.074 };

	std::string s;
	ifs >> s; //스트링 입력받기

			  //num : 암호문에서 문자의 빈도수 체크(0번째 : a의 빈도수, 1번째 : b의 빈도수 ...)
	double num[26] = { 0, };
	//fm : 암호문에서 문자의 빈도수 백분율
	//kai : 카이제곱결과 저장
	double fm[26] = { 0, }, kai[26] = { 0, }, min ;

	//문자열 받기
	/*(입력받은 스트링의 i번째가 A나 a이면 num배열의 0번째 값 1개씩 증가
	*b나 B이면 1번째 값 1개 증가 ...
	*스트링의 길이만큼 반복하면서 A(a) ~ Z(z) 빈도수 체크)*/
	for (int i = 0; i < s.length(); i++) {
		switch (s[i]) {
		case 'A':
		case 'a':
			num[0]++;
			break;

		case 'B':
		case 'b':
			num[1]++;
			break;

		case 'C':
		case 'c':
			num[2]++;
			break;

		case 'D':
		case 'd':
			num[3]++;
			break;

		case 'E':
		case 'e':
			num[4]++;
			break;

		case 'F':
		case 'f':
			num[5]++;
			break;

		case 'G':
		case 'g':
			num[6]++;
			break;

		case 'H':
		case 'h':
			num[7]++;
			break;

		case 'I':
		case 'i':
			num[8]++;
			break;

		case 'J':
		case 'j':
			num[9]++;
			break;

		case 'K':
		case 'k':
			num[10]++;
			break;

		case 'L':
		case 'l':
			num[11]++;
			break;

		case 'M':
		case 'm':
			num[12]++;
			break;

		case 'N':
		case 'n':
			num[13]++;
			break;

		case 'O':
		case 'o':
			num[14]++;
			break;

		case 'P':
		case 'p':
			num[15]++;
			break;

		case 'Q':
		case 'q':
			num[16]++;
			break;

		case 'R':
		case 'r':
			num[17]++;
			break;

		case 'S':
		case 's':
			num[18]++;
			break;

		case 'T':
		case 't':
			num[19]++;
			break;

		case 'U':
		case 'u':
			num[20]++;
			break;

		case 'V':
		case 'v':
			num[21]++;
			break;

		case 'W':
		case 'w':
			num[22]++;
			break;

		case 'X':
		case 'x':
			num[23]++;
			break;

		case 'Y':
		case 'y':
			num[24]++;
			break;

		case 'Z':
		case 'z':
			num[25]++;
			break;
		}
	}

	int cnt = 0; //스트링에서 알파벳만의 갯수
	for (int i = 0; i < s.length(); i++) {
		if (((65 <= (int)s[i]) && ((int)s[i]) <= 90) || (97 <= (int)s[i]) && (((int)s[i]) <= 122)) {
			cnt++;
		}
	}

	//암호문 백분율 계산
	//위에서 알파벳의 빈도수를 센 후에 백분율 계산
	// : 빈도수 / 알파벳만의 갯수
	for (int i = 0; i < cnt; i++) {
		fm[i] = num[i] / cnt;
	}
	min = kai[0];
	//카이제곱계산
	int key = 0, temp = 0;
	for (int i = 0; i < 26; i++) { //i : key값이 될 수 있는 후보
		for (int j = 0; j < 26; j++) { //j : fm[]에 접근할 인덱스
			 temp = i + j; //알파벳에서 키값만큼 이동한 알파벳이 있는 곳
			if (temp >= 26)
				temp -= 26;
			kai[i] += (fm[temp] * fm[temp]) / fe[j]; //빈도수의 제곱/알파벳에의 백분율을 kai에 저장
		}

		//카이제곱의 최솟값과 그 인덱스 찾기
		if (min > kai[i]) {
			min = kai[i];
			key = i;
		}
	}
	//key값 확인용 출력문
	//std::cout << "key : " << key << std::endl;

	for (int i = 0; i < s.length(); i++) {
		//알파벳일때만 key값만큼 이동해야함
		//key값만큼 뺐는데 65이나 97보다 작을 경우 25+1을 해줌
		if (char(s[i] )>= 'A' && char(s[i]) <= 'Z')
		{
			if (s[i] - key < 65)
				std::cout << char(s[i] - key + 26);
			else
				std::cout << char(s[i] - key);
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			if (s[i] - key < 97)
				std::cout << char(s[i] - key + 26);
			else
				std::cout << char(s[i] - key);
		}
		else
			std::cout << s[i];

	}std::cout << std::endl;
}