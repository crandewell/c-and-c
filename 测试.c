#include <stdio.h>
#include <ctype.h>

int main() {
	char sentence[1000];
	int word_count = 0;
	int i = 0;
	int in_word = 0; // 0表示不在单词中，1表示在单词中
	
	printf("请输入英文句子：");
	fgets(sentence, sizeof(sentence), stdin);
	
	// 统计单词数
	while (sentence[i] != '\0') {
		if (isalpha(sentence[i])) {
			// 当前字符是字母
			if (!in_word) {
				word_count++;
				in_word = 1;
			}
		} else if (isspace(sentence[i]) || sentence[i] == ',' || sentence[i] == '.') {
			// 当前字符是空格或标点
			in_word = 0;
		}
		i++;
	}
	
	printf("单词个数：%d\n", word_count);
	
	return 0;
}
