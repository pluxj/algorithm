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
            return _n == 0;
        };
        int size(){
            return _n;
        };
        void insert(int v);
        int delMax();

        void resize(int max);
    private:
        void swim(int k);
        void sink(int k);

    private:
        int _n;
        int _max;
        int * _pq;
    };
}


#endif //MAXPQ_H
