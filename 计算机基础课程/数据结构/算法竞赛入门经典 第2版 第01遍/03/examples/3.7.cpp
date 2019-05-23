/****************************************************
 * 回文词（ Palindromes, UVa401）
 *     输入一个字符串， 判断它是否为回文串以及镜像串。 输入字符串保证不含数字0。 
 *     所谓回文串， 就是反转以后和原串相同， 如abba和madam。
 *     所有镜像串， 就是左右镜像之后和原串相同， 如2S和3AIAE。 
 *     注意， 并不是每个字符在镜像之后都能得到一个合法字符。 
 *     输入的每行包含一个字符串（ 保证只有上述字符。 不含空白字符） ， 判断它是否为回文串和镜像串（ 共4种组合） 。 每组数据之后输出一个空行。
 * 
 * 样例输入：
 * NOTAPALINDROME
 * ISAPALINILAPASI
 * 2A3MEAS
 * ATOYOTA
 * 样例输出：
 * NOTAPALINDROME -- is not a palindrome.
 * ISAPALINILAPASI -- is a regular palindrome.
 * 2A3MEAS -- is a mirrored string.
 * ATOYOTA -- is a mirrored palindrome.
 * *************************************************/