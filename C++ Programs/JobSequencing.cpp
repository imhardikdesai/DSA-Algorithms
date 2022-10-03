/* 
Given an array of jobs where every job has a deadline 
and associated profit if the job is finished before the deadline. 
It is also given that every job takes a single unit of time, 
so the minimum possible deadline for any job is 1. Maximize the total 
profit if only one job can be scheduled at a time.
*/

#include <bits/stdc++.h>
using namespace std;

struct Job {

	char id;
	int deadline;
	int profit;
};

bool comp(Job a, Job b)
{
	return (a.profit > b.profit);
}

void JobScheduling(Job arr[], int n)
{
	sort(arr, arr + n, comp);

	int result[n]; 
	bool slot[n];

	for (int i = 0; i < n; i++) slot[i] = false;

	for (int i = 0; i < n; i++) {
		for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--) {
			if (slot[j] == false) {
				result[j] = i;
				slot[j] = true;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++){
        if (slot[i]) cout << arr[result[i]].id << " ";
    }	
        
}

int main()
{
	Job arr[] = { { 'a', 2, 100 },
				  { 'b', 1, 19 },
				  { 'c', 2, 27 },
				  { 'd', 1, 25 },
				  { 'e', 3, 15 } };

	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Following is maximum profit sequence of jobs: \n";

	JobScheduling(arr, n);
    cout << endl;
	return 0;
}
