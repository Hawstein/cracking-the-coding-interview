#include <iostream>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

struct point{
    double x, y;
};
class line{
public:
    double epsilon, slope, intercept;
    bool bslope;
public:
    line(){}
    line(point p, point q){
        epsilon = 0.0001;
        if(abs(p.x - q.x) > epsilon){
            slope = (p.y-q.y) / (p.x-q.x);
            intercept = p.y - slope * p.x;
            bslope = true;
        }
        else{
            bslope = false;
            intercept = p.x;
        }
    }
    void print(){
        cout<<"y = "<<slope<<"x + "<<intercept<<endl;
    }
};

bool operator <(const line &l1, const line &l2){
    return l1.slope < l2.slope;
}
bool equal(double a, double b){
    return abs(a-b) < 0.0001;
}
bool operator ==(const line &l1, const line &l2){
    if(l1.bslope == l2.bslope && equal(l1.slope, l2.slope) && equal(l1.intercept, l2.intercept))
            return true;
        return false;
}
line find_best_line(point *p, int point_num){
    line bestline;
    bool first = true;
    map<line, int> line_count;
    for(int i=0; i<point_num; ++i){
        for(int j=i+1; j<point_num; ++j){
            line l(p[i], p[j]);
            if(line_count.find(l)==line_count.end())
                line_count[l] = 0;
            line_count[l] = line_count[l] + 1;
            if(first){
                bestline = l;
                first = false;
            }
            else{
                if(line_count[l] > line_count[bestline])
                    bestline = l;
            }
        }
    }
    cout<<line_count[bestline]<<endl;
    return bestline;
}
int main(){
    srand((unsigned)time(0));
    int graph_size = 10;
    int point_num = 500;
    point *p = new point[point_num];
    for(int i=0; i<point_num; ++i){
        p[i].x = rand()/double(RAND_MAX) * graph_size;
        p[i].y = rand()/double(RAND_MAX) * graph_size;
        cout<<p[i].x<<" "<<p[i].y<<endl;
    }
    line l = find_best_line(p, point_num);
    l.print();
    return 0;
}
