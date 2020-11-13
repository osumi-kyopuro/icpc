#include<iostream>
#include<vector>
using namespace std;
int main() {
	while (true) {
		int n, x, j1=0, k=0,j2=0,soeji=0,flag=0;
		cin >> n;
		if (n == 0) {
			break;
		}
		vector<char>vec(n);
		vector<int>count(32, 0);
		for (int i = 0; i < n; i++) {
			cin >> vec.at(i);


			x = vec.at(i) - 'A';
			count.at(x)++;
			for (int j = 0; j < 32; j++) {
				if (j2 <= count.at(j) && count.at(j) != 0) {
					if (j1 <= count.at(j)) {
						if (j!=soeji) {
							j2 = j1;
						}
						j1 = count.at(j);
						soeji = j;
					}
					else{
						j2 = count.at(j);
					}
				}
			}
			cout << j1 << " " << j2 << " " << i+1 << endl;
			if (j1 > j2 + n -i-1&&flag==0) {
				cout <<(char)('A'+ soeji)<< " "<<i+1  << endl;
				flag++;
				
			}

		}
		if (flag==0) {
			cout << "TIE" << endl;
		}
	}
		
		
		
	system("pause");

}