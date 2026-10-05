class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算出旺仔哥哥最后会站在哪位小朋友旁边
     * @param a int整型vector 第 i 个小朋友的数字是 a_i
     * @param m int整型 表示旺仔哥哥的移动次数
     * @return int整型
     */
    int stopAtWho(vector<int>& a, int m) {
        int n=0;
        int cnt=a[0];
        for(int i=0;i<m;i++)
        {
            n = (n - cnt % (int)a.size() + (int)a.size()) % (int)a.size();
            // n-cnt本质:原来的位置，往前走多少步
            //%(int)a.size()本质:如果走了5个环，得到的余数为:在第6个环上 相较于 第6个环现在这个位置 多少步
            //+(int)a.size()%(int)a.size()本质：怕这个步是负数的，给他搞正来，例如是目的地为第六个环的-2步
            //就相当于第七个环的+4步
            cnt=a[n];
        }
        return n+1;
    }
};//noob 82