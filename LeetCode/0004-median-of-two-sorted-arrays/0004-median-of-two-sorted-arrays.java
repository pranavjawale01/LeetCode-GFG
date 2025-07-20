class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        float [] arr = new float[m+n];
        int i=0,j=0,k=0;

        while(i<m && j<n)
        {
            if(nums1[i] > nums2[j])
            {
                arr[k++] = nums2[j++];
            }
            else
            {
                arr[k++] = nums1[i++];
            }
        }
        while(i<m)
        {
            arr[k++] = nums1[i++];
        }
        while(j<n)
        {
            arr[k++] = nums2[j++];
        }
        float len = arr.length;
        if(len%2==0)
        {
            return (double) (arr[k/2]+arr[k/2-1])/2.0;
        }
        else
        {
            return (double) arr[k/2];
        }
    }
}