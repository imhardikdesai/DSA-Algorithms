//C# program to sort an integer array using Radix Sort.

using System;

class Sort
{
    static int MaxItem(int []arr) 
    {
        int max     = 0; 
        int loop    = 0;

        max=arr[0];
        for (loop = 1; loop < arr.Length; loop++)
        {
            if (arr[loop] > max)
                max = arr[loop];
        }
        return max;
    }
 
    static void CountSort(int []arr,int exp) 
    {
        int loop=0;
        int length = arr.Length;

        int [] output = new int[length] ; 
        int [] count  = new int[10]     ;

        for (loop = 0; loop < length; loop++)
            count[(arr[loop] / exp) % 10]++;

        for (loop = 1; loop < 10; loop++)
            count[loop] += count[loop - 1];

        for (loop = length - 1; loop >= 0; loop--)
        {
            output[count[(arr[loop] / exp) % 10] - 1] = arr[loop];
            count[(arr[loop] / exp) % 10]--;
        }

        for (loop = 0; loop < length; loop++)
            arr[loop] = output[loop];
    }
 

    static void RadixSort(int []arr) 
    {
        int exp = 1;
        int max = MaxItem(arr);
        int cond=0;

        while (true)
        { 
            cond=max / exp;

            if (cond <= 0)
                break;
            CountSort(arr, exp);

            exp = exp*10;
        }
    }
 
    static void Main(string[] args)
    {
        int []arr = {22,33,11,44,55,66,77,88};
        int loop = 0;
        
        RadixSort(arr);

        Console.WriteLine("Sorted Array: ");
        for (loop = 0; loop < arr.Length; loop++)
            Console.Write(arr[loop] + " ");

        Console.WriteLine();
    }
}
