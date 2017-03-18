
/*动态连通性问题
问题的输入是一列整数对，其中每个整数都表示一个某种类型的对象，一对整数pq可以理解为“p和q是相连的”。

*相连的特性：
自反性：p和p是相连的
对称性：p和q是相连的，那么q和p也是相连的
传递性：p和q是相连的，q和r是相连的，那么p和r是相连的

程序功能：过滤无意义的整数对
*/

#include<stdint.h>
#include<stdlib.h>
#include<stdbool.h>

void UF(int n);
void weightedUF(int n);
void connect(int p, int q);
int find(int p);
int count();
void quickUnion();
void weightedQuickUnion();


int main(void)
{

	return 0;
}

//quick union算法初始化
void UF(int n)
{

}
//weighted quick union算法初始化
void weightedUF(int n)
{

}
//在p和q之间添加一条连接
void connect(int p, int q)
{

}
//p（0到N-1）所在的分量的标识符
int find(int p)
{

}
//连通分量的数量
int count()
{

}
//quick find算法的实现
void quickUnion()
{

}
//带权重的quick union算法实现
void weightedQuickUnion()
{

}