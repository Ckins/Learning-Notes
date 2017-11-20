class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        index = 0;
        int i = 0;
        while (i < v1.size() && i < v2.size()) {
            zig.push_back(v1[i]);
            zig.push_back(v2[i]);
            i++;
        }
        while (i < v1.size()) zig.push_back(v1[i++]);
        while (i < v2.size()) zig.push_back(v2[i++]);
    }

    int next() {
        return zig[index++];
    }

    bool hasNext() {
        return index < zig.size();
    }
private:
    int index;
    vector<int> zig;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
