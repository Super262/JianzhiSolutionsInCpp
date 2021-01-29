#include <vector>

int findRepeatNumber(std::vector<int>& nums) {
    bool* existed = new bool[nums.size()];
    memset(existed, 0, sizeof(bool) * nums.size());
    for(int num : nums){
        if(existed[num]){
            return num;
        } else {
            existed[num] = true;
        }
    }
    delete[] existed;
    return -1;
}