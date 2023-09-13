class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        i, j, k = 0 ,0 , 0
        m = len(nums1)
        n = len(nums2)
        arr = []
        while(i<m and j<n):
            if(nums1[i]>nums2[j]):
                arr.append(nums2[j])
                k+=1
                j+=1
            else:
                arr.append(nums1[i])
                k+=1
                i+=1
        while(i<m):
            arr.append(nums1[i])
            k+=1
            i+=1
        while(j<n):
            arr.append(nums2[j])
            k+=1
            j+=1
        len_arr = len(arr)
        if(len_arr%2 == 0):
            return float (arr[k//2]+arr[k//2 -1])/2
        else:
            return float (arr[k//2])