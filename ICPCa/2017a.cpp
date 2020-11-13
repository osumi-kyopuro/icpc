#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	while (true) {
		int n, m,sum=0, k=0;
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		vector<int>vec(n);
		for (int i = 0; i < n; i++) {
			cin >> vec.at(i);

		}
		sort(vec.begin(), vec.end());
		//reverse(vec.begin(), vec.end());
		int i = vec.size()-1;
		while(m < sum + vec.at(i)) {
			i--; 
			vec.pop_back();
		}
		while (m>=sum+vec.at(i)) {
			sum += vec.at(i);
			i--;
			vec.pop_back();
			k++;
		}
		//reverse(vec.begin(), vec.end());
		i = 0;
		while (m >= sum + vec.at(i)) {
			sum += vec.at(i);
			i++;
			k++;
		}
		
		if (k==0||k==1) {
			cout << "NONE" << endl;
		}
		else {
			cout << sum << endl;
		}
	}
}