/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){

    int i,*ans,*lary,*rary;

    ans=malloc(4*numsSize);
    lary=malloc(4*numsSize);
    rary=malloc(4*numsSize);

    *returnSize=numsSize;
    lary[0]=1;
    for(i=1;i<numsSize;i++)
    {
        lary[i]=lary[i-1]*nums[i-1];
    }

    rary[numsSize-1]=1;
    for(i=numsSize-2;i>=0;i--)
    {
        rary[i]=rary[i+1]*nums[i+1];
    }

    for(i=0;i<numsSize;i++)
    {
        ans[i]=lary[i]*rary[i];
    }

    free(lary);
    free(rary);

    return ans;
}