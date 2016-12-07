#include <iostream>
#include <vector>

using namespace std;

int n = 0;
vector<int> k;

int result = 0;

void InputData()
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x = 0;
		cin >> x;
		k.push_back(x);
	}
}

void ProcData()
{
	// 전체를 순회한다. > 이 과정에서 히스토그램의 최대 면적을 갱신하고,
	// 최종 결과값이 result 변수에 저장된다.
	int sum = k[0];
	for (int i = 1; i < k.size(); ++i) {
		// 기준값을 정한다.
		int p = k[i]>k[i-1]?k[i-1]:k[i];

		// 기준값을 이용해 구할 수 있는 최대 면적을 구한다.
		sum = p*2;
		// 기준값보다 작은 값을 만날 때까지 이전의 네모를 순회한다.
		int j = i-2;
		while ((j>0) && (k[j]>=p)) {
			sum += p;
			j--;
		}

		result = (result>sum)?result:sum;
	}
}

void OutputData()
{
	cout << result << endl;
}

int main()
{
	InputData();
	ProcData();
	OutputData();

	return 1;
}
