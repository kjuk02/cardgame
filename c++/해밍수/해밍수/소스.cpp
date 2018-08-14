/* 20163150 2학년 이희지 <해밍수> */

#include <iostream>
#include <fstream>
#include <cmath>
#include<algorithm>

using namespace std;

int main(void) {

	ifstream inStream;
	inStream.open("input.txt");

	int numTestcase;
	inStream >> numTestcase;

	for (int i = 0; i < numTestcase; i++) {

		int num;
		inStream >> num;
		unsigned int arr[10000] = { 0, };
		int temp = 0;

		for (int c = 0; c < 13; c++) {
			for (int b = 0; b < 19; b++) {
				for (int a = 0; a < 30; a++) {

					if (pow(2, a) * pow(3, b) * pow(5, c) >= 398580750) {

						arr[temp] = 398580750;

					}
					else {
						arr[temp] = (pow(2, a)*pow(3, b)*pow(5, c));
						temp++;
					}

				}

			}
		}

		sort(arr, arr + temp);
		cout << arr[num - 1] << endl;

	}

	inStream.close();
	return 0;

}