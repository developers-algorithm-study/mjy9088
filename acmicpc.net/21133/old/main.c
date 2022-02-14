#include <stdio.h>

#define print(n) printf("%d\n", (n));

void solve_3_1(int n) {
	n /= 2;
	int line = n / 4;
	for (int i = 0; i < line; i++) {
		print(4 * (line - i) - 2);
		print(4 * (line - i));
	}
	for (int i = 0; i < n; i++) {
		print((n - i) * 2 + 1);
	}
	print(1);
	for (int i = 0; i < line; i++) {
		print(n + 4 * (line - i) - 2);
		print(n + 4 * (line - i));
	}
}

void solve_3_2(int n) {
	n /= 2;
	int line = n / 4 + 1;
	for (int i = 0; i < line; i++) {
		print(4 * (line - i) - 3);
		print(4 * (line - i) - 1);
	}
	for (int i = 0; i < n; i++) {
		print((n - i) * 2);
	}
	for (int i = 0; i < line; i++) {
		print(n + 4 * (line - i) - 2);
		print(n + 4 * (line - i));
	}
}

void solve_3_3(int n) {
	n /= 2;
	int line = n / 4;
	print(n + 2);
	for (int i = 0; i < line; i++) {
		print(n - i * 4 - 4);
		print(n - i * 4 - 2);
	}
	for (int i = 0; i < n; i++) {
		print((n - i) * 2 + 1);
	}
	print(1);
	for (int i = 0; i < line; i++) {
		print(n * 2 - i * 4 - 2);
		print(n * 2 - i * 4);
	}
	print(n);
}

void solve_3_4(int n) {
	n /= 2;
	int line = n / 4;
	print(n + 2);
	for (int i = 0; i < line; i++) {
		print(n - i * 4 - 4);
		print(n - i * 4 - 2);
	}
	for (int i = 0; i < n; i++) {
		print((n - i) * 2);
	}
	for (int i = 0; i < line; i++) {
		print(n * 2 - i * 4 - 1);
		print(n * 2 - i * 4 + 1);
	}
	print(n);
}

void (*solve3[4])(int n) = { solve_3_4, solve_3_1, solve_3_2, solve_3_3 };

// 6n, 6n+4
void solve_0(int n) {
	n /= 2;
	for (int i = 0; i < n; i++) {
		print(n + i + 1);
		print(i + 1);
	}
}

// 6n+1, 6n+5
void solve_1(int n) {
	print(n);
	n /= 2;
	for (int i = 0; i < n; i++) {
		print(n * 1 - i);
		print(n * 2 - i);
	}
}

// 6n+2
void solve_2(int n) {
	n /= 2;
	print(n + 2);
	print(1);
	print(n + 1);
	print(2);
	print(n * 2);
	print(3);
	for (int i = 3; i < n; i++) {
		print(n + i);
		print(i + 1);
	}
}

// 6n+3
void solve_3(int n) {
	solve3[n / 6 % 4](n);
}

void (*solve[4])(int n) = { solve_0, solve_1, solve_2, solve_3 };

int main() {
	int n;
	scanf("%d", &n);
	solve[n % 6 % 4](n);
}
