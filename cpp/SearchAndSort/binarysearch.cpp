// correct implementation of binary search that returns index of value in sorted array if it exists, else -1

int binarysearch(int A[], int length, int target)
{
    int lo = 0;
    int hi = length;

    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        int val = A[mid];
        if (val == target)
            return mid;
        else if (val < target)
            lo = mid + 1;
        else
            hi = mid;
    }

    return -1;
}