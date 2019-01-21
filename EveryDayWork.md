> 一来通过每日打卡的方式督促自己每天学习，二来总结一下知识点；主要面向自己，希望自己能坚持住吧，有一个好的结果
# 2019年1月18日打卡
+ 编程语言推荐C++（包含C）
+ 用scanf和printf相比cin/cout效率更高
+ int 的范围是±21亿，超过用long long 声明赋值后面加LL
+ 小数全用double
+ 小写字母比大写字母ASCII码大32
+ \#define和const 都可以定义常量，推荐使用const
+ 定义无穷大的数 const int INF = 0x3fffffff
+ 形如 += ，/=的复合赋值可以加快编译速度
+ double输入时是%lf，输出时用%f即可，long long是%lld
+ scanf的%c是可以读入空格和换行的，因此sanf("%d%c",&a,&c);输入2 a后，字符变量c的值为输入的2后面的空格
+ 常用的输出格式 **%md**，m为可选数字：不足m位的整数右对齐m位，高位（左端）补空格，对高于m位的整数输出没有影响
        **%0md**：与上一种类似，只不过高位用0补齐而非空格，在某些题目要求中特别有用
        **%.mf**：使浮点数保留m位小数，保留规则为四舍六入五成双（5后面有数，进一；5后面没有数，通过进0或1使5前一位变成偶数）

+ 通过getchar和putchar输入输出单个字符，getchar能读入空格
+ typedef 可以给数据类型重命名，比如： typedef long long LL （在宏定义的位置）
+ 常用math函数，math.h 或 cmath   *fabs（double x）*--绝对值，*floor（double x）/ceil（）*--向下取整/向上取整，二者返回值均为double，*pow（double a，double b）*--a的b次方，注意输入a，b均为double类型，*sqrt（double x）*--算术平方根，*log*--自然对数e为底的对数，如果求任意底的需要用换底公式，*sin，cos，tan*--输入必须是double的弧度制（角度/180 * Π），*round（double x）*--四舍五入，返回值是double类型，输出时需要（int）强制转型
+ if中如果是x！=0，可以省略后面改为if（x）；如果表达式是x==0，换成!x

# 2019年01月19日打卡
> 今天做了几道oj练习，也算充当任务量了，内容太简单了就不po了
+ if判断中的小技巧在while循环中同样适用
+ do-while后面有分号别忽略
+ C语言不允许for循环中初始化，C++可以，所以默认语言选为CPP也是前文提到的
+ int数组全赋值为0只用一个大括号即可：int a[] = {}
+ 如果数组大小超过十的六次方，要在main函数之外声明（申请），这样把变量从栈转移到静态区，否则会内存不够异常退出
+ 给数组所有元素赋值函数memset(数组名，值，sizeof(数组名))，头文件为string.h，建议只用来赋值0或-1，否则由于补码问题可能会出错（后面会介绍更实用的）
+ 用gets（str）获取字符串时如果前面是int要先用getchar（）吃掉int后面默认的回车
+ 字符串由于以\0结尾，开辟空间时要多+1
+ 如果不是使用scanf的%s或者gets（str）函数接受字符串输入，末尾要记得手动加\0
+ string.h头文件strlen(str)函数,strcmp(str1,str2) 1比于2 小负等零大正；strcpy(str1,str2) 2给1 ;strcat(str1,str2) 2接到1末尾;
+ string.h中的利器：sscanf和sprintf

*sscanf(str,"%d",&n)*————将str转化为数字赋值给整型变量n

*sprintf(str,"%d",n)*————将整数n转化为字符串str

**其中格式化的部分（第二个参数）还可以根据str格式匹配适应，比如：**
```C
#include<stdio.h>
#include<string.h>
int main(){
    char s[20] = "123:3.14,sdffg";
    char str[10];
    int a;
    double b;
    sscanf(s, "%d:%lf,%s", &a, &b, str);
    printf("%d,%f,%s",a,b,str);
}
```

这段代码就是根据字符串s中的格式匹配拆分成三个部分

当然逆过来的sprintf也成立

另外sscanf还支持正则表达式
+ 一维数组做参数不用写明长度，二维数组做参数要写明第二维长度
+

# 2019年01月20日打卡
+ 结构体不能定义自己，但是可以定义自身类型的指针变量
+ 结构体的指针类型用->代替(*p).
+ cin.getline(str,100)读入一整行赋值给字符数组str\[100]
+ getline(cin,str)读入一行赋值给字符串类型str
+ 浮点数比较相等，定义

const double eps = 1e-8

\#define Equ(a,b) ((fabs((a)-(b)))<(eps))————比较相等

\#define More(a,b) (((a)-(b))>(eps))————a大于b:即a>b+eps

\#define Less(a,b) (((a)-(b))<(-eps))————a小于b：即a<b-eps

\#define MoreEqu(a,b) (((a)-(b))>(-eps))————a大于等于b:即a>b-eps

\#define LessEqu(a,b) (((a)-(b))<(eps))————a小于等于b:即a<b+eps



# 2019年01月21日打卡
+ 圆周率π  const double PI = acos(-1.0);（记得引入math.h）
+ 对于多点测试要循环读入数据可以采用while(scanf("%d",&n) != EOF) {}来循环，因为scanf的返回值代表成功读入的参数的个数，如果读取失败返回-1，用EOF（end of file）表示，而对于gets可以判断返回值是否为空：while(gets(str) != NULL)
+ PAT B1001
```c
/*
 * Callatz(3n+1)猜想
 */
#include <stdio.h>
int main(){
    int count = 0;
    int n;
    scanf("%d",&n);
    while(n != 1){
        if(n %2==1) {
            n = 3*n+1;
        }
            n /= 2;
        count +=1;
    }
    printf("%d",count);
}
```


-----

```C
/*
 * PAT B1032
 */
#include <stdio.h>
const int MAX = 100001;
int score[MAX] = {0};
int main(){

    int n;
    scanf("%d",&n);
    int num,sco;
    for (int i = 0;i<n;++i){
        scanf("%d%d",&num,&sco);
        score[num] += sco;
    }
    num = 1;
    sco = 0;
    for (int i = 1; i < n +1; ++i) {
        //printf("%d",score[i]);
        if (score[i] > sco){
            sco = score[i];
            num = i;
        }
    }
    printf("%d %d",num,sco);
}
```


------

```C
/*
 * PAT B1036
 */
#include <stdio.h>
int main(){
    int n;
    char c;
    scanf("%d %c", &n, &c);
    int col;
    if (n % 2 == 0) {
        col = n/2;
    } else {
        col = n / 2 + 1;
    }
    for (int i = 0; i < col; ++i) {
        if (i == 0 || i == col - 1) {
            for (int j = 0; j < n; ++j) {
                printf("%c",c);
            }
        } else {
            for (int j = 0; j < n; ++j) {
                if (j == 0 || j == n - 1) {
                    printf("%c",c);
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}
```

+ 日期差值：拆分成年月日，一直加一，超过就进位，加到比第大日期大一天位置：
```C
//
// Created by zhaopeng on 19-1-21.
//

/*
 * codeup1928 日期之差
 */
#include <stdio.h>

int month[13][2] = {{0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}, {31, 31},
                         {30, 30}, {31, 31}, {30, 30}, {31, 31}};

bool isLeap(int year) {
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}
int main(){

    int time1, time2, y1, y2, m1, m2, d1, d2;
    while (scanf("%d%d", &time1, &time2) != EOF) {
        if (time1 > time2) {
            int temp = time1;
            time1 = time2;
            time2 = temp;
        }
        y1 = time1 / 10000;
        y2 = time2 / 10000;
        m1 = time1 % 10000 /100;
        m2 = time2 % 10000 /100;
        d1 = time1 % 100;
        d2 = time2 % 100;

        int ans = 1;
        while ((y1 < y2) || (m1 < m2) || (d1 < d2)) {
            d1++;
            if (d1 == month[m1][isLeap(y1)]+1) {
                m1 ++;
                d1 = 1;
            }
            if (m1 == 13) {
                y1 ++;
                m1 = 1;
            }
            ans ++;

        }
        printf("%d\n", ans);
    }
    return 0;


}
```

```C
/*
 * PAT B1009 说反话，将给定的句子中的单词反序
 */
#include <stdio.h>
int main(){
    char str[90][90];
    int num = 0;
    while (scanf("%s", str[num]) != EOF) {
        num++;
    }
    for (int i = num - 1; i > -1; --i) {
        printf("%s", str[i]);
        if (i != 0) {
            printf(" ");
        }
    }


}
```

