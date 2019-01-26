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
```c
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

```c
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

```c
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
```c
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

```c
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

# 2019年01月22日打卡
+ C语言的qsort函数由于涉及很多指针操作并且没有规避快排中的最简单情况，所以推荐使用C++中的sort函数
> ## sort(首元素地址，尾元素地址的下一地址，比较函数)
> + 使用时引入#include<algorithm> 以及 using namespace std
> + 简单数据类型比较函数的定义：

```c
bool cmp(T a,T b){
    return a>b;
}
//其中T可以为int，char，double
sort(a,a+n+1,cmp);
```
> + 对于结构体同理可以根据结构体内的元素写比较函数
```c
bool cmp(struct s1,struct s2){
    return s1.val>s2.val;
}
//按照结构体的val属性从大到小排列
```
> + 二级排序
```c
bool cmp(struct s1,struct s2){
    if(s1.a != s2.a)
        return s1.a > s2.a;
    else
        return s1.b > s2.b;
}
//
```
> + 容器排序：STL 标准容器只有vector，string，deque可以使用sort排序，排序的cmp函数与容器元素类型有关，比如
```c
bool cmp(int a,int b){
    return a > b;
}
vector<int> vi;
sort(vi.begin(),vi.end,cmp);
```

+ string的话不写cmp直接按照字典顺序排序
```c
string str[3] = {"bbb","sss","aaaaa"};
sort(str,str+3);
//或者指定cmp
bool cmp(string s1,string s2){
    return s1.length() < s2.length();
}
sort(str,str+3,cmp);    //按照长度从小到大排序
```

### 散列
> 将元素通过函数转化成一个整数，使得这个整数可以唯一地表示这个元素
+ 线性变换
+ 除留余数法： H(key) = key % m; m为素数
+ 平方取中法： 将key平方之后取中间的几位

防止冲突的方法：
+ 线性探查法： 一直+1寻找没有被占据的位置
+ 平方探查法： +/- k++的平方
+ 链地址法： 每个哈西值对应一个单链表

空间换取时间例题：在m个预查询的数中判断n个数是否出现过，m，n均小于十的五次方————空间换时间
开辟十的五次方个bool数组，在m输入时就将出现的位置置为true
```c
/*
 * m,n < 1 e5
 * 判断n个数中是否出现在m中
 * 空间换时间
 */
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
bool maxN[10010] = {false};
int main(){
    int n, m;
    int num;
    vector<int> Nv;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &num);
        maxN[num] = true;
    }
    for (int j = 0; j < n; ++j) {
        scanf("%d", &num);
        if (maxN[num]) {
            Nv.push_back(num);
        }
    }
    for (int k = 0; k < Nv.size() - 1; ++k) {
        printf("%d ", Nv.at(k));
    }
    printf("%d", Nv.at(Nv.size()-1));
}
```

+ 字符串散列：将字符串转化为惟一的数
常用的方法时进制转换：
比如如果只有大写字母或者小写字母，那就把26进制转化为十进制，对应的数值肯定是惟一的
```c
int hashFun(char s[], int len){
    int id = 0;
    for(int i = 0;i < len;++i){
        id = id * 26 + (s[i]-'A');
    }
    return id;
}
```
如果是多种字母混合，可以扩充进制位数，比如大小写混合就是26+26=52位，其中大写对应从0-25,小写对应从26-51
```c
int hashFun(char s[], int len){
    int id = 0;
    for(int i = 0;i < len;++i){
        if(s[i] >= 'A' && s[i] <= 'Z' ){
            id = id * 52 + (s[i] - 'A');
        }else if(s[i] >= 'a' && s[i] <= 'z'){
            id = id * 52 +(s[i] - 'a') + 26;
        }


    }
    return id;
}

```c
/*
 * 给出N个字符串（由恰好三位大写字母组成），再给除M个查询字符串，问每个查询字符串出现的次数
 */
#include <stdio.h>

const int maxn = 100;
char S[maxn][5], temp[5];
int hashTable[26 * 26 * 26 + 10];
int hashFun(char s[], int len){
    int id = 0;
    for(int i = 0;i < len;++i){
        id = id * 26 + (s[i]-'A');
    }
    return id;
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", S[i]);
        int id = hashFun(S[i], 3);
        hashTable[id]++;
    }
    for (int j = 0; j < m; ++j) {
        scanf("%s", temp);
        int id = hashFun(temp, 3);
        printf("%d\n", hashTable[id]);
    }
    return 0;
}
```

# 2019年01月23日打卡
### 分治法：
> 注意分治法解决的子问题应该是互相独立，没有交叉的，如果子问题之间存在相交部分不应该用分治法

+ 使用递归的方法实现分治法较为容易
> 要理解递归，你要先理解递归，直到你能理解递归

按字典序的全排列问题
```c
/*
 * 全排列，以n=3为例，体会分治递归思想
 */
#include <stdio.h>
const int MAX = 11;
int n, p[MAX], hashTable[MAX] = {false};

void generateP(int index) {
    if (index == n + 1) {
        for (int i = 1; i <= n; ++i) {
            printf("%d", p[i]);
        }
        printf("\n");
        return;
    }
    for (int j = 1; j <= n; ++j) {
        if (hashTable[j] == 0) {
            p[index] = j;
            hashTable[j] = true;
            generateP(index + 1);
            hashTable[j] = false;
        }
    }
}
int main() {
    n = 3;
    generateP(1);
    return 0;
}
```

n皇后问题
```c
/*
 * n皇后问题
 */
#include <stdio.h>
#include <math.h>
const int MAX = 10000;
int n, p[MAX], hashTable[MAX] = {false};
int count = 0;
void generateP(int index) {
    if (index == n + 1) {   //  递归边界，生成一个合法方案
        count++;    //能到达这里的一定是合法方案
        return;
    }

    for (int i = 1; i <= n; ++i) {  //第i行
        if (hashTable[i] == 0) {    //第i行还没有皇后
            bool flag = true;   //flag为true表示当前皇后不会和其他皇后冲突
            for (int pre = 1; pre < index; ++pre) { //遍历之前的皇后
                //第index列的皇后行号为i，第pre列的皇后行号为p[pre]
                if (abs(index - pre) == abs(i - p[pre])) {
                    flag = false;   //在一条对角线
                    break;
                }


            }
            if (flag) { //可以把皇后放在第i行

                p[index] = i;   //另index列的皇后行号为i
                hashTable[i] = true;    //第i行已经被占用
                generateP(index + 1);
                hashTable[i] = false;
            }

        }
    }
}
int main() {
    n = 8;
    generateP(1);
    printf("%d", count);
    return 0;
}
```
### 贪心
+ 总是考虑当前局部最优，以达到全局最优

```c
/*
 * PAT B 1020 月饼
 */
#include <stdio.h>
#include <algorithm>

using namespace std;
const int MAX = 1001;
struct MOON {
    double store;
    double sell;
    double price;
};

bool cmp(MOON m1, MOON m2) {
    return m1.price > m2.price;
}
int main(){
    int n;
    double total;
    scanf("%d%lf", &n, &total);
    MOON moon[MAX];
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &moon[i].store);
    }
    for (int j = 0; j < n; ++j) {
        scanf("%lf", &moon[j].sell);

    }
    for (int k = 0; k < n; ++k) {
        moon[k].price = moon[k].sell / moon[k].store;
    }

    double value = 0.0;
    sort(moon, moon + n, cmp);
    for (int l = 0; (l < n)&&(total > 0); ++l) {
        if (total <= moon[l].store) {
            value +=  moon[l].price * total;
            total = 0;
        } else {
            value += moon[l].sell;
            total -= moon[l].store;
        }
    }
    printf("%.2f", value);
}
```

组个最小数
```c

/*
 * PAT B 1023
 * 组个最小数
 */
#include <stdio.h>
int main() {
    int count[10];
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &count[i]);

    }

    for (int j = 1; j < 10; ++j) {
        if (count[j] != 0) {
            printf("%d", j);
            --count[j];
            break;
        }
    }
    for (int k = 0; k < 10; ++k) {
        while (count[k] != 0) {
            printf("%d", k);
            --count[k];
        }
    }
}
```


区间贪心

**区间选点问题**
给出N个闭区间\[x,y]，求最少需要确定多少个点，才能使每个闭区间中都至少存在一个点
```c
#include <stdio.h>
#include <algorithm>

using namespace std;
const int MAX = 110;
struct AREA {
    int x, y;

} area[MAX];

bool cmp(AREA a1, AREA a2) {    //左端点从大到小排序，左端点相同，右端点从小到大排序
    if (a1.x != a2.x) {
        return a1.x > a2.x;
    } else {
        return a1.y < a2.y;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &area[i].x, &area[i].y);

    }
    sort(area, area + n, cmp);
    int ans = 1, lastX = area[0].x;     //ans记录不相交区间个数，lastX记录上一个被选中的区间左端点
    for (int j = 1; j < n; ++j) {
        if (area[j].y < lastX) {
            lastX = area[j].x;
            ++ans;
        }
    }
    printf("%d", ans);
}

```

### 二分
+ 二分法查找
```c
int binarySearch(int A[], int left, int right, int x) {
    int mid;
    while (left < right) {
        mid = (left + right) / 2;       //防溢出替换为mid = left + (right - left) / 2
        if (A[mid] == x) {
            return mid;
        } else if (A[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;

        }


    }
    return -1;
}
```

固定模板
**闭区间寻找有序序列中第一个满足某条件的元素位置**
```c
int solve(int left, int right){
    int mid;
    while (left < right) {
        mid = (left + right) / 2;       //防溢出替换为mid = left + (right - left) / 2
        if (条件成立) {
            right = mid;
        } else {
            left = mid + 1;

        }


    }
    return left;
}
```

如果是想找出最后一个满足条件的元素位置，那么就是找出第一个不满足条件的元素位置-1
如果是在左开右闭区间，那么把while条件改为left+1<right,同时left = mid + 1改为left = mid即可

+ 二分法拓展
求根号2的近似值----》给定一个定义在\[L,R]区间上的单调函数f(x)，求f(x)=0的近似根
```c
const double eps = 1e-5;    //精度为10的-5次方
double f(double x){     //计算f(x)
    return ....;
}
double solve(double L, double R) {
    double left = L, right = R, mid;
    while (right - left > eps) {
        mid = (left + right) / 2;
        if (f(mid) > 0) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return mid;
}
```

如果f(x)递减，只需把f(mid)>0改成f(mid) < 0即可

# 2019年01月24日打卡
二分法解决木棒切割问题
给出N根木棒，长度均已知，现通过切割他们，得到至少K段长度相等的木棒（长度必须是整数），问长度相等的木棒最长能有多长
比如三根长度分别为10,24,15的木棒，希望K值为7，求最大长度

对于这一问题,首先注意到一个结论，相等的木棒长度L越长，木棒段数k越小，则可以采用二分法求解答案，即是求解满足长度k≥K的最后一个L值
即是求解满足k＜K的第一个L值-1，显然木棒段的最大长度不得超过木棒的最大长度，所以left=1，right=最大木棒长度：
```c
/*
 * 切割木棒问题
 *给出N根木棒，长度均已知，现通过切割他们，得到至少K段长度相等的木棒（长度必须是整数），问长度相等的木棒最长能有多长
 *比如三根长度分别为10,24,15的木棒，希望K值为7，求最大长度
 */
#include <stdio.h>

const int MAX = 100;
int stick[MAX] = {0};
int n, k;

int solve(int L, int R, int K) {
    int mid, count = 0;
    while (L + 1 < R) {

        count = 0;
        mid = (L + R) / 2;
        for (int i = 0; i < n; ++i) {
            count += stick[i] / mid;
        }
        if (count < K) {
            R = mid;
        } else {
            L = mid;
        }
    }
    return mid;
}

int main() {
    int maxL = -1;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &stick[i]);
        if (stick[i] > maxL) {
            maxL = stick[i];
        }
    }
    printf("%d", solve(1, maxL, k) - 1);

    return 0;

}
```


### 快速幂（二分幂）
给定三个正整数a，b，m，求a^b%m
当b是数量级很大的数时，显然使用循环的复杂度会很高
因此引入二分的思想

+ 若b是奇数，则有a^b = a * a^(b-1);
+ 若b是偶数，则有a^b = a^(b/2) * a^(b/2);

这样，在log(b)级别的转化之后，一定会得到a^0,再回退得到每一步的结果，因此得到快速幂的递归写法，时间复杂度为O(log b)
```c
typedef long long LL;
LL binaryPow(LL a,LL b,LL m){
    if (b == 0) {
        return 1;
    } else {
        if (b &1) {
            return a * binaryPow(a, b - 1, m) % m;
        } else {
            LL num = binaryPow(a, b / 2, m);
            return num * num % m;
        }

    }
}
```

**一个小技巧：对数进行奇偶判断时，可以使用n & 1,判断末位是不是1，对于需要判断奇偶的场合这种位运算效率会更高一点**

还有一种基于位运算的快速幂写法，但其实在实际应用中效率和递归差别并不大
这种位运算的原理是 a^b 一定可以写成 a^(2k)...a^8,a^4,a^2,a^1之中若干项的乘积
```c
typedef long long LL;

LL binaryPow(LL a, LL b, LL m) {
    LL ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = ans * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}
```

## two pointers
two points是一种常用的算法思想，即多指针遍历，通过遍历对象的规律而降低循环次数，减少复杂度
### 归并排序
+ 常见的二路归并： 将序列两两一组分成n/2组，组内排序，然后逐渐合并
```c
/*
 * 归并排序
 */
#include <stdio.h>
const int maxn = 100;
void merge(int A[],int L1,int R1,int L2,int R2) {
    int i = L1, j = L2, temp[maxn], index = 0;

    while ((i < R1) && (j < R2)) {
        if (A[i] <= A[j]) {
            temp[index++] = A[i++];
        } else {
            temp[index++] = A[j++];
        }
    }
    while (i <= R1) {
        temp[index++] = A[i++];
    }
    while (j <= R2) {
        temp[index++] = A[j++];
    }
    for (int k = 0; k < index; ++k) {
        A[L1 + k] = temp[k];
    }
}
//递归的归并
void mergeSort(int A[],int left,int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);
        merge(A, left, mid, mid + 1, right);
    }
}
//非递归的归并
void mergeSort(int A[]) {
    for (int step = 2; (step / 2) <= n; step *= 2) {
        for (int i = 1; i < n; i += step) {
            int mid = i + step / 2 - 1;
            if (mid + 1 <= n) {
                merge(A, i, mid, mid + 1, min(i + step - 1, n));
            }
        }
    }
}
```


### 快排
```c
/*
 * 快排
 */
int partition(int A[],int left,int right) {
    int temp = A[left];
    while (left < right) {
        while ((left < right) && (A[right] > temp)) {
            --right;
        }
        A[left] = A[right];
        while ((left < right) && (A[left] <= temp)) {
            ++left;
        }
        A[right] = A[left];
    }
    A[left] = temp;
    return left;
}

//
void quickSort(int A[], int left, int right) {
    if (left < right) {

        int position = partition(A, left, right);
        quickSort(A, left, position - 1);
        quickSort(A, position + 1, right);
    }
}

```

### 随机数
```c
#include <stdlib.h>
#include <time.h>
int main(){
    srand((unsigned int) time(NULL));
    rand();
}
```

rand()%(n)生成随机数的范围是 \[0,n-1]
因此想要生成\[a,b]范围内的就可以用rand()%(b-a+1) +a



# 2019年01月25日打卡

### 打表
一种典型的空间换时间的方法，一般指将所有可能用到的结果事先计算出来，之后用到的时候直接查表
+ 在一次性计算出所有结果
比如一个程序如果需要计算**大量的**斐波那契数，如果每次都从头开始算就会有很多重复的过程，因此把需要用到的先进行预处理，相对会省一些时间

+ 在B中计算出结果，手动写入程序A中
这种用法是由于程序某一部分时间较长，又相对没有更好的解决方法时，比如计算N皇后问题，很容易超时，就可以在本地先计算出复杂的n，在手动写到线上程序中
+ 对于一些不会做的题目，先暴力求解一部分情况，寻找规律及突破口
### 活用递推
例如有一类涉及序列的问题，序列每一位需要计算的值与其两侧的值有关，那么就可以根据递归确定两侧的值
比如PAT B1040
>字符串 APPAPT 中包含了两个单词 PAT，其中第一个 PAT 是第 2 位(P)，第 4 位(A)，第 6 位(T)；第二个 PAT 是第 3 位(P)，第 4 位(A)，第 6 位(T)。
现给定字符串，问一共可以形成多少个 PAT？
输入只有一行，包含一个字符串，长度不超过10​5​​，只包含 P、A、T 三种字母。
在一行中输出给定字符串中包含多少个 PAT。由于结果可能比较大，只输出对 1000000007 取余数的结果。

直接暴力的话一定是会超时的，换个角度想的话，字符串中能构成PA的数目等于每个A前面P的數目的和，能够成PAT的数目等于每个T前面PA数目的总和，因此在一次遍历中递推地得到相关的数量，然后乘积即可

```c
#include <stdio.h>
#define LIM 1000000007
int main()
{
    unsigned int P = 0, PA = 0, PAT = 0;
    char c;
    while((c = getchar()) != '\n')
    {
        if(c == 'P')   P++;
        if(c == 'A')   PA = (PA + P) % LIM;
        if(c == 'T')   PAT = (PAT + PA) % LIM;
    }
    printf("%d", PAT);
    return 0;
}
```

### 随机选择
主要围绕这样一个问题

如何从一个无序数组中输出第N大的数

最简单的想法是先排序，再选择，那么复杂度大概在O(nlogn)，

而这种随机选择算法对于任何输入期望复杂度都是O(n)

其思想类似于快排，执行一次左右分割后， 主元左侧的都是小于他的，即主元A\[p]就是第K=p-left +1大的数，假设这就是所求的N，那么就直接返回主元，如果K＞N，就说明要求的数在主元左侧，则向左递归，同理如果K ＜N，就说明要求的数在主元右侧，向右递归
```c
/*
 * 随机选择算法
 */
#include <stdio.h>
int randParitition(int A[],int left,int right) {
    int temp = A[left];
    while (left < right) {
        while ((left < right) && (A[right] < temp)) {

            --right;
        }
        A[left] = A[right];
        while ((left < right) && (A[left] <= temp)) {
            ++left;
        }
        A[right] = A[left];
    }
    A[left] = temp;
    return left;
}
int randSelect(int A[], int left, int right, int K) {
    if (left == right) {
        return A[left];
    }
    int p = randParitition(A, left, right);
    int M = p - left + 1;
    if (K == M) {
        return A[M];

    } else if (M < K) {
        return randSelect(A, p + 1, right, K - M);

    } else {
        return randSelect(A, left, p - 1, K);
    }
}

```




# 2019年01月26日打卡

### 简单数学
不涉及太多算法内容，注意数理逻辑即可
PAT B1019 数字黑洞
```c

/*
 * PAT B 1019
 * 数字黑洞
 */
#include <stdio.h>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

void to_array(int n, int num[]) {
    for (int i = 0; i < 4; ++i) {
        num[i] = n % 10;
        n /= 10;
    }
}

int to_number(int num[]) {
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        sum = sum * 10 + num[i];
    }
    return sum;
}
int main() {
    int n, MIN, MAX;
    scanf("%d", &n);
    int num[5];
    while (1) {
        to_array(n, num);
        sort(num, num + 4);
        MIN = to_number(num);
        sort(num, num + 4, cmp);
        MAX = to_number(num);
        n = MAX - MIN;
        printf("%04d - %04d = %04d", MAX, MIN, n);
        if (n == 0 || n == 6174) {
            break;
        }
        return 0;
    }
}
```

### 最大公约数与最小公倍数

欧几里得-辗转相除法
```c
int gcd(int a,int b){
    if(b == 0) return a;
    else return gcd(b,a % b);
}
```

最大公倍数
得到最小公约数d后，lcm = a * b /d
但是在实际中a*b可能会溢出，所以写成 a/d * b


### 分数的四则混合运算
**分数的表示与化简**
+ 如果分母为负数，分子分母同取相反数
+ 如果分数为零，规定分子为0，分母为1
+ 分子和分母通过最大公约数进行约分
```c
/*
 * 分数
 */

#include <math.h>

struct Fraction {
    int up,down;
};
int gcd(int a,int b) {
    if (b == 0) {
        return a;
    } else return gcd(a, a % b);

}
Fraction reduction(Fraction result) {
    if (result.down < 0) {
        result.down = -result.down;
        result.up = -result.up;

    }
    if (result.up == 0) {
        result.down = 1;
    } else {
        int d = gcd(abs(result.up), abs(result.down));
        result.up /= d;
        result.down /= d;
    }
    return result;
}
```

**分数加法**
```c
Fraction add(Fraction f1,Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;

    return reduction(result);
}
```


**分数减法**
```c
Fraction minu(Fraction f1,Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down - f2.up * f1.down;
    result.down = f1.down * f2.down;

    return reduction(result);
}
```

**分数乘法**
```c
//分数乘法
Fraction mul(Fraction f1,Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}
```

**分数除法**
```c
//分数除法
Fraction div(Fraction f1,Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;
    return reduction(result);
}
```

**分数的输出**
+ 化简
+ 如果分母为1，则输出整数（视题目要求）
+ 对于假分数（视题目要求）输出带分数

```c
void showResult(Fraction r) {
    r = reduction(r);
    if (r.down == 1) {
        printf("%d", r.up);
    } else if (abs(r.up) > r.down) {
        printf("%d %d/%d", r.up / r.down, abs(r.up) % r.down, r.down);

    } else {
        printf("%d/%d", r.up, r.down);
    }
}
```

### 素数
判断素数
```c
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    int sqr = (int) sqrt(1.0 * n);
    for (int i = 2; i <= sqr; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
```

**素数表筛法**

根据前一种判断素数生成素数表的时间复杂度为O(n根号n)
当数量较大时时间过长
因此介绍这种筛法
筛法的重点就在于筛

比如2是素数，那么就把随后2的倍数全都排除掉

3没有被排除，因此3是素数，随后把3的倍数筛掉

（4）由于已被筛掉所以继续

5没有被筛掉，所以5是素数......


当从小到大到达某数a时，如果a没有被筛掉，那么a一定是素数

```c
//素数筛法
const int maxn = 101;
int prime[maxn], pNum = 0;
bool p[maxn] = {0};
void Find_Prime() {
    for (int i = 2; i < maxn; ++i) {
        if (!p[i]) {
            prime[pNum++] = i;
            for (int j = i + 1; j < maxn; j += i) {
                p[j] = true;
            }
        }
    }
}
```

该算法的时间复杂度为O(nloglogn)