#include <iostream>
#include <deque>
#include <fstream>
#include <ctime>
#include <algorithm>

using namespace std;

void fromFile(deque<int>* deq);
void fromkeybord(deque<int>* deq);
void printDeque(deque<int>* deq);

int main()
{
	srand(time(NULL));
	deque<int>* dob_que = new deque<int>;
	cout << "Choose how input info: " << endl;
	cout << "1. from file;\n2. from keybord;" << endl;
	int n;
	cin >> n;
	switch (n)
	{
	case 1:
		fromFile(dob_que);
		break;
	case 2:
		fromkeybord(dob_que);
		break;
	default:
		cout << "Incorect wariant!" << endl;
		break;
	}
	unsigned int time_end = clock();
	cout << "\nTime: " << (double)time_end / 1000 << " s" << endl;
}

void fromFile(deque<int>* dob_que)
{
	ifstream from_file;
	int n;
	string fname;
	cout << "enter a file name: ";
	cin >> fname;
	from_file.open(fname);
	if (!from_file.is_open())
	{
		throw "Incorrect file name!";
	}
	while (from_file)
	{
		from_file >> n;
		dob_que->push_back(n);
	}
	dob_que->pop_back();
	cout << "deq_1: " << endl;
	printDeque(dob_que);
	cout << endl << "Rewers deque:\n";
	reverse(dob_que->begin(), dob_que->end());
	printDeque(dob_que);
	cout << endl;
}

void fromkeybord(deque<int>* dob_que)
{
	int n;
	cout << "Enter data: ";
	while (cin >> n)
	{
		dob_que->push_back(n);
	}
	cout << "deq: " << endl;
	printDeque(dob_que);
	cout << endl << "reverse deq:" << endl;
	reverse(dob_que->begin(), dob_que->end());
	printDeque(dob_que);
	cout << endl;
}

void printDeque(deque<int>* dob_que)
{
	for (auto& dob_que : *dob_que)
	{
		cout << dob_que << " ";
	}
}