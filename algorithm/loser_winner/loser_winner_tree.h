#include <stdio.h>

class LoserTree
{
public:
    LoserTree(int capacity):size_(capacity)
    {
        leaves_ = new int[capacity+1]{0};
        success_tree = new int[capacity]{0};
    }

    void adjust(int i)
    {
        
    }
    int get_left_child(int i)
    {
        if(2*i < size_)
        {
            return 2*i;
        }
        else{
            return 2*i - size_;
        }
    }
private:
    int size_;
    int *leaves_;
    int *success_tree;
};