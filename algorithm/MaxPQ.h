//
// Created by zzy on 2019-10-20.
//

#ifndef MAXPQ_H
#define MAXPQ_H

#include <string>
#include <assert.h>
#include <stdio.h>
#include <iostream>
using namespace std;


namespace myalgoritm {


    class MaxPQ {
    public:
        MaxPQ(int maxN);
        MaxPQ();
        ~MaxPQ();

        bool isEmpty(){
            return n_ == 0;
        };
        int size(){
            return n_;
        };
        void insert(int v);
        int delMax();

        void resize(int max);
    private:
        void swim(int k);
        void sink(int k);

    private:
        int n_;
        int max_;
        int * pq_;
    };


	template<typename Item>
    class IndexMaxHeap {

    private:
        Item* data_;    
        int* indexes_;   
        int* reverse_;

        int count_;
        int capacity_;

        void swim(int k)
        {
            while (k > 1 && data_[indexes_[k / 2]] < data_[indexes_[k]])
            {
                swap(indexes_[k / 2], indexes_[k]);
                reverse_[indexes_[k/2]] = k/2;
                reverse_[indexes_[k]] = k;
                k = k / 2;
            }
        }

        void sink(int k)
        {
            while (2 * k <= count_)
            {
                int j = k * 2;
                if (data_[indexes_[j]] < data_[indexes_[j + 1]])
                {
                    j = j + 1;
                }
                if (data_[indexes_[j]] <= data_[indexes_[k]])
                {
                    break;
                }
                swap(indexes_[j], indexes_[k]);
                reverse_[indexes_[j]] = j;
                reverse_[indexes_[k]] = k;
                k = j;
            }
        }

    public:
        IndexMaxHeap(int capacity)
        {
            capacity_ = capacity;
            data_ = new Item[capacity + 1];
            indexes_ = new int[capacity_ + 1];
            reverse_ = new int[capacity_+1]{0};
            
            count_ = 0;
        }

        ~IndexMaxHeap()
        {
            delete []data_;
            delete []indexes_;
            delete []reverse_;
        }

        int size() { return count_; }
        bool isEmpty(){return count_ == 0;}
        //传入的i 对用户而言，是从0开始索引的
        void insert(int i, Item item)
        {
            assert(count_ + 1 <= capacity_);
            assert(i + 1 >= 1 && i + 1 <= capacity_);

            i += 1;
            data_[i] = item;
            indexes_[count_ + 1] = i;
            reverse_[i] = count_ +1;
            count_++;
            swim(count_);
        }

        int extractMaxIndex()
        {
            assert(count_ == 0);
            int ret = indexes_[1] - 1;
            swap(indexes_[1], indexes_[count_]);
            reverse_[indexes_[1]] = 1;
            reverse_[indexes_[count_]] = 0;
            count_--;
            sink(1);
            return ret;
        }

        Item getItem(int i)
        {
            return data_[indexes_[i+1]];
        }
        /*
               0|1 |2 |3 |4 |5 | 6| 7| 8| 9|10
        index  -|10|9 |7 |8 |5 | 6| 3| 1| 4|2
        data   -|15|17|19|13|22|16|28|30|41|62
        //继续维护一个reverse 数组
               0|1 |2 |3 |4 |5 | 6| 7| 8| 9|10
        index  -|10|9 |7 |8 |5 | 6| 3| 1| 4|2
        data   -|15|17|19|13|22|16|28|30|41|62
        rev    -|8 |10|7 |9 |5 |6 |3 |5 |2 |1
        rev[i] 表示索引i 在堆中的位置
        indexes[i] = j
        rev[j] = i

        indexes[rev[j]] = j
        rev[indexed[i]] = i
        */
        void change(int i,Item newItem)
        {
            i += 1;
            
            data_[indexes_[i]] = newItem;
            //找到 data_[indexed_[i]] 在堆中的位置，indexes[j] = i
            // for(int j = 1;j < count_;j++)
            // {
            //     if(indexes_[j] == i)
            //     {
            //         swim(j);
            //         sink(j);
            //         break;
            //     }
            // }

            //使用reverse 数组优化
            int j = reverse_[i];
            swim[j];
            sink[j];
        }

    };
}


#endif //MAXPQ_H
