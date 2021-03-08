#include <stdio.h>

int numberLength(int number) {
	int result = 0;
	while(number) {
		number /= 10;
		result++;
	}
	return result;
}

int printNumber(int number, int length) {
	int pad = length - numberLength(number);
	while (pad) {
		putchar(' ');
		pad--;
	}
	printf("%d", number);
}

int numberAt(int y, int x) {
	int absY = y < 0 ? -y : y;
	int absX = x < 0 ? -x : x;
	// ����������
	// ����������
	// �޿޾ƿ���
	// �޾ƾƾƿ�
	// �ƾƾƾƾ�
	if (absY < absX) { // ���� �� �Ǵ� ������ ��
		int tmp = (2 * absX + 1) * (2 * absX + 1); // numberAt(abs(x), abs(x))
		if (x < 0) {
			// ���� �� - numberAt(0, x) = numberAt(abs(x), abs(x)) - 4abs(x) - x
			return tmp + 3 * x + y;
		} else {
			// ������ �� - numberAt(0, x) = numberAt(x, x) - 6abs(x) - x
			return tmp - 7 * x - y;
		}
	} else { // ���� �� �Ǵ� �Ʒ��� ��
		int tmp = (2 * absY + 1) * (2 * absY + 1); // numberAt(abs(y), abs(y))
		if (y < 0) {
			// ���� �� - numberAt(y, y) = numberAt(abs(y), abs(y)) - 4abs(y)
			return tmp + 5 * y - x;
		} else {
			// �Ʒ��� �� - numberAt(y, y) = (2y+1)^2
			return tmp - y + x;
		}
	}
}

int main(int argc, char **argv)
{
	int T, startY, startX, endY, endX, y, x;
	scanf("%d %d %d %d", &startY, &startX, &endY, &endX);
	int length = 0;
	// �� �� �ϳ��� ���� �� ���ڰ���...
	x = numberLength(numberAt(startY, startX)); if (length < x) length = x;
	x = numberLength(numberAt(startY, endX)); if (length < x) length = x;
	x = numberLength(numberAt(endY, startX)); if (length < x) length = x;
	x = numberLength(numberAt(endY, endX)); if (length < x) length = x;
	for (y = startY; y <= endY; y++) {
		for (x = startX; x < endX; x++) {
			printNumber(numberAt(y, x), length);
			putchar(' ');
		}
		printNumber(numberAt(y, x), length);
		putchar('\n');
	}
	return 0;
}

