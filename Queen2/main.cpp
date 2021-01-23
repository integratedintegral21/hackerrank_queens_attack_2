#include <iostream>
#include <vector>

using namespace std;

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
	int horizontal_attacks = n - 1;
	int vertical_attacks = n - 1;
	int d2_attacks = min(r_q - 1, c_q - 1) + min(n - r_q, n - c_q);
	int d1_attacks = min(r_q - 1, n - c_q) + min(n - r_q, c_q - 1);

	int d1_const = c_q - r_q;
	int d2_const = r_q + c_q;

	int vertical_removed_attacks_up = 0;
	int vertical_removed_attacks_down = 0;
	int horizontal_removed_attacks_right = 0;
	int horizontal_removed_attacks_left = 0;
	int d1_removed_attacks_up = 0;
	int d1_removed_attacks_down = 0;
	int d2_removed_attacks_up = 0;
	int d2_removed_attacks_down = 0;
	
	for (int i = 0; i < k; i++) {
		int a = obstacles[i][1]; //x
		int b = obstacles[i][0]; //y

		if (a == c_q) { //same column
			if (b < r_q) {
				if (b > vertical_removed_attacks_down) vertical_removed_attacks_down = b;
			}
			else {
				if (n - b + 1> vertical_removed_attacks_up) vertical_removed_attacks_up = n - b + 1;
			}
		}
		if (b == r_q) { // same row
			if (a < c_q) {
				if (a > horizontal_removed_attacks_left) horizontal_removed_attacks_left = a;
			}
			else {
				if (n - a + 1 > horizontal_removed_attacks_right) horizontal_removed_attacks_right = n - a + 1;
			}
		}
		if (a - b == d1_const) { // same d1
			int removed;
			if (a < c_q) {
				removed = min(a, b);
				if (removed > d1_removed_attacks_down) d1_removed_attacks_down = removed;
			}
			else {
				removed = min(n - a + 1, n - b + 1);
				if (removed > d1_removed_attacks_up) d1_removed_attacks_up = removed;
			}
		}
		if (a + b == d2_const) { // same d2
			int removed;
			if (a < c_q) {
				removed = min(a, n - b + 1);
				if (removed > d2_removed_attacks_up) d2_removed_attacks_up = removed;
			}
			else {
				removed = min(n - a + 1, b);
				if (removed > d2_removed_attacks_down) d2_removed_attacks_down = removed;
			}
		}
	}
	

	return horizontal_attacks - horizontal_removed_attacks_right - horizontal_removed_attacks_left + vertical_attacks - vertical_removed_attacks_up - vertical_removed_attacks_down + d1_attacks - d1_removed_attacks_up - d1_removed_attacks_down + d2_attacks - d2_removed_attacks_up - d2_removed_attacks_down;
}


int main() {

	int n = 8;
	int k = 1;
	int r_q = 4;
	int c_q = 4;
	vector <vector<int>> obstacles{
		{3,4}
	};

	cout << queensAttack(n, k, r_q, c_q, obstacles);

	return 0;
}