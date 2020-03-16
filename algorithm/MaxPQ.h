//
// Created by zzy on 2019-10-20.
//

#ifndef MAXPQ_H
#define MAXPQ_H

#include <string>
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
}


#endif //MAXPQ_H
