#include <stdio.h>

#define print(n) printf(" %d", (n));

void solve_3_1(int n) {
	n /= 2;
	int line = n / 4;
	for (int i = 0; i < line; i++) {
		print(4 * (line - i) - 3);
		print(4 * (line - i) - 1);
	}
	for (int i = 0; i < n; i++) {
		print((n - i) * 2);
	}
	print(0);
	for (int i = 0; i < line; i++) {
		print(n + 4 * (line - i) - 3);
		print(n + 4 * (line - i) - 1);
	}
}

void solve_3_2(int n) {
	n /= 2;
	int line = n / 4 + 1;
	for (int i = 0; i < line; i++) {
		print(4 * (line - i) - 4);
		print(4 * (line - i) - 2);
	}
	for (int i = 0; i < n; i++) {
		print((n - i) * 2 - 1);
	}
	for (int i = 0; i < line; i++) {
		print(n + 4 * (line - i) - 3);
		print(n + 4 * (line - i) - 1);
	}
}

void solve_3_3(int n) {
	n /= 2;
	int line = n / 4;
	print(n + 1);
	for (int i = 0; i < line; i++) {
		print(n - i * 4 - 5);
		print(n - i * 4 - 3);
	}
	for (int i = 0; i < n; i++) {
		print((n - i) * 2);
	}
	print(0);
	for (int i = 0; i < line; i++) {
		print(n * 2 - i * 4 - 3);
		print(n * 2 - i * 4 - 1);
	}
	print(n - 1);
}

void solve_3_4(int n) {
	n /= 2;
	int line = n / 4;
	print(n + 1);
	for (int i = 0; i < line; i++) {
		print(n - i * 4 - 5);
		print(n - i * 4 - 3);
	}
	for (int i = 0; i < n; i++) {
		print((n - i) * 2 - 1);
	}
	for (int i = 0; i < line; i++) {
		print(n * 2 - i * 4 - 2);
		print(n * 2 - i * 4);
	}
	print(n - 1);
}

void (*solve3[4])(int n) = { solve_3_4, solve_3_1, solve_3_2, solve_3_3 };

// 6n, 6n+4
void solve_0(int n) {
	n /= 2;
	for (int i = 0; i < n; i++) {
		print(n + i);
		print(i);
	}
}

// 6n+1, 6n+5
void solve_1(int n) {
	print(n - 1);
	n /= 2;
	for (int i = 0; i < n; i++) {
		print(n * 1 - i - 1);
		print(n * 2 - i - 1);
	}
}

// 6n+2
void solve_2(int n) {
	n /= 2;
	print(n + 1);
	print(0);
	print(n);
	print(1);
	print(n * 2 - 1);
	print(2);
	for (int i = 3; i < n; i++) {
		print(n + i - 1);
		print(i);
	}
}

// 6n+3
void solve_3(int n) {
	solve3[n / 6 % 4](n);
}

void (*solve[4])(int n) = { solve_0, solve_1, solve_2, solve_3 };

int main() {
	int t, n;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		printf("%d\n", n);
		solve[n % 6 % 4](n);
		putchar('\n');
	}
	return 0;
}
