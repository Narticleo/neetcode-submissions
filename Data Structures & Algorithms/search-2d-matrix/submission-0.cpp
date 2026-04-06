class Solution {
private:
    int _target;
    int n;
    bool binarySearch2D(int left, int right, vector<vector<int>> &matrix){
        if(right<left)return false;
        int mid = (left+right)/2;
        int i = mid/n;
        int j = mid%n;
        if(matrix[i][j] == _target)return true;
        return matrix[i][j] < _target ? binarySearch2D(mid+1, right, matrix) :
                                        binarySearch2D(left, mid-1, matrix);
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        _target = target;
        n = matrix[0].size();
        int m = matrix.size();
        return binarySearch2D(0, n*m-1, matrix);
    }
};
