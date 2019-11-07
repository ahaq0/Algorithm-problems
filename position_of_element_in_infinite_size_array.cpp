/*
Suppose you have a sorted array of infinite numbers, how would you search an element in the array?

So the best way to go about this is use a modified version of binary search. Since we do not know 
the size of the array, we will find our own size.
*/

int binarySearch(int start, int end, int key, int arr[])
{
    // first we need to check if we can use our start and end indexes

    // if we can't
    if (arr[end] < key)
    {
        start = end;
        end = end * 2;
        // then we call it again
        binarySearch(start, end, key, arr);
    }

    if (arr[end] == key)
    {
        return end;
    }
    // now what if we've found that the value at end is bigger? that means we can run binary search

    int mid = (end + start) / 2;

    if (arr[mid] > key)
    {
        binarySearch(start, mid, key, arr);
    }

    else if (arr[mid] < key)
    {
        binarySearch(mid, end, key, arr);
    }

    else if (arr[mid] == key)
    {
        return key;
    }

    else
    {
        return -1; // not found;
    }
}

// alternative / better solution. make methods to divide the task of finding the position and binary search
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

// function takes an infinite size array and a key to be
//  searched and returns its position if found else -1.
// We don't know size of arr[] and we can assume size to be
// infinite in this function.
// NOTE THAT THIS FUNCTION ASSUMES arr[] TO BE OF INFINITE SIZE
// THEREFORE, THERE IS NO INDEX OUT OF BOUND CHECKING
int findPos(int arr[], int key)
{
    int l = 0, h = 1;
    int val = arr[0];

    // Find h to do binary search
    while (val < key)
    {
        l = h;        // store previous high
        h = 2 * h;    // double high index
        val = arr[h]; // update new val
    }

    // at this point we have updated low and
    // high indices, Thus use binary search
    // between them
    return binarySearch(arr, l, h, key);
}
