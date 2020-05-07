vector<int> polar_point;
int polar_x, polar_y;
bool isPolar(vector<int> &a, vector<int> &b){
    if(a[1]==b[1]){//如果纵坐标相等，判断横坐标
        return a[0]<b[0];
    }
    return a[1]<b[1];//判断纵坐标
}
 
double dist(vector<int> &a,vector<int> &b){
    return pow(double(pow((a[0]-b[0]),2)+pow((a[1]-b[1]),2)),0.5);
}
 
bool smallerAngle(vector<int> &a, vector<int> &b){
    if(abs(atan2(a[1]-polar_y,a[0]-polar_x)-atan2(b[1]-polar_y,b[0]-polar_x))<1e-8){//这边注意不能比较浮点数是否相等，只能取一个范围
        return dist(a,polar_point)<dist(b,polar_point);
    }
    return atan2(a[1]-polar_y,a[0]-polar_x)<atan2(b[1]-polar_y,b[0]-polar_x);
}
 
bool isLeft(vector<int> cur, vector<int> polar, vector<int> top){
    int cross = (cur[0]-polar[0])*(top[1]-polar[1])-(top[0]-polar[0])*(cur[1]-polar[1]);//x1y2-x2y1 计算叉积
    if(cross>0)return false;
    else if(cross<0)return true;
    else{//叉积等于0的时候，有可能是反向的，要判断一下
        bool codirect = ((cur[0]-polar[0])*(top[0]-polar[0]))>0||((cur[1]-polar[1])*(top[1]-polar[1]))>0;//不能只用一个坐标x来判断，x有可能是0
        return codirect;
    }
}
 
bool isLine(vector<int> &a,vector<int> &b, vector<int> &c){
    bool coline = ((c[1]-a[1])*(a[0]-b[0]))==((a[1]-b[1])*(c[0]-a[0]));
    bool inbetween = (b[0]-a[0])*(c[0]-a[0])<0||(b[1]-a[1])*(c[1]-a[1])<0;//不能只用一个坐标x来判断，x有可能是0
    return coline&&inbetween;//(y3-y1)*(x1-x2)==(y1-y2)*(x3-x1) a在bc中间
}
 
class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        int n = points.size();//点的个数
        if(n==0||n==1||n==2||n==3){return points;}//简单情况直接处理
        sort(points.begin(),points.end(),isPolar);//排序找极点
        polar_point = points[0];//找到了极点
        polar_x = polar_point[0];polar_y = polar_point[1];
        sort(points.begin()+1,points.end(),smallerAngle);//基于极点排序
        vector<vector<int>> res;
        res.push_back(polar_point);
        int i = 1;
        res.push_back(points[i++]);
        int top = 1;
        while(i<n){//遍历所有的点
            if(isLeft(points[i],res[top-1],res[top])){//如果扫描到的点构成凸包
                res.push_back(points[i++]);
                top++;
            }
            else{//如果扫描到的点不构成凸包
                res.pop_back();
                top--;
            }
        }
        i = 1;
        while(i<n-1){//可能会漏掉的一部分点，介于极点与最后一个点之间的点，也是需要的
            if(isLine(points[i],points[0],points[n-1])&&find(res.begin(),res.end(),points[i])==res.end()){//要判断是否已经在答案里了
                res.push_back(points[i]);
            }
            i++;
        }
        return res;
    }
};
