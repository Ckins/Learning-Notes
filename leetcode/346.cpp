class MovingAverage {
public:
    int _size;
    int cur;
    int *store;
    bool full;
    
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        store = new int[size];
        memset(store, 0, sizeof(int) * size);
        _size = size;
        cur = -1;
        full = false;
    }
    
    double next(int val) {
        double res = 0.0;
        if (full) {
            cur = (cur + 1) % _size;
        } else {
            cur += 1;
            if (cur == _size - 1) full = true;
        }
        store[cur] = val;
        for (int i = 0; i < _size; i++) {
            // cout << store[i] << endl;
            res += store[i];
        }
        // cout << cur << endl;
        if (full) return res / _size;
        else return res / (cur + 1);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
