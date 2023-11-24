////https://www.luogu.com.cn/problem/P1095
//题目名：守望者的逃离

//题目分析：首先明白用户输入的是三个非负值
//常规速度：17m/s，
//特殊情况：法术，60m/s，
//代价：消耗十点法术
//恢复法术的条件：处在原地休息，每秒4点
//用户的输入：魔法初值M，需要走的距离S，限定时间T
//返回：能否掏出，能返回最短时间，不能返回最远距离

//首先假设一定能走的了，也就是不加限定时间

int fast_reply_off_condition(int M, int S)
{
    //s = 17t + 60*n
    //T = t + 4N(其中N会回复时间，n为回复次数)
    
    //一个一个加限定条件
    int t;
    int n;
    if(M < 10)
    {
        n = 0;
        return S / 17;
    }
    if(M > 10)
    {
        n = M / 10;
        return (S - 60 * n) / 17;
    }//这是一个基本的不回复的一个算法

}

int fast_only_magic_condition(int M, int S)//每过一秒判定一次；
{
    int n;
    if(S % 60 == 0)
        n = S / 60;
    if(S % 60 != 0)
        n = S / 60 + 1;
        
    int N;
    while(n)
    {
        N = 0;
        if(M < 10)
        {
            M + 4;
            N++;
        }
        if(M > 10)
        {
            M - 10;
            n--;
        }   
    }

    return N;

}//这是假设全用法术的算法；

int fast_only_conventional(int S){return S / 17;};//这是假设不使用法术的函数

int magic(int M)//注意！这里返回的是距离！
{
    int n;
    if(M < 10)
    {
        n = 0;
        return 0;
    }
    if(M > 10)
    {
        n = M / 10;
        return 60 * n;
    }
    
}

//综合算法，最后和根本不回复的算法作比较
//如果不加限定时间的话，其实很好判断。
int comprehensive_condition(int M, int S)
{
    int s;
    int t = M / 10;
    s = S - magic(M);
    while(s)
    {
        if(fast_only_magic_condition(M, s) < fast_only_conventional(s))
        {
            
        }
    }
    
}
