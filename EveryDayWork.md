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
            for (int j = i + i; j < maxn; j += i) {
                p[j] = true;
            }
        }
    }
}
```

该算法的时间复杂度为O(nloglogn)
筛法的精髓在于那句for (int j = i + i; j < maxn; j += i)


# 2019年01月27日打卡

### 质因子分解

定义结构体存储质数及指数
```c
struct factor{
    int x,cnt;
}fac[10];
```

因为前十位质数的乘积就已经超过int范围了，所以定义fac数组取十位就够了

前面提到对于一个整数来说，如果存在1和本身之外的因子则一定是对称分布的，因此可以引申到质因子上

+ 枚举1到sqrt(n)的所有质子p，判断p是否为n的因子，如果p是一个质因子就初始化p的cnt为0，只要p还是n的质因子，就另n/ p，cnt
的个数不断加一，直到不再是一个质因子
+ 如果p不是n的质因子就直接跳过

+ 如果经过上述过程n仍大于一，则说明n有且仅有一个大于sqrt(n)的质因子，有可能是n本身，这时候需要把质因子加入到fac中

PAT A1059 分解质因子

```c
/*
 * PAT A 1059
 * 分解质因子 Prime factor
 */
#include <stdio.h>
#include <math.h>

const int maxn = 100010;
bool isPrime(int n) {
    if (n == 1)return false;
    int sqr = static_cast<int>(sqrt(1.0 * n));
    for (int i = 2; i <= sqr; ++i) {
        if (n % i == 0) {
            return false;

        }
    }
    return true;
}

int prime[maxn], pNum = 0;
void Find_Prime() {
    for (int i = 1; i < maxn; ++i) {
        if (isPrime(i)) {
            prime[pNum++] = i;
        }
    }
}

struct factor {
    int x, cnt;

} fac[10];
int main() {
    Find_Prime();
    int n, num = 0;
    scanf("%d", &n);
    if (n == 1) {
        printf("1=1");

    } else {
        printf("%d=", n);
        int sqr = static_cast<int>(sqrt(1.0 * n));
        for (int i = 0; i < pNum && prime[i] <= sqr; ++i) {
            if (n % prime[i] == 0) {
                fac[num].x = prime[i];
                fac[num].cnt = 0;
                while (n % prime[i] == 0) {
                    fac[num].cnt++;
                    n /= prime[i];
                }
                num++;
            }
            if (n == 1) {
                break;
            }
        }
        if (n != 1) {
            fac[num].x = n;
            fac[num++].cnt = 1;
        }
    }

    for (int j = 0; j < num; ++j) {
        if (j > 0) {
            printf("*");
            printf("%d", fac[j].x);
            if (fac[j].cnt > 1) {
                printf("^%d", fac[j].cnt);

            }
        }
    }
    return 0;
}
```

## 大整数运算

大整数又称高精度整数

### 大整数储存
用数组来储存大整数，数组的高位储存大整数的高位，数组的低位储存大整数的低位，这样保持运算时从低位开始

```c
struct bigN {
    int d[1000];
    int len;

    bigN() {
        memset(d, 1000, sizeof(d));
        len = 0
    }
};


```

如果是由字符串读入的需要进行逆序

```c
int compare(bigN a, bigN b) {
    if (a.len > b.len) {
        return 1;
    } else if (a.len < b.len) {
        return -1;
    } else {
        for (int i = a.len - 1; i >= 0; --i) {
            if (a.d[i] > b.d[i]) {
                return 1;
            } else if (a.d[i], b.d[i]) {
                return -1;
            }
        }
        return 0;

    }
}

```


### 大整数加法

```c
bigN add(bigN a, bigN b) {
    bigN c;
    int carry = 0;  //进位
    for (int i = 0; i < a.len || i < b.len; ++i) {
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if (carry != 0) {
        c.d[c.len++] = carry;
    }
    return c;
}

```

### 大整数减法

```c
bigN sub(bigN a,bigN b) {
    bigN c;
    for (int i = 0; i < a.len || i < b.len; ++i) {
        if (a.d[i] < b.d[i]) {
            --a.d[i + 1];
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
        c.len--;
    }
    return c;
}
```

### 高精度与低精度的乘法

```c
bigN multi(bigN a,int b) {
    bigN c;
    int carry;
    for (int i = 0; i < a.len; ++i) {
        int temp = a.d[i] * b + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    while (carry != 0) {
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}
```

### 高精度与低精度的除法

```c
bigN div(bigN a, int b,int &r) {        //r为余数
    bigN c;
    c.len = a.len;
    for (int i = a.len - 1; i >= 0; --i) {
        r = r * 10 + a.d[i];
        if (r < b) {
            c.d[i] = 0;
        } else {
            c.d[i] = r / b;
            r %= b;
        }
    }
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
        c.len--;
    }
}
```

## 拓展欧几里得算法
```c
/*
 * 拓展欧几里得算法
 */
#include <stdio.h>

int exGcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int g = exGcd(b, a % b, x, y);
    int temp = x;
    x = y;
    y = temp - a / b * y;
    return g;
}
```

费马小定理：m是素数，a是任意数且a%m≠0，则a^(m-1) mod m = 1

## 组合数

从一个问题谈起：
n！中有多少个质因子p，即分解质因子后，质数p的次数是多少
正常的遍历方法复杂度为O(nlogn)，但是通过观察我们可以得到这样的规律

n!中有(n/p + n/p^2 + n/p^3....)个质因子p

其中每一个除法都是向下取整
于是我们得到了O(logn)的代码

```c
int cal(int n,int p){
    int ans = 0;
    while(n){
        ans += n/p;
        n /= p;
    }
    return ans;
}
```

通过这种算法可以马上解决n！中末尾有几个零，显然末尾0的个数等于因子中10的个数，等于质因子中5的个数
因此代入cal(n,5)即可

### 组合数的计算

C(n,m) = n! / (m! * (n-m)!)

+ 显然第一种方法，直接按照定义计算，求阶乘时一定会溢出
+ 第二种方法通过递推式计算：C(n,m) = C(n-1 ,m) + C(n-1,m-1)

```c
long long C(long long n,long long m){
    if(m == 0 || m == n) return 1;
    return C(n-1,m) + C(n-1,m-1);
}
```
+ 第三种通过定义的变形：C(n,m) = (n-m+1)(n-m+2)...(n-m+m) / 1*2*3*...*m

```c
long long C(long long n,long long m){
    long long ans = 1;
    for(long long i = 1; i <= m; ++i){
        ans = ans * (n-m+i)/i;
    }
    return ans;
}
```

不过有可能在最后一个乘法时溢出，但是复杂度已经降低到O(m)，非常可观

**Lucas定理解决C(n,m)%p问题**

如果p是素数，将m和n表示为p进制
m = m\[k]*p^k + m\[k-1]*p^(k-1) + ... + m\[0]
n = .....
则有C(n,m)%p = C(n\[k],m\[k]) * C(n\[k-1],m\[k-1])....%p

```c
long long p; //p为全局变量
int Lucas(int n,int m){
    if(m == 0) return 1;
    return C(n%p,m%p) * Lucas(n/p,m/p) % p;
}
```



# 2019年01月28日打卡
*今天学的少，小年快乐（借口）*

## C++STL标准模板库

### vector
+ 可变长数组
+ 头文件include<vector>  + using namespace std
+ 声明方式vector <类型> 变量名
+ 二维定义 vector<vector<int> > VI 相当于定义了一个二维的可变长数组
+ 定义vector数组 ： vector<int> Array\[n],与上一条的区别是这个一维是定长的n
+ vector可以通过下标访问0～vector.size()-1
+ 通过迭代器访问元素，相当于指针
```c
#include <vector>

using namespace std;
vector<int > vi;
    //迭代器不支持 it < vi.end()的写法，只能是!=
    for (vector<int>::iterator it = vi.begin(); it != vi.end(); ++it) {
        printf("%d", *it);
    }
    //或者
    vector<int>::iterator it2 = vi.begin();
    for (int i = 0; i < 5; ++i) {
        printf("%d", *(it2 + i));
    }
```


vector 的常用函数
+ push_back():在vector后面添加一个元素
+ pop_back(): 删除vector最后的元素，直接删除，void类型
+ size(): 返回元素个数，unsigned类型，但是用%d就可以
+ clear(): 清空
+ insert(it,x): 向任意迭代器it位置插入x
+ erase(it): 删除迭代器it处的元素，erase(first,last),删除二者之间元素，含first


vector常见用途
+ 数组
+ 未知数目储存
+ 邻接表存储图


### set
+ 集合
+ 有序无重复，默认递增顺序
+ 定义声明同vector
+ 只支持迭代器遍历  ，且迭代器不支持*(it+i)


set常用函数
+ insert(x): 插入，自动排序去重
+ find(value): 返回value对应**迭代器**
+ erase(it): 删除迭代器元素值；erase(value): 删除对应的值；erase(first,last):删除迭代器区间，包含first
+ size(),clear()同上

set常见用处
自动去重并按升序排序
set延伸为multiset //元素可重复；unordered_set //非排序集合

### string
+ 头文件include<string>，注意<string>和<string.h>是两个不同的头文件
+ 定义声明与普通数据类型相同
+ 可以通过下标访问string str = "abcd"；str\[i]这样子
+ 如果要输入输出整个字符串只能用cin，cout，或者printf("%s",str.c_str());其中c_str()将字符串转化为字符数组
+ 迭代器 string::iterator it

string常用函数

+ 重载运算符+：连接字符串，str1 += str2，连接之后赋值给str1；重载了比较运算符，比较的是字符串的字典序
+ length(),size()基本相同
+ str1.insert(pos,str2)： 在pos位置(数组下标)插入str2
+ insert(it,it1,it2): it为原字符串待插入的迭代器位置，it1，it2是要插入的字符串首尾迭代器的位置
+ erase(it),erase(first,last)同上，erase(pos,len)从pos位置删除len长度，pos类似数组标，str = "abcde"执行str.erase(3,2)删除的是de
+ clear()
+ substr(pos,len)返回pos开始，长度为len的子串
+ string::npos,是一个常数，本身是-1，代表匹配失败的值，但是由于本身是无符号数，所以也可以代表int；类型的最大值
+ find(str2):返回子串第一次出现的位置
+ replace(pos,len,str2): 将pos开始，len长度的字符串替换为str2
+ replace(it1,it2,str2)将it1,it2范围的字符串替换为str2


# 2019年01月29日打卡

### map
+ 键值对映射
+ 头文件map using namespace std
+ 声明定义map<type,type> mp类型可以是普通数据类型，或者STL容器，注意**数组不能做类型**
+ 通过下标访问：即根据键访问值，比如定义一个map<char,int> mp;就可以根据mp\['c']这种键的形式访问值
+ 通过迭代器访问，创建迭代器方式类似，map<int,int>::iterator it;it.first表示键，it.second表示值
+ map内部与set一样应用红黑树储存，因此默认按照键的升序排列

map常用函数
+ find(key):由键索值,返回的是该映射的迭代器
+ erase(it);erase(key);erase(first,last)类似前文
+ size(),clear()

常见用途
+ 建立字符串与整数之间的映射
+ 判断大整数或者其他类型数据是否存在可以把map当成bool数组用
+ multimap是一个键对应多个值，unordered_map是无序的效率更高

### queue
+ 队列，先进先出的容器
+ 声明定义是STL的一般形式
+ 只能通过front()和back()访问队列首和末尾的元素

queue常用函数
+ push(x): x入队列
+ front(),back()
+ pop(): 队首元素出队列
+ empty(): 返回队列是否为空
+ size()

queue常见用途
树的广度优先搜索
deque是双向队列

### priority_queue

+ 优先队列，底层用堆来实现，队首元素一定是当前队列中优先级最高的元素
+ 头文件就是<queue>，和普通队列一样，定义的时候类型写成priority_queue<type> name;
+ 优先队列没有front和back函数，只能通过top()访问优先级最高的队首元素

priority_queue常用函数

push，top，pop，empty，size

**优先队列中的优先级设置**

+ 如果是基本数据类型int；double；char，定义的时候写全参数priority_queue<int,vector<int>,greater<int> > q;三个参数的类型保持一致，最后一个参数less表示大的优先级高（在队首），greater表示小的优先级高
+ 对于结构体的话，要重载小于号进行比较
```c
struct fruit {
    string name;
    int price;

    friend bool operator<(fruit f1, fruit f2) {
        return f1.price < f2.price;
    }

};
```

然后正常定义就是按照默认大的在前面了
如果想让小的在前面，就把返回值里的小于号改成大于号

可以发现这种定义的逻辑和sort中的cmp函数逻辑正好相反，但是形式上却类似
其实也可以放到结构体之外定义，更加类似cmp函数

```c
struct cmp {
    bool  operator()(fruit f1,fruit f2) {
        return f1.price > f2.price;
    }
};
//此时定义方式必须是第三个参数写cmp
priority_queue<fruit,vector<fruit>,cmp> q;
```

第二种定义优先级的方式其实是通用的方式，一般数据类型以及STL容器都可以使用这种方式来定义

priority_queue经常用来解决贪心问题以及地杰斯特拉算法的优化等

### stack
+ 栈：后进先出
+ 定义头文件等按照STL一般规律
+ 访问元素同queue，只能top

常用函数
push，pop，top，size，empty正常操作
常见用途

多用来实现递归

### pair
+ 内部有两个元素的结构体
+ 头文件<utility>，或者导入map头文件时会自动导入涉及pair的部分
+ 定义pair<type1,type2> name;类似map，但是这两个是并列的关系，初始化的话直接跟着小括号了；里面赋值就可以
pair<string,int> p("hhh",2);
+ 如果想在代码中临时构建一个pair，（比如用来赋值给变量）有两种方法
第一种直接在类型后面赋值pair<type1,type2>("sddd",111)

第二种使用make_pair("adff",111)

+ pair的访问就是同结构体，第一个元素是first，第二个元素是second
```c
#include <stdio.h>
#include <utility>
#include <iostream>

using namespace std;
int main() {
    pair<string, int> p;
    p = make_pair("hhhhh", 121312);
    p.first = "ferge";
    p.second = 334342;
    p = pair<string, int>("jkjjj", 345);
}
```


pair常用函数解析
+ 可以直接用比较运算符> < == <= >=等等比较，首先比较first的大小，若想等继续比较second

pair常见用处
+ 替换只有两个元素的结构体，节约时间
+ map传值的时候经常用来构建pair传入，比如


```c
map<string,int> mp;

mp.insert(make_pair("hhh", 342));
```

# 2019年01月30日打卡

### algorithm头文件中的函数

记得加using namespace std
+ max(),min(),参数是两个浮点数可以嵌套使用，这样就可以求多个数的最大小值
+ abs(int),绝对值，参数必须是整数，如果是浮点数只能用math头文件下面的fabs()
+ swap(T a,T b),交换两个相同类型的值，
+ reverse(a,b)可以将数组指针或者容器迭代器之间的元素翻转，比如对于数组a\[10],reverse(a,a+10),或者容器reverse(it1,it2),比如reverse(str.begin(),str.end())
+ next_permutation() :给出一个序列在全排列中的下一个序列，比如123下一个就是132，如果已经到达末尾，会返回false，因此可以用这个函数求全排列

```c
#include <stdio.h>
#include <algorithm>

using namespace std;
int main() {
    int a[10] = {1, 2, 3};
    do {

        printf("%d%d%d\n", a[0], a[1], a[2]);
    } while (next_permutation(a, a + 3));
}
```

这里传入了两个迭代器用于更新数组中的值

+ fill(): fill可以把数组或者容器中的任意一段区间元素赋为相同的值，和memset不同，fill可以是任意值不容易出现差错fill(a,b,x)将迭代器a到b之间全赋值为x
+ sort在前文展开过，不做赘述
+ lower_bound()和upper_bound()，在前文涉及过实现，而在algorithm中有成型的函数
lower_bound(first,last,val)用来寻找在数组或容器内的first到last（左开右闭）范围内第一个值大于等于val的指针或迭代器
upper_bound(first,last,val)用来寻找在数组或容器内的first到last（左开右闭）范围内第一个值大于val的指针或迭代器
如果没有符合元素则返回可插入val的位置

```c
/*
 * lower_bound()
 * upper_bound()
 */
#include <stdio.h>
#include <algorithm>

using namespace std;
int main() {
    int a[10] = {1, 2, 2, 3, 3, 3, 5, 5, 5, 5};
    printf("%d,%d\n", lower_bound(a, a + 10, -1)-a, upper_bound(a, a + 10, -1)-a);
    printf("%d,%d\n", lower_bound(a, a + 10, 1)-a, upper_bound(a, a + 10, 1)-a);
    printf("%d,%d\n", lower_bound(a, a + 10, 3)-a, upper_bound(a, a + 10, 3)-a);
    printf("%d,%d\n", lower_bound(a, a + 10, 4)-a, upper_bound(a, a + 10, 4)-a);
    printf("%d,%d", lower_bound(a, a + 10, 6)-a, upper_bound(a, a + 10, 6)-a);
}
```

# 数据结构专题

## 栈的应用

STL中没有定义栈的清空，所以可以用当empty为false是一直循环pop

### 中缀转后缀

+ 设立一个操作符栈，用来临时存放操作符，设立一个数组或者队列，用来存放后缀表达式
+ 从左到右扫描中缀表达式，遇到操作数就一位一位读入，合并后加入到后缀表达式
+ 如果遇到操作符op，同栈顶的操作符比较，如果优先级高则压栈，否则弹出，加入到后缀表达式中
+ 重复上述操作，直到扫描完中缀表达式，如果栈中还有元素，依次弹栈加入到后缀表达式

所谓操作符的优先级即他们计算的优先级，乘==除 > 加==减，可以用map设定好

### 计算后缀表达式

从左到右扫描后缀表大会，如果是操作数，则压栈，如果是操作符，则连续弹出两个操作数进行计算，先弹出的是第二操作数，后弹出的是第一操作数

**注意**
+ 操作数要定义成浮点型
+ 用string的erase可以去除表达式中无用的空白符
+ 注意题目要求表达式是否合法

```c
/*
 * 四则运算计算器
 */
#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

struct node {
    double num;
    char op;
    bool flag;  //true表示操作数num，false表示操作符op

};

string str;
stack<node> s;
queue<node> q;
map<char, int> op;

//中缀转后缀
void change() {
    double num;
    node temp;
    for (int i = 0; i < str.length();) {
        if (str[i] >= '0' && str[i] <= '9') {
            temp.flag = true;
            temp.num = str[i++] - '0';
            while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
                temp.num = temp.num * 10 + (str[i] - '0');
                i++;
            }
            q.push(temp);
        } else {
            temp.flag = false;
            while (!s.empty() && op[str[i]] <= op[s.top().op]) {
                q.push(s.top());
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);
            i++;
        }
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

//计算后缀表达式
double cal() {
    double temp1, temp2;
    node cur,temp;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur.flag == true) {
            s.push(cur);

        } else {
            temp2 = s.top().num;
            s.pop();
            temp1 = s.top().num;
            s.pop();
            temp.flag = true;
            if (cur.op == '+') temp.num = (temp1 + temp2);
            else if (cur.op == '-')  temp.num = (temp1 - temp2);
            else if (cur.op == '*') temp.num = (temp1 * temp2);
            else temp.num = (temp1 / temp2);
            s.push(temp);
        }
    }
    return s.top().num;

}

int main() {
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    while (getline(cin, str), str != "0") {
        for (string::iterator it = str.end(); it != str.begin(); --it) {
            if (*it == ' ') {
                str.erase(it);
            }

        }
        while (!s.empty()) {
            s.pop();

        }
        change();
        printf("%.2f\n", cal());
    }
    return 0;
}
```


# 2019年01月31日打卡

今天一个项目被甲方查水表了嘤嘤嘤

## 队列的应用

同样STL中的队列没有提供清空的函数
因此可参照上文提到的清空栈的方法
在while中判断empty不为真就一直pop
上文的四则运算也涉及到了队列，也没什么要展开的

## 链表

链表同数组一样都是一种线性表，只不过顺序表的储存是连续的，链表的储存是不连续的
链表可以分为带头节点和不带头结点两类，每个节点一般有数据域和指针域

### 使用malloc和new为链表节点分配内存空间
malloc是C语言stdlib.h头文件下的内存分配函数，返回申请的指针
```c
node*p = (node*)malloc(sizeof(node));
```

如果用malloc申请较大的动态数组就会申请失败返回NULL

new是C++中申请动态空间的，形式要比malloc简单很多
```c
node *p = new node;
```

和malloc类似，如果用new开辟大量的空间，也会失败，但是会由C++中的异常管理机制处理，而不会返回NULL

### 内存泄漏
C、C++中没有动态内存管理机制，内存的申请和释放都要由程序员来完成
如果申请的内存没有及时释放，就会导致内存泄漏

C语言中对应malloc的释放函数是free，释放指针变量p： free（p）
C++中对应new的释放函数是delete，用法类似：delete(p)
### 链表操作

+ 创建链表
```c
/*
 * 链表
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    node *next;

};


node *create(int Array[]) {
    node *p, *pre, *head;
    head = new node;
    head->next = nullptr;
    pre = head;
    for (int i = 0; i < 5; ++i) {

        p = new node;
        p->data = Array[i];
        p->next = nullptr;
        pre->next = p;
        pre = p;
    }

    return head;


}
```

+ 查找元素

```c
//查找元素
int search(node *head, int x) {
    int count = 0;
    node *p = head->next;
    while (p != nullptr) {
        if (p.data == x) {
            count++;
        }
        p = p->next;
    }
    return count;
}
```

+ 插入元素

```c
//插入元素
void insert(node *head, int pos, int x) {
    node *p = head;
    for (int i = 0; i < pos - 1; ++i) {
        p = p->next;
    }
    node *q = new node;
    q->data = x;
    q->next = p->next;
    p->next = q;

}
```

+ 删除元素

```c
//删除元素
void del(node *head, int x) {
    node *p = head->next;
    node *pre = head;
    while (p != nullptr) {
        if (p.data == x) {
            pre->next = p->next;
            delete (p);
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
}
```

### 静态链表

静态链表的实现原理是hash，静态链表用整数来储存元素的地址，而不是用指针

PAT A1032

给出两个链表的首地址及若干节点地址、数据、下一个节点地址，求两条链表首个公用节点的位置若没有则输出-1

```c
/*
 * PAT A 1032
 */

#include <stdio.h>
#include <cstring>

const int maxn = 100010;
struct NODE {
    char data;
    int next;
    bool flag;
} node[maxn];

int main() {
    for (int i = 0; i < maxn; ++i) {
        node[i].flag = false;
    }
    int s1, s2, n;
    scanf("%d %d %d", &s1, &s2, &n);
    int address, next;
    char data;
    for (int j = 0; j < n; ++j) {
        scanf("%d %c %d", &address, &data, &next);
        node[address].data = data;
        node[address].next = next;
    }
    int p;
    for (p = s1; p != -1; p = node[p].next) {
        node[p].flag = true;
    }
    for (p = s2; p != -1; p = node[p].next) {
        if (node[p].flag) {
            break;
        }

    }
    if (p != -1) {
        printf("%05d\n", p);
    } else {
        printf("-1\n");
    }
    return 0;
}
```


# 2019年02月01日打卡

> 我承认今天划水了

应用静态链表解题的一般步骤
+ 定义静态链表
```c
struct Node{
    int address;
    type data;
    int next;
    XXX; //节点的某个性质
}node[100010];
```

+ 在程序的开始，对静态链表进行初始化，一般来讲对XXX进行初始化为正常情况下到达不了的数字

+ 题目一般会给出首地址，然后我们从首地址开始遍历，得到整条链表，在此过程中同步对XXX进行标记
+ 由于静态链表直接使用hash映射，因此不连续，可以通过地址排序筛出有效的节点并放在数组左边，就需要cmp函数里面二级排序等

PAT A 1052

给定n个节点地址数据指针域等等，要求按照数据从小到大排序输出

```c
/*
 * PAT A 1053
 *
 */

#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 100005;
struct Node {
    int address, data, next;
    bool flag;
} node[maxn];

bool cmp(Node a, Node b) {
    if (!a.flag || !b.flag) {
        return a.flag > b.flag;
    } else {
        return a.data < b.data;
    }
}

int main() {
    for (int i = 0; i < maxn; ++i) {
        node[i].flag = false;
    }
    int n, begin, address;
    scanf("%d%d", &n, &begin);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &address);
        scanf("%d%d", &node[address].data, &node[address].next);
        node[address].address = address;
    }

    int count = 0, p = begin;
    while (p != -1) {
        node[p].flag = true;
        count++;
        p = node[p].next;

    }
    if (count == 0) {
        printf("0 -1");
    } else {
        sort(node, node + maxn, cmp);
        printf("%d %05d\n", count, node[0].address);
        for (int i = 0; i < count; ++i) {
            if (i != count - 1) {
                printf("%05d %d %05d", node[i].address, node[i].data, node[i + 1].address);

            } else {
                printf("%05d %d -1\n", node[i].address, node[i].data);

            }
        }
    }
    return 0;

}

```


注意点
+ 直接使用%05d输出，不足在高位补零，但是要留意负数的输出
+ 可能会出现无效节点
+ 数据还可能存在无效情况，要注意判断


# 2019年02月02日打卡

> 过年这几天有点划水，年后补回来

### 深度优先搜索DFS

深度优先搜索是一种枚举所有完整路径以遍历所有情况的搜索方法
深度优先搜索和进出站的过程类似
因此我们显然可以想到用栈来实现深度优先搜索
深度优先搜索用递归的方法很好实现
现在我们用深度优先搜索来理解一下求解斐波那契数列的过程
F(n) = F(n-1) + F(n-2)
可以将F(n-1) 和 F(n-2)视为两个岔路口，由它可以到达两个新的节点
既然有岔路口，就存在死胡同，F(0) 与F(1)就是死胡同
到达死胡同之后再依次返回，这就是一种深度优先搜索，直到找到我们想要的出口，也就是代求的结果
举个例子
> 有n件物品，每件物品的重量为w(i)，价值为c(i)，现在需要选出若干件物品放入容积为V的背包内，使得总价值最大

在这个问题中，每个物品有放入或者不放入两个选择，这个就是一种岔路，而死胡同就是物品超重，需要返回最近的岔路口

```c
/*
 * 有n件物品，每件物品的重量为w(i)，价值为c(i)，现在需要选出若干件物品放入容积为V的背包内，使得总价值最大
 */

#include <stdio.h>

const int maxn = 30;
int n, V, maxValue = 0;
int w[maxn], c[maxn];
void DFS(int index,int sumW,int sumC) {
    if (index == n) {
        if (sumW <= V && sumC > maxValue) {
            maxValue = sumC;
        }
        return;
    }
    DFS(index + 1, sumW, sumC);
    DFS(index + 1, sumW + w[index], sumC + c[index]);
}
int main(){
    scanf("%d%d", &n, &V);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
    }
    DFS(0, 0, 0);
    printf("%d\n", maxValue);
    return 0;
}
```

可以发现算法复杂度很高，因此可以根据背包的容积来增加条件减少无用操作

```c
//优化后
void DFS1(int index,int sumW,int sumC) {
    if (index == n) {
        return;

    }
    DFS1(index + 1, sumW, sumC);
    if (sumW + w[index] <= V) {
        if (sumC + c[index] > maxValue) {
            maxValue = sumC + c[index];
        }
        DFS1(index + 1, sumW + w[index], sumC + c[index]);
    }
}
```

这种根据题目的限制减少DNF复杂度的过程称为**剪枝**
显然上述问题也等价于从给定的N个整数中选出K个整数的所有（最优）方法


# 2019年02月03日打卡

### 广度优先搜索BFS

广度优先搜索按照同一层次的先后顺序遍历
因此在过程上类似与队列，非递归形式可以用队列实现

一般过程
+ 首先定义队列Q，并将起点s入队列
+ 通过while循环判断队列是否为空
+ 在while循环中取出队首元素top，然后访问（这个访问可以泛指任何操作），访问完后将其出队列
+ 将top下一层节点中所有未曾入队的节点入队，并标记它们的层号为now的层号加一
+ 返回第二步继续循环

> 给出一个m*n的矩阵，矩阵中的元素为0或1，称位置(x,y)与其上下左右四个位置(x,y+1),(x-1,y),(x+1,y),(x,y-1)是相邻的，如果矩阵中有若干个1是相邻的，不必两两相邻，那么称这些1构成了一个块，求给定矩阵中块的个数

0111001

0010000

0000100

0001110

1110100

1111000


例如上面的矩阵中，块的个数是4
对于这个问题，求解的基本思想是，枚举每一个元素的位置，如果是0，则跳过，如果是1，则使用BFS查询与该位置相邻的四个元素，前提是不出界
直到周围的1访问完毕
为了防止走回头路，可以设置一个bool型数组，来记录每个元素的位置
一个小技巧是，设置两个增量数组，这样就可以利用for循环来枚举四个方向

```c
/*
 * 给出一个m*n的矩阵，矩阵中的元素为0或1，称位置(x,y)与其上下左右四个位置(x,y+1),(x-1,y),(x+1,y),(x,y-1)是相邻的，块的个数
 * 如果矩阵中有若干个1是相邻的，不必两两相邻，那么称这些1构成了一个块，求给定矩阵中
 */

#include <stdio.h>
#include <queue>

using namespace std;
const int maxn = 100;

struct node {
    int x, y;
} Node;

int n, m;
int matrix[maxn][maxn];
bool inq[maxn][maxn] = {false};
int X[4] = {0, 0, 1 - 1};
int Y[4] = {1, -1, 0, 0};

bool judge(int x, int y) {
    if (x >= n || x < 0 || y >= m || y < 0) {
        return false;
    }
    if (matrix[x][y] == 0 || inq[x][y]) {
        return false;
    }
    return true;
}

void BFS(int x, int y) {
    queue<node> Q;
    Node.x = x;
    Node.y = y;
    Q.push(Node);
    inq[x][y] = true;
    while (!Q.empty()) {
        node top = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if (judge(newX, newY)) {
                Node.x = newX, Node.y = newY;
                Q.push(Node);
                inq[newX][newY] = true;

            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            scanf("%d", &matrix[x][y]);

        }
    }
    int ans = 0;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            if (matrix[x][y] == 1 && !inq[x][y]) {
                ans++;
                BFS(x, y);
            }
        }
    }
    printf("%d\n", ans);
    return 0;

}

```

再来看下一个例子
> 给定一个大小为n*m的迷宫，其中*代表不可通过的墙壁，点代表平地，S表示起点，T表示终点，每次只能上下左右移动一步，求起点到终点的最小步数

```c
/*
 *
 * 给定一个大小为n*m的迷宫，其中*代表不可通过的墙壁，点代表平地，S表示起点，T表示终点，每次只能上下左右移动一步，求起点到终点的最小步数
 */
#include <stdio.h>
#include <cstring>
#include <queue>

using namespace std;
const int maxn = 100;
struct node {
    int x, y;
    int step;
} S, T, Node;

int n, m;
char maze[maxn][maxn];
bool inq[maxn][maxn] = {false};
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

bool test(int x, int y) {
    if (x >= n || x < 0 || y >= m || y < 0) {
        return false;
    }
    if (maze[x][y] == '*') {
        return false;
    }
    if (inq[x][y]) {
        return false;
    }
    return true;
}

int BFS() {
    queue<node> q;
    q.push(S);
    while (!q.empty()) {
        node top = q.front();
        q.pop();
        if (top.x == T.x && top.y == T.y) {
            return top.step;
        }
        for (int i = 0; i < 4; ++i) {
            int newX = top.x;
            int newY = top.y;
            if (test(newX, newY)) {
                Node.x = newX;
                Node.y = newY;
                Node.step = top.step + 1;
                q.push(Node);
                inq[newX][newY] = true;

            }
        }
    }
    return -1;
}

int main() {
    scanf("%d%d", &n,&m);
    for (int i = 0; i < n; ++i) {
        getchar();
        for (int j = 0; j < m; ++j) {
            maze[i][j] = getchar();
        }
        maze[i][m + 1] = '\0';
    }
    scanf("%d%d%d%d", &S.x, &S.y, &T.x, &T.y);
    S.step = 0;
    printf("%d\n", BFS());
    return 0;
}

```

inq数组是判断节点是否入队列，而不是判断节点是否被访问
push操作只是将副本入容器，不能直接修改，比如对于数组a\[],push（a【0】）后，a.front = xx并不影响原数组中的值

因此有些场所可以直接传入数组的下标
注意应用

# 2019年02月04日
辞旧迎新！除夕快乐！

# 2019年02月05日
恭贺新禧！新年快乐！
诸事顺心！永无bug！

# 2019年02月06日打卡

# 树

+ 结点，边
+ 空树 ： 没有结点的树
+ 树的层次 ： 从根节点算起的层次，一般认为根节点是一层，具体看要求
+ 度 ： 节点的子节点个数
+ 有n个结点的树一定有n-1个边
+ 叶子结点被定义为度数为0的结点，即没有子结点
+ 结点的深度是从根结点出发的层次，结点的高度是从叶子结点出发的层次
+ 森林是多棵树组成

+ 满二叉树： 每一层的结点都达到了最大值，就是叶子结点全在最下一层
+ 完全二叉树： 除了最下面一层外，剩下的层数都达到了最大值

+ 孩子节点，父亲节垫，兄弟节点，祖先节点

## 二叉树的储存结构
```c
struct node{
    type date;
    node* lchild;
    node* rchild;
};
node* root = NULL;
```

### 新建结点
```c
node* newNode(int v){
    node* Node = new node;
    Node->date = v;
    Node->lchild = NULL;
    Node->right = NULL;
    return Node;
};
```

### 二叉树结点的查找、修改

```c
void search(node* root,int x,int newDate){
    if(root == NULL){
        return;
    }
    if(root-> date == x){
        root->date = newDate;
    }
    search(root->lchild,x,newDate);
    search(root->rchild,x,newDate);
}
```

### 插入


