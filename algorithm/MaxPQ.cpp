//
// Created by zzy on 2019-10-20.
//

#include "MaxPQ.h"
using namespace std;
namespace myalgoritm{
    MaxPQ::MaxPQ(int maxN):_n(0) {
        _pq = new int[maxN+1];
        _max = maxN+1;
    }
    MaxPQ::MaxPQ():_n(0),_pq(nullptr),_max(0) {

    }
    int MaxPQ::delMax() {
        int max = _pq[1];
        swap(_pq[_n--],_pq[1]);
        _pq[_n+1] = NULL;
        sink(1);
        if(_n < _max /2)
            resize(_max/2);
        return max;
    }

    void MaxPQ::insert(int v ) {
        if(_n >= _max)
            resize(2*_max + 1);
        _pq[++_n] = v;
        swim(_n);

    }

    void MaxPQ::sink(int k) {
        while(2*k <= _n){
            int j = 2*k;
            if(j <= _n && (_pq[j] < _pq[j+1]))
                j++;
            if(_pq[k] > _pq[j])
                break;
            swap(_pq[k],_pq[j]);
            k = j;

        }
    }

    void MaxPQ::resize(int max) {
        int *pq = new int[max];
        for(int i = 1;i <= _n; i++)
            pq[i] = _pq[i];
        delete _pq;
        _pq = pq;
        pq = nullptr;
        _max = max;
    }

    void MaxPQ::swim(int k) {
        while(k > 1 ){
            if(_pq[k/2] > _pq[k])
                break;

            swap(_pq[k/2],_pq[k]);
            k = k /2;

        }
    }
}
