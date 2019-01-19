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