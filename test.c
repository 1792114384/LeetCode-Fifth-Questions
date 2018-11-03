#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

////�ж�һ���ַ����ǲ��ǻ���
//int IfPlalindrome(char *s) {
//	int count = strlen(s);
//	int left = 0;
//	int right = count - 1;
//	while (left < right)
//	{
//		if (s[left] != s[right])
//		{
//			return 0; //���ǻ��ķ���0���ǻ��ķ���1
//		}
//		left++;
//		right--;
//	}
//	return 1;
//}
////��ת�ַ���
//char *reverse(char *s, int count)
//{
//	char *p = (char *)malloc(sizeof(char) * (count + 1));
//	int i = 0;
//	for (; i < count; i++)
//	{
//		p[i] = s[count - i - 1];
//	}
//	p[i] = '\0';
//	return p;
//}
//
//char* longestPalindrome(char* s) {
//	int count = strlen(s);
//	//arr�д�ŵ�����Ļ����Ӵ�
//	char *arr = (char *)malloc(sizeof(char) * 1001);
//	char *p = reverse(s, count);
//	unsigned int max = 0;
//	//arr1�д��ÿһ��ѭ�������Ļ����Ӵ�
//	char arr1[2000];
//	for (int i = 0; i < count; i++) {
//		for (int j = 0; j < count; j++) {
//			int m = i;
//			int n = j;
//			int k = 0;
//			while (s[m] == p[n])
//			{
//				arr1[k] = s[m];
//				k++;
//				m++;
//				n++;
//			}
//			arr1[k] = '\0';
//			//�ж��ǲ��ǻ����Ӵ�
//			if (IfPlalindrome(arr1))
//			{
//				//��arr�еĻ����Ӵ��������Աȣ���Ļ����͸���
//				if (strlen(arr1) > max)
//				{
//					max = strlen(arr1);
//					strcpy(arr, arr1);
//				}
//			}
//		}
//	}
//	return arr;
//}

//char* longestPalindrome(char* s)
//{
//	int len = strlen(s);
//	if (len <= 1) { return s; }
//	//����bool���͵�dp��ֻ��Ϊtrue��false
//	bool dp[1001][1001];
//	memset(dp, 0, sizeof(dp));
//	dp[0][0] = 1;
//	for (int i = 1; i < len; i++)
//	{
//		dp[i][i] = true;
//		//һ����Ҫ���ԣ�������k=2���õ�
//		dp[i][i - 1] = true;
//	}
//	int left = 0;
//	int right = 0;
//	int max = 0;
//	//k��ʾ�����Ӵ��ĳ���
//	for (int k = 2; k <= len; k++)
//	{
//		//i��ʾ�����Ӵ�����ʼλ��
//		for (int i = 0; i < len - k + 1; i++)
//		{
//			if (s[i] == s[k - 1 + i] && dp[i + 1][k + i - 2])
//			{
//				dp[i][k - 1 + i] = true;
//				if (max < k - 1)
//				{
//					max = k - 1;
//					left = i;
//					right = k - 1 + i;
//				}
//			}
//		}
//	}
//
//	char *arr = (char *)malloc(sizeof(int) * (max * 2));
//	int i = 0;
//	for (; i <= max; i++)
//	{
//		arr[i] = s[left++];
//	}
//	arr[i] = '\0';
//	return arr;
//}

char* longestPalindrome(char* s)
{
	int len = strlen(s);
	if (len <= 1) { return s; }
	int start = 0;
	int maxlen = 0;
	//i��ʾ�м�Ԫ���±�
	for (int i = 1; i < len; i++)
	{
		//ż������
		int low = i - 1;
		int high = i;
		while (low >= 0 && high < len && s[low] == s[high])
		{
			low--;
			high++;
		}
		if (high - low - 1 > maxlen)
		{
			maxlen = high - low - 1;
			start = low + 1;
		}
		//��������
		low = i - 1; high = i + 1;
		while (low >= 0 && high < len && s[low] == s[high])
		{
			low--;
			high++;
		}
		if (high - low - 1 > maxlen)
		{
			maxlen = high - low - 1;
			start = low + 1;
		}
	}
	char *arr = (char *)malloc(sizeof(int) * (maxlen * 2));
	int i = 0;
	for (; i < maxlen; i++)
	{
		arr[i] = s[start++];
	}
	arr[i] = '\0';
	return arr;
}

int main()
{
	char *s = "ababd";
	printf("%s\n", longestPalindrome(s));
	system("pause");
	return 0;
}