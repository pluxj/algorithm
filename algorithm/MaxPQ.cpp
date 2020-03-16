//
// Created by zzy on 2019-10-20.
//

#include "MaxPQ.h"
using namespace std;
namespace myalgoritm{
    MaxPQ::MaxPQ(int maxN):n_(0) {
        pq_ = new int[maxN+1];
        max_ = maxN+1;
    }
    MaxPQ::MaxPQ():n_(0),pq_(nullptr),max_(0) {

    }
    int MaxPQ::delMax() {
        int max = pq_[1];
        swap(pq_[n_--],pq_[1]);
        pq_[n_+1] = NULL;
        sink(1);
        if(n_ < max_ /2)
            resize(max_/2);
        return max;
    }

    void MaxPQ::insert(int v ) {
        if(n_ >= max_)
            resize(2*max_ + 1);
        pq_[++n_] = v;
        swim(n_);

    }

    void MaxPQ::sink(int k) {
        while(2*k <= n_){
            int j = 2*k;
            if(j < n_ && (pq_[j] < pq_[j+1]))
                j++;
            if(pq_[k] > pq_[j])
                break;
            swap(pq_[k],pq_[j]);
            k = j;

        }
    }

    void MaxPQ::resize(int max) {
        int *pq = new int[max];
        for(int i = 1;i <= n_; i++)
            pq[i] = pq_[i];
        delete pq_;
        pq_ = pq;
        pq = nullptr;
        max_ = max;
    }

    void MaxPQ::swim(int k) {
        while(k > 1 ){
            if(pq_[k/2] > pq_[k])
                break;

            swap(pq_[k/2],pq_[k]);
            k = k /2;

        }
    }
}
