#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class SmartPointer{
public:
    SmartPointer(T* ptr){
        ref = ptr;
        ref_count = (unsigned*)malloc(sizeof(unsigned));
        *ref_count = 1;
    }
	
    SmartPointer(SmartPointer<T> &sptr){
        ref = sptr.ref;
        ref_count = sptr.ref_count;
        ++*ref_count;
    }
	
    SmartPointer<T>& operator=(SmartPointer<T> &sptr){
        if (this != &sptr) {
            if (--*ref_count == 0){
                clear();
                cout<<"operator= clear"<<endl;
            }
            
            ref = sptr.ref;
            ref_count = sptr.ref_count;
            ++*ref_count;
        }
        return *this;
    }
	
    ~SmartPointer(){
        if (--*ref_count == 0){
            clear();
            cout<<"destructor clear"<<endl;
        }
    }
	
    T getValue() { return *ref; }
    
private:
    void clear(){
        delete ref;
        free(ref_count);
        ref = NULL; // 避免它成为迷途指针
        ref_count = NULL;
    }
   
protected:	
    T *ref;
    unsigned *ref_count;
};

int main(){
    int *ip1 = new int();
    *ip1 = 11111;
    int *ip2 = new int();
    *ip2 = 22222;
    SmartPointer<int> sp1(ip1), sp2(ip2);
    SmartPointer<int> spa = sp1;
    sp2 = spa;
    return 0;
}
