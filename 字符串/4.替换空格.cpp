/*****************************************************************************
 * 问题：
 * 实现一个函数，将一个字符串中的每个空格替换成“%20”。
 * 
 * 解决方案:
 * (1)遍历字符串，统计空格个数为count，此时指针str处于字符串尾部。然后在新建一个指针
 * tail，在字符串尾部2*count处。两个指针同时向左移动，同时tail复制str的元素。若str
 * 指向空格，则tail依次写入'0','2','%'，直到str超出字符串首地址为止。
 * (2)创建一个string容器，依次复制字符串的元素，遇到空格就写入"%20"。然后字符串再从头
 * 复制string的元素。 * 
 */


#include <string>

using namespace std;

class Solution1 {
public:
	void replaceSpace(char *str,int length) {
        int count = 0;
        char* head = str;
        while(*str!='\0')
        {
            if(*str==' ')
                count++;
            ++str;
        }
        char *tail = str+count*2;
        while(str>=head)
        {
            if(*str==' ')
            {
                *tail = '0';
                *(tail-1) = '2';
                *(tail-2) = '%';
                tail -= 3;
            }
            else
            {
                *tail = *str;
                --tail;
            }
            --str;
        }
	}
};

class Solution2 {
public:
    void replaceSpace(char *str,int length) {
        string res;
        for(int i=0;i<length;i++)
        {
            while(str[i]!=' '&&i<length)
            {
                res+=str[i];
                i++;
            }
            if(i<length)
            {
                res+='%';
                res+='2';
                res+='0';
            }
        }
        for(int i=0;i<res.size();i++)
            str[i]=res[i];       
    }
};
