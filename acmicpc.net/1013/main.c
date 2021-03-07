#include <stdio.h>

// ���� �� CRLF �ּ� ó��!
#define CRLF

#define FALSE 0
#define TRUE 1

#ifdef CRLF
char myGetChar() { char ret = getchar(); if (ret == '\r') return getchar(); return ret; }
#else
#define myGetChar getchar 
#endif

// input�� ���� ���ڸ� �ްų�, ���� �� return
#define NEXT_INPUT(RETURN_VALUE_IF_END) { if ((input = myGetChar()) == '\n' || input == EOF) return RETURN_VALUE_IF_END; }

// �̹� �� ���۸� ���� return
#define SAFE_RETURN(RETURN_VALUE) { while (TRUE) { if ((input = myGetChar()) == '\n' || input == EOF) break; } return RETURN_VALUE; }

// ���� ���ڰ� VALUE���� Ȯ��
#define ASSERT_NEXT_IS(VALUE) { NEXT_INPUT(FALSE); if (input != VALUE) SAFE_RETURN(FALSE); }

// VALUE�� �Էµ� ������ ��ٸ�
#define IGNORE_UNTIL(VALUE, RETURN_VALUE_IF_END) { while (TRUE) { NEXT_INPUT(RETURN_VALUE_IF_END); if (input == VALUE) break; } }

// �̹� ���� (100+1+ | 01)+���� Ȯ���ϴ� �Լ�. ���ǻ� (100+11* | 01)+�� �ϰ��� (N+�� 1�� �̻��� N, N*�� 0�� �̻��� N)
int solve() {
	// �� ���̸� false
	int RETURN_VALUE_ON_EMPTY = FALSE;
	// �� ��ũ�θ� ����ϱ� ���� �ʿ��� ����
	char input;
	// �� ��¥ goto �� ��������� �̹���... �� ����!
	RESET:
	// 100+11*���� 100+1���� ������ break (�� �� ó���� goto ���� �Ʒ��� ����)
	while (TRUE) {
		// 01�� ������ ������ true. ��, �ƹ��͵� �� ������ false
		NEXT_INPUT(RETURN_VALUE_ON_EMPTY);
		// �� ���� �̻� ������ �� ���� �ƴ�
		RETURN_VALUE_ON_EMPTY = TRUE;
		if (input == '0') {
			// 0�� ������ ������ �ݵ�� 1�� ���;� �� (01)
			ASSERT_NEXT_IS('1');
		} else {
			// 1�� ������ ������ �ݵ�� 0�� 2�� �̻� ���;� �� (100+1+)
			ASSERT_NEXT_IS('0');
			ASSERT_NEXT_IS('0');
			// �� �������δ� 1�� ������ ���;� ��
			IGNORE_UNTIL('1', FALSE);
			break;
		}
	}
	// ���� 1*�� ���� �� �ְ�, �ٽ� (100+11* | 01)+�� �ݺ���
	while (TRUE) {
		// �Ʒ� ��ø while���� continue�ϱ� ���� ���
		CONTINUE:
		// 100+1���� ������ TRUE
		NEXT_INPUT(TRUE);
		if (input == '0') {
			// 100+1 ������ �ٷ� 0�� ������ ���� (100+11*)(100+11*)�� �� �����Ƿ� 01��
			ASSERT_NEXT_IS('1');
			// �ٽ� 1*�� ���� �� (100+11* | 01)+�� �ݺ��� �� �� �ݺ����� �����ϵ��� �ʱ�ȭ
			goto RESET;
		}
		// 0 �� ������ 1�� ������ 100+11*�� ���·� �������Ƿ� true
		IGNORE_UNTIL('0', TRUE); 
		// 0���� ������ false
		NEXT_INPUT(FALSE);
		if (input == '0') {
			// 0�� 2�� �������� �������Ƿ� 100+11*�� ���. �� 100+1���� �ް� continue �ϸ� ��
			IGNORE_UNTIL('1', FALSE);
			continue;
		} else {
			// (100+11*)(01)�� ���. �� 100+1���� �ް� continue �ϸ� ��

			// 100+1+���� 100+1���� ������ continue (�� �� ó���� goto ���� ���� ����)
			while (TRUE) {
				// 01�� ������ ������ true (�ռ� �� ���� �̻� �Էµ� ���´� �� �� ó���� ����)
				NEXT_INPUT(TRUE);
				if (input == '0') {
					// 0�� ������ ������ �ݵ�� 1�� ���;� �� (01)
					ASSERT_NEXT_IS('1');
				} else {
					// 1�� ������ ������ �ݵ�� 0�� 2�� �̻� ���;� �� (100+11*)
					ASSERT_NEXT_IS('0');
					ASSERT_NEXT_IS('0');
					// �� �������δ� 1�� ������ ���;� ��
					IGNORE_UNTIL('1', FALSE);
					// ���⼭ continue ��� goto�ӿ� ����
					goto CONTINUE;
				}
			}

		}
	}
//	SAFE_RETURN(TRUE); // unreachable code
}

int main(int argc, char **argv)
{
	int T, i;
	scanf("%d", &T);
	myGetChar(); // �ٹٲ޹���
	for (i = 0; i < T; i++) {
		if (solve()) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}

